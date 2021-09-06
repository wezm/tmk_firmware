#include "action_util.h"

// Used for SHIFT_ESC
#define MODS_CTRL_MASK (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

const uint8_t PROGMEM keymaps[][MATRIX_COLS][MATRIX_ROWS] = {
    /* Layer 0: Standard ANSI layer */
    KEYMAP(\
         ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11,  F12,   PSCR,SLCK,PAUS,                         \
         FN9, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS, EQL,BSPC,   INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS, \
         FN1, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,   DEL, END, PGDN,    P7,  P8,  P9,  PPLS, \
         LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,      ENT,                      P4,  P5,  P6,        \
         LSFT,NUBS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT ,SLSH,     RSFT,        UP,           P1,  P2,  P3,  PENT, \
         FN0 ,LALT,LGUI,               SPC,                RGUI,RALT,APP ,RCTL,   LEFT,DOWN,RGHT,    P0,  PDOT),          \
    /* Layer 1: Function layer */
    KEYMAP(\
         TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,MPRV,MPLY,MNXT,MUTE,VOLD,VOLU,   TRNS,TRNS,BOOTLOADER,                         \
         GRV ,TRNS,FN2 ,FN3 ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN7 ,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS, \
         TRNS,TRNS,FN4 ,TRNS,TRNS,TRNS,HOME,PGDN,PGUP,END ,FN8 ,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS, \
         TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LEFT,DOWN,UP  ,RGHT,TRNS,TRNS,     TRNS,                      TRNS,TRNS,TRNS,      \
         TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN5 ,TRNS,FN6 ,TRNS,     TRNS,        TRNS,         TRNS,TRNS,TRNS,TRNS, \
         TRNS,TRNS,TRNS,               TRNS,               TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS)
};

enum macro_id {
  MACRO_EMAIL,
  MACRO_WORK_EMAIL,
  MACRO_FNAME,
  MACRO_LNAME,
  MACRO_SIG,
  MACRO_YAY,
  MACRO_PHONE,
};

enum layer_id {
  LAYER_DEFAULT,
  LAYER_FUNCTION,
};

/*
 * Fn action definition
 */
enum function_id {
    SHIFT_ESC,
};

// Macros with personal details are put in here and not published to GitHub
#include "keymap_wezm_private.h"

const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(LAYER_FUNCTION),
    [1] = ACTION_LAYER_TAP_KEY(LAYER_FUNCTION, KC_TAB),
    [2] = ACTION_MACRO(MACRO_EMAIL),
    [3] = ACTION_MACRO(MACRO_WORK_EMAIL),
    [4] = ACTION_MACRO(MACRO_FNAME),
    [5] = ACTION_MACRO(MACRO_LNAME),
    [6] = ACTION_MACRO(MACRO_SIG),
    [7] = ACTION_MACRO(MACRO_YAY),
    [8] = ACTION_MACRO(MACRO_PHONE),
    [9] = ACTION_FUNCTION(SHIFT_ESC),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    enum macro_id mid = id;

    switch (mid) {
        case MACRO_EMAIL:
            // wes@wezm.net
            return (record->event.pressed ?
                    MACRO( T(W), T(E), T(S), D(LSHIFT), T(2), U(LSHIFT), T(W), T(E), T(Z), T(M), T(DOT), T(N), T(E), T(T), END ) : MACRO_NONE );
        case MACRO_WORK_EMAIL:
            return MACRO_NONE;
            // return keymap_wezm_macro_work_email(record, mid, opt);
        case MACRO_FNAME:
            // Wesley
            return (record->event.pressed ?
                    MACRO( D(LSHIFT), T(W), U(LSHIFT), T(E), T(S), T(L), T(E), T(Y), END ) : MACRO_NONE );
        case MACRO_LNAME:
            // Moore
            return (record->event.pressed ?
                    MACRO( D(LSHIFT), T(M), U(LSHIFT), T(O), T(O), T(R), T(E), END ) : MACRO_NONE );
        case MACRO_SIG:
            // Regards,
            // Wes
            return (record->event.pressed ?
                    MACRO( D(LSHIFT), T(R), U(LSHIFT), T(E), T(G), T(A), T(R), T(D), T(S), T(COMM), T(ENT),
                           D(LSHIFT), T(W), U(LSHIFT), T(E), T(S), END ) : MACRO_NONE );
        case MACRO_YAY:
            // \o/
            return (record->event.pressed ?
                    MACRO( T(BSLS), T(O), T(SLSH), END ) : MACRO_NONE );
        case MACRO_PHONE:
            return keymap_wezm_macro_phone(record, mid, opt);
    }

    return MACRO_NONE;
}


void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    static uint8_t shift_esc_shift_mask;
    switch (id) {
        case SHIFT_ESC:
            shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
            if (record->event.pressed) {
                if (shift_esc_shift_mask) {
                    add_key(KC_GRV);
                    send_keyboard_report();
                } else {
                    add_key(KC_ESC);
                    send_keyboard_report();
                }
            } else {
                if (shift_esc_shift_mask) {
                    del_key(KC_GRV);
                    send_keyboard_report();
                } else {
                    del_key(KC_ESC);
                    send_keyboard_report();
                }
            }
            break;
    }
}
