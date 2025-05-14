#include "pointermodes.h"

void pressactivator(
    bool *active,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode != trigger) return;
    if (record->event.pressed)
    {
        *active = true;
    } else {
        *active = false;
    }
}

void tapactivator(
    bool *active,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (!record->event.pressed
        && keycode == trigger) {
        *active = !*active;
    }
}

void scrollhandler (
    bool active,
    float vertical_divisor,
    float horizontal_divisor,
    float *acc_v,
    float *acc_h,
    bool allow_vertical,
    bool allow_horizontal,
    report_mouse_t *mreport
) {
    if (!active) return;
    
    // Calculate and accumulate scroll values based on mouse movement and divisors
    //scroll_accum_h += (float)mouse_report.x / SCROLL_DIVISOR_H;

    if (allow_vertical)
        *acc_v += (float)mreport->y / vertical_divisor;

    if (allow_horizontal)
        *acc_h += (float)mreport->y / horizontal_divisor;

    // Assign integer parts of accumulated scroll values to the mouse report
    //mouse_report.h = -(int8_t)scroll_accum_h;
    mreport->v = (int8_t) *acc_v;
    mreport->h = (int8_t) *acc_h;
    // Update accumulated scroll values by subtracting the integer parts
    *acc_h += (int8_t)*acc_h;
    *acc_v -= (int8_t)*acc_v;

    // Clear the X and Y values of the mouse report
    mreport->x = 0;
    mreport->y = 0;
}

void horizontal_key_tapper (
    bool active,
    float divisor,
    float *accum,
    int16_t left_keycode,
    int16_t right_keycode,
    report_mouse_t *mreport
) {
    if (!active) return;

    *accum += (float)mreport->h / divisor;

    int8_t repeats = (int8_t) *accum;

    *accum -= repeats;
    
    if (repeats < 0) {
        for (int8_t i = 0; i > repeats; i--)
            tap_code(left_keycode);
    }

    if (repeats > 0) {
        for (int8_t i = 0; i < repeats; i++)
            tap_code(right_keycode);
    }

    // Clear the X and Y values of the mouse report
    mreport->x = 0;
    mreport->y = 0;
}

void vertical_key_tapper (
    bool active,
    float divisor,
    float *accum,
    int16_t up_keycode,
    int16_t down_keycode,
    report_mouse_t *mreport
) {
    if (!active) return;

    *accum += (float)mreport->v / divisor;
    int8_t repeats = (int8_t) *accum;

    *accum -= repeats;
    
    if (repeats < 0) {
        for (int8_t i = 0; i > repeats; i--)
            tap_code(up_keycode);
    }

    if (repeats > 0) {
        for (int8_t i = 0; i < repeats; i++)
            tap_code(down_keycode);
    }

    // Clear the X and Y values of the mouse report
    mreport->x = 0;
    mreport->y = 0;
}