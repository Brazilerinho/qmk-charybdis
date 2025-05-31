#include QMK_KEYBOARD_H

#define CUSTOM_SAFE_RANGE SAFE_RANGE

#include "lang_shift/include.h"
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
    _EN,
    _EN_S,
    _RU,
    _RU_S,
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
    OS_SHFT = CUSTOM_SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    SW_WIN,  // Switch to next window         (alt-tab)
    SW_TAB,  // Switch to next browser tab    (ctrl-tab)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_EN] = LAYOUT_main(
    /* ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐             ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐*/
    /* │           │           │           │MEDIA PREV │MEDIA NEXT │MEDIA PAUSE│             │    VOL-   │    VOL+   │    MUTE   │           │           │           │*/  
            XXXX,      XXXX,       XXXX,      KC_MPRV,    KC_MNXT,    KC_MPLY,                  KC_VOLD,    KC_VOLU,    KC_MUTE,     XXXX,      KC_PSCR,     XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │    TAB    │     Q     │     W     │     E     │     R     │     T     │             │     Y     │     U     │     I     │     O     │     P     │     [     │*/        
          KC_TAB,      EN_Q,       EN_W,       EN_E,       EN_R,       EN_T,                     EN_Y,       EN_U,       EN_I,       EN_O,       EN_P,      EN_LBRC,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │    ESC    │     A     │     S     │     D     │     F     │     G     │             │     H     │     J     │     K     │     L     │     ;     │     '     │*/
          KC_ESC,      EN_A,       EN_S,       EN_D,       EN_F,       EN_G,                     EN_H,       EN_J,       EN_K,       EN_L,     EN_SCLN,    EN_QUOT,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │ MOUSE MID │     Z     │     X     │     C     │     V     │     B     │             │     N     │     M     │     ,     │     .     │     /     │     ]     │*/
          KC_BTN3,     EN_Z,       EN_X,       EN_C,       EN_V,       EN_B,                     EN_N,       EN_M,      EN_COMM,    EN_DOT,     EN_SLSH,    EN_RBRC,
    /* └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘             └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘*/
    /*                                          ┌───────────┬───────────┬───────────┐   ┌───────────┬───────────┐                                                     */
    /*                                          │MOUSE LEFT │    NAV    │   SPACE   │   │   SHIFT   │    SYM    │                                                     */
                                                   KC_BTN1,    LA_NAV,     KC_SPC,         KC_LSFT,     LA_SYM,     
    /*                                          └───────────┼───────────┼───────────┤   ├───────────┼───────────┘                                                     */
    /*                                                      │MOUSE RIGHT│    LNG    │   │    CMD    │                                                                 */
                                                               KC_BTN2,    LA_CHNG,        LA_CMD
    /*                                                      └───────────┴───────────┘   └───────────┘                                                                 */
    ),

    [_EN_S] = LAYOUT_main(
    /* ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐             ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐*/
    /* │           │           │           │MEDIA PREV │MEDIA NEXT │MEDIA PAUSE│             │    VOL-   │    VOL+   │    MUTE   │           │           │           │*/  
            XXXX,      XXXX,       XXXX,      KC_MPRV,    KC_MNXT,    KC_MPLY,                  KC_VOLD,    KC_VOLU,    KC_MUTE,     XXXX,      KC_PSCR,     XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │    TAB    │     Q     │     W     │     E     │     R     │     T     │             │     Y     │     U     │     I     │     O     │     P     │     {     │*/        
          KC_TAB,     EN_S_Q,     EN_S_W,     EN_S_E,     EN_S_R,     EN_S_T,                   EN_S_Y,     EN_S_U,     EN_S_I,     EN_S_O,     EN_S_P,     EN_LCBR,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │    ESC    │     A     │     S     │     D     │     F     │     G     │             │     H     │     J     │     K     │     L     │     :     │     "     │*/
          KC_ESC,     EN_S_A,     EN_S_S,     EN_S_D,     EN_S_F,     EN_S_G,                   EN_S_H,     EN_S_J,     EN_S_K,     EN_S_L,     EN_COLN,    EN_DQUO,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │    LANG   │     Z     │     X     │     C     │     V     │     B     │             │     N     │     M     │     <     │     >     │     ?     │     }     │*/
          LA_CHNG,    EN_S_Z,     EN_S_X,     EN_S_C,     EN_S_V,     EN_S_B,                   EN_S_N,     EN_S_M,      EN_LT,      EN_GT,     EN_QUES,    EN_RCBR,
    /* └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘             └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘*/
    /*                                          ┌───────────┬───────────┬───────────┐   ┌───────────┬───────────┐                                                     */
    /*                                          │MOUSE LEFT │    NAV    │   SPACE   │   │   SHIFT   │    SYM    │                                                     */
                                                   KC_BTN1,    LA_NAV,     KC_SPC,         KC_LSFT,     LA_SYM,     
    /*                                          └───────────┼───────────┼───────────┤   ├───────────┼───────────┘                                                     */
    /*                                                      │MOUSE RIGHT│    LNG    │   │    CMD    │                                                                 */
                                                               KC_BTN2,    LA_CHNG,        LA_CMD
    /*                                                      └───────────┴───────────┘   └───────────┘                                                                 */
    ),

    [_RU] = LAYOUT_main(
    /* ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐             ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐*/
    /* │           │           │           │MEDIA PREV │MEDIA NEXT │MEDIA PAUSE│             │    VOL-   │    VOL+   │    MUTE   │           │           │           │*/  
            XXXX,      XXXX,       XXXX,      KC_MPRV,    KC_MNXT,    KC_MPLY,                  KC_VOLD,    KC_VOLU,    KC_MUTE,     XXXX,      KC_PSCR,     XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │    TAB    │     Й     │     Ц     │     У     │     К     │     Е     │             │     Н     │     Г     │     Ш     │     Щ     │     З     │     Х     │*/        
          KC_TAB,      RU_J,       RU_TS,      RU_U,       RU_K,       RU_JE,                    RU_N,       RU_G,       RU_SH,      RU_SC,      RU_Z,       RU_H,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │    ESC    │     Ф     │     Ы     │     В     │     А     │     П     │             │     Р     │     О     │     Л     │     Д     │     Ж     │     Э     │*/
          KC_ESC,      RU_F,       RU_Y,       RU_V,       RU_A,       RU_P,                     RU_R,       RU_O,       RU_L,       RU_D,       RU_ZH,      RU_E,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │    LANG   │     Я     │     Ч     │     С     │     М     │     И     │             │     Т     │     Ь     │     Б     │     Ю     │     Ё     │     Ъ     │*/
          LA_CHNG,     RU_JA,      RU_CH,      RU_S,       RU_M,       RU_I,                     RU_T,       RU_SF,      RU_B,       RU_JU,      RU_JO,      RU_HD,
    /* └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘             └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘*/
    /*                                          ┌───────────┬───────────┬───────────┐   ┌───────────┬───────────┐                                                     */
    /*                                          │MOUSE LEFT │    NAV    │   SPACE   │   │   SHIFT   │    SYM    │                                                     */
                                                   KC_BTN1,    LA_NAV,     KC_SPC,         KC_LSFT,     LA_SYM,     
    /*                                          └───────────┼───────────┼───────────┤   ├───────────┼───────────┘                                                     */
    /*                                                      │MOUSE RIGHT│    LNG    │   │    CMD    │                                                                 */
                                                               KC_BTN2,    LA_CHNG,        LA_CMD
    /*                                                      └───────────┴───────────┘   └───────────┘                                                                 */
    ),

    [_RU_S] = LAYOUT_main(
    /* ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐             ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐*/
    /* │           │           │           │MEDIA PREV │MEDIA NEXT │MEDIA PAUSE│             │    VOL-   │    VOL+   │    MUTE   │           │           │           │*/  
            XXXX,      XXXX,       XXXX,      KC_MPRV,    KC_MNXT,    KC_MPLY,                  KC_VOLD,    KC_VOLU,    KC_MUTE,     XXXX,      KC_PSCR,     XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │    TAB    │     Й     │     Ц     │     У     │     К     │     Е     │             │     Н     │     Г     │     Ш     │     Щ     │     З     │     Х     │*/        
          KC_TAB,     RU_S_J,     RU_S_TS,    RU_S_U,     RU_S_K,     RU_S_JE,                  RU_S_N,     RU_S_G,     RU_S_SH,    RU_S_SC,    RU_S_Z,     RU_S_H,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │    ESC    │     Ф     │     Ы     │     В     │     А     │     П     │             │     Р     │     О     │     Л     │     Д     │     Ж     │     Э     │*/
          KC_ESC,     RU_S_F,     RU_S_Y,     RU_S_V,     RU_S_A,     RU_S_P,                   RU_S_R,     RU_S_O,     RU_S_L,     RU_S_D,     RU_S_ZH,    RU_S_E,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │    LANG   │     Я     │     Ч     │     С     │     М     │     И     │             │     Т     │     Ь     │     Б     │     Ю     │     Ё     │     Ъ     │*/
          LA_CHNG,    RU_S_JA,    RU_S_CH,    RU_S_S,     RU_S_M,     RU_S_I,                   RU_S_T,     RU_S_SF,    RU_S_B,     RU_S_JU,    RU_S_JO,    RU_S_HD,
    /* └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘             └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘*/
    /*                                          ┌───────────┬───────────┬───────────┐   ┌───────────┬───────────┐                                                     */
    /*                                          │MOUSE LEFT │    NAV    │   SPACE   │   │   SHIFT   │    SYM    │                                                     */
                                                   KC_BTN1,    LA_NAV,     KC_SPC,         KC_LSFT,     LA_SYM,     
    /*                                          └───────────┼───────────┼───────────┤   ├───────────┼───────────┘                                                     */
    /*                                                      │MOUSE RIGHT│    LNG    │   │    CMD    │                                                                 */
                                                               KC_BTN2,    LA_CHNG,        LA_CMD
    /*                                                      └───────────┴───────────┘   └───────────┘                                                                 */
    ),

    [_GAM] = LAYOUT_main(
    /* ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐             ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐*/
    /* │    ESC    │     1     │     2     │     3     │     4     │     5     │             │     6     │     7     │     8     │     9     │     0     │  VOLUME+  │*/
          KC_ESC,      KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                     KC_6,       KC_7,       KC_8,       KC_9,       KC_0,      KC_VOLU,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │    TAB    │    TAB    │     Q     │     W     │     E     │     R     │             │     F1    │    HOME   │     ↑     │    END    │     F9    │  VOLUME-  │*/
          KC_TAB,     KC_TAB,      KC_Q,       KC_W,       KC_E,       KC_R,                     KC_F1,     KC_HOME,     KC_UP,      KC_END,     KC_F9,     KC_VOLD,        
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │      H    │   SHIFT   │     A     │     S     │     D     │     F     │             │     F2    │     ←     │     ↓     │     →     │     F8    │    F10    │*/
            KC_H,     KC_LSFT,     KC_A,       KC_S,       KC_D,       KC_F,                     KC_F2,     KC_LEFT,    KC_DOWN,    KC_RGHT,     KC_F8,      KC_F10,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │      N    │    CTRL   │     Z     │     X     │     C     │     V     │             │     F3    │     F4    │     F5    │     F6    │     F7    │  TOG GAME │*/
            KC_N,     KC_LCTL,     KC_Z,       KC_X,       KC_C,       KC_V,                     KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,     TG(_GAM),
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
    /* │           │           │           │           │           │           │             │           │           │           │           │           │           │*/  
           XXXX,       XXXX,       XXXX,       XXXX,       XXXX,       XXXX,                     XXXX,       XXXX,       XXXX,       XXXX,       XXXX,       XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │     `     │     !     │     @     │     #     │     $     │     %     │             │     ^     │     ?     │     *     │     (     │     )     │     |     │*/        
           EN_GRV,    AG_EXCL,     EN_AT,    S(KC_3),     EN_DLR,     AG_PERC,                  EN_CIRC,    AG_QUES,    AG_ASTR,    AG_LPRN,   AG_RPRN,     EN_PIPE,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │     ~     │     '     │     [     │     ]     │     ,     │     -     │             │     +     │     .     │     )     │     (     │     "     │     \     │*/
          EN_TILD,    EN_QUOT,    EN_LBRC,    EN_RBRC,    AG_COMM,    AG_MINS,                  AG_PLUS,    AG_DOT,     AG_RPRN,    AG_LPRN,    AG_DQUO,    AG_BSLS,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │           │     &     │     <     │     >     │     ;     │     _     │             │     =     │     :     │     }     │     {     │     "     │     /     │*/
          _______,    EN_AMPR,     EN_LT,      EN_GT,     AG_SCLN,    AG_UNDS,                  AG_EQL,     AG_COLN,    EN_RCBR,    EN_LCBR,    AG_DQUO,    AG_SLSH,
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
    /*                                          │           │           │           │   │           │           │                                                     */
                                                   _______,    _______,    _______,        _______,    _______,
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
    /* │           │ SWAP TAB  │ SWAP WIN  │ PREV TAB  │ NEXT TAB  │    ESC    │             │           │   HOME    │     ↑     │    END    │           │ Backspace │*/        
          C(KC_X),    SW_TAB,     SW_WIN,      TAB_L,     TAB_R,      KC_DEL,                    XXXX,      KC_HOME,     KC_UP,     KC_END,      XXXX,      KC_BSPC,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │           │STICKY WIN │STICKY ALT │STICKY CTRL│STICK SHIFT│   ENTER   │             │   ENTER   │     ←     │     ↓     │     →     │           │           │*/
          C(KC_C),    OS_CMD,     OS_ALT,     OS_CTRL,    OS_SHFT,    KC_ENT,                   KC_ENT,    KC_LEFT,     KC_DOWN,    KC_RGHT,     XXXX,       XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │           │    UNDO   │SPACE LEFT │SHFT+CTRL+C│SHFT+CTRL+↓│    TAB    │             │ Backspace │  PAGE UP  │ PAGE DOWN │           │  NUM LOCK │GAME LAYER │*/
          C(KC_V),    C(KC_Z),    SPACE_L,  C(S(KC_C)),C(S(KC_DOWN)), KC_TAB,                   KC_BSPC,    KC_PGUP,    KC_PGDN,    KC_QUOT,     KC_NUM,   TG(_GAM),
    /* └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘             └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘*/
    /*                                          ┌───────────┬───────────┬───────────┐   ┌───────────┬───────────┐                                                     */
    /*                                          │           │           │ CMD LAYER │   │CTRL+SPACE │           │                                                     */
                                                   _______,    _______,    LA_CMD,        C(KC_SPC),   _______,
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
    /* │           │           │           │           │           │           │             │           │           │           │           │           │           │*/  
           XXXX,     MEH(KC_Q),  MEH(KC_W),  MEH(KC_E),  MEH(KC_R), C(S(KC_UP)),               MEH(KC_Y),   KC_VOLD,    KC_MUTE,    KC_VOLU,   MEH(KC_P),    XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │           │     ~     │           │     '     │     "     │     -     │             │     +     │MEDIA PREV │MEDIA PAUSE│MEDIA NEXT │           │           │*/
           XXXX,     MEH(KC_A),  MEH(KC_S),  MEH(KC_D),  MEH(KC_F),C(S(KC_DOWN)),              MEH(KC_H),   KC_MPRV,    KC_MPLY,    KC_MNXT,  MEH(KC_SCLN),  XXXX,
    /* ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤             ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤*/
    /* │           │     \     │           │     ;     │     ,     │     _     │             │     =     │     .     │     :     │     |     │     /     │           │*/
           XXXX,     MEH(KC_Z),  MEH(KC_X),  MEH(KC_C),  MEH(KC_V),  C(S(KC_C)),               MEH(KC_N),  MEH(KC_M),MEH(KC_COMM),MEH(KC_DOT),MEH(KC_SLSH),  XXXX,
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
    case KC_BTN1:
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

    if (!lang_shift_process_record(keycode, record))
        return false;

    return true;
}

void user_timer(void) {
    lang_shift_user_timer();
}
  
void matrix_scan_user(void) {
    user_timer();
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
        case _EN:
        rgb_matrix_sethsv_noeeprom(105, RGB_MATRIX_DEFAULT_SAT, RGB_MATRIX_DEFAULT_VAL);
        break;
    case _EN_S:
        rgb_matrix_sethsv_noeeprom(105, RGB_MATRIX_DEFAULT_SAT, RGB_MATRIX_DEFAULT_VAL / 2);
        break;
    case _RU:
        rgb_matrix_sethsv_noeeprom(85, RGB_MATRIX_DEFAULT_SAT, RGB_MATRIX_DEFAULT_VAL);
        break;
    case _RU_S:
        rgb_matrix_sethsv_noeeprom(85, RGB_MATRIX_DEFAULT_SAT, RGB_MATRIX_DEFAULT_VAL / 2);
        break;
    case _NAV:
        rgb_matrix_sethsv_noeeprom(0, RGB_MATRIX_DEFAULT_SAT, RGB_MATRIX_DEFAULT_VAL);  
        break;
    case _SYM:
        rgb_matrix_sethsv_noeeprom(28, RGB_MATRIX_DEFAULT_SAT, RGB_MATRIX_DEFAULT_VAL);  
        break;
    case _NUM:
        rgb_matrix_sethsv_noeeprom(43, RGB_MATRIX_DEFAULT_SAT, RGB_MATRIX_DEFAULT_VAL); 
        break;
    case _GAM:
        rgb_matrix_sethsv_noeeprom(170, RGB_MATRIX_DEFAULT_SAT, RGB_MATRIX_DEFAULT_VAL); 
        break;
    case _ALT:
        rgb_matrix_sethsv_noeeprom(128, RGB_MATRIX_DEFAULT_SAT, RGB_MATRIX_DEFAULT_VAL); 
        break;
    case _CMD:
        rgb_matrix_sethsv_noeeprom(213, RGB_MATRIX_DEFAULT_SAT, RGB_MATRIX_DEFAULT_VAL); 
        break;
    case _GFN:
        rgb_matrix_sethsv_noeeprom(0, RGB_MATRIX_DEFAULT_SAT, RGB_MATRIX_DEFAULT_VAL); 
        break;      
    default:
        rgb_matrix_sethsv_noeeprom(105, RGB_MATRIX_DEFAULT_SAT, RGB_MATRIX_DEFAULT_VAL); 
        break;
    }

    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(28, 0, bright, 0);
        RGB_MATRIX_INDICATOR_SET_COLOR(35, 0, bright, 0);
    }

    return false;
}