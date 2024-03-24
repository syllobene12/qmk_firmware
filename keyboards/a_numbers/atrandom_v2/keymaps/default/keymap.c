// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "wait.h"

enum custom_keycodes {
    KC_BL_SPIN = SAFE_RANGE,
    KC_BL_SPIN_DUP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ 7 │ 8 │ 9 │
     * ├───┼───┼───┤
     * │ 4 │ 5 │ 6 │
     * ├───┼───┼───┤
     * │ 1 │ 2 │ 3 │
     * ├───┼───┼───┤
     * │ 0 │ . │ / │
     * └───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,
        KC_P1,   KC_P2,   KC_P3,
        KC_P0,   KC_PDOT, KC_PSLS
    ),
    [1] = LAYOUT(
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,
        KC_P1,   KC_P2,   KC_P3,
        KC_P0,   KC_BL_SPIN, KC_BL_SPIN_DUP
    ),
};

static void multiple(uint16_t keycode1, uint16_t keycode2)
{
    register_code(keycode1);
    register_code(keycode2);
    unregister_code(keycode2);
    unregister_code(keycode1);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BL_SPIN:
            if (record->event.pressed) {
                multiple(KC_LSFT, KC_SPC);      // Shift + Space
                wait_ms(300);
                multiple(KC_LSFT, KC_0);        // Shift + 0
            } else 
            return false;
        case KC_BL_SPIN_DUP:
            if (record->event.pressed) {
                multiple(KC_LSFT, KC_SPC);      // Shift + Space
                wait_ms(300);
                multiple(KC_LCTL, KC_1);        // Ctrl + 1
            }
            return false;  // キーのイベントをQMKに通知しない
        default:
            return true;   // その他のキーは通常の処理を行う
    }
}
