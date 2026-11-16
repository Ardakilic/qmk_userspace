# AGENTS.md

Notes for coding agents working in this repo. [README.md](README.md) has the long version. Check claims against the files before relying on them.

## What this repo is

- Arda Kılıçdağı's (Ardakilic) [QMK External Userspace](https://docs.qmk.fm/newbs_external_userspace): keymaps, plus 4 full keyboard definitions that upstream QMK doesn't have.
- Build targets: `qmk.json` (13 `[keyboard, keymap]` pairs).
- CI (`.github/workflows/build_binaries.yaml`) builds every target on each push and on `workflow_dispatch`, on upstream [`qmk/qmk_firmware`](https://github.com/qmk/qmk_firmware) `master`.
- Only a push to `main` whose build succeeded replaces the `latest` GitHub release. Other runs only keep the firmware in the run's `Firmware` artifact.
- No fork of `qmk_firmware` is used. The old `Ardakilic/qmk_firmware` fork is retired; don't point anything back at it.

## Layout

| Path | What |
|---|---|
| `qmk.json` | build targets |
| `keyboards/<kb>/keymaps/<km>/` | keymaps (`keymap.c`, `config.h`, `rules.mk`, README). Upstream boards: `crkbd`, `ergotravel`, `horizon`, `peej/lumberjack`, `planck` (target `planck/rev6`), `tada68` |
| `keyboards/{cost_crafter40,skywatch,woodpecker,yakamoz}/` | full keyboard definitions (`keyboard.json`, `config.h`, `rules.mk`, `halconf.h`/`mcuconf.h`, `lib/`, ...) with my keymaps in their `keymaps/` |
| `layouts/` | community-layout keymaps (`ortho_5x12`, `orhto_4x12` [sic]). Not in `qmk.json` |
| `users/Ardakilic/` | shared headers: `ardakilic.h` (includes `custom_codes.h`), `custom_codes.h` (Turkish-Q shortcuts), `user_song_list.h` |
| `scripts/sync_keyboards.sh` | copies the keyboard definitions into a `qmk_firmware` tree |
| `scripts/build.sh` | local docker build, same steps as CI |
| `.devcontainer/` | VS Code dev container (`ghcr.io/qmk/qmk_cli`) |
| `TODO.md` | boards from the old fork not ported yet |

Keyboards kept here. All 4 are designed by **ozkan**:

| Keyboard | Source | Keymaps built |
|---|---|---|
| `cost_crafter40` | https://github.com/ozkan/CostCrafter40-QMK | `ardakilic` |
| `skywatch` | https://github.com/ozkan/skywatch | `arda` |
| `woodpecker` | https://github.com/Ardakilic/woodpecker-keyboard (ozkan's design, hosted on Ardakilic's repo) | `ardakilic` |
| `yakamoz` | https://github.com/ozkan/Yakamoz | `ardakilic`, `yakamoz_ithalat_trackpad` |

Don't name anyone else as a board's designer. README.md credits other contributors, such as woodpecker's QMK port and shields, separately.

## How builds work

- External Userspace only overlays keymaps (`keyboards/*/keymaps/`, `layouts/`, `users/`). QMK only discovers *keyboards* under `qmk_firmware/keyboards/`.
- So `scripts/sync_keyboards.sh` runs before every build. It copies each folder under `keyboards/` that has a `keyboard.json` (outside `keymaps/`) into `qmk_firmware/keyboards/`.
    - It never copies `keymaps/`.
    - It merges and never deletes.
    - It prints `::warning::` if upstream QMK has the same path. If that happens, delete the copy here and use upstream's.
- CI: `uses: qmk/.github/.github/workflows/qmk_userspace_build.yml@main` with
  `qmk_repo: qmk/qmk_firmware`, `qmk_ref: master`, `preparation_command: bash scripts/sync_keyboards.sh qmk_firmware`
  (runs after `qmk userspace-doctor`, before `qmk userspace-compile`). Publishing uses `qmk_userspace_publish.yml@main`.
- Local: `scripts/build.sh` runs everything in `ghcr.io/qmk/qmk_cli:latest`. You only need docker plus a `qmk_firmware` clone with submodules at `../qmk_firmware` (or set `QMK_HOME`). Never install qmk, Python packages or toolchains on the host.

```sh
git clone --depth 1 --recurse-submodules --shallow-submodules \
    https://github.com/qmk/qmk_firmware.git ../qmk_firmware   # one time
scripts/build.sh                      # all qmk.json targets (qmk userspace-compile)
scripts/build.sh yakamoz:ardakilic    # single target(s), strict qmk compile
# drop the synced boards from the local clone: dry run (-n), review the list, then delete (-f)
git -C ../qmk_firmware/keyboards clean -nd -- cost_crafter40 skywatch woodpecker yakamoz
git -C ../qmk_firmware/keyboards clean -fd -- cost_crafter40 skywatch woodpecker yakamoz
```

- Firmware lands in the repo root (`*.uf2`, `*.bin`, `*.hex` are git-ignored).
- Cleaning the local clone:
    - Clean only the synced board folders, never all of `keyboards/`: that also deletes the user's own untracked keyboards and keymaps in the clone.
    - Review the dry run before deleting. It also lists anything of the user's inside those folders, such as their own `keymaps/<name>/`.
    - Keep the folder list in step with the kept boards. Use the folder the sync copies: the `keyboard:` path it prints, or the `copied from` path when it shows one.

## Rules and gotchas

- **Keymap names:** only `a-z`, `0-9` and `_`. No `-`, no capitals.
- **Adding a target:** `qmk userspace-add -kb <kb> -km <km>` or edit `qmk.json` by hand. `userspace-add` checks that the keyboard exists, so for the 4 boards kept here run the sync first.
- **Zero warnings:** QMK builds with `-Werror`. Don't set `ALLOW_WARNINGS`.
- **Keycodes:** use current names (e.g. `QK_BOOT`, `MS_BTN1`). QMK renames keycodes and later drops the old aliases. Check the QMK docs through Context7 (`/qmk/qmk_firmware`) instead of relying on memory.
- **`url` in `keyboard.json` must not be empty:**
    - With `"url": ""`, schema validation drops the whole file, and `qmk compile` fails (`No LAYOUTs defined`, `Invalid BOOTLOADER`).
    - `qmk userspace-compile`, which CI runs, skips that check, so CI can be green while `qmk compile` fails.
    - So run a strict single build for any keyboard you change here.
- **Keymaps in `qmk_firmware` win** over userspace keymaps with the same name. Never copy keymaps into `qmk_firmware`; that's why the sync skips `keymaps/`.
- **`users/Ardakilic`:**
    - No `qmk.json` target uses it. Only `layouts/*/ardakilic/keymap.c` include `ardakilic.h`.
    - QMK looks in `users/$(USER_NAME)`. `USER_NAME` defaults to the keymap name, and the lookup is case-sensitive on Linux CI.
    - To use the folder from a keymap, set `USER_NAME = Ardakilic` in that keymap's `rules.mk`.
- **Don't commit:**
    - firmware binaries;
    - a `qmk_firmware` tree or submodule;
    - local build output.
- **Credits:** keep the designer credits (`manufacturer`/`maintainer`/`url` in `keyboard.json`, readmes, license headers) when you edit a kept keyboard.
- **Publish condition:** the `publish` job's `if:` must keep `needs.build.result == 'success'` (plus the push-to-`main` checks). The publisher deletes the old release first, so a partial build would replace good firmware with an incomplete set.

## The `yakamoz_ithalat_trackpad` keymap

This is the `ardakilic` keymap plus an Azoteq TPS65 trackpad (IQS550, `POINTING_DEVICE_DRIVER = azoteq_iqs5xx`) in the [ithalat](https://github.com/Ardakilic/ithalat) wrist rest. Details are in its `README.md` and `config.h`.

- **Bus:** the pad shares the OLED's I2C1 bus: SDA `GP2`, SCL `GP3`. Don't copy cost_crafter40's `GP18`/`GP19`, which are matrix columns on Yakamoz.
- **Hot-plug:**
    - `keymap.c` checks for the pad every `TRACKPAD_HOTPLUG_INTERVAL_MS` (1000 ms) and re-initialises it.
    - `TRACKPAD_CPI` is re-applied after every init.
    - The OLED shows `Pad: on` / `Pad: --`.
- **Tap-latch workaround:** works around QMK >= 0.34.0 never releasing a tap's click. `TRACKPAD_NO_TAP_LATCH_FIX` turns it off.
- **One pointing driver:** it replaces the Pimoroni trackball option.
- **Not tested on hardware yet.**
- **Scenario tests** live in the ithalat repo, not here: `firmware/tests/azoteq_scenarios/`, run with `firmware/test.sh` after `firmware/build.sh` (docker only).
    - They exercise the twin keymap `firmware/qmk_userspace/keyboards/yakamoz/keymaps/ithalat/`.
    - The tested code is its first `#ifdef POINTING_DEVICE_ENABLE` ... `#endif // POINTING_DEVICE_ENABLE` block.
- **Keep the twins in sync:**
    - Covered: the trackpad block in `keymap.c` (that first `POINTING_DEVICE_ENABLE` block), the trackpad section of `config.h`, and `rules.mk`. Today only comments differ.
    - Change one, port it to the other, then rerun ithalat's `firmware/test.sh`.

## Checklist before a PR

1. `scripts/build.sh`: all 13 targets `[OK]`, no warnings.
2. Changed a kept keyboard (`cost_crafter40`, `skywatch`, `woodpecker`, `yakamoz`)? Also run `scripts/build.sh <kb>:<km>` (strict `qmk compile`).
3. Changed a shell script? Run
   `docker run --rm -v "$PWD":/mnt -w /mnt koalaman/shellcheck:stable scripts/*.sh .devcontainer/setup.sh`
4. Changed a workflow? Run
   `docker run --rm -v "$PWD":/repo -w /repo rhysd/actionlint:latest`
5. Changed the trackpad code? Sync the ithalat twin and run its tests.
6. Changed how something works? Update README.md and this file. No firmware files in the diff.
