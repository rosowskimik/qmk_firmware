// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keycodes.h"

enum layers {
    BASE,
    CONTROL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [BASE] =    LAYOUT(
        KC_GRV,     KC_Z,       KC_X,       KC_C,       MO(1)
    ),
    [CONTROL] = LAYOUT(
        KC_ESC,     XXXXXXX,    KC_ENT,     KC_F2,      _______
    ),
    // clang-format on
};

void keyboard_pre_init_user(void) {
    // Disable RGB leds
    gpio_set_pin_output(16);
    gpio_write_pin_high(16);
    gpio_set_pin_output(17);
    gpio_write_pin_high(17);
    gpio_set_pin_output(25);
    gpio_write_pin_high(25);
}
