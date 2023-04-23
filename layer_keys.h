// Henrik Pejers futile attempt at QMK.
#pragma once
#include "pejer.h"
#include "keymap_swedish.h"
// Utility rows
#define ________________BLANK________________      ________ ,_______    ,_______    ,_______    ,______

// Real layers, as in where your regular letters etc, are

// QWERTY
#define ______________QWERTY_L1______________     KC_Q      , KC_W      , KC_E      , KC_R      , KC_T
#define ______________QWERTY_L2______________     KC_A      , KC_S      , KC_D      , KC_F      , KC_G
#define ______________QWERTY_L3______________     KC_Z      , KC_X      , KC_C      , KC_V      , KC_B

#define ______________QWERTY_R1______________     KC_Y      , KC_I      , KC_I      , KC_O      , KC_P
#define ______________QWERTY_R2______________     KC_H      , KC_J      , KC_K      , KC_L      , SE_ODIA
#define ______________QWERTY_R3______________     KC_N      , KC_M      , KC_COMM   , KC_DOT    , KC_SLASH

// WORKERMAN
#define ______________WORKMN_L1______________     KC_Q      , KC_D      , KC_R      , KC_W      , KC_B
#define ______________WORKMN_L2______________     KC_A      , KC_S      , KC_H      , KC_T      , KC_G
#define ______________WORKMN_L3______________     KC_Z      , KC_X      , KC_M      , KC_C      , KC_V

#define ______________WORKMN_R1______________     KC_J      , KC_F      , KC_U      , KC_P      , SE_ODIA
#define ______________WORKMN_R2______________     KC_Y      , KC_N      , KC_E      , KC_O      , KC_I
#define ______________WORKMN_R3______________     KC_K      , KC_L      , KC_COMM   , KC_DOT    , KC_SLASH

/* #define ______________NUMBER_L1______________    [          ,KC_7       ,KC_8       ,KC_9       ,]
#define ______________NUMBER_L2______________   "           ,KC_4       ,KC_5       ,KC_6       ,=
#define ______________NUMBER_L3______________    `          ,KC_1       ,KC_2       ,KC_3       ,\

#define ______________NUMBER_R1______________   ________________BLANK________________
#define ______________NUMBER_R2______________   ________________BLANK________________
#define ______________NUMBER_R3______________   ________________BLANK________________ */

#define ______________FKEYS_L1______________    KC_F12      ,KC_F7      ,KC_F8      ,KC_F9      ,
#define ______________FKEYS_L2______________    KC_F11      ,KC_F4      ,KC_F5      ,KC_F6      ,
#define ______________FKEYS_L3______________    KC_F10      ,KC_F1      ,KC_F2      ,KC_F3      ,

#define ______________FKEYS_R1______________   ________________BLANK________________
#define ______________FKEYS_R2______________   ________________BLANK________________
#define ______________FKEYS_R3______________   ________________BLANK________________
