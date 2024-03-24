// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "wait.h"

//#define MACOS

#define KC_FN0 0x7E40
#define KEY_INDEX(x) (x - KC_FN0)

typedef struct {
    uint16_t keycode1;
    uint16_t keycode2;
    uint16_t keycode3;
    uint16_t keycode4;
} shortcut_t;

const shortcut_t bl_ed_keymaps[32] = {
#ifdef MACOS
    { KC_E,      KC_NO,     KC_NO,    KC_NO },  // 0 KC_BL_ED_EXTRUDE_REGION
    { KC_LSFT,   KC_4,      KC_NO,    KC_NO },  // 1 KC_BL_ED_EXTRUDE_MANIFOLD
    { KC_LSFT,   KC_5,      KC_NO,    KC_NO },  // 2 KC_BL_ED_EXTRUDE_ALONG_NORMALS
    { KC_LSFT,   KC_6,      KC_NO,    KC_NO },  // 3 KC_BL_ED_EXTRUDE_INDIVIDUAL
    { KC_LSFT,   KC_7,      KC_NO,    KC_NO },  // 4 KC_BL_ED_EXTRUDE_TO_CURSOR

    { KC_I,      KC_NO,     KC_NO,    KC_NO },  // 5 KC_BL_ED_INSET_FACES
    { KC_LGUI,   KC_B,      KC_NO,    KC_NO },  // 6 KC_BL_ED_BEVEL
    { KC_LGUI,   KC_R,      KC_NO,    KC_NO },  // 7 KC_BL_ED_LOOP_CUT
    { KC_LSFT,   KC_LGUI,   KC_R,     KC_NO },  // 8 KC_BL_ED_OFFSET_LOOP_CUT
    { KC_K,      KC_NO,     KC_NO,    KC_NO },  // 9 KC_BL_ED_KNIFE
    { KC_LSFT,   KC_8,      KC_NO,    KC_NO },  // 10 KC_BL_ED_BISECT
    { KC_LSFT,   KC_9,      KC_NO,    KC_NO },  // 11 KC_BL_ED_POLY_BUILD
    { KC_LSFT,   KC_0,      KC_NO,    KC_NO },  // 12 KC_BL_ED_SPIN
    { KC_LCTL,   KC_1,      KC_NO,    KC_NO },  // 13 KC_BL_ED_SPIN_DUPLICATES

    { KC_LCTL,   KC_2,      KC_NO,    KC_NO },  // 14 KC_BL_ED_SMOOTH
    { KC_LCTL,   KC_3,      KC_NO,    KC_NO },  // 15 KC_BL_ED_RANDOMIZE
    { KC_LCTL,   KC_4,      KC_NO,    KC_NO },  // 16 KC_BL_ED_EDGE_SLIDE
    { KC_LSFT,   KC_V,      KC_NO,    KC_NO },  // 17 KC_BL_ED_VERTEX_SLIDE
    { KC_LALT,   KC_S,      KC_NO,    KC_NO },  // 18 KC_BL_ED_SHRINK_FATTERN
    { KC_LCTL,   KC_5,      KC_NO,    KC_NO },  // 19 KC_BL_ED_PUSH_PULL
    { KC_LSFT,   KC_LALT,   KC_LGUI,  KC_S  },  // 20 KC_BL_ED_SHEAR
    { KC_LSFT,   KC_LALT,   KC_S,     KC_NO },  // 21 KC_BL_ED_TO_SPHEARE
    { KC_V,      KC_NO,     KC_NO,    KC_NO },  // 22 KC_BL_ED_RIP_REGION
    { KC_LALT,   KC_D,      KC_NO,    KC_NO },  // 23 KC_BL_ED_RIP_EDGE

    { KC_NO, KC_NO, KC_NO, KC_NO },             // 24
    { KC_NO, KC_NO, KC_NO, KC_NO },             // 25
    { KC_NO, KC_NO, KC_NO, KC_NO },             // 26
    { KC_NO, KC_NO, KC_NO, KC_NO },             // 27
    { KC_NO, KC_NO, KC_NO, KC_NO },             // 28
    { KC_NO, KC_NO, KC_NO, KC_NO },             // 29
    { KC_NO, KC_NO, KC_NO, KC_NO },             // 30
    { KC_NO, KC_NO, KC_NO, KC_NO }              // 31
#else
    { KC_E,      KC_NO,     KC_NO,    KC_NO },  // 0 KC_BL_ED_EXTRUDE_REGION
    { KC_LSFT,   KC_4,      KC_NO,    KC_NO },  // 1 KC_BL_ED_EXTRUDE_MANIFOLD
    { KC_LSFT,   KC_5,      KC_NO,    KC_NO },  // 2 KC_BL_ED_EXTRUDE_ALONG_NORMALS
    { KC_LSFT,   KC_6,      KC_NO,    KC_NO },  // 3 KC_BL_ED_EXTRUDE_INDIVIDUAL
    { KC_LSFT,   KC_7,      KC_NO,    KC_NO },  // 4 KC_BL_ED_EXTRUDE_TO_CURSOR

    { KC_I,      KC_NO,     KC_NO,    KC_NO },  // 5 KC_BL_ED_INSET_FACES
    { KC_LCTL,   KC_B,      KC_NO,    KC_NO },  // 6 KC_BL_ED_BEVEL
    { KC_LCTL,   KC_R,      KC_NO,    KC_NO },  // 7 KC_BL_ED_LOOP_CUT
    { KC_LSFT,   KC_LCTL,   KC_R,     KC_NO },  // 8 KC_BL_ED_OFFSET_LOOP_CUT
    { KC_K,      KC_NO,     KC_NO,    KC_NO },  // 9 KC_BL_ED_KNIFE
    { KC_LSFT,   KC_8,      KC_NO,    KC_NO },  // 10 KC_BL_ED_BISECT
    { KC_LSFT,   KC_9,      KC_NO,    KC_NO },  // 11 KC_BL_ED_POLY_BUILD
    { KC_LSFT,   KC_0,      KC_NO,    KC_NO },  // 12 KC_BL_ED_SPIN
    { KC_LCTL,   KC_1,      KC_NO,    KC_NO },  // 13 KC_BL_ED_SPIN_DUPLICATES

    { KC_LCTL,   KC_2,      KC_NO,    KC_NO },  // 14 KC_BL_ED_SMOOTH
    { KC_LCTL,   KC_3,      KC_NO,    KC_NO },  // 15 KC_BL_ED_RANDOMIZE
    { KC_LCTL,   KC_4,      KC_NO,    KC_NO },  // 16 KC_BL_ED_EDGE_SLIDE
    { KC_LSFT,   KC_V,      KC_NO,    KC_NO },  // 17 KC_BL_ED_VERTEX_SLIDE
    { KC_LALT,   KC_S,      KC_NO,    KC_NO },  // 18 KC_BL_ED_SHRINK_FATTERN
    { KC_LCTL,   KC_5,      KC_NO,    KC_NO },  // 19 KC_BL_ED_PUSH_PULL
    { KC_LSFT,   KC_LALT,   KC_LCTL,  KC_S  },  // 20 KC_BL_ED_SHEAR
    { KC_LSFT,   KC_LALT,   KC_S,     KC_NO },  // 21 KC_BL_ED_TO_SPHEARE
    { KC_V,      KC_NO,     KC_NO,    KC_NO },  // 22 KC_BL_ED_RIP_REGION
    { KC_LALT,   KC_D,      KC_NO,    KC_NO },  // 23 KC_BL_ED_RIP_EDGE

    { KC_NO, KC_NO, KC_NO, KC_NO },             // 24
    { KC_NO, KC_NO, KC_NO, KC_NO },             // 25
    { KC_NO, KC_NO, KC_NO, KC_NO },             // 26
    { KC_NO, KC_NO, KC_NO, KC_NO },             // 27
    { KC_NO, KC_NO, KC_NO, KC_NO },             // 28
    { KC_NO, KC_NO, KC_NO, KC_NO },             // 29
    { KC_NO, KC_NO, KC_NO, KC_NO },             // 30
    { KC_NO, KC_NO, KC_NO, KC_NO }              // 31
#endif
};

