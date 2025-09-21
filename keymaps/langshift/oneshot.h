#pragma once

#include QMK_KEYBOARD_H

// Represents the four states a oneshot key can be in
typedef enum {
    os_up_unqueued,
    os_up_queued,
    os_down_unused,
    os_down_used,
} oneshot_state;

// Custom oneshot mod implementation that doesn't rely on timers. If a mod is
// used while it is held it will be unregistered on keyup as normal, otherwise
// it will be queued and only released after the next non-mod keyup.
void update_oneshot(
    oneshot_state *state,
    uint16_t mod,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
);

/// @brief Register each oneshot key that you desire to have selected color
///        of selected leds of RGB Matrix in keymap.c file in the
///        bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max)
///        callback
/// @param state - Pointer to state of oneshot key 
/// @param leds - Array with numbers of LEDs (look at <your_keyboard>.c file)
/// @param ledscount - Size of leds array
/// @param red - Red color part of light to be on during oneshot key is active 
/// @param green - Green color part of light to be on during oneshot key is active 
/// @param blue - Blue color part of light to be on during oneshot key is active 
void light_oneshot(
    oneshot_state *state,
    int8_t leds[],
    size_t ledscount,
    int8_t red,
    int8_t green,
    int8_t blue
);

// To be implemented by the consumer. Defines keys to cancel oneshot mods.
bool is_oneshot_cancel_key(uint16_t keycode);

// To be implemented by the consumer. Defines keys to ignore when determining
// whether a oneshot mod has been used. Setting this to modifiers and layer
// change keys allows stacking multiple oneshot modifiers, and carrying them
// between layers.
bool is_oneshot_ignored_key(uint16_t keycode);
