#include QMK_KEYBOARD_H

enum ferris_layers {
  _BASE,
  _NUM,
  _SYM,
  _NAV,
};

enum custom_keycodes {
    DELWORD = SAFE_RANGE, // Delete last word via S-Opt-Left Del combo
    // German umlaute
    A_UMLT,
    O_UMLT,
    U_UMLT,
    SS_UMLT,
    TMUX,
};

// One shot modifiers used on all upper layers
#define M_GUI OSM(MOD_LGUI)
#define M_SHFT OSM(MOD_LSFT)
#define M_ALT OSM(MOD_LALT)
#define M_CTRL OSM(MOD_LCTL)

// Mod tap shift keys used on base layer
#define T_SFT_Z LSFT_T(KC_Z)
#define T_SFT_SLH LSFT_T(KC_SLSH)
#define T_CTL_BSPC LCTL_T(KC_BSPC)

//*********************************************************
//          KEYMAP
//*********************************************************

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,            KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,            KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
    T_SFT_Z, KC_X,    KC_C,    KC_D,    KC_V,            KC_K,    KC_H,    KC_COMM, KC_DOT,  T_SFT_SLH,
                                      MO(1), KC_SPC, T_CTL_BSPC, MO(2)
  ),

  [_NUM] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    M_SHFT,  M_ALT,   M_CTRL,  M_GUI,   KC_GRV,          KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_ESC,
    KC_LSFT, A_UMLT,  U_UMLT,  O_UMLT,  SS_UMLT,         KC_TRNS, KC_ENT,  KC_TAB,  KC_DEL,  KC_LSFT,
                                    KC_TRNS, KC_TRNS, DELWORD, MO(3)
  ),

  [_SYM] = LAYOUT(
    KC_EXLM, KC_QUES, KC_LPRN, KC_RPRN, KC_ASTR,         KC_TRNS, A_UMLT,  U_UMLT,  O_UMLT,  SS_UMLT,
    M_SHFT,  M_ALT,   M_CTRL,  M_GUI,   KC_BSLS,         KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_SCLN,
    KC_LSFT, KC_TRNS, KC_TRNS, TMUX,    KC_TRNS,         KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_LSFT,
                                    MO(3), KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_NAV] = LAYOUT(
    KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,         QK_BOOT, KC_F9,   KC_F10,  KC_F11,  KC_F12,
    M_SHFT,  M_ALT,   M_CTRL,  M_GUI,   KC_VOLU,         KC_BRIU, KC_F5,   KC_F6,   KC_F7,   KC_F8,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD,         KC_BRID, KC_F1,   KC_F2,   KC_F3,   KC_F4,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};

//*********************************************************
//          COMBOS
//*********************************************************

enum combos {
  // Use combo for setting controller into boot mode (as I stuggled to solder the reset buttons properly)
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

//*********************************************************
//          CUSTOM KEYS HANDLING
//*********************************************************

// Handle custom Umlaut keys
void process_umlaut(keyrecord_t *record, uint16_t keycode) {
    if (record->event.pressed) {
        uint8_t mods = get_mods();
        uint8_t oneshot_mods = get_oneshot_mods();

        clear_mods();
        clear_oneshot_mods();

        register_code(KC_LALT);
        tap_code(KC_U);
        unregister_code(KC_LALT);

        if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
            register_code(KC_LSFT);
            tap_code(keycode);
            unregister_code(KC_LSFT);
        } else {
            tap_code(keycode);
        }

        set_mods(mods);
        set_oneshot_mods(oneshot_mods);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case DELWORD:
        if (record->event.pressed) {
            register_code(KC_LSFT);
            register_code(KC_LALT);
            tap_code(KC_LEFT);
            unregister_code(KC_LSFT);
            unregister_code(KC_LALT);
            tap_code(KC_DEL);
        }
        break;
    case A_UMLT:
        process_umlaut(record, KC_A); 
        break;
    case O_UMLT:
        process_umlaut(record, KC_O); 
        break;
    case U_UMLT:
        process_umlaut(record, KC_U); 
        break;
    case SS_UMLT:
        if (record->event.pressed) {
            uint8_t mods = get_mods();
            uint8_t oneshot_mods = get_oneshot_mods();

            clear_mods();
            clear_oneshot_mods();

            register_code(KC_LALT);
            tap_code(KC_S);
            unregister_code(KC_LALT);

            set_mods(mods);
            set_oneshot_mods(oneshot_mods);
        }
        break;
    case TMUX:
        if (record->event.pressed) {
            uint8_t mods = get_mods();
            uint8_t oneshot_mods = get_oneshot_mods();

            clear_mods();
            clear_oneshot_mods();

            register_code(KC_LCTL);
            tap_code(KC_A);
            unregister_code(KC_LCTL);

            set_mods(mods);
            set_oneshot_mods(oneshot_mods);
        }
        break;
    }
    return true;
};

//*********************************************************
//          CUSTOM TAPPING TERM
//*********************************************************

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case M_GUI: 
    case M_CTRL: 
    case M_ALT: 
    case M_SHFT: 
        return ONESHOT_TAPPING_TERM;
    default:
        return TAPPING_TERM;
    }
}

