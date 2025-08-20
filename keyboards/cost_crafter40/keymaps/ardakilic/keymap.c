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
  _NUMPAD
};

// KC_NONUS_BACKSLASH (\|) is equivalent to [<>|] key in Turkish keyboards.
// KC_GRV (~ `) is equivalent to ["é] key in Turkish keyboards.
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
#define LESS_THAN KC_NONUS_BACKSLASH
#define GREATER_THAN RALT(KC_1)
#define LOCKSCREEN LCTL(LSFT(KC_PWR)) // Screen Lock shortcut for OSX

// Combo keys for missing keys
enum combos {
  C_ESC,
  C_DEL,
  C_TAB,
  C_ENTER,
  C_CTRL,
  C_ALT,
  C_RAISE,
  C_ADJUST,
  C_NUMPAD
};

const uint16_t PROGMEM c_esc_combo[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM c_del_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM c_tab_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM c_enter_combo[] = {KC_SCLN, KC_SLSH, COMBO_END};
const uint16_t PROGMEM c_ctrl_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM c_alt_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM c_raise_combo[] = {KC_LGUI, KC_SPC, COMBO_END};
const uint16_t PROGMEM c_adjust_combo[] = {KC_LGUI, KC_ENT, COMBO_END};
const uint16_t PROGMEM c_numpad_combo[] = {KC_A, KC_Z, COMBO_END};

combo_t key_combos[] = {
    [C_ESC] = COMBO(c_esc_combo, KC_ESC),
    [C_DEL] = COMBO(c_del_combo, KC_DEL),
    [C_TAB] = COMBO(c_tab_combo, KC_TAB),
    [C_ENTER] = COMBO(c_enter_combo, KC_ENT),
    [C_CTRL] = COMBO(c_ctrl_combo, KC_LCTL),
    [C_ALT] = COMBO(c_alt_combo, KC_LALT),
    [C_RAISE] = COMBO(c_raise_combo, MO(_RAISE)),
    [C_ADJUST] = COMBO(c_adjust_combo, MO(_ADJUST)),
    [C_NUMPAD] = COMBO(c_numpad_combo, MO(_NUMPAD)),
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
 * │ALT│CTL│CMD│LWR│SPC│ENT│ ← │ ↓ │ ↑ │ → │
 * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
 *
 * Combos: Q+A=ESC, O+P=DEL, Q+W=TAB, Ş+./⇧=ENT, X+C=CTRL, C+V=ALT, CMD+SPC=RAISE, CMD+ENT=ADJUST, A+Z=NUMPAD
 */
[_QWERTY] = LAYOUT(
    KC_Q,          KC_W,    KC_E,    KC_R,               KC_T,            KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,
    KC_A,          KC_S,    KC_D,    KC_F,               KC_G,            KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN,
    LSFT_T(KC_Z),  KC_X,    KC_C,    KC_V,               KC_B,            KC_N,    KC_M,     KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),
    KC_LALT,       LCTL_T(KC_GRV), KC_LGUI, MO(_LOWER), LT(_RAISE, KC_SPC), KC_ENT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* LOWER (Function Keys & Symbols)
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │F1 │F2 │F3 │F4 │F5 │ \ │ | │ - │ = │ _ │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │F6 │F7 │F8 │F9 │F10│ # │ ` │ İ │ Ğ │ Ü │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │F11│F12│ * │ ? │ @ │ $ │ { │ } │ < │ > │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │ % │ ! │ & │   │ ^ │ ( │ ) │ [ │ ] │ ~ │
 * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
 */
[_LOWER] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   BACKSLASH,    VERTICAL_PIPE, KC_MINS,       KC_EQL,        KC_UNDS,
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  HASHTAG,      BACKTICK,      KC_QUOT,       KC_LBRC,       KC_RBRC,
    KC_F11,  KC_F12,  KC_ASTR, KC_QUES, KC_AT,   DOLLAR_SIGN,  CURLY_OPEN,    CURLY_CLOSE,   LESS_THAN,     GREATER_THAN,
    KC_PERC, KC_EXLM, KC_AMPR, _______, KC_CIRC, KC_LPRN,      KC_RPRN,       SQUARE_OPEN,   SQUARE_CLOSE,  TILDE
),

/* RAISE (Numbers & Symbols)
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │   │   │   │   │ ` │ ~ │ + │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │   │   │   │   │ [ │ ] │ | │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │   │   │   │   │   │   │ _ │
 * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
 */
[_RAISE] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,           KC_9,           KC_0,
    _______, _______, _______, _______, _______, _______, _______, BACKTICK,       TILDE,          KC_PLUS,
    _______, _______, _______, _______, _______, _______, _______, SQUARE_OPEN,    SQUARE_CLOSE,   VERTICAL_PIPE,
    _______, _______, _______, _______, _______, _______, _______, _______,        _______,        KC_UNDS
),

/* ADJUST (System & Settings)
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │RST│   │   │   │   │   │   │   │   │LCK│
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │   │   │   │VL-│VL+│   │   │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │CAP│   │   │   │   │PRV│PLY│NXT│   │   │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │   │   │   │   │   │   │   │
 * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
 */
[_ADJUST] = LAYOUT(
    QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, LOCKSCREEN,
    _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______, _______,
    KC_CAPS, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
    _______, _______, _______, _______, KC_BSPC, KC_PDOT, KC_P0,   KC_P0,   KC_PDOT, KC_PENT
)
};

