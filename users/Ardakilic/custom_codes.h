/*
 * Custom keycodes for QMK
 * These keycodes are mostly for Turkish layout
 */

// KC_NONUS_BACKSLASH (\|) is equivalent to ["é] key in Turkish keyboards.
// KC_GRV (~ `) is equivalent to [<>|] key in Turkish keyboards.
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
#define LOCKSCREEN LCTL(LSFT(KC_SYSTEM_POWER)) // Screen Lock shortcut for OSX

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
