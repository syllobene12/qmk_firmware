// Copyright 2023 syllobene12 (@syllobene12)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0x414e
#define PRODUCT_ID      0x0041
#define DEVICE_VER      0x0001
#define MANUFACTURER    syllobene12 
#define PRODUCT         ATRANDOM

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* key matrix size */
#define MATRIX_COLS 3
#define MATRIX_ROWS 4

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_COL_PINS { F4, F6, B4 }
#define MATRIX_ROW_PINS { D4, B3, D7, B6 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW
