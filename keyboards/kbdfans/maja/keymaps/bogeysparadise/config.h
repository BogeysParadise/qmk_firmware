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

/*#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_ANIMATIONS
#    define RGBLIGHT_SLEEP
#    define RGBLIGHT_LIMIT_VAL 200
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    define RGBLIGHT_SPLIT
#    define RGBLIGHT_LAYERS
#endif
*/

//Undefine the RGB matrix disables in the Keyboard config.h

#undef DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#undef DISABLE_RGB_MATRIX_BAND_SAT
#undef DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#undef DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#undef DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#undef DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#undef DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#undef DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#undef DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#undef DISABLE_RGB_MATRIX_SPLASH
#undef DISABLE_RGB_MATRIX_MULTISPLASH
#undef DISABLE_RGB_MATRIX_SOLID_SPLASH
#undef DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#undef DISABLE_RGB_MATRIX_DIGITAL_RAIN

#undef RGB_MATRIX_STARTUP_MODE

#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SPLASH


//#define RGB_MATRIX_STARTUP_HUE 0x50
//#define RGB_MATRIX_STARTUP_SPD 0xba

