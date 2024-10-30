/* Copyright 2022 lexbrugman
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

static bool isAltSetBySpecialTab = false;

enum custom_keycodes {
    SPECIALTAB = SAFE_RANGE,
    KVM_1,
    KVM_2,
    KVM_3,
    KVM_4
};

#define KC_STAB LALT(SPECIALTAB)

enum combo_events { KVM_1_COMBO, KVM_2_COMBO, KVM_3_COMBO, KVM_4_COMBO };

const uint16_t PROGMEM kvm1_combo[] = {KC_LALT, KC_1, COMBO_END};
const uint16_t PROGMEM kvm2_combo[] = {KC_LALT, KC_2, COMBO_END};
const uint16_t PROGMEM kvm3_combo[] = {KC_LALT, KC_3, COMBO_END};
const uint16_t PROGMEM kvm4_combo[] = {KC_LALT, KC_4, COMBO_END};

combo_t key_combos[] = {
    [KVM_1_COMBO] = COMBO_ACTION(kvm1_combo),
    [KVM_2_COMBO] = COMBO_ACTION(kvm2_combo),
    [KVM_3_COMBO] = COMBO_ACTION(kvm3_combo),
    [KVM_4_COMBO] = COMBO_ACTION(kvm4_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case KVM_1_COMBO:
      if (pressed) {
        SEND_STRING(SS_TAP(X_RCTL)SS_DELAY(250)SS_TAP(X_RCTL)SS_DELAY(250)"1");
      }
      break;
    case KVM_2_COMBO:
      if (pressed) {
        SEND_STRING(SS_TAP(X_RCTL)SS_DELAY(250)SS_TAP(X_RCTL)SS_DELAY(250)"2");
      }
      break;
    case KVM_3_COMBO:
      if (pressed) {
        SEND_STRING(SS_TAP(X_RCTL)SS_DELAY(250)SS_TAP(X_RCTL)SS_DELAY(250)"3");
      }
        break;
    case KVM_4_COMBO:
      if (pressed) {
        SEND_STRING(SS_TAP(X_RCTL)SS_DELAY(250)SS_TAP(X_RCTL)SS_DELAY(250)"4");
      }
        break;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_SCRL, KC_PAUS, KC_PGUP, KC_PGDN,
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_HOME, KC_NUM, KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_END, KC_P7, KC_P8, KC_P9, KC_PPLS,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_P4, KC_P5, KC_P6,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_P1, KC_P2, KC_P3, KC_PENT,
        KC_LCTL, KC_LGUI, MO(1), KC_SPC, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0, KC_PDOT
    ),

    [1] = LAYOUT(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, TO(2), KC_PAUS, KC_PGUP, KC_PGDN,
        KC_GRV, KVM_1, KVM_2,    KVM_3,    KVM_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_HOME, KC_NUM, KC_PSLS, KC_PAST, QK_BOOT,
        KC_STAB, KC_Q, KC_W, KC_E, LCTL(KC_R), KC_T, LAG(KC_B), KC_U, KC_I, KC_O, LSG(KC_S), KC_LBRC, KC_RBRC, KC_BSLS, KC_END, KC_P7, KC_P8, KC_P9, KC_PPLS,
        KC_CAPS, LCTL(KC_A), LCTL(KC_S), KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_P4, KC_P5, KC_P6,
        KC_LSFT, LCTL(KC_Z), LCTL(KC_X),  LCTL(KC_C),  LCTL(KC_V), KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_PGUP, KC_P1, KC_P2, KC_P3, KC_PENT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RCTL, KC_HOME, KC_PGDN, KC_END, KC_P0, KC_PDOT
    ),

    [2] = LAYOUT(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, TO(0), KC_PAUS, KC_PGUP, KC_PGDN,
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_HOME, KC_NUM, KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_END, KC_P7, KC_P8, KC_P9, KC_PPLS,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_P4, KC_P5, KC_P6,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_P1, KC_P2, KC_P3, KC_PENT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0, KC_PDOT
    ),
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
  if (layer != 1 && isAltSetBySpecialTab && isAltOn) {
    //printf("unsetting\r");
    unregister_mods(MOD_LALT);
    isAltSetBySpecialTab = false;
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  unregiterAltAfterSpecialTabUsed(state);
  rgblight_config_t rgblight_config;
  switch (biton32(state)) {
    case 0:
        rgblight_enable_noeeprom();
        rgblight_sethsv_at(HSV_PURPLE, 0);
        rgblight_sethsv_at(HSV_PURPLE, 1);
        rgblight_sethsv_at(HSV_PURPLE, 2);
        rgblight_sethsv_at(HSV_PURPLE, 3);
        break;
    case 1:
        rgblight_enable_noeeprom();
        rgblight_sethsv_at(HSV_BLUE, 0);
        rgblight_sethsv_at(HSV_BLUE, 1);
        rgblight_sethsv_at(HSV_BLUE, 2);
        rgblight_sethsv_at(HSV_BLUE, 3);
        break;
    case 2:
        // Red
        rgblight_sethsv_at(HSV_RED, 0);
        rgblight_sethsv_at(HSV_RED, 1);
        rgblight_sethsv_at(HSV_RED, 2);
        rgblight_sethsv_at(HSV_RED, 3);
        break;
    default:
        // White
        // Read RGB Light State
        rgblight_config.raw = eeconfig_read_rgblight();
        // If enabled, set white
        if (rgblight_config.enable) {
            rgblight_sethsv_at(HSV_WHITE, 1);
        } else { // Otherwise go back to disabled
            rgblight_disable_noeeprom();
        }
        break;
  }
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
        case KVM_1:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_RCTL)SS_DELAY(250)SS_TAP(X_RCTL)SS_DELAY(250)"1");
            }
            return false;
            break;
        case KVM_2:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_RCTL)SS_DELAY(250)SS_TAP(X_RCTL)SS_DELAY(250)"2");
            }
            return false;
            break;
        case KVM_3:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_RCTL)SS_DELAY(250)SS_TAP(X_RCTL)SS_DELAY(250)"3");
            }
            return false;
            break;
        case KVM_4:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_RCTL)SS_DELAY(250)SS_TAP(X_RCTL)SS_DELAY(250)"4");
            }
            return false;
            break;
        default:
            return true;  // Process all other keycodes normally
    }
}