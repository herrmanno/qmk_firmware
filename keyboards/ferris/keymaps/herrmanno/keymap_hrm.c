#include QMK_KEYBOARD_H

enum ferris_layers {
  _BASE,
  _NUM,
  _SYM,
  _SPECIAL,
  _NAV,
};

// BASE LAYER HOMEROW MODS (LEFT HAND)
#define KC_SHL0 LSFT_T(KC_A)
#define KC_ALL0 LALT_T(KC_R)
#define KC_CTL0 LCTL_T(KC_S)
#define KC_GUL0 GUI_T(KC_T)
// BASE LAYER HOMEROW MODS (RIGHT HAND)
#define KC_GUR0 GUI_T(KC_N)
#define KC_CTR0 RCTL_T(KC_E)
#define KC_ALR0 RALT_T(KC_I)
#define KC_SHR0 RSFT_T(KC_O)

// NUM LAYER HOMEROW MODS (LEFT HAND)
#define KC_SHL1 LSFT_T(KC_ESC)
// NUM LAYER HOMEROW MODS (RIGHT HAND)
#define KC_GUR1 GUI_T(KC_DOWN)
#define KC_CTR1 RCTL_T(KC_UP)
#define KC_ALR1 RALT_T(KC_RIGHT)
#define KC_SHR1 RSFT_T(KC_QUOT)

// SYM LAYER HOMEROW MODS (LEFT HAND)
#define KC_SHL2 LSFT_T(KC_TAB)
// SYM LAYER HOMEROW MODS (RIGHT HAND)
#define KC_GUR2 GUI_T(KC_EQL)
#define KC_CTR2 RCTL_T(KC_LBRC)
#define KC_ALR2 RALT_T(KC_RBRC)
#define KC_SHR2 RSFT_T(KC_BSLS)

#define KC_SPM1 LT(1, KC_SPC)
#define KC_BSM2 LT(2, KC_BSPC)

enum unicode_names {
    uUML,
    UUML
};

const uint32_t unicode_map[] PROGMEM = {
    [uUML] = 252,  // u Umlaut
    [UUML] = 220,  // U Umlaut
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,            KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    KC_SHL0, KC_ALL0, KC_CTL0, KC_GUL0, KC_G,            KC_M,    KC_GUR0, KC_CTR0, KC_ALR0, KC_SHR0,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,            KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                                    MO(3), KC_SPM1, KC_BSM2, MO(4)
  ),

  [_NUM] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_SHL1, KC_TRNS, KC_TRNS, KC_TRNS, KC_GRV,          KC_LEFT, KC_GUR1, KC_CTR1, KC_ALR1, KC_SHR1,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,         KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_ENT,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_SYM] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_SHL2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_MINS, KC_GUR2, KC_CTR2, KC_ALR2, KC_SHR2,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_UNDS, KC_PLUS, KC_TRNS, KC_TRNS, KC_ENT,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_SPECIAL] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, XP(uUML, UUML), KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_NAV] = LAYOUT(
    KC_BRID, KC_BRIU, KC_MPLY, KC_MPRV, KC_MNXT,         KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};

enum combos {
  LBOOT_COMBO,
  RBOOT_COMBO,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM lboot_combo[] = {KC_Q, KC_W, KC_F, KC_P, KC_B, COMBO_END};
const uint16_t PROGMEM rboot_combo[] = {KC_J, KC_L, KC_U, KC_Y, KC_SCLN, COMBO_END};

combo_t key_combos[] = {
  [LBOOT_COMBO] = COMBO(lboot_combo, QK_BOOT),
  [RBOOT_COMBO] = COMBO(rboot_combo, QK_BOOT),
};
