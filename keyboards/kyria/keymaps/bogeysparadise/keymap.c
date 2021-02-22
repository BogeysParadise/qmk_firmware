/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "bogeysparadise.h"

uint8_t is_master;

#ifndef UNICODE_ENABLE
#    define UC(x) KC_NO
#endif

//Setup Space Cadet Shifts

//#define LSPO_KEYS(KC_LSFT, KC_LSFT, KC_9)
//#define RSPO_KEYS(KC_RSFT, KC_RSFT, KC_0)

/*
 * The `LAYOUT_kyria_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_kyria_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
      KC_GESC,  K01,     K02,     K03,     K04,     K05,                                             K06,     K07,     K08,     K09,     K0A,     KC_BSPC, \
   LALT_T(KC_TAB), K11, K12,     K13,     K14,     K15,                                             K16,     K17,     K18,     K19,     K1A, RALT_T(KC_QUOT), \
      KC_LSPO, CTL_T(K21), K22,  K23,     K24,     K25,  TG_MODS, MEH(KC_MINS),  KC_CAPS,  ADJUST, K26,     K27,     K28,     K29, RCTL_T(K2A), KC_RSPC, \
                                 KC_MUTE, OS_LALT, OS_LGUI,  KC_SPC,  SP_LWER,     SP_RAIS, KC_SPC,  KC_ENT, UC_IRNY, UC_SHRG \
    )

/* Re-pass though to allow templates to be used */

#define LAYOUT_kyria_base_wrapper(...)       LAYOUT_kyria_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_kyria_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),

    [_MODS] = LAYOUT_wrapper(
        _______, ___________________BLANK___________________,                                       ___________________BLANK___________________, _______,
        _______, ___________________BLANK___________________,                                       ___________________BLANK___________________, _______,
        KC_LSFT, ___________________BLANK___________________, _______, _______,   _______, _______, ___________________BLANK___________________, KC_RSFT,
                                   _______, KC_LALT, KC_LGUI, _______, _______,   _______, _______, _______, _______, _______
    ),

    [_LOWER] = LAYOUT_wrapper(
        KC_F12,  _________________LOWER_L1__________________,                                       _________________LOWER_R1__________________, KC_F11,
        _______, _________________LOWER_L2__________________,                                       _________________LOWER_R2__________________, KC_PIPE,
        _______, _________________LOWER_L3__________________, _______, _______,   _______, _______, _________________LOWER_R3__________________, _______,
                                   _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT_wrapper(
        KC_F12,  _________________RAISE_L1__________________,                                       _________________RAISE_R1__________________, KC_F11,
        _______, _________________RAISE_L2__________________,                                       _________________RAISE_R2__________________, KC_BSLS,
        _______, _________________RAISE_L3__________________, _______, _______,   _______, _______, _________________RAISE_R3__________________, _______,
                                   _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT_wrapper(
        KC_MAKE, _________________ADJUST_L1_________________,                                       _________________ADJUST_R1_________________, KC_RESET,
        VRSN,    _________________ADJUST_L2_________________,                                       _________________ADJUST_R2_________________, EEP_RST,
        _______, _________________ADJUST_L3_________________, HPT_TOG, HPT_FBK,   MG_NKRO, _______, _________________ADJUST_R3_________________, TG_MODS,
                                   _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
    ),

//     [_LAYERINDEX] = LAYOUT_wrapper(
//       _______, _______, _______, _______, _______, _______,                                       _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                       _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
//     ),
};
// clang-format on

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifndef SPLIT_KEYBOARD
        if (keycode == RESET && !is_master) {
            return false;
        }
#endif
    }
    return true;
}

void matrix_init_keymap(void) { is_master = (uint8_t)is_keyboard_master(); }

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

// clang-format off

/*#    ifndef SPLIT_TRANSPORT_MIRROR
void oled_driver_render_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}
#    endif
*/
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
#endif

#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM shift_layers[] = RGBLIGHT_LAYER_SEGMENTS(
    {  8, 1, 120, 255, 255},
    { 18, 1, 120, 255, 255}
);

const rgblight_segment_t PROGMEM control_layers[] = RGBLIGHT_LAYER_SEGMENTS(
    {  6, 1, 0, 255, 255},
    { 16, 1, 0, 255, 255}
);

const rgblight_segment_t PROGMEM alt_layers[] = RGBLIGHT_LAYER_SEGMENTS(
    {  2, 1, 240, 255, 255},
    { 17, 1, 250, 255, 255}
);

const rgblight_segment_t PROGMEM gui_layers[] = RGBLIGHT_LAYER_SEGMENTS(
    {  7, 1, 51, 255, 255},
    { 12, 1, 51, 255, 255}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    shift_layers,
    control_layers,
    alt_layers,
    gui_layers
);

void keyboard_post_init_keymap(void) {
    rgblight_layers = my_rgb_layers;
}

void matrix_scan_keymap(void) {
        uint8_t mods = mod_config(get_mods()|get_oneshot_mods());
        rgblight_set_layer_state(0, mods & MOD_MASK_SHIFT);
        rgblight_set_layer_state(1, mods & MOD_MASK_CTRL);
        rgblight_set_layer_state(2, mods & MOD_MASK_ALT);
        rgblight_set_layer_state(3, mods & MOD_MASK_GUI);
}
#endif
