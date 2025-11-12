/* Copyright 2025 Arda Kilicdagi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum cost_crafter40_layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMPAD,
  _SPACE,
  _MAC
};

// KC_NONUS_BACKSLASH (\|) is equivalent to [<>|] key in Turkish keyboards.
// KC_GRV (~ `) is equivalent to ["é] key in Turkish keyboards.
// KC_SCLN is Turkish s [şŞ] key
// KC_QUOT is Turkish i [iİ] key
// KC_COMM is Turkish o [öÖ] key
// KC_DOT is Turkish c [çÇ] key
// KC_LBRC is Turkish g [ğĞ] key
// KC_RBRC is Turkish u [üÜ] key

// Custom shortcuts specific to Turkish layout
#define CURLY_OPEN RALT(KC_7)
#define CURLY_CLOSE RALT(KC_0)
#define SQUARE_OPEN RALT(KC_8)
#define SQUARE_CLOSE RALT(KC_9)
#define DOLLAR_SIGN RALT(KC_4)
#define BACKSLASH RALT(KC_MINS)
#define VERTICAL_PIPE RALT(KC_EQL)
#define BACKTICK RALT(KC_BSLS)
#define TILDE RALT(KC_RBRC)
#define HASHTAG RALT(KC_3)
#define LESS_THAN KC_NONUS_BACKSLASH
#define GREATER_THAN RALT(KC_1)
#define LOCKSCREEN LCTL(LSFT(KC_PWR)) // Screen Lock shortcut for OSX

enum custom_keycodes {
    MOUSE_INFINITE_TOGGLE = SAFE_RANGE,
    MO_NUMPAD
};

// Combo keys for missing keys
enum combos {
  C_ESC,
  C_DEL,
  C_TAB,
  C_BSPC,
  C_CTRL,
  C_GUI,
  C_NUMPAD_LAYER,
  C_LEFT_MOUSE_BTN_1,
  C_LEFT_MOUSE_BTN_2,
  C_RIGHT_MOUSE_BTN_1,
  C_RIGHT_MOUSE_BTN_2,
  C_MIDDLE_MOUSE_BTN_1,
  C_MIDDLE_MOUSE_BTN_2
};

const uint16_t PROGMEM c_esc_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM c_del_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM c_tab_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM c_bspc_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM c_ctrl_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM c_gui_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM c_numpad_layer_combo[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM c_left_mouse_btn_1_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM c_left_mouse_btn_2_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM c_right_mouse_btn_1_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM c_right_mouse_btn_2_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM c_middle_mouse_btn_1_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM c_middle_mouse_btn_2_combo[] = {KC_H, KC_J, COMBO_END};

combo_t key_combos[] = {
    [C_ESC] = COMBO(c_esc_combo, KC_ESC),
    [C_DEL] = COMBO(c_del_combo, KC_DEL),
    [C_TAB] = COMBO(c_tab_combo, KC_TAB),
    [C_BSPC] = COMBO(c_bspc_combo, KC_BSPC),
    [C_CTRL] = COMBO(c_ctrl_combo, KC_LCTL),
    [C_GUI] = COMBO(c_gui_combo, KC_LGUI),
    [C_NUMPAD_LAYER] = COMBO(c_numpad_layer_combo, MO_NUMPAD),
    [C_LEFT_MOUSE_BTN_1] = COMBO(c_left_mouse_btn_1_combo, X_MS_BTN1),
    [C_LEFT_MOUSE_BTN_2] = COMBO(c_left_mouse_btn_2_combo, X_MS_BTN1),
    [C_RIGHT_MOUSE_BTN_1] = COMBO(c_right_mouse_btn_1_combo, X_MS_BTN2),
    [C_RIGHT_MOUSE_BTN_2] = COMBO(c_right_mouse_btn_2_combo, X_MS_BTN2),
    [C_MIDDLE_MOUSE_BTN_1] = COMBO(c_middle_mouse_btn_1_combo, X_MS_BTN3),
    [C_MIDDLE_MOUSE_BTN_2] = COMBO(c_middle_mouse_btn_2_combo, X_MS_BTN3),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │ A │ S │ D │ F │ G │ H │ J │ K │ L │ Ş │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │Z/⇧│ X │ C │ V │ B │ N │ M │ Ö │ Ç │./⇧│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │"/N│<>/│Alt│Cmd│Lwr│Spc│ ← │ ↓ │ ↑ │ → │
 * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
 *
 * Combos: Q+W=ESC, O+P=DEL, A+S=TAB, L+Ş=BSPC, X+C=CTRL, C+V=GUI, Q+A=NUMPAD(hold)
 * Mouse: D+F=LMB, J+K=LMB, V+B=RMB, N+M=RMB, F+G=MMB, H+J=MMB
 * Layer Taps: "=Numpad (hold), Space=SPACE layer (hold), <>|=Ctrl (hold)
 */
