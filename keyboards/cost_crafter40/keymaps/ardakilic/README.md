# Cost Crafter 40 - Ardakilic Turkish Keymap

```
╔═══════════════════════════════════════════════════════════════════╗
║                    COST CRAFTER 40 KEYMAP                         ║
║                   Turkish Layout - macOS/Windows                  ║
║                                                                   ║
║  40-Key Compact Layout │ Azoteq Trackpad │ 7 Layers │ 13 Combos   ║
╚═══════════════════════════════════════════════════════════════════╝
```

This keymap is optimized for **Turkish Q keyboard layout** on macOS, with automatic OS detection for Windows/Linux compatibility. It combines functionality from multiple larger keyboards (yakamoz, woodpecker, horizon) into a compact 40-key layout using layers and combos.

## Features Overview

```
┌─────────────────────────────────────────────────────────────────┐
│ ✓ Turkish Layout      Full ş, ı, ğ, ü, ö, ç character support   │
│ ✓ 7 Layers            QWERTY, LOWER, SPACE, NUMPAD, ADJUST,     │
│                       RAISE, MAC                                │
│ ✓ 13 Combos           Essential keys + mouse buttons            │
│ ✓ Trackpad            Azoteq TPS65 with I2C (DPI 500)           │
│ ✓ OS Detection        Auto MAC layer on macOS                   │
│ ✓ Tap-Hold Keys       Space-efficient multi-function keys       │
│ ✓ Auto Mouse Move     Prevent screen lock feature               │
└─────────────────────────────────────────────────────────────────┘
```

---

## Layers

### Base Layer (QWERTY)
```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │
│     │     │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  Ş  │
│     │     │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  Ö  │  Ç  │  .  │
│ ⇧(t)│     │     │     │     │     │     │     │     │ ⇧(t)│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│  "  │ <>| │ Alt │ Cmd │Lowr │Spc  │  ←  │  ↓  │  ↑  │  →  │
│ (h) │ (h) │     │     │     │ (h) │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘

Legend: ⁽ᵗ⁾=Tap-hold  ⁽ʰ⁾=Hold for layer
Special: " key holds for NUMPAD │ <>| key holds for CTRL │ Spc holds for SPACE layer

COMBOS - Essential Keys:
┌─────────────────────────────────────────────────────────────┐
│ Q + W  = ESC          │ A + S  = TAB                        │
│ O + P  = DEL          │ L + Ş  = BACKSPACE                  │
│ X + C  = CTRL         │ C + V  = GUI/CMD                    │
│ Q + A  = NUMPAD Layer (momentary while held)                │
└─────────────────────────────────────────────────────────────┘

COMBOS - Mouse Buttons (for trackpad):
┌─────────────────────────────────────────────────────────────┐
│ D + F  = Left Click   │ J + K  = Left Click                 │
│ V + B  = Right Click  │ N + M  = Right Click                │
│ F + G  = Middle Click │ H + J  = Middle Click               │
└─────────────────────────────────────────────────────────────┘
```

### LOWER Layer (Function Keys & Symbols)
**Access:** Hold "Lower" key (5th key from left on bottom row)
```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │  \  │  |  │  -  │  =  │
│     │     │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │  #  │  `  │  İ  │  Ğ  │
│     │     │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │  *  │  ?  │  @  │  $  │  {  │  }  │  Ü  │  _  │
│     │     │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │  %  │  !  │  &  │ ▓▓▓ │  ^  │  ~  │  (  │  )  │  +  │
│     │     │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘

Turkish Characters: İ (i with dot), Ğ (g breve), Ü (u umlaut)
Programming Symbols: All braces, brackets, special chars accessible
```

### SPACE Layer (CMD Shortcuts & Navigation)
**Access:** Hold "Space" key (layer tap)
```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│CMD 1│CMD 2│CMD 3│CMD 4│CMD 5│CMD 6│CMD 7│CMD 8│CMD 9│CMD 0│
│     │     │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │     │     │     │     │  ↑  │     │
│     │     │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │     │     │     │  ←  │  ↓  │  →  │
│     │     │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │     │ ▓▓▓ │     │Bri -│  ↑  │Bri +│
│     │     │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘

