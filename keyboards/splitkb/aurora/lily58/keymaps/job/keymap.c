#include "keycodes.h"
#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

// Modifiers
#define SG_S LSG(KC_S)
#define LG_PSCR LGUI(KC_PSCR)

#define CA_F1 LCA(KC_F1)
#define CA_F2 LCA(KC_F2)
#define CA_F11 LCA(KC_F11)
#define CA_F12 LCA(KC_F12)

// Mod-Tap
#define MT_LSFT LSFT_T(KC_SPC)

// One Shot Keys
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)

enum custom_keycodes {
    KC_LARR = SAFE_RANGE,
    KC_RARR,
    KC_HPTH,
    KC_CPTH,
};

enum layers {
    BASE,
    LOWER,
    HIGHER,
    ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [BASE] = LAYOUT(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     /*          |          */  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MUTE,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     /*          |          */  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_MINS,
        KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     /*          |          */  KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
        OS_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_LBRC,  /*|*/  KC_RBRC,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  OS_RSFT,
        /*                        */  KC_LALT,  KC_LGUI,  MO(1),    MT_LSFT,  /*|*/  KC_ENT,   MO(2),    KC_BSPC,  KC_RALT
    ),
    [LOWER] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,  /*          |          */  _______,  _______,  _______,  _______,  _______,  _______,
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    /*          |          */  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
        KC_GRV,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  /*          |          */  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_PIPE,
        _______,  _______,  KC_HOME,  KC_LT,    KC_GT,    KC_END,   _______,  /*|*/  _______,  XXXXXXX,  KC_TILD,  KC_SLSH,  KC_LCBR,  KC_RCBR,  KC_BSLS,
                                      _______,  _______,  _______,  _______,  /*|*/  _______,  MO(3),    _______,  _______
    ),
    [HIGHER] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,  /*          |          */  _______,  _______,  _______,  _______,  _______,  _______,
        QK_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     /*          |          */  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_PSCR,
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    /*          |          */  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_DEL,   KC_PGUP,
        KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  /*|*/  _______,  KC_PLUS,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_PGDN,
                                      _______,  _______,  MO(3),    _______,  /*|*/  _______,  _______,    _______,  _______
    ),
    [ADJUST] = LAYOUT(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  /*          |          */  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        CA_F1,    CA_F2,    LG_PSCR,  XXXXXXX,  XXXXXXX,  XXXXXXX,  /*          |          */  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PSCR,  CA_F11,   CA_F12,
        XXXXXXX,  XXXXXXX,  SG_S,     BS_TOGG,  KC_LARR,  XXXXXXX,  /*          |          */  KC_HPTH,  KC_RARR,  RM_TOGG,  RM_HUEU,  RM_SATU,  RM_VALU,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_CPTH,  XXXXXXX,  XXXXXXX,  XXXXXXX,  /*|*/  XXXXXXX,  XXXXXXX,  KC_DQUO,  RM_NEXT,  RM_HUED,  RM_SATD,  RM_VALD,
                                      _______,  _______,  _______,  _______,  /*|*/  _______,  _______,  _______,  _______
    ),
    // clang-format on
};

void keyboard_pre_init_user(void) {
    // Disable power led
    gpio_set_pin_output(24);
    gpio_write_pin_high(24);
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_LPRN:
            return KC_RPRN;
        case KC_RPRN:
            return KC_LPRN;
        case KC_LT:
            return KC_GT;
        case KC_GT:
            return KC_LT;
    }

    return KC_TRNS;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LARR:
            if (record->event.pressed) {
                SEND_STRING("<-");
            }
            break;
        case KC_RARR:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;
        case KC_HPTH:
            if (record->event.pressed) {
                SEND_STRING("~/");
            }
            break;
        case KC_CPTH:
            if (record->event.pressed) {
                SEND_STRING("./");
            }
            break;
    }
    return true;
}