[_QWERTY] = LAYOUT(
    KC_Q,               KC_W,    KC_E,    KC_R,     KC_T,            KC_Y,                   KC_U,     KC_I,    KC_O,    KC_P,
    KC_A,               KC_S,    KC_D,    KC_F,     KC_G,            KC_H,                   KC_J,     KC_K,    KC_L,    KC_SCLN,
    LSFT_T(KC_Z),       KC_X,    KC_C,    KC_V,     KC_B,            KC_N,                   KC_M,     KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),
    LT(_NUMPAD, KC_GRV), LCTL_T(KC_NONUS_BACKSLASH), KC_LALT, KC_LGUI, MO(_LOWER), LT(_SPACE, KC_SPC), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* LOWER (Function Keys & Symbols)
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │F1 │F2 │F3 │F4 │F5 │F6 │ \ │ | │ - │ = │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │F7 │F8 │F9 │F10│F11│F12│ # │ ` │ İ │ Ğ │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │ * │ ? │ @ │ $ │ { │ } │ Ü │ _ │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │ % │ ! │ & │   │ ^ │ ~ │ ( │ ) │ + │
 * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
 */
[_LOWER] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,        BACKSLASH,    VERTICAL_PIPE, KC_MINS,       KC_EQL,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,       HASHTAG,      BACKTICK,      KC_QUOT,       KC_LBRC,
    _______, _______, KC_ASTR, KC_QUES, KC_AT,   DOLLAR_SIGN,  CURLY_OPEN,   CURLY_CLOSE,   KC_RBRC,       KC_UNDS,
    _______, KC_PERC, KC_EXLM, KC_AMPR, _______, KC_CIRC,      TILDE,        KC_LPRN,       KC_RPRN,       KC_PLUS
),

/* RAISE (Numbers & Symbols)
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │   │   │   │ * │ - │ \ │ | │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │   │   │   │ # │ " │ ~ │ ` │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │   │   │   │   │ < │ [ │ ] │
 * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
 */
[_RAISE] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,           KC_9,           KC_0,
    _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,         BACKSLASH,      VERTICAL_PIPE,
    _______, _______, _______, _______, _______, _______, HASHTAG, KC_GRV,         TILDE,          BACKTICK,
    _______, _______, _______, _______, _______, _______, _______, LESS_THAN,      SQUARE_OPEN,    SQUARE_CLOSE
),

/* ADJUST (System & Settings)
 * Accessed via LOWER + RAISE (layer combination)
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │RST│   │   │   │   │   │   │   │   │LCK│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │CAP│   │   │   │   │   │   │   │   │   │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │   │   │PRV│PLY│NXT│VL-│VL+│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │MAC│   │ENT│BR-│   │ ↑ │BR+│
 * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
 */
[_ADJUST] = LAYOUT(
    QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, LOCKSCREEN,
    KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU,
    _______, _______, _______, TG(_MAC), _______, KC_ENT, KC_BRMD, _______, KC_UP,   KC_BRMU
),

/* NUMPAD
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │   │   │   │   │NUM│ / │ 7 │ 8 │ 9 │ - │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │   │   │ * │ 4 │ 5 │ 6 │ + │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │   │   │ = │ 1 │ 2 │ 3 │Ent│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │   │BSP│ , │ 0 │ 0 │ . │Ent│
 * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
 */