App Switching: CMD+1 through CMD+0 for quick app switching
Navigation: Enhanced arrow keys for text navigation
Brightness: Quick brightness controls
```

### NUMPAD Layer
**Access:** Hold `"` key (bottom-left) OR Hold Q+A combo
```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │ Num │  /  │  7  │  8  │  9  │  -  │
│     │     │     │     │Lock │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │     │  *  │  4  │  5  │  6  │  +  │
│     │     │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │     │  =  │  1  │  2  │  3  │Enter│
│     │     │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ ▓▓▓ │     │     │     │Bksp │  ,  │  0  │  0  │  .  │Enter│
│     │     │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘

Full numpad on right side
Double zero for faster number entry
Turkish layout: Period (.) key types comma (,) on numpad
```

### ADJUST Layer (System & Settings)
**Access:** Hold LOWER + SPACE together (tri-layer activation)
```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│RESET│     │     │     │     │     │     │     │     │Lock │
│     │     │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│CAPS │     │     │     │     │     │     │     │     │     │
│Lock │     │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │     │Prev │Play │Next │Vol -│Vol +│
│     │     │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │ MAC │ ▓▓▓ │Enter│Bri -│     │  ↑  │Bri +│
│     │     │     │Tggl │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘

System: QK_BOOT for firmware reset, Screen Lock (macOS)
Media: Full media controls (previous, play/pause, next)
Volume: Volume up/down
Brightness: Screen brightness controls
MAC: Toggle MAC layer manually for Windows/Mac key swap
```

