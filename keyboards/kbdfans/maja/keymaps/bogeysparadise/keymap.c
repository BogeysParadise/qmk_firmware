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
#define LAYOUT_wrapper(...)            LAYOUT(__VA_ARGS__)
#define LAYOUT_maja_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, \
    K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A \
  ) \
  LAYOUT_wrapper( \
        KC_GESC, K01,     K02,     K03,     K04,     K05,     K06,              K07,     K08,     K09,     K0A,     KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL, \
        KC_TAB,  K11,     K12,     K13,     K14,     K15,              K16,     K17,     K18,     K19,     K1A,     KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP, \
        KC_CAPS, K21,     K22,     K23,     K24,     K25,              K26,     K27,     K28,     K29,     K2A,     K2B,     KC_ENT,                    KC_PGDN, \
        KC_LSPO, K31,     K32,     K33,     K34,     K35,              KC_B,    K36,     K37,     K38,     K39,     K3A,     KC_RSPC,          KC_UP, \
        KC_LCTL,          KC_LGUI, KC_SPC,  KC_LALT,                            KC_SPC,           MO(1),                              KC_LEFT, KC_DOWN, KC_RGHT \
    )

/* Re-pass though to allow templates to be used */

#define LAYOUT_maja_base_wrapper(...)       LAYOUT_maja_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_maja_base_wrapper(
        ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________,
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),

    [_LOWER] = LAYOUT_wrapper(
        _______, _________________FUNC_LEFT_________________, _________________FUNC_RIGHT________________,          _______, _______, _______,          KC_MUTE,
        _______, _________________ADJUST_L1_________________,          _______, _______, _______, _______, _______, _______, _______, _______,          KC_VOLU,
        _______, _________________ADJUST_L2_________________,          _______, _______, _______, _______, _______, _______, _______,                   KC_VOLD,
        _______, _________________ADJUST_L3_________________,          _______, _______, _______, _______, _______, _______, _______,          KC_PGUP,
        _______,          _______, _______, _______,                            _______,          _______,                            KC_HOME, KC_PGDN, KC_END
    ),

    [_RAISE] = LAYOUT_wrapper(
        _______, _________________FUNC_LEFT_________________, _________________FUNC_RIGHT________________,          _______, _______, _______,          KC_MUTE,
        _______, _________________ADJUST_L1_________________,          _______, _______, _______, _______, _______, _______, _______, _______,          KC_VOLU,
        _______, _________________ADJUST_L2_________________,          _______, _______, _______, _______, _______, _______, _______,                   KC_VOLD,
        _______, _________________ADJUST_L3_________________,          _______, _______, _______, _______, _______, _______, _______,          KC_PGUP,
        _______,          _______, _______, _______,                            _______,          _______,                            KC_HOME, KC_PGDN, KC_END
    ),
    [_ADJUST] = LAYOUT_wrapper(
        _______, _________________FUNC_LEFT_________________, _________________FUNC_RIGHT________________,          _______, _______, _______,          KC_MUTE,
        _______, _________________ADJUST_L1_________________,          _______, _______, _______, _______, _______, _______, _______, _______,          KC_VOLU,
        _______, _________________ADJUST_L2_________________,          _______, _______, _______, _______, _______, _______, _______,                   KC_VOLD,
        _______, _________________ADJUST_L3_________________,          _______, _______, _______, _______, _______, _______, _______,          KC_PGUP,
        _______,          _______, _______, _______,                            _______,          _______,                            KC_HOME, KC_PGDN, KC_END
    ),

//     [_LAYERINDEX] = LAYOUT_wrapper(
//       _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,          _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,          _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,                   _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,          _______,
//       _______,          _______, _______, _______,                            _______,          _______,                            _______, _______, _______
//     ),
};
// clang-format on


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
