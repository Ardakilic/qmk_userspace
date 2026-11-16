# Arda Kılıçdağı's QMK Userspace

This is a template repository which allows for an external set of QMK keymaps to be defined and compiled. This is useful for users who want to maintain their own keymaps without having to fork the [main QMK repository](https://github.com/qmk/qmk_firmware). You must still fork the main QMK repository if writing firmware for a *new* keyboard.

This repo doesn't need that fork: the 4 keyboards it builds that upstream QMK doesn't have live here too. See [Keyboards kept in this repo](#keyboards-kept-in-this-repo-no-qmk-fork).

Coding agents (and humans in a hurry): [AGENTS.md](AGENTS.md) has the repo rules and the pre-PR checklist.

## Notable keymaps

* [`yakamoz:yakamoz_ithalat_trackpad`](keyboards/yakamoz/keymaps/yakamoz_ithalat_trackpad/README.md) -- my `yakamoz:ardakilic` keymap plus the Azoteq TPS65 trackpad of the [ithalat](https://github.com/Ardakilic/ithalat) wrist rest (hot-pluggable, on the OLED's I2C bus).

## Howto configure your build targets

1. Run the normal `qmk setup` procedure if you haven't already done so -- see [QMK Docs](https://docs.qmk.fm/#/newbs) for details.
1. Fork this repository
1. Clone your fork to your local machine
1. Enable userspace in QMK config using `qmk config user.overlay_dir="$(realpath qmk_userspace)"`
1. Add a new keymap for your board using `qmk new-keymap`
    * This will create a new keymap in the `keyboards` directory, in the same location that would normally be used in the main QMK repository. For example, if you wanted to add a keymap for the Planck, it will be created in `keyboards/planck/keymaps/<your keymap name>`
    * You can also create a new keymap using `qmk new-keymap -kb <your_keyboard> -km <your_keymap>`
    * Alternatively, add your keymap manually by placing it in the location specified above.
    * `layouts/<layout name>/<your keymap name>/keymap.*` is also supported if you prefer the layout system
1. Add your keymap(s) to the build by running `qmk userspace-add -kb <your_keyboard> -km <your_keymap>`
    * This will automatically update your `qmk.json` file
    * Corresponding `qmk userspace-remove -kb <your_keyboard> -km <your_keymap>` will delete it
    * Listing the build targets can be done with `qmk userspace-list`
1. Commit your changes

## Howto build with GitHub

1. In the GitHub Actions tab, enable workflows
1. Push your changes above to your forked GitHub repository
1. Look at the GitHub Actions for a new actions run
1. Wait for the actions run to complete
1. Inspect the Releases tab on your repository for the latest firmware build

### Keyboards kept in this repo (no QMK fork)

**TL;DR:** CI builds every `qmk.json` target on upstream [`qmk/qmk_firmware`](https://github.com/qmk/qmk_firmware) (`master`). The 4 keyboards upstream QMK doesn't have live here and get copied into `qmk_firmware` right before each build. No fork to maintain. Only pushes to `main` publish the `latest` release.

| Keyboard | Designer | Keymaps built |
|---|---|---|
| `cost_crafter40` | ozkan ([CostCrafter40-QMK](https://github.com/ozkan/CostCrafter40-QMK)) | `ardakilic` |
| `skywatch` | ozkan ([skywatch](https://github.com/ozkan/skywatch)) | `arda` |
| `woodpecker` | ozkan ([woodpecker-keyboard](https://github.com/Ardakilic/woodpecker-keyboard), hosted in my repo) | `ardakilic` |
| `yakamoz` | ozkan ([Yakamoz](https://github.com/ozkan/Yakamoz)) | `ardakilic`, `yakamoz_ithalat_trackpad` |

* Each is a full keyboard definition in `keyboards/<keyboard>/` (`keyboard.json`, `config.h`, `rules.mk`, `halconf.h`/`mcuconf.h`, `lib/`, ...), next to my keymaps in `keyboards/<keyboard>/keymaps/`.
* Imported from my old fork (`Ardakilic/qmk_firmware` @ `f5cca70`), without the fork's keymaps. `manufacturer`/`maintainer` and license headers are unchanged.
* `woodpecker`: PCB by [Özkan Çelik](https://github.com/ozkan), made at my request. The PCB, plates and shields live in my [woodpecker-keyboard](https://github.com/Ardakilic/woodpecker-keyboard) repo. Its QMK definition started in [Ender Piyale](https://github.com/enderpiyale)'s QMK fork (he and Kazim Kaba also made the shields).
* `keyboards/yakamoz/user_song_list.h` comes from [ozkan/Yakamoz-qmk](https://github.com/ozkan/Yakamoz-qmk): it defines `STAR_WARS_IMPERIAL_MARCH`, the startup song set in `keyboards/yakamoz/config.h`.

#### Why copy them?

* External Userspace only overlays keymaps (`keyboards/*/keymaps/`, `layouts/`, `users/`). QMK only finds *keyboards* under `qmk_firmware/keyboards/`.
* So `scripts/sync_keyboards.sh` copies every folder here that has a `keyboard.json` into `qmk_firmware/keyboards/` before the build.
* It never copies `keymaps/`: keymaps inside `qmk_firmware` win over the userspace ones, so a copy there would silently replace mine.
* It merges and never deletes. If upstream QMK ever adds a keyboard at the same path, it prints a `::warning::`. Then delete the copy here and use upstream's.

#### How CI does it

`.github/workflows/build_binaries.yaml`:

```yaml
qmk_repo: qmk/qmk_firmware
qmk_ref: master
preparation_command: bash scripts/sync_keyboards.sh qmk_firmware
```

* The reusable QMK workflow runs `preparation_command` after `qmk userspace-doctor` and before `qmk userspace-compile`, from this repo's root, with upstream QMK checked out in `./qmk_firmware`.
* Publishing: only a `push` to `main` replaces the `latest` release, and only when every target built. Other branches and manual (`workflow_dispatch`) runs just build; their firmware is in the run's `Firmware` artifact.

#### Build locally (docker, same steps as CI)

```sh
# one time: upstream QMK with submodules, next to this repo
git clone --depth 1 --recurse-submodules --shallow-submodules \
    https://github.com/qmk/qmk_firmware.git ../qmk_firmware

scripts/build.sh                                   # all qmk.json targets (qmk userspace-compile)
scripts/build.sh yakamoz:ardakilic skywatch:arda   # single targets (qmk compile, strict)
QMK_HOME=~/src/qmk_firmware scripts/build.sh       # QMK clone somewhere else
```

* Runs `ghcr.io/qmk/qmk_cli:latest`: the sync, then the build. Nothing to install besides docker.
* Firmware files land in this repo's root (git-ignored).
* The copied keyboards stay in your local `qmk_firmware` (CI starts clean every run). Reset with `git -C ../qmk_firmware clean -fdq keyboards/`.

#### Add or update a keyboard

1. Put the whole keyboard folder in `keyboards/<keyboard>/`. Everything except `keymaps/` gets copied. Nested names work too (`keyboards/handwired/foo/`).
1. Add the keymap in `keyboards/<keyboard>/keymaps/<keymap>/`.
1. Add the target to `qmk.json`, by hand or with `qmk userspace-add -kb <keyboard> -km <keymap>` (it checks that the keyboard exists, so run the sync first).
1. Check it with a strict single build: `scripts/build.sh <keyboard>:<keymap>`.
1. To update a keyboard, edit its files here. The next build picks them up.

#### Gotcha: `url` in `keyboard.json` must not be empty

* QMK checks `keyboard.json` against its schema. With `"url": ""`, it ignores the whole file (`☒ Not including data from file: ... url: '' should be non-empty`), and `qmk compile` then fails with `No LAYOUTs defined` / `Invalid BOOTLOADER`.
* `qmk userspace-compile` (what CI runs) skips that check, so CI can be green while `qmk compile` fails. Hence the strict single build above.
* `cost_crafter40` and `skywatch` had empty URLs in the fork. They now point to ozkan's repos. `woodpecker` had no `url`; it now points to [woodpecker-keyboard](https://github.com/Ardakilic/woodpecker-keyboard).

#### The fork is no longer used

* Nothing here uses `Ardakilic/qmk_firmware` anymore. It can be archived (Settings → General → Archive this repository).
* Archive rather than delete: archived repos stay readable, so anything pinned to a fork commit keeps working.
* It still holds 5 boards that aren't built here: `cheapis`, `domo`, `eswai/qol56`, `handwired/ardapad`, `handwired/ardapuke`.
    * To build one again, copy its folder into `keyboards/` (see [Add or update a keyboard](#add-or-update-a-keyboard)).
    * All but `domo` still use the old `info.json` format. Current QMK (and the sync) only treats a folder with a `keyboard.json` as a keyboard, so migrate those first.

## Howto build locally

1. Run the normal `qmk setup` procedure if you haven't already done so -- see [QMK Docs](https://docs.qmk.fm/#/newbs) for details.
1. Fork this repository
1. Clone your fork to your local machine
1. `cd` into this repository's clone directory
1. Set global userspace path: `qmk config user.overlay_dir="$(realpath .)"` -- you MUST be located in the cloned userspace location for this to work correctly
    * This will be automatically detected if you've `cd`ed into your userspace repository, but the above makes your userspace available regardless of your shell location.
1. Compile normally: `qmk compile -kb your_keyboard -km your_keymap` or `make your_keyboard:your_keymap`

Alternatively, if you configured your build targets above, you can use `qmk userspace-compile` to build all of your userspace targets at once.

> [!NOTE]
> `cost_crafter40`, `skywatch`, `woodpecker` and `yakamoz` aren't in upstream QMK, so both commands fail for them until you run `scripts/sync_keyboards.sh` (it copies them into your `qmk_firmware`). Or use `scripts/build.sh`, which does both: see [Build locally](#build-locally-docker-same-steps-as-ci).

## Extra info

If you wish to point GitHub actions to a different repository, a different branch, or even a different keymap name, you can modify `.github/workflows/build_binaries.yaml` to suit your needs.

To override the `build` job, you can change the following parameters to use a different QMK repository or branch:
```
    with:
      qmk_repo: qmk/qmk_firmware
      qmk_ref: master
```

If you wish to manually manage `qmk_firmware` using git within the userspace repository, you can add `qmk_firmware` as a submodule in the userspace directory instead. GitHub Actions will automatically use the submodule at the pinned revision if it exists, otherwise it will use the default latest revision of `qmk_firmware` from the main repository.

This can also be used to control which fork is used, though only upstream `qmk_firmware` will have support for external userspace until other manufacturers update their forks.

1. (First time only) `git submodule add https://github.com/qmk/qmk_firmware.git`
1. (To update) `git submodule update --init --recursive`
1. Commit your changes to your userspace repository
