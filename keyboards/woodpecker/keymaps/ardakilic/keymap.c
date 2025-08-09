/* Copyright 2022 Arda Kilicdagi
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

enum woodpecker_layers {
  _QWERTY = 0,
  _LOWER,
  // _RAISE,
  _NUMPAD,
  _ADJUST,
  // _SPACE,
  // _SODA,
  _MAC
};

// KC_NONUS_BACKSLASH (\|) is equivalent to [<>|] key in Turkish Windows keyboards.
// KC_GRV (~ `) is equivalent to ["é] key in Turkish Windows keyboards.
// KC_SCLN is Turkish s [şŞ] key
// KC_QUOT is Turkish i [iİ] key
// KC_COMM is Turkish o [öÖ] key
// KC_DOT is Turkish c [çÇ] key

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
#define LOCKSCREEN LCTL(LSFT(KC_PWR)) // Screen Lock shortcut for OSX

enum custom_keycodes {
    MOUSE_INFINITE_TOGGLE = SAFE_RANGE
};

/*
// Unicode Turkish characters, in case it's needed
enum {
    TR_C, // ç
    TR_C_L, // Ç
    TR_I, // ı
    TR_I_L, // İ
    TR_G, // ğ
    TR_G_L, // Ğ
    TR_S, // ş
    TR_S_L, // Ş
    TR_U, // ü
    TR_U_L, // Ü
    TR_O, // ö
    TR_O_L, // Ö
};

// clang-format off
const uint32_t PROGMEM unicode_map[] = {
    [TR_C] = 0x00c7,
    [TR_C_L] = 0x00e7,
    [TR_I] = 0x0130,
    [TR_I_L] = 0x0131,
    [TR_G] = 0x011e,
    [TR_G_L] = 0x011f,
    [TR_S] = 0x015e,
    [TR_S_L] = 0x015f,
    [TR_U] = 0x00dc,
    [TR_U_L] = 0x00fc,
    [TR_O] = 0x00d6,
    [TR_O_L] = 0x00f6,
};
// clang-format on
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------. ,-----------------------------------------.
 * |  "   |  1   |  2   |  3   |  4   |  5   | |  6   |  7   |  8   |  9   |  0   | BkSp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  E   |  R   |  T   | |  Y   |  U   |  I   |  O   |  P   | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |NpdEsc|  A   |  S   |  D [mbb] F [lmb] G | | H [lmb] J [mbb] K. |  L   |  Ş   |  İ   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | LSFT |  Z   |  X   |  C   |  V [rmb] B  | | N [rmb] M   |  Ö   |  Ç   |  .   |SftEnt|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl |Adj|<>| Win  | Alt  |Lowr|,|Space | | Ent  | AltGR| Left | Down |  Up  | Rght |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_QWERTY] = LAYOUT_woodpecker_grid(
    KC_GRV,KC_1,KC_2,KC_3,KC_4,KC_5,                    /*|*/   KC_6,KC_7,KC_8,KC_9,KC_0,KC_BSPC,
    KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,                    /*|*/   KC_Y,KC_U,KC_I,KC_O,KC_P,KC_DEL,
    LT(_NUMPAD, KC_ESC),KC_A,KC_S,KC_D,KC_F,KC_G,       /*|*/   KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,
    KC_LSFT,KC_Z,KC_X,KC_C,KC_V,KC_B,           /*|*/   KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,SC_SENT,
    KC_LCTL,LT(_ADJUST,KC_NONUS_BACKSLASH),KC_LGUI,KC_LALT,LT(_LOWER,KC_BSLS),KC_SPC, /*|*/ KC_ENT,KC_RALT,KC_LEFT,KC_DOWN,KC_UP,KC_RGHT
),


/* Lower
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  | |      |      |  "\" |  "|" |  *   |  -   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  | F10  | |      |   #  |   "  |  "¨" | "~"  |  "=" |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      | |  *   |   ?  |  "`" |  Ğ   |  Ü   |  _   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      | "$"  |  "{" |  "}" |  <   |  ">" |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |==XX==| Entr | | BkSp |      |  "[" |  "]" |  '   |  "   |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_LOWER] = LAYOUT_woodpecker_grid(
    _______,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,              /*|*/   _______,_______,BACKSLASH,VERTICAL_PIPE,KC_MINS,KC_EQL,
    _______,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,             /*|*/   _______,HASHTAG,KC_GRV,RALT(KC_LBRC),RALT(KC_RBRC),LSFT(KC_0),
    _______,KC_F11,KC_F12,_______,_______,_______,      /*|*/   KC_MINS,KC_UNDS,BACKTICK,KC_LBRC,KC_RBRC,KC_PLUS,
    _______,_______,_______,_______,_______,_______,    /*|*/   _______,DOLLAR_SIGN,CURLY_OPEN,CURLY_CLOSE,KC_NONUS_BACKSLASH, RALT(KC_1),
    _______,_______,_______,_______,_______,KC_ENT,     /*|*/   KC_BSPC,_______,SQUARE_OPEN,SQUARE_CLOSE,LSFT(KC_2),KC_GRV
),