### MAC Layer (Auto-enabled on macOS)
**Access:** Automatically enabled on macOS via OS detection, or toggle manually in ADJUST
```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │     │     │     │     │     │     │
│     │     │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │     │     │     │     │     │     │
│     │     │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │     │     │     │     │     │     │
│     │     │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ <>| │  "  │     │     │     │     │     │     │     │     │
│SWAP │SWAP │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘

Purpose: Swaps `<>|` and `"é` keys for Mac/Windows compatibility
This layer is transparent except for the two swapped keys
Automatically activates when macOS is detected
```

### RAISE Layer
**Note:** Currently not actively used but reserved for future expansion

---

## Quick Reference

### Layer Access Summary
```
┌────────────┬──────────────────────────────────────────────────┐
│ LAYER      │ ACCESS METHOD                                    │
├────────────┼──────────────────────────────────────────────────┤
│ QWERTY     │ Base layer (always active)                       │
│ LOWER      │ Hold "Lower" key (bottom row, 5th from left)    │
│ SPACE      │ Hold "Space" key (bottom row, 6th from left)    │
│ NUMPAD     │ Hold `"` key (bottom-left) OR Q+A combo         │
│ ADJUST     │ Hold LOWER + SPACE together (tri-layer)         │
│ MAC        │ Auto-enabled on macOS (or manual toggle)        │
└────────────┴──────────────────────────────────────────────────┘
```

### Combo Cheat Sheet
```
┌─────────────────────────────────────────────────────────────┐
│               ESSENTIAL KEYS (Text Editing)                 │
├────────────┬────────────────────────────────────────────────┤
│ Q + W      │ ESC        - Escape key                        │
│ O + P      │ DELETE     - Delete forward                    │
│ A + S      │ TAB        - Tab key                           │
│ L + Ş      │ BACKSPACE  - Delete backward                   │
│ X + C      │ CTRL       - Control modifier (hold)           │
│ C + V      │ GUI/CMD    - Command modifier (hold)           │
│ Q + A      │ NUMPAD     - Access numpad layer (hold both)   │
└────────────┴────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────┐
│              MOUSE BUTTONS (for Trackpad)                   │
├────────────┬────────────┬───────────────────────────────────┤
│ Left Hand  │ Right Hand │ Function                          │
├────────────┼────────────┼───────────────────────────────────┤
│ D + F      │ J + K      │ Left Click                        │
│ V + B      │ N + M      │ Right Click                       │
│ F + G      │ H + J      │ Middle Click (scroll wheel)       │
└────────────┴────────────┴───────────────────────────────────┘
```

## Turkish Character Guide

### Direct Access Characters (Base Layer)
```
┌──────┬────────────────┬─────────────┬────────────────────┐
│ Char │ Description    │ QMK Code    │ Position           │
├──────┼────────────────┼─────────────┼────────────────────┤
│  Ş   │ S with cedilla │ KC_SCLN     │ Top row, right end │
│  Ö   │ O with umlaut  │ KC_COMM     │ 3rd row, 8th key   │
│  Ç   │ C with cedilla │ KC_DOT      │ 3rd row, 9th key   │
└──────┴────────────────┴─────────────┴────────────────────┘
```

### LOWER Layer Characters
```
┌──────┬────────────────┬─────────────┬────────────────────┐
│ Char │ Description    │ QMK Code    │ Position           │
├──────┼────────────────┼─────────────┼────────────────────┤
│  İ   │ I with dot     │ KC_QUOT     │ LOWER, 2nd row 9th │
│  Ğ   │ G with breve   │ KC_LBRC     │ LOWER, 2nd row 10th│
│  Ü   │ U with umlaut  │ KC_RBRC     │ LOWER, 3rd row 9th │
└──────┴────────────────┴─────────────┴────────────────────┘
```

### Special Key Positions (Turkish Layout Specific)
```
┌───────┬─────────────────────────────────────────────────┐
│ Key   │ Description                                     │
├───────┼─────────────────────────────────────────────────┤
│ "é    │ Quote key (swaps with <> on Mac)                │
│ <>|   │ Less than/greater than (swaps with " on Mac)    │
└───────┴─────────────────────────────────────────────────┘
```

### Special Symbols via RALT (AltGr)
When using Turkish keyboard layout in macOS, these require RALT:
```
┌──────┬─────────────┬──────────────────────────────────────┐
│ Key  │ RALT + Key  │ Symbol                               │
├──────┼─────────────┼──────────────────────────────────────┤
│  Q   │ RALT + Q    │  @  (at sign)                        │
│  W   │ RALT + W    │  €  (Euro)                           │
│  2   │ RALT + 2    │  £  (Pound)                          │
│  3   │ RALT + 3    │  #  (Hash)                           │
│  4   │ RALT + 4    │  $  (Dollar)                         │
│  8   │ RALT + 8    │  {  (Left brace)                     │
│  9   │ RALT + 9    │  }  (Right brace)                    │
│  Ş   │ RALT + Ş    │  ´  (Acute accent)                   │
│  İ   │ RALT + İ    │  `  (Grave accent)                   │
└──────┴─────────────┴──────────────────────────────────────┘
```

---

## Hardware Features

### Azoteq TPS65 Trackpad
- **Model:** Azoteq IQS5XX TPS65
- **Communication:** I2C on GP18 (SDA) and GP19 (SCL)
- **DPI:** 500 (configured for precise control)
- **Auto Mouse Movement:** Enabled to prevent screen lock
- **Circular Touchpad:** Optimized for ergonomic finger movement

### Key Features
- **OS Detection:** Automatically detects macOS and enables MAC layer
- **Tap-Hold Keys:** Multiple tap-hold configurations for space efficiency
- **Combo System:** 13 combos for essential keys and mouse buttons
- **Tri-Layer:** ADJUST layer activated by holding LOWER + SPACE
- **Turkish Layout:** Full support for Turkish characters and symbols

---

## Build Instructions

### Compile Firmware
```bash
# Using QMK CLI
qmk compile -kb cost_crafter40 -km ardakilic

# Or using userspace compile
qmk userspace-compile -kb cost_crafter40 -km ardakilic
```

### Flash to Keyboard
```bash
# Enter bootloader mode (ADJUST layer -> top-left RESET key)
# Then flash
qmk flash -kb cost_crafter40 -km ardakilic
```

---

## Notes & Tips

### Usage Tips
- **First Time Setup:** The keyboard will automatically detect macOS and swap the `<>|` and `"` keys
- **Trackpad Control:** DPI is set to 500 for comfortable cursor movement
- **Screen Lock Prevention:** Auto mouse movement feature prevents screen lock
- **Combos:** Practice the essential combos (Q+W for ESC, A+S for TAB) - they become second nature quickly
- **NUMPAD Access:** Two ways to access - either hold `"` key or use Q+A combo

### Customization
- All layers are fully customizable in `keymap.c`
- Combo timing can be adjusted in `config.h` (COMBO_TERM)
- Tap-hold timing can be adjusted in `config.h` (TAPPING_TERM)
- Trackpad DPI can be changed in the keyboard config

### Troubleshooting
- **Wrong characters:** Make sure macOS keyboard is set to "Turkish Q"
- **Combos not working:** Check COMBO_TERM in config.h - increase if needed
- **Tap-hold issues:** Adjust TAPPING_TERM in config.h
- **Mac key swap not working:** Toggle MAC layer manually in ADJUST layer

