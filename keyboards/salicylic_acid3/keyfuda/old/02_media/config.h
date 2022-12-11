/*
Copyright 2021 Salicylic_Acid

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x04D8
#define PRODUCT_ID      0xE887
#define DEVICE_VER      0x0001
#define MANUFACTURER    Salicylic_Acid
#define PRODUCT         keyfuda02_media

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 14

#define DIRECT_PINS {{ D3, D1, D4, C6, D7, E6, B4, D2, D0, F4, F5, F6, NO_PIN, NO_PIN }}
#define UNUSED_PINS

#define ENCODERS_PAD_A { B1 }
#define ENCODERS_PAD_B { F7 }
#define ENCODER_RESOLUTION 4

/* ws2812 RGB LED */
#define RGB_DI_PIN B3

#ifndef RGBLED_NUM
  #define RGBLED_NUM 1
#endif

#define RGBLIGHT_ANIMATIONS

#ifndef IOS_DEVICE_ENABLE
  #define RGBLIGHT_LIMIT_VAL 180
  #define RGBLIGHT_VAL_STEP 17
#else
  #define RGBLIGHT_LIMIT_VAL 50
  #define RGBLIGHT_VAL_STEP 4
#endif
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17

#if defined(RGBLIGHT_ENABLE) && !defined(IOS_DEVICE_ENABLE)
// USB_MAX_POWER_CONSUMPTION value for naked48 keyboard
//  120  RGBoff, OLEDoff
//  120  OLED
//  330  RGB 6
//  300  RGB 32
//  310  OLED & RGB 32
  #define USB_MAX_POWER_CONSUMPTION 400
#else
  // fix iPhone and iPad power adapter issue
  // iOS device need lessthan 100
  #define USB_MAX_POWER_CONSUMPTION 100
#endif