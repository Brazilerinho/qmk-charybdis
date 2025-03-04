#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "swapper.h"
#include "pointermodes.h"

#define RESET QK_BOOT

#define XXXX KC_NO

#define LA_SYM MO(_SYM)
#define LA_ALT MO(_ALT)
#define LA_NAV MO(_NAV)
#define LA_CMD MO(_CMD)
#define LA_GFN MO(_GFN)

#define QUOT S(KC_GRV)
#define PIPE S(KC_NUBS)
#define DPIPE S(RALT(KC_NUBS))
#define SCLN S(KC_BSLS)
#define CLN S(KC_RBRC)
#define GRV RALT(KC_GRV)
#define BSL RALT(KC_NUBS)
#define NBSP  RALT(KC_SPC)

#define SPACE_L S(G(KC_LEFT))
#define SPACE_R S(G(KC_RGHT))

#define TAB_L C(S(KC_TAB))
#define TAB_R C(KC_TAB)
#define LBRACE S(RALT(KC_DOT))
#define RBRACE S(RALT(KC_SLSH))

enum layers {
    _DEF,
    _GAM,
    _GFN,
    _SYM,
    _ALT,
    _NAV,
    _CMD,
    _NUM,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    SW_WIN,  // Switch to next window         (alt-tab)
    SW_TAB,  // Switch to next browser tab    (ctrl-tab)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DEF] = LAYOUT_main(
    /* ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐             ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐*/
    /* │     `     │           │           │           │           │           │             │           │           │           │           │           │           │*/  
          KC_GRV,      XXXX,       XXXX,       XXXX,       XXXX,       XXXX,                     XXXX,       XXXX,       XXXX,       XXXX,       XXXX,       XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │    TAB    │     Q     │     W     │     E     │     R     │     T     │             │     Y     │     U     │     I     │     O     │     P     │     [     │*/        
          KC_TAB,      KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                     KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,      KC_LBRC,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │    ESC    │     A     │     S     │     D     │     F     │     G     │             │     H     │     J     │     K     │     L     │     ;     │     '     │*/
          KC_ESC,       KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                     KC_H,       KC_J,       KC_K,       KC_L,     KC_SCLN,    KC_QUOT,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │ MOUSE MID │     Z     │     X     │     C     │     V     │     B     │             │     N     │     M     │     &     │     [     │     ]     │     ]     │*/
          KC_BTN3,     KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                     KC_N,       KC_M,      KC_COMM,    KC_DOT,     KC_SLSH,    KC_RBRC,
    /* └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘             └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘*/
    /*                                          ┌───────────┬───────────┬───────────┐   ┌───────────┬───────────┐                                                     */
    /*                                          │    NAV    │   SPACE   │ MOUSE LEFT│   │   SHIFT   │    SYM    │                                                     */
                                                   LA_NAV,     KC_SPC,     KC_BTN1,        KC_LSFT,     LA_SYM,     
    /*                                          └───────────┼───────────┼───────────┤   ├───────────┼───────────┘                                                     */
    /*                                                      │ CAPS LOCK │MOUSE RIGHT│   │    ALT    │                                                                 */
                                                               KC_CAPS,    KC_BTN2,         LA_ALT
    /*                                                      └───────────┴───────────┘   └───────────┘                                                                 */
    ),

    [_GAM] = LAYOUT_main(
    /* ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐             ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐*/
    /* │    ESC    │     1     │     2     │     3     │     4     │     5     │             │     6     │     7     │     8     │     9     │     0     │  VOLUME+  │*/
          KC_ESC,      KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                     KC_6,       KC_7,       KC_8,       KC_9,       KC_0,      KC_VOLU,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │    TAB    │    TAB    │     Q     │     W     │     E     │     R     │             │     F1    │    HOME   │     UP    │    END    │     F9    │  VOLUME-  │*/
          KC_TAB,     KC_TAB,      KC_Q,       KC_W,       KC_E,       KC_R,                     KC_F1,     KC_HOME,     KC_UP,      KC_END,     KC_F9,     KC_VOLD,        
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │      H    │   SHIFT   │     A     │     S     │     D     │     F     │             │     F2    │    LEFT   │    DOWN   │   RIGHT   │     F8    │    F10    │*/
            KC_H,     KC_LSFT,     KC_A,       KC_S,       KC_D,       KC_F,                     KC_F2,     KC_LEFT,    KC_DOWN,    KC_RGHT,     KC_F8,      KC_F10,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │      N    │    CTRL   │     Z     │     X     │     C     │     V     │             │     F3    │     F4    │     F5    │     F6    │     F7    │  TOG GAME │*/
            KC_N,     KC_LCTL,     KC_Z,       KC_X,       KC_C,       KC_V,                     KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,     DF(_DEF),
    /* └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘             └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘*/
    /*                                          ┌───────────┬───────────┬───────────┐   ┌───────────┬───────────┐                                                     */
    /*                                          │    ALT    │   SPACE   │     G     │   │   ENTER   │   BKSPC   │                                                     */
                                                   KC_LALT,    KC_SPC,      KC_G,          KC_ENT,     KC_BSPC,
    /*                                          └───────────┼───────────┼───────────┤   ├───────────┼───────────┘                                                     */
    /*                                                      │      T    │     B     │   │ WIN+CTRL+V│                                                                 */
                                                                 KC_T,      KC_B,         C(G(KC_V))
    /*                                                      └───────────┴───────────┘   └───────────┘                                                                 */
    
    ),

    [_GFN] = LAYOUT_main(
    /* ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐             ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐*/
    /* │           │           │           │           │           │           │             │           │           │           │           │           │           │*/  
           XXXX,       XXXX,       XXXX,       XXXX,       XXXX,       XXXX,                     XXXX,       XXXX,       XXXX,       XXXX,       XXXX,       XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │    TAB    │     Q     │     W     │     E     │     R     │     T     │             │           │           │    UP     │           │           │           │*/        
          KC_TAB,      KC_5,       KC_1,       KC_2,       KC_3,       KC_4,                     XXXX,       XXXX,       KC_UP,      XXXX,       XXXX,       XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │    ESC    │     A     │     S     │     D     │     F     │     G     │             │           │    LEFT   │    DOWN   │   RIGHT   │           │           │*/
          KC_ESC,      KC_0,       KC_6,       KC_7,       KC_8,       KC_9,                     XXXX,      KC_LEFT,    KC_DOWN,    KC_RGHT,     XXXX,       XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │    CTRL   │     Z     │     X     │     C     │     V     │     B     │             │           │           │           │           │           │           │*/
          KC_LCTL,     KC_G,       KC_J,       KC_I,       KC_M,       KC_T,                     XXXX,       XXXX,       XXXX,       XXXX,       XXXX,       XXXX,
    /* └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘             └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘*/
    /*                                          ┌───────────┬───────────┬───────────┐   ┌───────────┬───────────┐                                                     */
    /*                                          │    ESC    │   ENTER   │           │   │           │           │                                                     */
                                                   KC_ESC,     KC_ENT,     _______,        _______,    _______,
    /*                                          └───────────┼───────────┼───────────┤   ├───────────┼───────────┘                                                     */
    /*                                                      │           │           │   │           │                                                                 */
                                                               _______,    _______,        _______
    /*                                                      └───────────┴───────────┘   └───────────┘                                                                 */
    ),

    [_SYM] = LAYOUT_main(
    /* ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐             ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐*/
    /* │     `     │           │           │           │           │           │             │           │           │           │           │           │           │*/  
            GRV,       XXXX,       XXXX,       XXXX,       XXXX,       XXXX,                     XXXX,       XXXX,       XXXX,       XXXX,       XXXX,       XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │           │     !     │     @     │     #     │     $     │     %     │             │     ^     │     ?     │     *     │     (     │     )     │     |     │*/        
          _______,    S(KC_1),    S(KC_2),    S(KC_3),    S(KC_4),    S(KC_5),                  S(KC_6),    S(KC_7),    S(KC_8),    S(KC_9),   S(KC_0),      PIPE,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │           │     <     │     >     │     '     │     "     │     -     │             │     +     │STICK SHIFT│STICKY CTRL│STICKY ALT │STICKY WIN │     \     │*/
          _______,  RALT(KC_O), RALT(KC_P),   KC_GRV,      QUOT,      KC_MINS,                  KC_PLUS,    OS_SHFT,    OS_CTRL,    OS_ALT,     OS_CMD,       BSL,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │           │     [     │     ]     │     ;     │     ,     │     _     │             │     =     │     .     │     :     │     {     │     }     │     /     │*/
          _______, RALT(KC_DOT),RALT(KC_SLSH), SCLN,      KC_BSLS,    KC_UNDS,                   KC_EQL,    KC_RBRC,      CLN,      LBRACE,      RBRACE,    KC_NUBS,
    /* └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘             └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘*/
    /*                                          ┌───────────┬───────────┬───────────┐   ┌───────────┬───────────┐                                                     */
    /*                                          │           │           │           │   │           │           │                                                     */
                                                   _______,    _______,    _______,        _______,    _______,
    /*                                          └───────────┼───────────┼───────────┤   ├───────────┼───────────┘                                                     */
    /*                                                      │           │           │   │           │                                                                 */
                                                               _______,    _______,        _______
    /*                                                      └───────────┴───────────┘   └───────────┘                                                                 */
    ),

    [_ALT] = LAYOUT_main(
    /* ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐             ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐*/
    /* │           │           │           │           │           │           │             │           │           │           │           │           │           │*/  
           XXXX,       XXXX,       XXXX,       XXXX,       XXXX,       XXXX,                     XXXX,       XXXX,       XXXX,       XXXX,       XXXX,       XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │           │     ψ     │     ω     │     €     │     ®     │     ё     │             │     ¥     │     λ     │     щ     │     <     │     >     │           │*/        
           XXXX,    RALT(KC_Q), RALT(KC_W), RALT(KC_E), RALT(KC_R), RALT(KC_T),               RALT(KC_Y), RALT(KC_U), RALT(KC_I), RALT(KC_O), RALT(KC_P),    XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │           │     α     │     §     │     °     │     £     │     γ     │             │     ₽     │     ø     │     =>    │     «     │     »     │           │*/
           XXXX,    RALT(KC_A), RALT(KC_S), RALT(KC_D), RALT(KC_F), RALT(KC_G),               RALT(KC_H), RALT(KC_J), RALT(KC_K), RALT(KC_L),RALT(KC_SCLN),  XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │           │     μ     │     ×     │     ©     │     √     │     β     │             │     η     │     ъ     │     &     │     [     │     ]     │           │*/
           XXXX,    RALT(KC_Z), RALT(KC_X), RALT(KC_C), RALT(KC_V), RALT(KC_B),               RALT(KC_N), RALT(KC_M),RALT(KC_COMM),RALT(KC_DOT),RALT(KC_SLSH),XXXX,
    /* └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘             └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘*/
    /*                                          ┌───────────┬───────────┬───────────┐   ┌───────────┬───────────┐                                                     */
    /*                                          │           │   NBSP    │           │   │           │           │                                                     */
                                                   _______,     NBSP,      _______,        _______,    _______,
    /*                                          └───────────┼───────────┼───────────┤   ├───────────┼───────────┘                                                     */
    /*                                                      │           │           │   │           │                                                                 */
                                                               _______,    _______,        _______
    /*                                                      └───────────┴───────────┘   └───────────┘                                                                 */
    ), 

    [_NAV] = LAYOUT_main(
    /* ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐             ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐*/
    /* │           │           │           │           │           │           │             │           │           │           │           │           │           │*/  
          C(KC_Z),     XXXX,       XXXX,       XXXX,       XXXX,       XXXX,                     XXXX,       XXXX,       XXXX,       XXXX,       XXXX,       XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │           │ SWAP TAB  │ SWAP WIN  │ PREV TAB  │ NEXT TAB  │    ESC    │             │    ESC    │   HOME    │     UP    │    END    │  Delete   │           │*/        
          C(KC_X),    SW_TAB,     SW_WIN,      TAB_L,     TAB_R,      KC_DEL,                   KC_BSPC,    KC_HOME,     KC_UP,     KC_END,     KC_DEL,      XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │           │STICKY WIN │STICKY ALT │STICKY CTRL│STICK SHIFT│   ENTER   │             │   ENTER   │   LEFT    │   DOWN    │   RIGHT   │ Backspace │           │*/
          C(KC_C),    OS_CMD,     OS_ALT,     OS_CTRL,    OS_SHFT,    KC_ENT,                   KC_ENT,    KC_LEFT,     KC_DOWN,    KC_RGHT,    KC_BSPC,     XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │           │SPACE LEFT │SPACE RIGHT│GAME LAYER │ PRNT SCRN │    TAB    │             │    TAB    │  PAGE UP  │ PAGE DOWN │           │  NUM LOCK │           │*/
          C(KC_V),    SPACE_L,    SPACE_R,   DF(_GAM),    KC_PSCR,    KC_TAB,                   KC_TAB,     KC_PGUP,    KC_PGDN,    KC_QUOT,     KC_NUM,     XXXX,
    /* └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘             └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘*/
    /*                                          ┌───────────┬───────────┬───────────┐   ┌───────────┬───────────┐                                                     */
    /*                                          │           │ CMD LAYER │           │   │           │           │                                                     */
                                                   _______,    LA_CMD,     _______,        _______,    _______,
    /*                                          └───────────┼───────────┼───────────┤   ├───────────┼───────────┘                                                     */
    /*                                                      │           │           │   │           │                                                                 */
                                                               _______,    _______,        _______
    /*                                                      └───────────┴───────────┘   └───────────┘                                                                 */
    ),

    [_CMD] = LAYOUT_main(
    /* ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐             ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐*/
    /* │           │           │           │           │           │           │             │           │           │           │           │           │           │*/  
           XXXX,       XXXX,       XXXX,       XXXX,       XXXX,       XXXX,                     XXXX,       XXXX,       XXXX,       XXXX,       XXXX,       XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │           │           │           │           │           │           │             │           │    VOL-   │    MUTE   │    VOL+   │           │           │*/        
           XXXX,     MEH(KC_Q),  MEH(KC_W),  MEH(KC_E),  MEH(KC_R),  MEH(KC_T),                MEH(KC_Y),   KC_VOLD,    KC_MUTE,    KC_VOLU,   MEH(KC_P),    XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │           │     ~     │           │     '     │     "     │     -     │             │     +     │MEDIA PREV │MEDIA PAUSE│MEDIA NEXT │           │           │*/
           XXXX,     MEH(KC_A),  MEH(KC_S),  MEH(KC_D),  MEH(KC_F),  MEH(KC_G),                MEH(KC_H),  KC_MPRV,   KC_MPLY,      KC_MNXT,  MEH(KC_SCLN),  XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │           │     \     │           │     ;     │     ,     │     _     │             │     =     │     .     │     :     │     |     │     /     │           │*/
           XXXX,     MEH(KC_Z),  MEH(KC_X),  MEH(KC_C),  MEH(KC_V),  MEH(KC_B),                MEH(KC_N),  MEH(KC_M),MEH(KC_COMM),MEH(KC_DOT),MEH(KC_SLSH),  XXXX,
    /* └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘             └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘*/
    /*                                          ┌───────────┬───────────┬───────────┐   ┌───────────┬───────────┐                                                     */
    /*                                          │           │           │           │   │    WIN    │           │                                                     */
                                                   _______,    _______,    _______,        KC_LGUI,    _______,
    /*                                          └───────────┼───────────┼───────────┤   ├───────────┼───────────┘                                                     */
    /*                                                      │           │           │   │           │                                                                 */
                                                               _______,    _______,        _______
    /*                                                      └───────────┴───────────┘   └───────────┘                                                                 */
    ),

    [_NUM] = LAYOUT_main(
    /* ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐             ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐*/
    /* │           │           │           │           │           │           │             │           │           │           │           │           │           │*/  
           XXXX,       XXXX,       XXXX,       XXXX,       XXXX,       XXXX,                     XXXX,       XXXX,       XXXX,       XXXX,       XXXX,       XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │           │     1     │     2     │     3     │     4     │     5     │             │     6     │     7     │     8     │     9     │     0     │           │*/        
           XXXX,       KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                     KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │    F11    │STICKY WIN │STICKY ALT │STICKY CTRL│STICK SHIFT│     ,     │             │     ,     │STICK SHIFT│STICKY CTRL│STICKY ALT │STICKY WIN │    F12    │           │*/
          KC_F11,     OS_CMD,     OS_ALT,     OS_CTRL,    OS_SHFT,    KC_PDOT,                  KC_PDOT,    OS_SHFT,    OS_CTRL,    OS_ALT,     OS_CMD,      KC_F12,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │           │     F1    │     F2    │     F3    │     F4    │     F5    │             │     F6    │     F7    │     F8    │     F9    │    F10    │           │*/
           XXXX,       KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                    KC_F6,      KC_F7,      KC_F8,      KC_F9,     KC_F10,      XXXX,
    /* └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘             └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘*/
    /*                                          ┌───────────┬───────────┬───────────┐   ┌───────────┬───────────┐                                                     */
    /*                                          │           │           │           │   │           │           │                                                     */
                                                   _______,    _______,    _______,        _______,    _______,
    /*                                          └───────────┼───────────┼───────────┤   ├───────────┼───────────┘                                                     */
    /*                                                      │           │           │   │           │                                                                 */
                                                               _______,    _______,        _______
    /*                                                      └───────────┴───────────┘   └───────────┘                                                                 */
    )
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 64.0
#define SCROLL_DIVISOR_V 45.0
 