enum custom_keycodes {
    KC_BL_ED_EXTRUDE_REGION = KC_FN0,   // Func0
    KC_BL_ED_EXTRUDE_MANIFOLD,          // Func1
    KC_BL_ED_EXTRUDE_ALONG_NORMALS,     // Func2
    KC_BL_ED_EXTRUDE_INDIVIDUAL,        // Func3
    KC_BL_ED_EXTRUDE_TO_CURSOR,         // Func4

    KC_BL_ED_INSET_FACES,               // Func5
    KC_BL_ED_BEVEL,                     // Func6
    KC_BL_ED_LOOP_CUT,                  // Func7
    KC_BL_ED_OFFSET_LOOP_CUT,           // Func8
    KC_BL_ED_KNIFE,                     // Func9
    KC_BL_ED_BISECT,                    // Func10
    KC_BL_ED_POLY_BUILD,                // Func11
    KC_BL_ED_SPIN,                      // Func12
    KC_BL_ED_SPIN_DUPLICATES,           // Func13

    KC_BL_ED_SMOOTH,                    // Func14
    KC_BL_ED_RANDOMIZE,                 // Func15
    KC_BL_ED_EDGE_SLIDE,                // Func16
    KC_BL_ED_VERTEX_SLIDE,              // Func17
    KC_BL_ED_SHRINK_FATTERN,            // Func18
    KC_BL_ED_PUSH_PULL,                 // Func19
    KC_BL_ED_SHEAR,                     // Func20
    KC_BL_ED_TO_SPHEARE,                // Func21
    KC_BL_ED_RIP_REGION,                // Func22
    KC_BL_ED_RIP_EDGE,                  // Func23
    KC_BL_ED_END,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌─┬─┬─┐
     * │7 │8 │9 │
     * ├─┼─┼─┤
     * │4 │5 │6 │
     * ├─┼─┼─┤
     * │1 │2 │3 │
     * ├─┼─┼─┤
     * │0 │. │/ │
     * └─┴─┴─┘
     */
    [0] = LAYOUT(
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,
        KC_P1,   KC_P2,   KC_P3,
        KC_P0,   KC_PDOT, KC_PSLS
    ),
    [1] = LAYOUT(
        KC_BL_ED_EXTRUDE_REGION,     KC_BL_ED_EXTRUDE_MANIFOLD,  KC_BL_ED_EXTRUDE_ALONG_NORMALS,
        KC_BL_ED_EXTRUDE_INDIVIDUAL, KC_BL_ED_EXTRUDE_TO_CURSOR, KC_BL_ED_INSET_FACES,
        KC_BL_ED_BEVEL,              KC_BL_ED_LOOP_CUT,          KC_BL_ED_OFFSET_LOOP_CUT,
        KC_BL_ED_KNIFE,              KC_BL_ED_BISECT,            KC_BL_ED_POLY_BUILD
    ),
    [2] = LAYOUT(
        KC_BL_ED_SPIN,           KC_BL_ED_SPIN_DUPLICATES, KC_BL_ED_SMOOTH,
        KC_BL_ED_RANDOMIZE,      KC_BL_ED_EDGE_SLIDE,      KC_BL_ED_VERTEX_SLIDE,
        KC_BL_ED_SHRINK_FATTERN, KC_BL_ED_PUSH_PULL,       KC_BL_ED_SHEAR,
        KC_BL_ED_TO_SPHEARE,     KC_BL_ED_RIP_REGION,      KC_BL_ED_RIP_EDGE
    ),
    [3] = LAYOUT(
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,
        KC_P1,   KC_P2,   KC_P3,
        KC_P0,   KC_PDOT, KC_PSLS
    )
};

