/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "keymap_norwegian.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion

// Blank template at the bottom

enum customKeycodes {
	URL  = 1
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * | L1/ESC |   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------+------.           .------+------+------+------+------+------+--------|
 * | Tab    |   A  |   S  |  D   |   F  |   G  |  ' § |           |   ´  |   H  |   J  |   K  |   L  |   Ø  |   Æ    |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |  < > |           |   ^  |   N  |   M  |  , ; |  . : | -  _ |  @  *  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .-------.                                 .------.   .-----.
 *                    |   Ctrl   |   |  CMD  |                                 | Space|   | BKSP|
 *                    '----------'   '-------'                                 `------.   '-----'
 *                                        ,-------.                      ,-------.
 *                                        |  ALT  |                      | DEL   |
 *                                 ,------|-------|                      |-------|------.
 *                                 | SYMB | NUMB  |                      |       |      |
 *                                 | Space| Enter |                      | Space | Enter|
 *                                 |      |       |                      |       |      |
 *                                 `--------------'                      `--------------'
 */
[BASE] = LAYOUT_gergo(
     LT(NUMB, KC_ESC),      KC_Q,  KC_W,   KC_E,   KC_R, KC_T,                                          KC_Y,  KC_U, KC_I, KC_O,   KC_P,    NO_AA,
     KC_TAB,                KC_A,  KC_S,   KC_D,   KC_F, KC_G, NO_APOS_MAC,                   NO_ACUT,  KC_H,  KC_J, KC_K, KC_L,   NO_OSLH, NO_AE,
     KC_LSFT,               KC_Z,  KC_X,   KC_C,   KC_V, KC_B, NO_PIPE, KC_LALT,      KC_DEL, NO_CIRC,  KC_N,  KC_M, KC_COMM, KC_DOT, NO_MINS, NO_AT_MAC,
                           KC_LCTL, KC_LCMD, LT(SYMB, KC_SPC), LT(NUMB, KC_ENT),      KC_SPC, KC_ENT,   KC_SPC, KC_BSPC
    ),
/* Keymap 1: Symbols layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  !   |   "  |   #  |   $  |   %  |                         |   &  |   /  |  (   |   )  |  =   |   ?    |
 * |--------+------+------+------+------+------+------.           .------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |   "  |           |      |      |  \   |  {   |  }   |  +   |   ~    |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  |   |  [   |  ]   |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   | DEL |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     |       |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |   ;  |   =   |                     |   =   |   :  |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                            NO_AMPR, NO_SLSH,     NO_LPRN,     NO_RPRN,     NO_EQL,  NO_QUES,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NO_QUO2,                          KC_TRNS, KC_TRNS, NO_BSLS_MAC, NO_LCBR_MAC, NO_RCBR_MAC, NO_PLUS, NO_TILD,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, NO_PIPE_MAC, NO_LBRC,     NO_RBRC,     KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_SCLN, KC_EQL,         KC_EQL,  NO_COLN, KC_TRNS, KC_DEL
    ),
/* Keymap 2: Pad/Function layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                         |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------+------.           .------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  | F3   | F4   | F5   | F6   |           | Home | PGUP |  UP  | PGDN | Mute |VolDn | VolUp  |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |  F7  |  F8  | F9   | F10  | F11  | F12  |           | End  | LEFT | DOWN | RGHT | Prev |Ply/Pa|  Skip  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     |       |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[NUMB] = LAYOUT_gergo(
    KC_TRNS, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         KC_HOME,  KC_PGUP, KC_UP,   KC_PGDN, KC_MUTE, KC_VOLD, KC_VOLU,
    KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,     KC_TRNS, KC_END,   KC_LEFT, KC_DOWN, KC_RGHT, KC_MPRV, KC_MPLY, KC_MNXT,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS
    ),
};

/* Keymap template
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------.           .------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
 */
