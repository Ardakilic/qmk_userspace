# Yakamoz - ithalat trackpad keymap (`yakamoz_ithalat_trackpad`)

My `ardakilic` Yakamoz keymap plus an **Azoteq TPS65 trackpad** in the [ithalat](https://github.com/Ardakilic/ithalat) wrist rest.

## TL;DR

- **What:** the `ardakilic` keymap + a hot-pluggable TPS65 trackpad on the OLED's I2C bus.
- **Gestures:** tap = left click, 2-finger tap = right click, press-and-hold (~0.5 s) = drag, 2-finger slide = scroll.
- **OLED:** a new line shows `Pad: on` / `Pad: --`.
- **Hardware:** [ithalat](https://github.com/Ardakilic/ithalat), wired with the [wiring guide](https://github.com/Ardakilic/ithalat/blob/main/wiring.md).
- **Build:** `qmk compile -kb yakamoz -km yakamoz_ithalat_trackpad`
- **Flash:** drop `yakamoz_yakamoz_ithalat_trackpad.uf2` onto the `RPI-RP2` drive.

> [!WARNING]
> **Not tested on hardware yet.** It compiles with zero warnings and the trackpad logic passed ithalat's simulated tests. Do the [test checklist](https://github.com/Ardakilic/ithalat/blob/main/firmware/README.md#test-checklist-after-flashing) on first flash.

## What it adds vs. `ardakilic`

| Area | Change |
|---|---|
| Layers, Turkish-Q macros, audio, WPM | unchanged |
| Trackpad | `POINTING_DEVICE_DRIVER = azoteq_iqs5xx`, TPS65 profile, on I2C1 (GP2 SDA / GP3 SCL), shared with the OLED |
| Speed | `TRACKPAD_CPI 500`, re-applied after every (re)init |
| Hot-plug | plug the pad in after boot: it is found and set up within ~1 s; unplug: `Pad: --` |
| Tap-latch fix | works around QMK >= 0.34.0 never releasing a tap's click |
| OLED | one extra line: `Pad: on` / `Pad: --` |
| SODA layer | `[3,6]`/`[3,7]` are removed on the ithalat build, so their audio keys are copied: `QK_AUDIO_VOICE_NEXT` to `[3,4]`, `QK_MUSIC_TOGGLE` to `[3,9]` |

- **Still works on a stock Yakamoz:** every original keycode stays in place.
- **Trackball or trackpad, not both:** QMK takes one pointing driver, so this replaces the Pimoroni trackball option.

## Wiring at a glance

| Signal | Pico pin |
|---|---|
| SDA | GP2 (pin 4) |
| SCL | GP3 (pin 5) |
| 3V3 | 3V3(OUT) (pin 36) - **never 5 V** |
| GND | any GND |
| RDY (optional) | GP15 (pin 20) |

Full guide: [ithalat wiring.md](https://github.com/Ardakilic/ithalat/blob/main/wiring.md).

## Build

The `yakamoz` keyboard definition lives in this repo (`keyboards/yakamoz/`). QMK only finds keyboards inside `qmk_firmware/keyboards/`, so copy it in first. CI does this with the same script.

> [!WARNING]
> `scripts/build.sh` and `scripts/sync_keyboards.sh` both copy **every** keyboard definition kept here (`cost_crafter40`, `skywatch`, `woodpecker`, `yakamoz`), not just `yakamoz`. They overwrite files at the same paths in `qmk_firmware/keyboards/` (`keymaps/` is skipped), local edits included, and warn only when upstream QMK tracks the same keyboard. Make keyboard changes in this repo, and back up local edits in your QMK clone before running either.

```sh
# easiest: docker, same steps as CI
scripts/build.sh yakamoz:yakamoz_ithalat_trackpad

# or with your own QMK install, inside this userspace clone
qmk config user.overlay_dir="$(realpath .)"
scripts/sync_keyboards.sh                  # copies every keyboard kept here into qmk_firmware

# build this keymap only
qmk compile -kb yakamoz -km yakamoz_ithalat_trackpad

# or every target in qmk.json
qmk userspace-compile
```

- **Output:** `yakamoz_yakamoz_ithalat_trackpad.uf2`
- **No local QMK?** GitHub Actions builds it on every push. Grab it from this repo's Releases (updated by pushes to `main`) or from the run's `Firmware` artifact.

## Flash

1. **Bootloader:** double-tap reset, or hold `SODA` (bottom-left key) and press `QK_BOOT` (top row, 2nd key).
2. **Copy:** drop the `.uf2` onto the `RPI-RP2` drive.
3. **Pad:** plug the trackpad in and wait for `Pad: on` on the OLED.

Or in one step: `qmk flash -kb yakamoz -km yakamoz_ithalat_trackpad`

## Tweak it (`config.h`)

| Define | Default | Change it when |
|---|---|---|
| `TRACKPAD_CPI` | `500` | the cursor is too slow/fast (`0` = native ~1200) |
| `AZOTEQ_IQS5XX_ROTATION_90` / `_180` / `_270` | off | the cursor moves the wrong way ([calibration](https://github.com/Ardakilic/ithalat/blob/main/firmware/README.md#calibration-30-seconds)) |
| `I2C1_CLOCK_SPEED` | `400000` | the cursor stutters or `Pad:` flickers: try `100000` |
| `POINTING_DEVICE_MOTION_PIN` | off | you wired RDY to GP15 (pogo only) |
| `AZOTEQ_IQS5XX_PRESS_AND_HOLD_ENABLE` | `true` | resting a finger gives unwanted clicks |

## More

- **Deep dive** (hot-plug timing, tap-latch cause, simulated tests): [ithalat firmware/README.md](https://github.com/Ardakilic/ithalat/blob/main/firmware/README.md)
- **Why underscores in the name:** QMK keymap names allow only `a-z`, `0-9` and `_` (`qmk new-keymap`, `qmk lint` and the `qmk.json` schema reject `-`).
