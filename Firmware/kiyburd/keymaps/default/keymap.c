// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_TAB, 	KC_Q,		KC_W, 	KC_F, 	KC_P, 	KC_G,   KC_J,	KC_L,	KC_U, 		KC_Y, 	KC_SCLN, 	KC_BSPC, 
		KC_LCTL,	KC_A, 		KC_R, 	KC_S, 	KC_T, 	KC_D,   KC_H, 	KC_N, 	KC_E, 		KC_I, 	KC_O, 		KC_QUOT, 
		KC_LSFT,	KC_Z, 		KC_X,  	KC_C, 	KC_V, 	KC_B, 	KC_K, 	KC_M, 	KC_COMM, 	KC_DOT, KC_SLSH, 	KC_BSLS, 
		KC_LALT,	                	KC_LGUI,MO(1), 	KC_SPC,	MO(2), 	MO(3), 	KC_RALT, 	                	KC_ENT
    ),

    [1] = LAYOUT(
        KC_TAB, 	KC_NO,		KC_NO, 	KC_NO, 	KC_NO, 	KC_NO,    KC_NO,	KC_NO,	KC_NO, 		KC_NO, 	KC_NO, 	    KC_ESC, 
		KC_LCTL,	KC_NO, 		KC_NO, 	KC_NO, 	KC_NO, 	KC_NO,    KC_f1,    KC_f2, 	KC_f3, 		KC_f4, 	KC_f5, 		KC_f6, 
		KC_LSFT,	KC_NO, 		KC_NO,  KC_NO, 	KC_NO, 	KC_NO,    KC_f7,    KC_f8, 	KC_f9,  	KC_f10, KC_f11, 	KC_f12, 
		KC_LALT,	                	KC_LGUI,KC_NO, 	KC_SPC,   MO(2), 	MO(3), 	KC_RALT, 	                	KC_ENT
    ),

    [2] = LAYOUT(
        KC_TAB, 	KC_1,		KC_2, 	KC_3, 	KC_4, 	KC_5,   KC_NO,	KC_NO,	KC_NO, 		KC_NO, 	KC_NO, 	    KC_BSPC, 
		KC_LCTL,	KC_6, 		KC_7, 	KC_8, 	KC_9, 	KC_0,   KC_LEFT, KC_DOWN, 	KC_UP, 	KC_RIGHT, KC_NO, 	KC_NO, 
		KC_LSFT,	KC_GRV, 	KC_MINS,KC_EQL, KC_LBRC,KC_RBRC, KC_NO, 	KC_NO,  	KC_NO, KC_NO, 	KC_NO, 
		KC_LALT,	                	KC_LGUI,MO(1), 	KC_SPC,  KC_NO, MO(3), 	KC_RALT, 	                	KC_ENT
    ),

    [3] = LAYOUT(
        KC_TAB, 	KC_NO,		KC_NO, 	KC_NO, 	KC_NO, 	KC_NO,    KC_NO,	KC_NO,	KC_NO, 		KC_NO, 	KC_NO, 	    KC_ESC, 
		KC_LCTL,	KC_NO, 		KC_NO, 	KC_NO, 	KC_NO, 	KC_NO,    KC_HOME,  KC_INS, KC_DEL, 	KC_END, KC_NO, 		KC_NO, 
		KC_LSFT,	KC_NO, 		KC_NO,  KC_NO, 	KC_NO, 	KC_NO,    KC_NO,    KC_NO, 	KC_NO,  	KC_NO, KC_NO, 	    KC_NO, 
		KC_LALT,	                	KC_LGUI,MO(1), 	KC_SPC,   MO(2), 	KC_NO, 	KC_RALT, 	                	KC_ENT
    )
    
    
};
