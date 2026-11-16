#!/usr/bin/env bash
# Build this userspace locally in docker, the same way CI does:
# upstream qmk_firmware + the keyboard definitions kept in this repo (scripts/sync_keyboards.sh).
#   scripts/build.sh                                 # every target in qmk.json (qmk userspace-compile)
#   scripts/build.sh yakamoz:ardakilic skywatch:arda  # single targets (qmk compile, strict keyboard.json check)
# Needs docker and a qmk/qmk_firmware clone with submodules: ../qmk_firmware, or set QMK_HOME.
# Firmware files land in this repo's root (git-ignored), like the CI 'Firmware' artifact.
set -euo pipefail

IMAGE=ghcr.io/qmk/qmk_cli:latest
US=$(cd "$(dirname "$0")/.." && pwd)
QMK_HOME=${QMK_HOME:-$US/../qmk_firmware}
if [ ! -d "$QMK_HOME/keyboards" ] || [ -z "$(ls -A "$QMK_HOME/lib/chibios" 2>/dev/null)" ]; then
    echo "error: no qmk_firmware clone with submodules at '$QMK_HOME'. Get one with:" >&2
    echo "  git clone --depth 1 --recurse-submodules --shallow-submodules https://github.com/qmk/qmk_firmware.git '$QMK_HOME'" >&2
    echo "or point QMK_HOME at an existing clone." >&2
    exit 1
fi
QMK_HOME=$(cd "$QMK_HOME" && pwd)
for t in "$@"; do
    [[ $t == ?*:?* ]] || { echo "error: '$t' is not keyboard:keymap" >&2; exit 1; }
done

# CI always runs the newest image; stay on the local copy when offline.
docker pull -q "$IMAGE" >/dev/null || echo "warning: could not pull $IMAGE, using the local image" >&2

# Runs as your user, so build output in both trees stays yours. HOME=/tmp keeps qmk/git config throwaway.
docker run --rm --user "$(id -u):$(id -g)" -e HOME=/tmp \
    -v "$US":/userspace -v "$QMK_HOME":/qmk_firmware -w /userspace "$IMAGE" bash -euc '
    git config --global --add safe.directory "*"
    qmk config user.qmk_home=/qmk_firmware user.overlay_dir=/userspace >/dev/null
    bash scripts/sync_keyboards.sh /qmk_firmware
    if [ $# -eq 0 ]; then
        qmk userspace-compile -j "$(nproc)" -p
    else
        for t in "$@"; do qmk compile -j "$(nproc)" -kb "${t%%:*}" -km "${t#*:}"; done
    fi
' _ "$@"
