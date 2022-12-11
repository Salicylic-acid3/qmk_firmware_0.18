/*
Copyright 2020 Salicylic_Acid

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
#include QMK_KEYBOARD_H
#include "keymap_jp.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _QWERTY = 0,
  _FLOCK,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,--------------------------------------------------------------|             |--------------------------------------------------------------.
   TG(_FLOCK),  KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0, JP_MINS, KC_BSPC, \
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
                KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, JP_LBRC, JP_RBRC, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
              KC_LCTRL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                  KC_H,    KC_J,    KC_K,    KC_L, JP_MINS, JP_BSLS,  KC_ENT, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                  KC_N,    KC_M, JP_COMM,  JP_DOT, JP_SLSH,   KC_UP, KC_RSFT, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               KC_ZKHK, KC_LALT,LGUI_T(KC_MHEN),LT(_LOWER,KC_ENT),KC_BSPC,KC_MUTE,KC_DEL,LT(_RAISE,KC_SPC),ALT_T(KC_HENK),KC_LEFT,KC_DOWN,KC_RIGHT  \
          //`-----------------------------------------------------------------------------------------------------------------------------------'
  ),

  [_FLOCK] = LAYOUT( \
  //,--------------------------------------------------------------|             |--------------------------------------------------------------.
      _______, _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, \
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______, _______,          _______, _______, _______,      _______, _______, _______, _______,          _______, _______, _______  \
          //`-----------------------------------------------------------------------------------------------------------------------------------'
  ),

  [_LOWER] = LAYOUT( \
  //,--------------------------------------------------------------|             |--------------------------------------------------------------.
      _______,  KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, \
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               JP_QUOT, JP_EXLM, JP_QUES, JP_LBRC, JP_RBRC, JP_TILD,                 KC_P6,   KC_P7,   KC_P8,   KC_P9, JP_ASTR, JP_SLSH, XXXXXXX, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               JP_QUOT, JP_HASH,  JP_DQT, JP_LPRN, JP_RPRN,   JP_AT,               XXXXXXX,   KC_P4,   KC_P5,   KC_P6, JP_MINS,  JP_EQL,  KC_ENT, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               JP_CIRC, JP_PERC, JP_AMPR, JP_SCLN, JP_COLN, JP_PIPE,                 KC_P0,   KC_P1,   KC_P2,   KC_P3, JP_PLUS,   KC_UP, KC_RSFT, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               KC_ZKHK, _______,          _______,MO(_LOWER),_______,     _______, _______,MO(_RAISE),JP_DOT,          KC_LEFT, KC_DOWN, KC_RIGHT  \
          //`-----------------------------------------------------------------------------------------------------------------------------------'
  ),

  [_RAISE] = LAYOUT( \
  //,--------------------------------------------------------------|             |--------------------------------------------------------------.
      _______,  KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, \
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
                KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,               XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
        LCTL_T(KC_F11), XXXXXXX,   KC_F2,   KC_F3,   KC_F4,   KC_F5,               XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, XXXXXXX, _______, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
         SFT_T(KC_F12),   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, _______, _______, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______, _______,          _______, _______, _______,      _______, _______, _______, _______,          _______, _______, _______  \
          //`-----------------------------------------------------------------------------------------------------------------------------------'
  ),

  [_ADJUST] = LAYOUT( /* Base */
  //,--------------------------------------------------------------|             |--------------------------------------------------------------.
      _______,   RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, \
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX,LCA(KC_DEL),LALT(KC_PSCR),KC_PSCR,XXXXXXX, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
               _______, _______,          _______, _______, _______,      _______, _______, _______, _______,          _______, _______, _______  \
          //`-----------------------------------------------------------------------------------------------------------------------------------'
  )
};

//A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
return state;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_PGUP);
    } else {
        tap_code(KC_PGDN);
    }
}
