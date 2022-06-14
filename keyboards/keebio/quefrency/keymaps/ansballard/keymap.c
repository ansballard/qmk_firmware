#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1

uint8_t layer;

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────────┬─────┐
   * │ESC  │  1  │  2  │  3  │  4  │  5  │  6  │     │  7  │  8  │  9  │  0  │  -  │  =  │ BACKSPACE │E_VOL│
   * ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┘  ┌──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┼─────┤
   * │TAB     │  Q  │  W  │  E  │  R  │  T  │     │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │   \    │ END │
   * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐    └┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┼─────┤
   * │LCTRL    │  A  │  S  │  D  │  F  │  G  │     │  H  │  J  │  K  │  L  │  ;  │  '  │    ENTER    │PgUp │
   * ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┐  └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴───────┬─────┼─────┤
   * │LSHFT       │  Z  │  X  │  C  │  V  │  B  │     │  N  │  M  │  ,  │  .  │  /  │RSHFT     │ UP  │PgDn │
   * ├──────┬─────┴─┬───┴──┬──┴─┬───┴─────┴─────┤     ├─────┴─────┴────┬┴────┬┴────┬┴────┬─────┼─────┼─────┤
   * │      │       │L_GUI │FN1 │   SPACE       │     │      ENTER     │R_ALT│R_GUI│R_CTL│LEFT │DOWN │RIGHT│
   * └──────┴───────┴──────┴────┴───────────────┘     └────────────────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [_BASE] = LAYOUT_65(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, KC_HOME,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
    _______, _______, KC_LGUI, MO(_FN1),KC_SPC,           KC_ENT,  KC_ENT,  KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  /*
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────────┬─────┐
   * │ESC  │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │     │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │ BACKSPACE │E_WH │
   * ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┘  ┌──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┼─────┤
   * │RGB_TGL │RGB_M│  W  │  E  │  R  │  T  │     │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │   \    │ END │
   * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐    └┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┼─────┤
   * │LCTRL    │  A  │LEFT │RIGHT│ UP  │  {  │     │  }  │  J  │  K  │  L  │  ;  │  '  │    ENTER    │PgUp │
   * ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┐  └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴───────┬─────┼─────┤
   * │LSHFT       │  Z  │  X  │  C  │DOWN │  [  │     │  ]  │  M  │  ,  │  .  │  /  │RSHFT     │ UP  │PgDn │
   * ├──────┬─────┴─┬───┴──┬──┴─┬───┴─────┴─────┤     ├─────┴─────┴────┬┴────┬┴────┬┴────┬─────┼─────┼─────┤
   * │      │       │L_GUI │FN1 │   SPACE       │     │      ENTER     │R_ALT│R_GUI│R_CTL│LEFT │DOWN │RIGHT│
   * └──────┴───────┴──────┴────┴───────────────┘     └────────────────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [_FN1] = LAYOUT_65(
    KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC, _______,
    RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_LEFT, KC_RGHT, KC_UP,   KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_DOWN, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
  layer = biton32(layer_state);
  if (layer == _BASE) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
  else if (layer == _FN1) {
    if (clockwise) {
      tap_code(KC_WH_U);
    } else {
      tap_code(KC_WH_D);
    }
  }
  return false;
}
