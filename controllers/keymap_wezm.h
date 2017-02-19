
const uint8_t PROGMEM keymaps[][MATRIX_COLS][MATRIX_ROWS] = {
    /* Layer 0: Standard ANSI layer */
    KEYMAP(\
         ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11,  F12,   PSCR,SLCK,PAUS,                         \
         GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS, EQL,BSPC,   INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS, \
         FN1, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,   DEL, END, PGDN,    P7,  P8,  P9,  PPLS, \
         CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,      ENT,                      P4,  P5,  P6,        \
         LSFT,NUBS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RSFT,        UP,           P1,  P2,  P3,  PENT, \
         LCTL,LALT,LGUI,               SPC,                RGUI,RALT, FN0,RCTL,   LEFT,DOWN,RGHT,    P0,  PDOT),          \
    /* Layer 1: Function layer */
    KEYMAP(\
         TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,MPRV,MPLY,MNXT,MUTE,VOLD,VOLU,   TRNS,TRNS,TRNS,                         \
         TRNS,TRNS,FN2 ,FN3 ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN7 ,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS, \
         TRNS,TRNS,FN4 ,TRNS,TRNS,TRNS,HOME,PGDN,PGUP,END ,TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS, \
         TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LEFT,DOWN,UP  ,RGHT,TRNS,TRNS,     TRNS,                      TRNS,TRNS,TRNS,      \
         TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN5 ,TRNS,FN6 ,TRNS,     TRNS,        TRNS,         TRNS,TRNS,TRNS,TRNS, \
         TRNS,TRNS,TRNS,               TRNS,               TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS)
};

const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_LAYER_TAP_KEY(1, KC_TAB),
    [2] = ACTION_MACRO(0),
    [3] = ACTION_MACRO(1),
    [4] = ACTION_MACRO(2),
    [5] = ACTION_MACRO(3),
    [6] = ACTION_MACRO(4),
    [7] = ACTION_MACRO(5),
};

enum macro_id {
  MACRO_EMAIL,
  MACRO_WORK_EMAIL,
  MACRO_FNAME,
  MACRO_LNAME,
  MACRO_SIG,
  MACRO_YAY,
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    enum macro_id mid = id;

    switch (mid) {
        case MACRO_EMAIL:
            return (record->event.pressed ?
                    MACRO( T(W), T(E), T(S), D(LSHIFT), T(2), U(LSHIFT), T(W), T(E), T(Z), T(M), T(DOT), T(N), T(E), T(T), END ) : MACRO_NONE );
        case MACRO_WORK_EMAIL:
            return (record->event.pressed ?
                    MACRO( I(0), T(H), T(E), T(L), T(L), W(255), T(O), END ) : MACRO_NONE );
        case MACRO_FNAME:
            return (record->event.pressed ?
                    MACRO( I(0), T(H), T(E), T(L), T(L), W(255), T(O), END ) : MACRO_NONE );
        case MACRO_LNAME:
            return (record->event.pressed ?
                    MACRO( I(0), T(H), T(E), T(L), T(L), W(255), T(O), END ) : MACRO_NONE );
        case MACRO_SIG:
            return (record->event.pressed ?
                    MACRO( I(0), T(H), T(E), T(L), T(L), W(255), T(O), END ) : MACRO_NONE );
        case MACRO_YAY:
            return (record->event.pressed ?
                    MACRO( T(BSLS), T(O), T(SLSH), END ) : MACRO_NONE );
    }

    return MACRO_NONE;
}

/*
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  (void)opt;
  switch(id) {
    case ACTION_LEDS_ALL:
        if(record->event.pressed) {
          // signal the LED controller thread
          chMBPost(&led_mailbox, LED_MSG_GAME_TOGGLE, TIME_IMMEDIATE);
        }
      break;
    case ACTION_LEDS_GAME:
      if(record->event.pressed) {
        // signal the LED controller thread
        chMBPost(&led_mailbox, LED_MSG_ALL_TOGGLE, TIME_IMMEDIATE);
      }
      break;
  }
}
*/