/* Numpad & Mouse
 * KC_PDOT is comma on the Turkish layout ¯\_(ツ)_/¯
 * ,-----------------------------------------. ,-----------------------------------------.
 * | ACL0 | ACL1 | ACL2 |M-clic|      |      | |      | NLCK |   /  |   *  |   -  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |L-clck|  Up  |R-clck|Scrl U| |      |   7  |   8  |   9  |   +  |  =   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |==XX==|      | Left | Down |Right |Scrl D| |      |   4  |   5  |   6  |   +  |  ,   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      | VOLU |      | PREV |PAUSE | NEXT | |      |   1  |   2  |   3  |Enter |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      | VOLD |      | MUTE | Bksp | Del  | |Enter |Space |   0  |   .  |Enter |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_NUMPAD] = LAYOUT_woodpecker_grid(
    KC_ACL0,KC_ACL1,KC_ACL2,KC_BTN3,_______,_______,    /*|*/   _______,KC_NUM,KC_PSLS,KC_PAST,KC_PMNS,KC_BSPC,
    _______,_______,KC_BTN1,KC_MS_U,KC_BTN2,KC_WH_U,    /*|*/   _______,KC_P7,KC_P8,KC_P9,KC_PPLS,KC_PEQL,
    _______,_______,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_D,    /*|*/   _______,KC_P4,KC_P5,KC_P6,KC_PPLS,KC_PDOT,
    _______,KC_VOLU,_______,KC_MPRV,KC_MPLY,KC_MNXT,    /*|*/   _______,KC_P1,KC_P2,KC_P3,KC_PENT,_______,
    _______,KC_VOLD,_______,KC_MUTE,KC_BSPC,KC_DEL,     /*|*/   KC_PENT,KC_SPC,KC_P0,KC_SLSH,KC_PENT,_______
),

/* Adjust
 * ,-----------------------------------------. ,-----------------------------------------.
 * |EepRST|BotLdr| Debug|Reboot|      |      | | macOS|      |MsInfTg|     |      |LckOSX|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |CpsLck|      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |==XX==|      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_ADJUST] = LAYOUT_woodpecker_grid(
    EE_CLR,QK_BOOT,DB_TOGG, QK_RBT,_______,_______,     /*|*/   TG(_MAC),_______,MOUSE_INFINITE_TOGGLE,_______,_______,LOCKSCREEN,
    _______,_______,_______,_______,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______,
    KC_CAPS,_______,_______,_______,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______
),

/* MAC
 * This layout toggles Win/CMD and Left Alt keys's positions for Win and Mac compatibility
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |==XX==|      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      | Alt  | CMD  |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_MAC] = LAYOUT_woodpecker_grid(
    _______,_______,_______,_______,_______,_______,     /*|*/   _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,                /*|*/   _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,                /*|*/   _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,                /*|*/   _______,_______,_______,_______,_______,_______,
    _______,_______,KC_LALT,KC_LGUI,_______,_______,                /*|*/   _______,_______,_______,_______,_______,_______
)


};

#ifdef POINTING_DEVICE_DRIVER
// DPI setting
void keyboard_post_init_user(void) {
    pointing_device_set_cpi(500);
}
#endif

// Combo keys
// Can be used with modifier and layer toggle keys
// https://github.com/qmk/qmk_firmware/pull/8591#issuecomment-976019486
enum combos {
  C_LEFT_MOUSE_BTN_1,
  C_LEFT_MOUSE_BTN_2,
  C_RIGHT_MOUSE_BTN_1,
  C_RIGHT_MOUSE_BTN_2,
  C_MIDDLE_MOUSE_BTN_1,
  C_MIDDLE_MOUSE_BTN_2,
};

const uint16_t PROGMEM c_left_mouse_btn_1_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM c_left_mouse_btn_2_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM c_right_mouse_btn_1_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM c_right_mouse_btn_2_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM c_middle_mouse_btn_1_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM c_middle_mouse_btn_2_combo[] = {KC_J, KC_K, COMBO_END};

const uint16_t PROGMEM c_left_layer_enter_combo[] = {KC_F, KC_G, COMBO_END};
combo_t key_combos[] = {
    [C_LEFT_MOUSE_BTN_1] = COMBO(c_left_mouse_btn_1_combo, KC_BTN1),
    [C_LEFT_MOUSE_BTN_2] = COMBO(c_left_mouse_btn_2_combo, KC_BTN1),
    [C_RIGHT_MOUSE_BTN_1] = COMBO(c_right_mouse_btn_1_combo, KC_BTN2),
    [C_RIGHT_MOUSE_BTN_2] = COMBO(c_right_mouse_btn_2_combo, KC_BTN2),
    [C_MIDDLE_MOUSE_BTN_1] = COMBO(c_middle_mouse_btn_1_combo, KC_BTN3),
    [C_MIDDLE_MOUSE_BTN_2] = COMBO(c_middle_mouse_btn_2_combo, KC_BTN3),
};
// END Combo keys

// Auto Moving Mouse
bool moving_mouse = false;
uint16_t last_mouse_move = 0;
void toggle_infinite_mouse_movement(void) {
    moving_mouse = !moving_mouse;
}
void matrix_scan_user(void) {
    if (moving_mouse && timer_elapsed(last_mouse_move) > 5000) {
        tap_code(KC_MS_L);  // Move 1px left
        wait_ms(10);
        tap_code(KC_MS_R);  // Move 1px right
        last_mouse_move = timer_read();  // Reset timer
    }
}
// END Auto Moving Mouse


// Fix Windows and MacOS inconsistency between lower than and greater than keys on Turkish layout
// Grave and Non US Backslash keys are swapped on Turkish layout on Windows and MacOS
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
  }
  return true; // Process all other keycodes normally
}


// OS Detection
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
