#!/usr/bin/env bash
# Copy the keyboard definitions kept in this userspace into a qmk_firmware tree.
# QMK only discovers keyboards under qmk_firmware/keyboards/, so this runs before every build:
# CI runs it as the preparation_command, scripts/build.sh runs it locally.
#   * keyboard definition = a folder under keyboards/ with a keyboard.json (outside keymaps/);
#     it is copied from its highest parent folder that upstream QMK doesn't have, so the shared
#     files of a multi-revision board (keyboards/foo/{info.json,lib/} for foo/rev1) come along
#   * keymaps/ is never copied: QMK reads keymaps from this userspace, and a copy inside
#     qmk_firmware would win over the userspace one
#   * files are merged into existing folders; nothing in qmk_firmware is deleted
# Usage: scripts/sync_keyboards.sh [path/to/qmk_firmware]   (default: `qmk env QMK_FIRMWARE`)
#   qmk_firmware must be a git clone (CI's checkout and `qmk setup` are)
set -euo pipefail

QMK_DIR=${1:-$(qmk env QMK_FIRMWARE)}
if [ -z "$QMK_DIR" ]; then
    echo "error: pass the qmk_firmware path, or set user.qmk_home (qmk env QMK_FIRMWARE is empty)" >&2
    exit 1
fi
if [ ! -d "$QMK_DIR/keyboards" ]; then
    echo "error: '$QMK_DIR' is not a qmk_firmware folder (no keyboards/ inside)" >&2
    exit 1
fi
QMK_DIR=$(cd "$QMK_DIR" && pwd)
# upstream_has needs qmk_firmware's own git metadata: --show-prefix is empty only at the top of a
# work tree, so a plain folder is rejected, also one that sits inside another repo (this checkout).
if [ -n "$(git -c safe.directory='*' -C "$QMK_DIR" rev-parse --show-prefix 2>/dev/null || echo x)" ]; then
    echo "error: '$QMK_DIR' is not a git clone of qmk_firmware (git tells the sync which keyboards upstream has)" >&2
    exit 1
fi
cd "$(dirname "$0")/.."
if [ ! -d keyboards ]; then
    echo "No keyboards/ folder, nothing to copy."
    exit 0
fi

# True if upstream QMK already has this path (git-tracked in qmk_firmware). Files left behind by an
# earlier local sync are untracked, so they don't count (plain "exists" would count them).
upstream_has() {
    git -c safe.directory='*' -C "$QMK_DIR" ls-files --error-unmatch -- "keyboards/$1" >/dev/null 2>&1
}

paths=()
while IFS= read -r kb; do
    root=$kb
    while [ "$(dirname "$root")" != . ] && ! upstream_has "$(dirname "$root")"; do
        root=$(dirname "$root")
    done
    echo "keyboard: $kb$([ "$root" = "$kb" ] || echo " (copied from keyboards/$root)")"
    if upstream_has "$kb"; then
        echo "::warning::keyboards/$kb also exists in upstream QMK; the files kept here are merged over it"
    fi
    # Revisions of one board share a root; sorted input keeps them next to each other.
    if [ ${#paths[@]} -eq 0 ] || [ "${paths[${#paths[@]}-1]}" != "$root" ]; then
        paths+=("$root")
    fi
done < <(cd keyboards && find . -name keyboard.json -not -path '*/keymaps/*' -exec dirname {} \; | sed 's#^\./##' | sort)

if [ ${#paths[@]} -eq 0 ]; then
    echo "No keyboard definitions found under keyboards/, nothing to copy."
    exit 0
fi
tar -C keyboards --exclude=keymaps -cf - -- "${paths[@]}" | tar -C "$QMK_DIR/keyboards" --no-same-owner -xf -
echo "Copied into $QMK_DIR/keyboards (keymaps/ skipped)."
