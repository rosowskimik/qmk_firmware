#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

#define OS_LCTL OSM(MOD_LCTL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_RALT OSM(MOD_RALT)

#define MT_SPC LSFT_T(KC_SPC)

#define LT1_ESC LT(1, KC_ESC)
#define LT2_BSPC LT(2, KC_BSPC)

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
        OS_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     /*          |          */  KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
        OS_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_LBRC,  /*|*/  KC_RBRC,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  OS_RSFT,
        /*                        */  OS_LALT,  KC_LGUI,  LT1_ESC,  MT_SPC,   /*|*/  KC_ENT,   LT2_BSPC, KC_DEL,   OS_RALT
    ),
    [HIGHER] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,  /*          |          */  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     /*          |          */  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
        _______,  KC_AT,    KC_MINS,  KC_PLUS,  KC_EQL,   KC_PAST,  /*          |          */  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_COLN,  _______,
        _______,  KC_PIPE,  KC_AMPR,  KC_QUOT,  KC_DQT,   KC_SLSH,  KC_GRV,   /*|*/  _______,  KC_BSLS,  KC_UNDS,  KC_EXLM,  KC_QUES,  KC_HASH,  _______,
                                      _______,  _______,  MO(3),    KC_LCTL,  /*|*/  _______,  _______,  _______,  _______
    ),
    [LOWER] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,  /*          |          */  _______,  _______,  _______,  _______,  _______,  _______,
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    /*          |          */  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
        _______,  KC_HOME,  KC_TAB,   KC_LCBR,  KC_RCBR,  QK_AREP,  /*          |          */  QK_AREP,  KC_LPRN,  KC_RPRN,  KC_BSPC,  KC_PGUP,  _______,
        OS_LALT,  KC_END,   _______,  KC_LBRC,  KC_RBRC,  QK_REP,   _______,  /*|*/  _______,  QK_REP,   KC_LT,    KC_GT,    _______,  KC_PGDN,  _______,
                                      _______,  _______,  _______,  _______,  /*|*/  KC_RALT,  MO(3),    _______,  _______
    ),
    [ADJUST] = LAYOUT(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  /*          |          */  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  /*          |          */  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  UG_SPDD,  UG_VALD,  UG_SATD,  UG_HUED,  XXXXXXX,  /*          |          */  XXXXXXX,  UG_HUEU,  UG_SATU,  UG_VALU,  UG_SPDU,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  UG_TOGG,  UG_PREV,  XXXXXXX,  XXXXXXX,  /*|*/  XXXXXXX,  XXXXXXX,  UG_NEXT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  /*|*/  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
    ),
    // clang-format
};

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_LPRN: return KC_RPRN;
        case KC_RPRN: return KC_LPRN;
        case KC_LT: return KC_GT;
        case KC_GT: return KC_LT;
    }

    return KC_TRNS;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    // 0 is left-half encoder,
    // 1 is right-half encoder
    if (index == 0) goto _exit;

    uint8_t current_layer = get_highest_layer(layer_state | default_layer_state);

    switch (current_layer) {
        case BASE:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
        case LOWER:
            if (clockwise) {
                tap_code(KC_BRIU);
            } else {
                tap_code(KC_BRID);
            }
            break;
    }
_exit:
    return false;
}
#endif
