/* Copyright 2015-2017 Jack Humbert
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

#include QMK_KEYBOARD_H
#include "muse.h"

#define SE_LT   KC_GRV          // <
#define SE_GT   S(SE_LT)        // >
#define SE_PLUS KC_MINS         // +
#define SE_QM   S(SE_PLUS)      // ?
#define SE_ACUT KC_EQL          // ´
#define SE_APOS  KC_BSLS        // '
#define SE_ASTR S(SE_APOS)      // *
#define SE_QUOT S(KC_2)         // "
#define SE_AA   KC_LBRC         // å
#define SE_OE   KC_SCLN         // ö
#define SE_AE   KC_QUOT         // ä
#define SE_UMLA KC_RBRC         // ¨
#define SE_TILD A(SE_UMLA)      // ~
#define SE_CIRC S(SE_TILD)      // ^
#define SE_MINS KC_SLSH         // -
#define SE_DEG  S(KC_NUBS)      // °
#define SE_EQL  S(KC_0)         // =
#define SE_PERC S(KC_5)         // %
#define SE_AMPR S(KC_6)         // &
#define SE_LBR  A(KC_8)         // [
#define SE_RBR  A(KC_9)         // ]
#define SE_LCBR S(SE_LBR)       // {
#define SE_RCBR S(SE_RBR)       // }
#define SE_LPRN S(KC_8)         // (
#define SE_RPRN S(KC_9)         // )
#define SE_PIPE A(KC_7)         // |
#define SE_BSLS S(SE_PIPE)      // backslash
#define SE_SLSH S(KC_7)         // /
#define SE_AT   A(KC_2)         // @
#define SE_DLR  A(KC_4)         // $

#define MY_ENT  LSFT_T(KC_ENT)
#define MY_SPC  LSFT_T(KC_SPC)

#define MT_LSFT OSM(MOD_LSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[0] = LAYOUT_preonic_grid( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    SE_PLUS, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  MT_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  SE_MINS, MT_LSFT, \
  KC_LALT, KC_LCTL, KC_LCTL, KC_LGUI, MO(1),   MY_ENT,  KC_SPC,  KC_SPC,  MO(2),   KC_ESC,  _______, _______  \
),

/*
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[1] = LAYOUT_preonic_grid( \
  SE_DEG,  _______, _______, SE_LT,   SE_GT,   _______, _______,    _______,    KC_MUTE,  KC_VOLD,    KC_VOLU, SE_UMLA,  \
  _______, KC_EXLM, SE_SLSH, SE_LBR,  SE_RBR,  SE_ACUT, A(KC_LEFT), KC_PGDN,    KC_PGUP,  A(KC_RGHT), SE_CIRC, SE_TILD,  \
  _______, SE_AT,   SE_DLR,  SE_LPRN, SE_RPRN, SE_QUOT, SE_EQL,     _______,    _______,  _______,    SE_ASTR, _______,  \
  KC_LSFT, SE_QM,   KC_HASH, SE_LCBR, SE_RCBR, SE_APOS, SE_PERC,    SE_AMPR,    SE_LT,    SE_GT,      SE_PIPE, _______,  \
  KC_LALT, KC_LCTL, KC_LCTL, KC_LGUI, _______, KC_ESC,  KC_BSPC,    KC_BSPC,    KC_TAB,   KC_ESC,     _______, MO(3)     \
),

/*
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[2] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_0,    KC_4,    KC_5,    KC_6,    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
  _______, KC_0,    KC_1,    KC_2,    KC_3,    _______, _______, SE_PLUS, SE_MINS, SE_ASTR, SE_SLSH, _______, \
  _______, _______, _______, _______, KC_ESC,  _______, KC_SPC,  KC_SPC,  _______, _______, _______, _______  \
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[3] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,  \
  _______, _______, _______, AU_ON,   AU_OFF,  _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)

/*
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
[ ] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),
*/

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(3);
      } else {
        layer_off(3);
      }
      break;
   }
}

void matrix_scan_user(void) {
}