[_NUMPAD] = LAYOUT(
    _______, _______, _______, _______, KC_NUM,  KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
    _______, _______, _______, _______, _______, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
    _______, _______, _______, _______, _______, KC_PEQL, KC_P1,   KC_P2,   KC_P3,   KC_PENT,
    _______, _______, _______, _______, KC_BSPC, KC_PDOT, KC_P0,   KC_P0,   KC_SLSH, KC_PENT
),

/* SPACE (CMD+Number shortcuts & Navigation)
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │⌘1 │⌘2 │⌘3 │⌘4 │⌘5 │⌘6 │⌘7 │⌘8 │⌘9 │⌘0 │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │   │   │   │   │   │ ↑ │   │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │   │   │   │   │ ← │ ↓ │ → │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │   │   │   │   │BR-│ ↑ │BR+│
 * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
 */
[_SPACE] = LAYOUT(
    LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0),
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_UP,      _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_BRMD,    KC_UP,      KC_BRMU
),

/* MAC (Key Position Swap for Mac Compatibility)
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │   │   │   │   │   │   │   │   │   │   │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │   │   │   │   │   │   │   │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │   │   │   │   │   │   │   │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │<>|│ " │   │   │   │   │   │   │   │   │
 * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
 */
[_MAC] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_NONUS_BACKSLASH, KC_GRV, _______, _______, _______, _______, _______, _______, _______, _______
)
};

#ifdef POINTING_DEVICE_DRIVER
// DPI setting for trackpad
void keyboard_post_init_user(void) {
    pointing_device_set_cpi(500);
}
#endif

// Layer state handling for ADJUST layer (activated when LOWER + RAISE are both active)
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _SPACE, _ADJUST);
}

// Auto Moving Mouse to prevent screen lock
bool moving_mouse = false;
uint16_t last_mouse_move = 0;
void toggle_infinite_mouse_movement(void) {
    moving_mouse = !moving_mouse;
}
void matrix_scan_user(void) {
    if (moving_mouse && timer_elapsed(last_mouse_move) > 5000) {
        tap_code(KC_MS_WH_LEFT);  // Move 1px left
        wait_ms(10);
        tap_code(KC_MS_WH_RIGHT);  // Move 1px right
        last_mouse_move = timer_read();  // Reset timer
    }
}

// Fix Windows and MacOS inconsistency between lower than and greater than keys on Turkish layout
// Grave and Non US Backslash keys are swapped on Turkish layout on Windows and MacOS
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Handle MO_NUMPAD custom keycode
  if (keycode == MO_NUMPAD) {
    if (record->event.pressed) {
      layer_on(_NUMPAD);
    } else {
      layer_off(_NUMPAD);
    }
    return false;
  }
  
  if(IS_LAYER_ON(_MAC)) {
    switch (keycode) {
      case KC_NONUS_BACKSLASH:
        if (record->event.pressed) {
            register_code(KC_GRV);
        } else {
            unregister_code(KC_GRV);
        }
        return false; // Skip all further processing of this key
      case KC_GRV:
        if (record->event.pressed) {
            register_code(KC_NONUS_BACKSLASH);
        } else {
            unregister_code(KC_NONUS_BACKSLASH);
        }
        return false; // Skip all further processing of this key
      case MOUSE_INFINITE_TOGGLE:
        if (record->event.pressed) {
            toggle_infinite_mouse_movement();
        }
        return false;  // Skip further processing for this key
      default:
        return true; // Process all other keycodes normally
    }
  } else {
    // When not on MAC layer, still handle MOUSE_INFINITE_TOGGLE
    if (keycode == MOUSE_INFINITE_TOGGLE && record->event.pressed) {
        toggle_infinite_mouse_movement();
        return false;
    }
  }
  return true; // Process all other keycodes normally
}

// OS Detection - Automatically enable MAC layer on macOS
bool process_detected_host_os_user(os_variant_t detected_os) {
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            if (!IS_LAYER_ON(_MAC)) {
                layer_on(_MAC);
            }
            break;
        case OS_WINDOWS:
        case OS_LINUX:
            if (IS_LAYER_ON(_MAC)) {
                layer_off(_MAC);
            }
            break;
        case OS_UNSURE:
            if (IS_LAYER_ON(_MAC)) {
                layer_off(_MAC);
            }
            break;
    }
    return true;
}

