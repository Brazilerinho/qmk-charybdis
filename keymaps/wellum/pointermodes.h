#pragma once

#include QMK_KEYBOARD_H

// Activates mode by pressing a trigger key. Mode deactivates when the key is released
// State of mode writes into 'active' argument
void pressactivator(
    bool *active,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
);

// Toggles mode by tapping a trigger key. Mode deactivates when the key is released
// State of mode writes into 'active' argument
void tapactivator(
    bool *active,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
);

void scrollhandler (
    bool active,
    float vertical_divisor,
    float horizontal_divisor,
    float *acc_v,
    float *acc_h,
    bool allow_vertical,
    bool allow_horizontal,
    report_mouse_t *mreport
);

void horizontal_key_tapper (
    bool active,
    float divisor,
    float *accum,
    int16_t left_keycode,
    int16_t right_keycode,
    report_mouse_t *mreport
);

void vertical_key_tapper (
    bool active,
    float divisor,
    float *accum,
    int16_t up_keycode,
    int16_t down_keycode,
    report_mouse_t *mreport
);

