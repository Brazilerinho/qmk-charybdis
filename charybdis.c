//#include "rgb_matrix.h"
#include "quantum.h"

/* ┌────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┐ */
/* │    8   │   12   │   16   │   20   │   24   │   28   │           │   35   │   39   │   43   │   47   │   51   │   55   │ */ 
/* │  0,  6 │ 15,  6 │ 30,  0 │ 45,  0 │ 60,  0 │ 75,  0 │           │149,  0 │164,  0 │179,  0 │194,  0 │209,  6 │224,  6 │ */ 
/* ├────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┤ */
/* │    7   │   11   │   15   │   19   │   23   │   27   │           │   34   │   38   │   42   │   46   │   50   │   54   │ */ 
/* │  0, 17 │ 15, 17 │ 30, 12 │ 45, 12 │ 60, 12 │ 75, 12 │           │149, 12 │164, 12 │179, 12 │194, 12 │209, 17 │224, 17 │ */ 
/* ├────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┤ */
/* │    6   │   10   │   14   │   18   │   22   │   26   │           │   33   │   37   │   41   │   45   │   49   │   53   │ */
/* │  0, 29 │ 15, 29 │ 30, 23 │ 45, 23 │ 60, 23 │ 75, 23 │           │149, 23 │164, 23 │179, 23 │194, 23 │209, 29 │224, 29 │ */ 
/* ├────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┤ */
/* │    5   │    9   │   13   │   17   │   21   │   25   │           │   32   │   36   │   40   │   44   │   48   │   52   │ */  
/* │  0, 41 │ 15, 41 │ 30, 35 │ 45, 35 │ 60, 35 │ 75, 35 │           │149, 35 │164, 35 │179, 35 │194, 35 │209, 41 │224, 41 │ */      
/* └────────┴────────┴────────┴────────┴────────┴────────┘           └────────┴────────┴────────┴────────┴────────┴────────┘ */
/*                                ┌────────┬────────┬────────┐   ┌────────┬────────┐                                         */
/*                                │    2   │    3   │    4   │   │   30   │   31   │                                         */
/*                                │ 67, 47 │ 82, 52 │ 97, 58 │   │127, 58 │142, 52 │                                         */
/*                                └────────┼────────┼────────┤   ├────────┼────────┘                                         */
/*                                         │    0   │    1   │   │   29   │                                                  */
/*                                         │ 75, 58 │ 90, 64 │   │142, 64 │                                                  */
/*                                         └────────┴────────┘   └────────┘                                                  */ 

led_config_t g_led_config = { 
    {
    // Key Matrix to LED Index
    { 8, 12, 16, 20, 24, 28 },
    { 7, 11, 15, 19, 23, 27 },
    { 6, 10, 14, 18, 22, 26 },
    { 5, 9, 13, 17, 21, 25 },
    { NO_LED, NO_LED, NO_LED, 2, 3, 4 },
    { NO_LED, NO_LED, NO_LED, NO_LED, 0, 1 },

    { 35, 39, 43, 47, 51, 55 },
    { 34, 38, 42, 46, 50, 54 },
    { 33, 37, 41, 45, 49, 53 },
    { 32, 36, 40, 44, 48, 52 },
    { 30, 31, NO_LED, NO_LED, NO_LED, NO_LED },
    { 29, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    }, {
    // LED Index to Physical Position
    // Left Half
    { 75,  58 }, { 90,  64 }, { 67,  47 }, { 82,  52 }, { 97,  58 }, //Thumb cluster
    {  0,  41 }, {  0,  29 }, {  0,  17 }, {  0,  6 }, 
    { 15,  41 }, { 15,  29 }, { 15,  17 }, { 15,  6 },
    { 30,  35 }, { 30,  23 }, { 30,  12 }, { 30,  0 }, 
    { 45,  35 }, { 45,  23 }, { 45,  12 }, { 45,  0 },
    { 60,  35 }, { 60,  23 }, { 60,  12 }, { 60,  0 },
    { 75,  35 }, { 75,  23 }, { 75,  12 }, { 75,  0 },

    // Right Half
    { 142,  64 }, { 127,  58 }, { 142,  52 }, //Thumb cluster
    { 149,  35 }, { 149,  23 }, { 149,  12 }, { 149,  0 }, 
    { 164,  35 }, { 164,  23 }, { 164,  12 }, { 164,  0 },
    { 179,  35 }, { 179,  23 }, { 179,  12 }, { 179,  0 },
    { 194,  35 }, { 194,  23 }, { 194,  12 }, { 194,  0 },
    { 209,  41 }, { 209,  29 }, { 209,  17 }, { 209,  6 }, 
    { 224,  41 }, { 224,  29 }, { 224,  17 }, { 224,  6 }
    }, {
    // LED Index to Flag
    LED_FLAG_INDICATOR, LED_FLAG_INDICATOR, LED_FLAG_INDICATOR, LED_FLAG_INDICATOR, LED_FLAG_INDICATOR, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_INDICATOR,
    LED_FLAG_INDICATOR, LED_FLAG_INDICATOR, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT
    } 
};
