// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    /* Qwerty
 * ,-----------------------------------------.     .-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | LCtrl|   A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |   \  |
 * |------+------'------+------+------+------|     |------+------+------+------'------+------|
 * | LAlt |             | GUI  |Lower |Space |     | Raise|Raise2| RAlt |             |Enter |
 * `------'             '--------------------'     '--------------------'             '------'
 */

    [0] = LAYOUT(
        KC_TAB, 	KC_Q,		KC_W, 	KC_E, 	KC_R, 	KC_T,   KC_Y,	KC_U,	KC_I, 		KC_O, 	KC_P, 	    KC_BSPC, 
		KC_LCTL,	KC_A, 		KC_S, 	KC_D, 	KC_F, 	KC_G,   KC_H, 	KC_J, 	KC_K, 		KC_L, 	KC_SCLN, 	KC_QUOT, 
		KC_LSFT,	KC_Z, 		KC_X,  	KC_C, 	KC_V, 	KC_B, 	KC_N, 	KC_M, 	KC_COMM, 	KC_DOT, KC_SLSH, 	KC_BSLS, 
		KC_LALT,	                	KC_LGUI,MO(1), 	KC_SPC,	MO(2), 	MO(3), 	KC_RALT, 	                	KC_ENT
    ),


/* Lower
 * ,-----------------------------------------.     .-----------------------------------------.
 * | Tab  |      |      |      |      |      |     |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | LCtrl|      |      |      |      |      |     |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |     |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------'------+------+------+------|     |------+------+------+------'------+------|
 * | LAlt |             | GUI  |Lower |Space |     | Raise|Raise2| RAlt |             |Enter |
 * `------'             '--------------------'     '--------------------'             '------'
 */

    [1] = LAYOUT(
        KC_TAB, 	KC_NO,		KC_NO, 	KC_NO, 	KC_NO, 	KC_NO,    KC_NO,	KC_NO,	KC_NO, 		KC_NO, 	KC_NO, 	    KC_ESC, 
		KC_LCTL,	KC_NO, 		KC_NO, 	KC_NO, 	KC_NO, 	KC_NO,    KC_F1,    KC_F2, 	KC_F3, 		KC_F4, 	KC_F5, 		KC_F6, 
		KC_LSFT,	KC_NO, 		KC_NO,  KC_NO, 	KC_NO, 	KC_NO,    KC_F7,    KC_F8, 	KC_F9,  	KC_F10, KC_F11, 	KC_F12, 
		KC_LALT,	                	KC_LGUI,KC_NO, 	KC_SPC,   MO(2), 	MO(3), 	KC_RALT, 	                	KC_ENT
    ),


/* Raise
 * ,-----------------------------------------.     .-----------------------------------------.
 * | Tab  |   1  |   2  |  3   |  4   |   5  |     |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | LCtrl|   6  |   7  |  8   |  9   |   0  |     | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Shift|   `  |   -  |  =   |  [   |   ]  |     |      |      |      |      |      |      |
 * |------+------'------+------+------+------|     |------+------+------+------'------+------|
 * | LAlt |             | GUI  |Lower |Space |     | Raise|Raise2| RAlt |             |Enter |
 * `------'             '--------------------'     '--------------------'             '------'
 */

    [2] = LAYOUT(
        KC_TAB, 	KC_1,		KC_2, 	KC_3, 	KC_4, 	KC_5,   KC_NO,	 KC_NO,	    KC_NO, 		KC_NO, 	    KC_NO, 	KC_BSPC, 
		KC_LCTL,	KC_6, 		KC_7, 	KC_8, 	KC_9, 	KC_0,   KC_LEFT, KC_DOWN, 	KC_UP, 	    KC_RIGHT,   KC_NO, 	KC_NO, 
		KC_LSFT,	KC_GRV, 	KC_MINS,KC_EQL, KC_LBRC,KC_RBRC,KC_NO, 	 KC_NO,  	KC_NO,      KC_NO, 	    KC_NO,  KC_NO,
		KC_LALT,	                	KC_LGUI,MO(1), 	KC_SPC, KC_NO,   MO(3), 	KC_RALT, 	                	KC_ENT
    ),


/* Raise 2
 * ,-----------------------------------------.     .-----------------------------------------.
 * | Tab  |   !  |   @  |  #   |  $   |   %  |     |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | LCtrl|   ^  |   &  |  *   |  (   |   )  |     | Home |Insert|Delete|  End |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Shift|   ~  |   _  |  +   |  {   |   }  |     |      |      |      |      |      |      |
 * |------+------'------+------+------+------|     |------+------+------+------'------+------|
 * | LAlt |             | GUI  |Lower |Space |     | Raise|Raise2| RAlt |             |Enter |
 * `------'             '--------------------'     '--------------------'             '------'
 */

    [3] = LAYOUT(
        KC_TAB, 	KC_EXCLAIM,     	KC_AT, 	        KC_HASH,        KC_DOLLAR,KC_PERCENT,   KC_NO,	             KC_NO,	   KC_NO, 	KC_NO, 	KC_NO, 	            KC_ESC, 
		KC_LCTL,	KC_CIRCUMFLEX, 	    KC_AMPERSAND, 	KC_ASTERISK, 	KC_LEFT_PAREN, 	        KC_RIGHT_PAREN,      KC_HOME,  KC_INS,  KC_DEL, KC_END, KC_NO, 		KC_NO, 
		KC_LSFT,	KC_TILDE, 		    KC_UNDERSCORE,  KC_PLUS, 	    KC_LEFT_CURLY_BRACE, 	KC_RIGHT_CURLY_BRACE,KC_NO,    KC_NO, 	KC_NO,  KC_NO, KC_NO, 	    KC_NO, 
		KC_LALT,	                	                KC_LGUI,        MO(1), 	                KC_SPC,              MO(2),    KC_NO, 	KC_RALT, 	                KC_ENT
    )
    
    
};
