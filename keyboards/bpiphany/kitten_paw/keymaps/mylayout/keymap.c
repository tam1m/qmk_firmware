#include QMK_KEYBOARD_H
#include <print.h>

/*
 * Matrix col/row mapping
 *
 * ,----.    ,-------------------. ,-------------------. ,-------------------. ,--------------.
 * | J6 |    | I4 | H4 | H2 | H6 | | A7 | E6 | D2 | D4 | | B4 | B7 | B6 | B0 | | C7 | C5 | A5 |
 * `----'    `-------------------' `-------------------' `-------------------' `--------------'
 * ,-------------------------------------------------------------------------. ,--------------. ,-------------------.
 * | J4 | J7 | I7 | H7 | G7 | G4 | F4 | F7 | E7 | D7 | R7 | R4 | E4 |     B2 | | L4 | O4 | Q4 | | K1 | L1 | Q1 | Q0 |
 * |-------------------------------------------------------------------------| |--------------| |-------------------|
 * | J2   | J5 | I5 | H5 | G5 | G2 | F2 | F5 | E5 | D5 | R5 | R2 | E2 |   B3 | | K4 | O7 | Q7 | | K5 | L5 | Q5 | O5 |
 * |-------------------------------------------------------------------------| '--------------' |--------------     |
 * | O5    | J3 | I3 | H3 | G3 | G6 | F6 | F3 | E3 | D3 | R3 | R6 |       B1 |                  | K2 | L2 | Q2 |    |
 * |-------------------------------------------------------------------------|      ,----.      |-------------------|
 * | N2 | I6 | J1 | I1 | H1 | G1 | G0 | F0 | F1 | E1 | D1 | R0 |          N3 |      | O6 |      | K3 | L3 | Q3 | O3 |
 * |-------------------------------------------------------------------------| ,--------------. |--------------     |
 * | A4 | P2 | C6 |                  K6                  | C0 | M3 | D0 | A1 | | O0 | K0 | L0 | | L6      | Q6 |    |
 * `-------------------------------------------------------------------------' `--------------' `-------------------'
 */


//layers
enum layers {
    DEFAULT,
    MEDIA,
};


//Tap Dance Declarations
enum tapdance {
  TD_WIN_LOCK
};


//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
   //TD(TD_WIN_LOCK)
  [TD_WIN_LOCK]  = ACTION_TAP_DANCE_DOUBLE(MAGIC_NO_GUI, MAGIC_UNNO_GUI)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEFAULT] = LAYOUT_fullsize_ansi(
            KC_ESC,            KC_F1,  KC_F2,  KC_F3,  KC_F4,     KC_F5,  KC_F6,  KC_F7,  KC_F8,         KC_F9,  KC_F10,  KC_F11,  KC_F12,      KC_PSCR, KC_SLCK, KC_PAUS,

            KC_GRV,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0, KC_MINS, KC_EQL,           KC_BSPC,       KC_INS, KC_HOME, KC_PGUP,      KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS,

            KC_TAB,       KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,    KC_RBRC,  KC_BSLS,       KC_DEL,  KC_END, KC_PGDN,        KC_P7,    KC_P8,    KC_P9,  KC_PPLS,

           KC_CAPS,         KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L, KC_SCLN, KC_QUOT,                KC_ENT,                                        KC_P4,    KC_P5,    KC_P6,

           KC_LSFT,           KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM, KC_DOT, KC_SLSH,                      KC_RSFT,                 KC_UP,                 KC_P1,    KC_P2,    KC_P3,  KC_PENT,

           KC_LCTL,KC_LGUI, KC_LALT,                             KC_SPC,                         KC_RALT, KC_RGUI, LT(1,KC_APP),  KC_RCTL,      KC_LEFT,  KC_DOWN,  KC_RGHT,      KC_P0,  KC_PDOT
  ),

  [MEDIA] = LAYOUT_fullsize_ansi(
            RESET,             KC_NO,  KC_NO,  KC_NO,  KC_NO,     KC_NO,  KC_NO,  KC_NO,  KC_NO,        KC_NO,   KC_NO,   KC_NO,    KC_NO,        KC_NO,   KC_NO,   KC_NO,

            KC_NO,     KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO, KC_NO,    KC_NO,             KC_NO,        KC_NO,   KC_NO,   KC_NO,        KC_NO,    KC_NO,    KC_NO,    KC_NO,

            KC_NO,       KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,  KC_NO,      KC_NO,      KC_NO,    KC_NO,      KC_MPRV,   KC_NO, KC_MNXT,        KC_NO,    KC_NO,    KC_NO,    KC_NO,

            KC_NO,         KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,  KC_NO,   KC_NO,                 KC_NO,                                        KC_NO,    KC_NO,    KC_NO,

            KC_NO,           KC_NO,  KC_NO,   KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,                      KC_LOCK,               KC_MPLY,                 KC_NO,    KC_NO,    KC_NO,    KC_NO,

            KC_NO, MAGIC_UNNO_GUI, KC_NO,                         KC_NO,                                KC_NO, MAGIC_NO_GUI, KC_NO, KC_NO,       KC_VOLD, KC_MUTE, KC_VOLU,       KC_NO,    KC_NO
  )
};


layer_state_t layer_state_set_user(layer_state_t state){
    return state;
}


void led_set_user(uint8_t usb_led) {

    uint8_t layer = biton32(layer_state);
    switch (layer) {
//        case DEFAULT:
              // Turn LEDs off in default layer
//            break;
        case MEDIA:
            USB_LED_SCROLL_LOCK_ON;
            break;
    }
}


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

