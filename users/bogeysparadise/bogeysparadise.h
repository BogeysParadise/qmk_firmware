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

#pragma once
#include "eeprom.h"
#include "wrappers.h"
#include "process_records.h"
#include <stdbool.h>

#ifdef TAP_DANCE_ENABLE
  #include "tap_dances.h"
#endif

#ifdef RGBLIGHT_ENABLE
  #include "rgb_stuff.h"
#endif

#ifdef RGB_MATRIX_ENABLE
  #include "rgb_matrix_stuff.h"
#endif

#ifdef OLED_DRIVER_ENABLE
  #include "oled_stuff.h"
#endif

#ifdef ENCODER_ENABLE
  bool left_encoder_rotated;
  bool right_encoder_rotated;
  uint16_t encoder_rotated_timer;
#endif

/* Define layer names */
//*enum userspace_layers {
//    _QWERTY  = 0,
//    _MODS,
//    _LOWER,
//    _RAISE,
//    _ADJUST,
//};

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _NUMPAD 4

#define _MOUSE _MACROS

bool          mod_key_press_timer(uint16_t code, uint16_t mod_code, bool pressed);
bool          mod_key_press(uint16_t code, uint16_t mod_code, bool pressed, uint16_t this_timer);
void          matrix_init_keymap(void);
void          matrix_init_secret(void);
void          shutdown_keymap(void);
void          suspend_power_down_keymap(void);
void          suspend_wakeup_init_keymap(void);
void          matrix_scan_keymap(void);
void          matrix_scan_secret(void);
layer_state_t layer_state_set_keymap(layer_state_t state);
layer_state_t default_layer_state_set_keymap(layer_state_t state);
void          led_set_keymap(uint8_t usb_led);
void          eeconfig_init_keymap(void);
bool          hasAllBitsInMask(uint8_t value, uint8_t mask);

// Shortcut Keys
#define K_LOCK LGUI(LCTL(KC_Q)) // Locks screen on MacOS
#define K_CSCN LGUI(LCTL(LSFT(KC_4))) // Copy a portion of the screen to the clipboard

// Layer Keys
#define LT_LOW LT(_LOWER, KC_ENT)
#define LT_RAI LT(_RAISE, KC_SPC)

// Mod-Tap Keys
#define MT_DEL MT(MOD_LALT | MOD_LSFT, KC_DEL)
#define MT_EQL MT(MOD_RSFT, KC_EQL)

// clang-format off
typedef union {
    uint32_t raw;
    struct {
        bool    rgb_layer_change     :1;
        bool    swapped_numbers      :1;
        bool    rgb_matrix_idle_anim :1;
    };
} userspace_config_t;
// clang-format on

extern userspace_config_t userspace_config;
