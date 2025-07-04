/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"

//MODTAPキーの定義
#define MT_E MT(MOD_LGUI, KC_E)  
#define MT_I MT(MOD_LALT, KC_I)  
#define MT_A MT(MOD_LCTL, KC_A)  
#define MT_O MT(MOD_LSFT, KC_O)  

#define MT_O MT(MOD_LSFT, KC_O)  
#define MT_T MT(MOD_LSFT, KC_T) 
#define MT_N MT(MOD_LCTL, KC_N) 
#define MT_S MT(MOD_LALT, KC_S) 
#define LT_H LT(3, KC_H) 

#define LT_CTRLM LT(3, LCTL(KC_M))




// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_Q     , KC_L     , KC_U     , KC_DOT     , KC_QUESTION     ,                            KC_F     , KC_W     , KC_R     , KC_Y     , KC_P     ,
    MT_E     , MT_I     , MT_A     , MT_O     , KC_COMM     ,                            KC_K     , MT_T     , MT_N     , MT_S     , LT_H  ,
    LSFT_T(KC_Z)     , KC_X     , KC_C     , KC_V     , KC_AT     ,                            KC_G     , KC_D     , KC_M  , KC_J   , LGUI_T(KC_B)  ,
    KC_LGUI  , KC_LALT  , KC_LCTL  ,LSFT_T(KC_TAB),LT_CTRLM,LCTL_T(KC_ENT),KC_BSPC,LT(1,KC_SPC),KC_1,KC_2,KC_3, KC_BTN1
  ),

  [1] = LAYOUT_universal(
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_RBRC  ,                            KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,
    KC_1    , KC_2  , KC_3  ,KC_4, KC_5  ,                           KC_6, KC_7  , KC_8  , KC_9  , KC_0  ,
    S(KC_EQL),S(KC_LBRC),S(KC_7)   , S(KC_2)  ,S(KC_RBRC),                            KC_LBRC  , KC_DLR   , KC_PGDN  , KC_BTN3  , KC_F11   ,
    KC_INT1  , KC_EQL   , S(KC_3)  , _______  , _______  , _______  ,      TO(2)    , TO(0)    , _______  , KC_RALT  , KC_RGUI  , KC_F12
  ),

  [2] = LAYOUT_universal(
    KC_TAB   , KC_7     , KC_8     , KC_9     , KC_MINS  ,                            KC_NUHS  , _______  , KC_BTN3  , _______  , KC_BSPC  ,
   S(KC_QUOT), KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                            S(KC_9)  , KC_BTN1  , KC_UP    , KC_BTN2  , KC_QUOT  ,
    KC_SLSH  , KC_1     , KC_2     , KC_3     ,S(KC_MINS),                           S(KC_NUHS), KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  ,
    KC_ESC   , KC_0     , KC_DOT   , KC_DEL   , KC_ENT   , KC_BSPC  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  ,                            _______  , _______  , SSNP_HOR , SSNP_VRT , SSNP_FRE ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , SCRL_DVI ,                            _______  , _______  , _______  , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , SCRL_DVD ,                            CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    QK_BOOT  , KBC_RST  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , KBC_RST  , QK_BOOT
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif



//以下コンボ追記箇所

const uint16_t PROGMEM test_combo1[] = {KC_Y, KC_P, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_Q, KC_L, COMBO_END};
const uint16_t PROGMEM test_combo3[] = {MT_T, MT_N, COMBO_END};
const uint16_t PROGMEM test_combo4[] = {MT_N, MT_S, COMBO_END};
const uint16_t PROGMEM test_combo5[] = {MT_O, KC_COMMA, COMBO_END};
const uint16_t PROGMEM test_combo6[] = {KC_K, MT_T, COMBO_END};
//const uint16_t PROGMEM test_combo7[] = {KC_X, KC_C, COMBO_END};
//const uint16_t PROGMEM test_combo8[] = {KC_M, KC_J, COMBO_END};

combo_t key_combos[] = {
    COMBO(test_combo1, KC_DEL), 
    COMBO(test_combo2, KC_ESC), 
    COMBO(test_combo3, KC_BTN1),
    COMBO(test_combo4, KC_BTN2),
    COMBO(test_combo5, KC_LNG2),
    COMBO(test_combo6, KC_LNG1),
    //COMBO(test_combo7, KC_LNG2),
    //COMBO(test_combo8, KC_LNG1),
};


