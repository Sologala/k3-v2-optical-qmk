/*
Copyright 2020 Dimitris Mantzouranis
Copyright 2022 Pablo Ramirez

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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
  WIN_BASE,
  WIN_FN
};

#define KC_TASK LGUI(KC_TAB)        // Task viewer
#define KC_FLXP LGUI(KC_E)          // Windows file explorer
#define KC_SNIP LGUI(LSFT(KC_S))    // Windows snip tool

#define KC_MSSN LGUI(KC_F3)         // Mission Control
#define KC_FIND LALT(LGUI(KC_SPC))  // Finder
#define KC_MSCR LSFT(LGUI(KC_3))    // Mac screenshot
#define KC_MSNP LSFT(LGUI(KC_4))    // Mac snip tool

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*  Windows base layout
    +------------------------------------------------------------------------------+
    | ESC| F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| F11| F12|PSCR|INS| DEL|
    +------------------------------------------------------------------------------+
    |  ~ |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = | BACKSP |PGUP|
    +------------------------------------------------------------------------------+
    |  TAB |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |      |PGDN|
    +-------------------------------------------------------------------  RET -----+
    |CAPSLCK|  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; |  ' |  # |     |HOME|
    +------------------------------------------------------------------------------+
    |LSHFT|  \ |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / | RSHIFT| UP | END|
    +------------------------------------------------------------------------------+
    |LCTRL| LGUI| LALT|            SPACE            | RALT| FN |RCTL|LEFT|DOWN|RGHT|
    +------------------------------------------------------------------------------+
*/
  [WIN_BASE] = LAYOUT_75_iso(
  /*  0          1          2          3        4        5        6         7        8        9          10          11          12         13         14         15        */
      KC_ESC,    KC_F1,     KC_F2,     KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,     KC_F10,     KC_F11,     KC_F12,    KC_PSCR,   KC_INS,    KC_DEL    ,
      KC_ESC,    KC_1,      KC_2,      KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,      KC_0,       KC_MINS,    KC_EQL,    KC_BSPC,              KC_PGUP   ,
      KC_TAB,    KC_Q,      KC_W,      KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,      KC_P,       KC_LBRC,    KC_RBRC,                         KC_PGDN   ,
   MO(WIN_FN),   KC_A,      KC_S,      KC_D,    KC_F,    KC_G,    KC_H,     KC_J,    KC_K,    KC_L,      KC_SCLN,    KC_QUOT,    KC_NUHS,   KC_ENT,               KC_HOME   ,
      KC_LSFT,   KC_NUBS,   KC_Z,      KC_X,    KC_C,    KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM,   KC_DOT,     KC_SLSH,               KC_RSFT,   KC_UP,     KC_END    ,
      KC_LALT,   KC_LGUI,   KC_LCTL,                              KC_SPC,                                KC_LGUI,    MO(WIN_FN), KC_RCTL,   KC_LEFT,   KC_DOWN,   KC_RGHT
  ),

/*  Windows Fn overlay
    +------------------------------------------------------------------------------+
    | RST|BRID|BRIU|TASK|FLXP|RVAD|RVAI|MPRV|MPLY|MNXT|MUTE|VOLD|VOLU|   |RTOG|RMOD|
    +------------------------------------------------------------------------------+
    |    |    |    |    |    |    |    |    |    |    |    |    |    |        |RM_P|
    +------------------------------------------------------------------------------+
    |      |    |    |    |    |    |    |    |    |    |    |    |    |      |    |
    +-------------------------------------------------------------------      -----+
    |       |    |    |    |    |    |    |    |    |    |    |    |    |     |    |
    +------------------------------------------------------------------------------+
    |     |    |    |    |    |    |    |    |    |    |    |    |       |RSAI|    |
    +------------------------------------------------------------------------------+
    |     |     |     |                             |     |    |    |RHUD|RSAD|RHUI|
    +------------------------------------------------------------------------------+
*/
  [WIN_FN] = LAYOUT_75_iso(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15         */
      RESET,      KC_BRID,    KC_BRIU,    KC_TASK,    KC_FLXP,    RGB_VAD,    RGB_VAI,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD,    KC_VOLU,    _______,    RGB_TOG,    RGB_MOD    ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                RGB_M_P    ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_HOME,    _______,    KC_END,     _______,    _______,    _______,                            _______    ,
      _______,    _______,    _______,    _______,    _______,    _______,    KC_LEFT,    KC_DOWN,      KC_UP,    KC_RGHT,    _______,    _______,    _______,    _______,                _______    ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    RGB_SAI,    _______    ,
      _______,    _______,    _______,                                   EEPROM_RESET,                                        _______,    _______,    _______,    RGB_HUD,    RGB_SAD,    RGB_HUI
  ),
};

bool dip_switch_update_user(uint8_t index, bool active) {
  switch(index) {
    case 0: // OS switch
      if (active) { // Mac/iOS mode
          rgblight_enable_noeeprom();
      }
      else { // Windows/Android mode
          rgblight_disable_noeeprom();
      }
      break;
    case 1: // Connection switch
      // Probably it's not possible to do anything sensible here as switching from Cable to BT requires turning off the board. (BT / OFF / Cable)
      if (active) { // BT mode
        // do stuff
      }
      else { //Cable mode
        // do stuff
      }
      break;
  }
  return true;
}

void keyboard_post_init_user(void) {
}
