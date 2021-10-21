#include QMK_KEYBOARD_H

enum custom_keycodes {
  UP_URL = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_4x4(
	KC_ASTR, KC_9,   KC_8,   KC_7,
	KC_SLSH, KC_6,   KC_5,   KC_4,
	KC_PLUS, KC_3,   KC_2,   KC_1,
	KC_MINS, KC_DOT, KC_0,   LT(1, KC_ENT)
    ),
    [1] = LAYOUT_ortho_4x4(
	KC_ESC,  _______, _______, KC_BSPC,
	KC_TAB,  _______, RESET,   _______,
	_______, _______, _______, _______,
	_______, _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case UP_URL:
            if (record->event.pressed) {
                SEND_STRING("http://1upkeyboards.com");
            }
            return false;
            break;
    }
    return true;
}

#ifdef ENCODER_ENABLE
#include "encoder.h"
void encoder_update_user(int8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
}
#endif