// Variables to store accumulated scroll values
float scroll_accum_h = 0.0;
float scroll_accum_v = 0.0;

bool scroll_active = false;


bool sw_win_active = false;
bool sw_tab_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_win_active, KC_LALT, KC_TAB, SW_WIN, OS_SHFT,
        keycode, record
    );
    update_swapper(
        &sw_tab_active, KC_LCTL, KC_TAB, SW_TAB, OS_SHFT,
        keycode, record
    );

    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    pressactivator(
        &scroll_active, LA_NAV,
        keycode, record
    );

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _NUM);
}

// Function to handle mouse reports and perform drag scrolling
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    scrollhandler(
        scroll_active, SCROLL_DIVISOR_V, SCROLL_DIVISOR_H,
        &scroll_accum_v, &scroll_accum_h, true, false,
        &mouse_report
    );

    return mouse_report;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    uint8_t bright = rgb_matrix_get_val();

    switch (get_highest_layer(layer_state|default_layer_state)) {
    case _NAV:
        RGB_MATRIX_INDICATOR_SET_COLOR(1, 0, bright, bright);
        RGB_MATRIX_INDICATOR_SET_COLOR(29, 0, bright, bright);  
        break;
    case _SYM:
        RGB_MATRIX_INDICATOR_SET_COLOR(1, 0, 0, bright);
        RGB_MATRIX_INDICATOR_SET_COLOR(29, 0, 0, bright); 
        break;
    case _NUM:
        RGB_MATRIX_INDICATOR_SET_COLOR(1, bright, 0, 0);
        RGB_MATRIX_INDICATOR_SET_COLOR(29, bright, 0, 0);
        break;
    case _GAM:
        RGB_MATRIX_INDICATOR_SET_COLOR(1, bright, bright, 0);
        RGB_MATRIX_INDICATOR_SET_COLOR(29, bright, bright, 0);
        break;
    case _ALT:
        RGB_MATRIX_INDICATOR_SET_COLOR(1, bright, 0, bright);
        RGB_MATRIX_INDICATOR_SET_COLOR(29, bright, 0, bright);
        break;
    case _CMD:
        RGB_MATRIX_INDICATOR_SET_COLOR(1, bright, bright, bright);
        RGB_MATRIX_INDICATOR_SET_COLOR(29, bright, bright, bright);
        break;
    case _GFN:
        RGB_MATRIX_INDICATOR_SET_COLOR(1, 0, bright, 0);
        RGB_MATRIX_INDICATOR_SET_COLOR(29, 0, bright, 0);
    default:
        break;
    }

    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(4, 0, bright, 0);
        RGB_MATRIX_INDICATOR_SET_COLOR(30, 0, bright, 0);
    }

    return false;
}