#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */
#include "print.h"

static bool isAltSetBySpecialTab = false;

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  SPECIALTAB,
};

enum custom_layers {
    _BASE,
    _FN1
};

enum {
    TD_GRV_LAYER_2,
    TD_GRV_LAYER_0
};

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_GRV_LAYER_2] = ACTION_TAP_DANCE_LAYER_MOVE(KC_GRV, 2),
    [TD_GRV_LAYER_0] = ACTION_TAP_DANCE_LAYER_MOVE(KC_GRV, 0)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_INS, KC_PGUP, KC_PGDN, TD(TD_GRV_LAYER_2), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_P4, KC_P5, KC_P6, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_P1, KC_P2, KC_P3, KC_PENT, KC_LCTL, LALT_T(KC_LGUI), MO(1), KC_SPC, KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0, KC_PDOT),
	[1] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_END, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LALT(SPECIALTAB), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_UP, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_S), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END, KC_TRNS, KC_TRNS),
	[2] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_INS, KC_PGUP, KC_PGDN, TD(TD_GRV_LAYER_0), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_P4, KC_P5, KC_P6, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_P1, KC_P2, KC_P3, KC_PENT, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0, KC_PDOT)
};

void unregiterAltAfterSpecialTabUsed(uint32_t state) {
  uint8_t layer = -1;
  if(state >= 0) {
      layer = biton32(state);
  }
  else {
      layer = biton32(layer_state);
  }
  bool  isAltOn = get_mods() & MOD_BIT(KC_LALT);
  //printf("Layer: %d, isAltSet: %d, isAltOn: %d\r", layer, isAltSetBySpecialTab, isAltOn);
  if (layer != _FN1 && isAltSetBySpecialTab && isAltOn) {
    //printf("unsetting\r");
    unregister_mods(MOD_LALT);
    isAltSetBySpecialTab = false;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  //print(keycode);
  //unregiterAltAfterSpecialTabUsed(-1);
  switch (keycode) {
    case SPECIALTAB:
      if (record->event.pressed) {
        bool isAltOn = get_mods() & MOD_BIT(KC_LALT);
        if (!isAltOn) {
          register_mods(MOD_LALT);
          isAltSetBySpecialTab = true;
        }
        register_code(KC_TAB);
        unregister_code(KC_TAB);
      }
      return false;
      break;
  }  
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {  
    unregiterAltAfterSpecialTabUsed(state);
    return state;
}
