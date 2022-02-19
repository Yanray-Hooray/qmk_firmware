#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0x7363  // Stream Cheap
#define PRODUCT_ID 0x1213
#define DEVICE_VER 0x0001
#define MANUFACTURER Stream Cheap
#define PRODUCT 2x3

/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 3

/* key matrix pins */
#define MATRIX_ROW_PINS { B4, B5 }
#define MATRIX_COL_PINS { B3, B2, B6 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define TAPPING_TERM 175