static void run_shortcuts(uint16_t keycode)
{
    shortcut_t keymaps = bl_ed_keymaps[KEY_INDEX(keycode)];

    register_code(keymaps.keycode1);
    if (keymaps.keycode2 != KC_NO) register_code(keymaps.keycode2);
    if (keymaps.keycode3 != KC_NO) register_code(keymaps.keycode3);
    if (keymaps.keycode4 != KC_NO) register_code(keymaps.keycode4);
    if (keymaps.keycode4 != KC_NO) unregister_code(keymaps.keycode4);
    if (keymaps.keycode3 != KC_NO) unregister_code(keymaps.keycode3);
    if (keymaps.keycode2 != KC_NO) unregister_code(keymaps.keycode2);
    unregister_code(keymaps.keycode1);

    return;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
        case KC_BL_ED_EXTRUDE_REGION:
        case KC_BL_ED_EXTRUDE_MANIFOLD:
        case KC_BL_ED_EXTRUDE_ALONG_NORMALS:
        case KC_BL_ED_EXTRUDE_INDIVIDUAL:
        case KC_BL_ED_EXTRUDE_TO_CURSOR:
        case KC_BL_ED_INSET_FACES:
        case KC_BL_ED_BEVEL:
        case KC_BL_ED_LOOP_CUT:
        case KC_BL_ED_OFFSET_LOOP_CUT:
        case KC_BL_ED_KNIFE:
        case KC_BL_ED_BISECT:
        case KC_BL_ED_POLY_BUILD:
        case KC_BL_ED_SPIN:
        case KC_BL_ED_SPIN_DUPLICATES:
        case KC_BL_ED_SMOOTH:
        case KC_BL_ED_RANDOMIZE:
        case KC_BL_ED_EDGE_SLIDE:
        case KC_BL_ED_VERTEX_SLIDE:
        case KC_BL_ED_SHRINK_FATTERN:
        case KC_BL_ED_PUSH_PULL:
        case KC_BL_ED_SHEAR:
        case KC_BL_ED_TO_SPHEARE:
        case KC_BL_ED_RIP_REGION:
        case KC_BL_ED_RIP_EDGE:
            if (record->event.pressed) {
                // ショートカット呼び出し：Shift + Space
                register_code(KC_LSFT);
                register_code(KC_SPC);
                unregister_code(KC_SPC);
                unregister_code(KC_LSFT);

                // インターバルを置く
                wait_ms(300);

                // ショートカット実行
                run_shortcuts(keycode);
            }
            return false;
        default:
            return true;   // その他のキーは通常の処理を行う
    }
}
