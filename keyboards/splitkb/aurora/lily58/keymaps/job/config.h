#pragma once

#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
#define POINTING_DEVICE_ROTATION_180
#define AZOTEQ_IQS5XX_TPS43
#define AZOTEQ_IQS5XX_PRESS_AND_HOLD_ENABLE true

#define AUTO_SHIFT_TIMEOUT 143
#define AUTO_SHIFT_REPEAT
#define NO_AUTO_SHIFT_SYMBOLS
#define NO_AUTO_SHIFT_NUMERIC
#define AUTO_SHIFT_NO_SETUP

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_INVERT_ON_SHIFT

#define TAPPING_TERM 170
#define PERMISSIVE_HOLD

// Workaround for broken left column - remap to one of free pins
// Value from `platforms/chibios/converters/elite_c_to_rp2040_ce/_pin_defs.h`
#define B7 12U
#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS {B7, F7, B1, B3, B2, B6}
