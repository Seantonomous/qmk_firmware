#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum iris_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Tap Dance Declarations
enum {
    TD_LGUI_LALT= 0,
    TD_RGUI_RALT
};

// Macro Definitions
enum {
    //SELF
    KC_EMAIL = SAFE_RANGE,
    KC_WEMAIL,

    //TELEPHONY
    KC_OPT,

    //GIT
    KC_GSTATUS,
    KC_GADDALL,
    KC_GCOMMIT,

    //GENERAL
};

#define KC_ KC_TRNS

#define KC_LOWR MO(_LOWER)
#define KC_RASE MO(_RAISE)
#define KC_RST RESET
#define KC_DBUG DEBUG

//Custom
#define KC_MLOC LCTL(LGUI(KC_Q)) //Lock MacOS
#define KC_POW  LSFT(LGUI(KC_Q)) //Power Off MacOS

//Chumkwm Specific
//Resize?
//Move to next/previous window?
//Probably some custom scripts here

#define KC_LAG TD(TD_LGUI_LALT)
#define KC_RAG TD(TD_RGUI_RALT)
#define KC_RSEN MT(MOD_RSFT, KC_ENT)
#define KC_SHT MT(MOD_LSFT | KC_LGUI | KC_4, MOD_LSFT | MOD_LCTL | KC_LGUI | KC_4)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_EMAIL:
            if (record->event.pressed) {
                SEND_STRING("Seanmhansen7@gmail.com");
            }
            break;
        case KC_WEMAIL:
            if (record->event.pressed) {
                SEND_STRING("sean.hansen@pnmac.com");
            }
         case KC_OPT:
            if (record->event.pressed) {
                SEND_STRING("tftp://sipftp.pnmac.com");
            }
            break;
         case KC_GSTATUS:
            if (record->event.pressed) {
                SEND_STRING("git status\n");
            }
            break;
         case KC_GADDALL:
            if (record->event.pressed) {
                SEND_STRING("git add *\n");
            }
            break;
         case KC_GCOMMIT:
            if (record->event.pressed) {
                SEND_STRING("git commit\n");
            }
            break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LCTL, Z  , X  , C  , V  , B  , ENT,     ENT , N  , M  ,COMM,DOT ,SLSH,RSEN,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                        LAG ,LOWR,SPC,       SPC ,RASE, RAG
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CAPS,TILD,PGUP, UP ,PGDN, DEL,              ,HOME, END, INS,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,GRV ,LEFT,DOWN,RGHT,LCBR,               RCBR,MINS,PLUS,EQL ,UNDS,PIPE,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     MPLY,MPRV,MNXT,VOLD,VOLU,LBRC,    ,         ,RBRC,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     MLOC, F1 , F2 , F3 , F4 , F5 ,                F6 ,EMAIL,WEMAIL, F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,GSTATUS,GADDALL,GCOMMIT,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,               NLCK, P7 , P8 , P9 ,PSLS,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               PSCR, P4 , P5 , P6 ,PAST,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               SLCK, P1 , P2 , P3 ,PPLS,ENT ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,PAUS, P0 , P0 ,PDOT,PMNS,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  )

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for L-Alt, twice for L-GUI
    [TD_LGUI_LALT] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_LALT),
    // Tap once for R-Alt, twice for R-GUI
    [TD_RGUI_RALT] = ACTION_TAP_DANCE_DOUBLE(KC_RGUI, KC_RALT)
};
