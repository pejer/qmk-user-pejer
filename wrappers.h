#pragma once
#include "pejer.h"
/*
So very stopen from Drashna! 

Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

#if defined(KEYMAP_SAFE_RANGE)
#    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif


// clang-format off

// Defined in process_records

enum userspace_custom_keycodes {
    VRSN = PLACEHOLDER_SAFE_RANGE,  // Prints QMK Firmware and board info
    KC_QWERTY,                      // Sets default layer to QWERTY
    KC_COLEMAK,                     // Sets default layer to COLEMAK
    KC_DVORAK,                      // Sets default layer to DVORAK
    KC_WORKMAN,                     // Sets default layer to WORKMAN
    KC_DIABLO_CLEAR,                // Clears all Diablo Timers
    KC_MAKE,                        // Run keyboard's customized make command
    KC_RGB_T,                       // Toggles RGB Layer Indication mode
    RGB_IDL,                        // RGB Idling animations
    KC_SECRET_1,                    // test1
    KC_SECRET_2,                    // test2
    KC_SECRET_3,                    // test3
    KC_SECRET_4,                    // test4
    KC_SECRET_5,                    // test5
    KC_CCCV,                        // Hold to copy, tap to paste
    KC_NUKE,                        // NUCLEAR LAUNCH DETECTED!!!
    UC_FLIP,                        // (ಠ痊ಠ)┻━┻
    UC_TABL,                        // ┬─┬ノ( º _ ºノ)
    UC_SHRG,                        // ¯\_(ツ)_/¯
    UC_DISA,                        // ಠ_ಠ
    NEW_SAFE_RANGE,                  // use "NEWPLACEHOLDER for keymap specific codes
    KC_PRINT_TRUTH
};


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define TG_MODS TG(_MODS)
#define TG_GAME TG(_GAMEPAD)
#define OS_LWR OSL(_LOWER)
#define OS_RSE OSL(_RAISE)

#define KC_SEC1 KC_SECRET_1
#define KC_SEC2 KC_SECRET_2
#define KC_SEC3 KC_SECRET_3
#define KC_SEC4 KC_SECRET_4
#define KC_SEC5 KC_SECRET_5

#define QWERTY KC_QWERTY
#define DVORAK KC_DVORAK
#define COLEMAK KC_COLEMAK
#define WORKMAN KC_WORKMAN

#define KC_RESET RESET
#define KC_RST KC_RESET
#define BK_LWER LT(_LOWER, KC_BSPC)
#define SP_LWER LT(_LOWER, KC_SPC)
#define DL_RAIS LT(_RAISE, KC_DEL)
#define ET_RAIS LT(_RAISE, KC_ENTER)

/* OSM keycodes, to keep things clean and easy to change */
#define KC_MLSF OSM(MOD_LSFT)
#define KC_MRSF OSM(MOD_RSFT)

#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_MEH OSM(MOD_MEH)
#define OS_HYPR OSM(MOD_HYPR)

#define ALT_APP ALT_T(KC_APP)

#define MG_NKRO MAGIC_TOGGLE_NKRO

#define UC_IRNY UC(0x2E2E)
#define UC_CLUE UC(0x203D)
// end defined in process_records
#define LAYOUT_ergodox_wrapper(...)          LAYOUT_ergodox(__VA_ARGS__)
#define LAYOUT_ergodox_pretty_wrapper(...)   LAYOUT_ergodox_pretty(__VA_ARGS__)
#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_homerow_wrapper(...)          LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_ortho_5x12_wrapper(...)       LAYOUT_ortho_5x12(__VA_ARGS__)
#define LAYOUT_gergo_wrapper(...)            LAYOUT_gergo(__VA_ARGS__)

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO

#define LOWER MO(_LOWER)
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD
#define KC_CTLTB CTL_T(KC_TAB)
#define KC_GUIEI GUI_T(KC_LANG2)
#define KC_ALTKN ALT_T(KC_LANG1)


// PEJER
// To make home row keys act as shift,ctl,alt,GUI when pressed & held
#define KC_PEJ_A SFT_T(KC_A)
#define KC_PEJ_S GUI_T(KC_S)
#define KC_PEJ_D ALT_T(KC_D)
#define KC_PEJ_F CTL_T(KC_F)
#define KC_PEJ_J CTL_T(KC_J)
#define KC_PEJ_K ALT_T(KC_K)
#define KC_PEJ_L GUI_T(KC_L)
#define KC_PEJ_SCLN SFT_T(KC_SCLN)

// PEJER
// To access SYMBOL0 and SYMBOL1 layers
#define KC_PEJ_E LT(_NUMBERS,KC_E)
#define KC_PEJ_I LT(_SYMBOL1, KC_I)

// PEJER
// To have characters on the top row
#define KC_PEJ_1 LSFT(KC_1)
#define KC_PEJ_2 RALT(KC_2)
#define KC_PEJ_3 LSFT(KC_3)
#define KC_PEJ_4 RALT(KC_4)
#define KC_PEJ_5 LSFT(KC_5)
#define KC_PEJ_6 RALT(LSFT(KC_RBRC))
#define KC_PEJ_7 KC_CIRC
#define KC_PEJ_8 LSFT(KC_BSLS)
#define KC_PEJ_9 LSFT(KC_0)
#define KC_PEJ_0 RALT(KC_7)
#define KC_PEJ_BSPC LT(_SYMBOL0,KC_BSPC)
#define KC_PEJ_SPC LT(_NUMBERS,KC_SPC)
#define KC_PEJ_TAB LT(_SYMBOL1, KC_TAB)
#define KC_PEJ_QUE LSFT(KC_MINS)

#define KC_PEJ_PARO LSFT(KC_8)
#define KC_PEJ_PARC LSFT(KC_9)

#define KC_PEJ_CURO LSFT(RALT(KC_8))
#define KC_PEJ_CURC LSFT(RALT(KC_9))

#define KC_PEJ_BRAO RALT(KC_8)
#define KC_PEJ_BRAC RALT(KC_9)

#define KC_PEJ_CIT LSFT(KC_2)
#define KC_PEJ_BCK LSFT(RALT(KC_7))
#define KC_PEJ_RBRC RALT(KC_RBRC)




/*
Shamefully stolen from Drashna.

*/

#define ___________PEJER_QWERTY_L1_________________        KC_Q,    KC_W,    KC_PEJ_E,    KC_R,    KC_T
#define ___________PEJER_QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define ___________PEJER_QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define ___________PEJER_QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define ___________PEJER_QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_PEJ_SCLN
#define ___________PEJER_QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define ___________PEJER_SYMBOL0_L1________________        KC_PEJ_1,    KC_PEJ_2,    KC_PEJ_3,    KC_PEJ_4,    KC_PEJ_5
#define ___________PEJER_SYMBOL0_L2________________        KC_PEJ_PARO,KC_PEJ_BRAO,KC_PEJ_CURO, KC_BSLS,KC_AMPR
#define ___________PEJER_SYMBOL0_L3________________        KC_PEJ_PARC,KC_PEJ_BRAC,KC_PEJ_CURC,KC_PEJ_CIT,KC_PEJ_BCK

#define ___________PEJER_SYMBOL0_R1________________        KC_PEJ_6, KC_PEJ_7,  KC_PEJ_8,  KC_PEJ_9,  KC_PEJ_0
#define ___________PEJER_SYMBOL0_R2________________        KC_EQL,     KC_LBRC, KC_PEJ_RBRC,     KC_6,   KC_F10
#define ___________PEJER_SYMBOL0_R3________________        KC_F16,     KC_7,     KC_8,     KC_9,   KC_F20

#define ___________PEJER_SYMBOL1_L1________________         KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5
#define ___________PEJER_SYMBOL1_L2________________        KC_A, KC_S, KC_D, KC_F,     KC_G
#define ___________PEJER_SYMBOL1_L3________________         KC_Z,     KC_X,     KC_C,     KC_V,     KC_B

#define ___________PEJER_SYMBOL1_R1________________         KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10
#define ___________PEJER_SYMBOL1_R2________________         KC_LEFT, KC_DOWN,    KC_UP, KC_RIGHT, KC_SEC1
#define ___________PEJER_SYMBOL1_R3________________         KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX

 
#define ___________PEJER_NUMBER_L1_________________        KC_1,     KC_2,     KC_3,     KC_4,     KC_5 
#define ___________PEJER_NUMBER_L2_________________        KC_LSFT , KC_NO, KC_BTN2, KC_BTN1,  KC_NO
#define ___________PEJER_NUMBER_L3_________________        _______, _______, KC_WH_U, KC_WH_D ,_______

#define ___________PEJER_NUMBER_R1_________________       KC_6,     KC_1,     KC_2,     KC_3,     KC_0
#define ___________PEJER_NUMBER_R2_________________       KC_EQL,     KC_4,     KC_5,     KC_6,   KC_F10 
#define ___________PEJER_NUMBER_R3_________________        KC_F16,     KC_7,     KC_8,     KC_9,   KC_F20

#define _______________PEJ_BLANK___________________       _______,_______,_______,_______,_______

/*
#define ___________PEJER_COLEMAK_L1________________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define ___________PEJER_COLEMAK_L2________________       KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define ___________PEJER_COLEMAK_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define ___________PEJER_COLEMAK_R1________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ___________PEJER_COLEMAK_R2________________       KC_H,    KC_N,    KC_E,    KC_I,    KC_O
#define ___________PEJER_COLEMAK_R3________________       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define ________PEJER_COLEMAK_MOD_DH_L1____________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ________PEJER_COLEMAK_MOD_DH_L2____________       KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define ________PEJER_COLEMAK_MOD_DH_L3____________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define ________PEJER_COLEMAK_MOD_DH_R1____________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ________PEJER_COLEMAK_MOD_DH_R2____________       KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define ________PEJER_COLEMAK_MOD_DH_R3____________       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH


#define ___________PEJER_DVORAK_L1_________________        KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y
#define ___________PEJER_DVORAK_L2_________________        KC_A,    KC_O,    KC_E,   KC_U,     KC_I
#define ___________PEJER_DVORAK_L3_________________        KC_SCLN, KC_Q,    KC_J,   KC_K,     KC_X

#define ___________PEJER_DVORAK_R1_________________        KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define ___________PEJER_DVORAK_R2_________________        KC_D,    KC_H,    KC_T,    KC_N,    KC_S
#define ___________PEJER_DVORAK_R3_________________        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z


#define __________PEJER_DVORAK_AU_L1_______________        KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y
#define __________PEJER_DVORAK_AU_L2_______________        KC_O,    KC_A,    KC_E,   KC_I,     KC_U
#define __________PEJER_DVORAK_AU_L3_______________        KC_SCLN, KC_Q,    KC_J,   KC_K,     KC_X

#define __________PEJER_DVORAK_AU_R1_______________        KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define __________PEJER_DVORAK_AU_R2_______________        KC_D,    KC_H,    KC_T,    KC_N,    KC_S
#define __________PEJER_DVORAK_AU_R3_______________        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z

#define ___________PEJER_WORKMAN_L1________________       KC_Q,    KC_D,    KC_R,   KC_W,     KC_B
#define ___________PEJER_WORKMAN_L2________________       KC_A,    KC_S,    KC_H,   KC_T,     KC_G
#define ___________PEJER_WORKMAN_L3________________       KC_Z,    KC_X,    KC_M,   KC_C,     KC_V

#define ___________PEJER_WORKMAN_R1________________       KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN
#define ___________PEJER_WORKMAN_R2________________       KC_Y,    KC_N,    KC_E,    KC_O,    KC_I
#define ___________PEJER_WORKMAN_R3________________       KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLASH


#define ___________PEJER_NORMAN_L1_________________       KC_Q,    KC_W,    KC_D,    KC_F,    KC_K
#define ___________PEJER_NORMAN_L2_________________       KC_A,    KC_S,    KC_E,    KC_T,    KC_G
#define ___________PEJER_NORMAN_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define ___________PEJER_NORMAN_R1_________________       KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN
#define ___________PEJER_NORMAN_R2_________________       KC_Y,    KC_N,    KC_I,    KC_O,    KC_U
#define ___________PEJER_NORMAN_R3_________________       KC_P,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH


#define ___________PEJER_MALTRON_L1________________       KC_Q,    KC_P,    KC_Y,    KC_C,    KC_B
#define ___________PEJER_MALTRON_L2________________       KC_A,    KC_N,    KC_I,    KC_S,    KC_F
#define ___________PEJER_MALTRON_L3________________       KC_SCLN, KC_SLSH, KC_J,    KC_G,    KC_COMM

#define ___________PEJER_MALTRON_R1________________       KC_V,    KC_M,    KC_U,    KC_Z,    KC_L
#define ___________PEJER_MALTRON_R2________________       KC_D,    KC_T,    KC_D,    KC_O,    KC_R
#define ___________PEJER_MALTRON_R3________________       KC_DOT,  KC_W,    KC_K,    KC_MINS, KC_X


#define ___________PEJER_EUCALYN_L1________________       KC_SLSH, KC_COMM, KC_DOT,  KC_F,    KC_Q
#define ___________PEJER_EUCALYN_L2________________       KC_A,    KC_O,    KC_E,    KC_I,    KC_U
#define ___________PEJER_EUCALYN_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_W

#define ___________PEJER_EUCALYN_R1________________       KC_M,    KC_R,    KC_D,    KC_Y,    KC_P
#define ___________PEJER_EUCALYN_R2________________       KC_G,    KC_T,    KC_K,    KC_S,    KC_N
#define ___________PEJER_EUCALYN_R3________________       KC_B,    KC_H,    KC_J,    KC_L,    KC_SCLN


#define _______PEJER_CARPLAX_QFMLWY_L1_____________       KC_Q,    KC_F,    KC_M,    KC_L,    KC_W
#define _______PEJER_CARPLAX_QFMLWY_L2_____________       KC_D,    KC_S,    KC_T,    KC_N,    KC_R
#define _______PEJER_CARPLAX_QFMLWY_L3_____________       KC_Z,    KC_V,    KC_G,    KC_C,    KC_X

#define _______PEJER_CARPLAX_QFMLWY_R1_____________       KC_Y,    KC_U,    KC_O,    KC_B,    KC_J
#define _______PEJER_CARPLAX_QFMLWY_R2_____________       KC_I,    KC_A,    KC_E,    KC_H,    KC_SCLN
#define _______PEJER_CARPLAX_QFMLWY_R3_____________       KC_P,    KC_K,    KC_COMM, KC_DOT,  KC_SLSH


#define _______PEJER_CARPLAX_QGMLWB_L1_____________       KC_Q,    KC_G,    KC_M,    KC_L,    KC_W
#define _______PEJER_CARPLAX_QGMLWB_L2_____________       KC_D,    KC_S,    KC_T,    KC_N,    KC_R
#define _______PEJER_CARPLAX_QGMLWB_L3_____________       KC_Z,   KC_X,    KC_C,    KC_F,    KC_J

#define _______PEJER_CARPLAX_QGMLWB_R1_____________       KC_B,    KC_Y,    KC_U,    KC_V,    KC_SCLN
#define _______PEJER_CARPLAX_QGMLWB_R2_____________       KC_I,    KC_A,    KC_E,    KC_O,    KC_H
#define _______PEJER_CARPLAX_QGMLWB_R3_____________       KC_K,    KC_P,    KC_COMM, KC_DOT,  KC_SLSH


#define _______PEJER_CARPLAX_QGMLWY_L1_____________       KC_Q,    KC_G,    KC_M,    KC_L,    KC_W
#define _______PEJER_CARPLAX_QGMLWY_L2_____________       KC_D,    KC_S,    KC_T,    KC_N,    KC_R
#define _______PEJER_CARPLAX_QGMLWY_L3_____________       KC_Z,   KC_X,    KC_C,    KC_V,    KC_J

#define _______PEJER_CARPLAX_QGMLWY_R1_____________       KC_Y,    KC_F,    KC_U,    KC_B,    KC_SCLN
#define _______PEJER_CARPLAX_QGMLWY_R2_____________       KC_I,    KC_A,    KC_E,    KC_O,    KC_H
#define _______PEJER_CARPLAX_QGMLWY_R3_____________       KC_K,    KC_P,    KC_COMM, KC_DOT,  KC_SLSH


#define ___________PEJER_WHITE_R1__________________       KC_V,    KC_Y,    KC_D,    KC_COMM, KC_QUOT
#define ___________PEJER_WHITE_R2__________________       KC_A,    KC_T,    KC_H,    KC_E,    KC_B
#define ___________PEJER_WHITE_R3__________________       KC_P,    KC_K,    KC_G,    KC_W,    KC_Q

#define ___________PEJER_WHITE_L1__________________       KC_INT1, KC_J,    KC_M,    KC_L,    KC_U
#define ___________PEJER_WHITE_L2__________________       KC_MINS, KC_C,    KC_S,    KC_N,    KC_O  // KC_I
#define ___________PEJER_WHITE_L3__________________       KC_X,    KC_R,    KC_F,    KC_DOT,  KC_Z


#define __________PEJER_NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define __________PEJER_NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define ___________PEJER_FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define ___________PEJER_FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define _____________PEJER_BLANK___________________        _______, _______, _______, _______, _______

*/
#define ___________PEJER_LOWER_L1__________________        KC_PEJ_1,KC_PEJ_2,KC_PEJ_3,KC_PEJ_4,KC_PEJ_5
#define ___________PEJER_LOWER_L2__________________        F1,F2,F3,F4,F5
#define ___________PEJER_LOWER_L3__________________        F11,F12,F13,F14,F15

#define ___________PEJER_LOWER_R1__________________        KC_PEJ_6,KC_PEJ_7,KC_PEJ_8.KC_PEJ_9, KC_PEJ_0
#define ___________PEJER_LOWER_R2__________________        F6,F7,F8,F9,F10
#define ___________PEJER_LOWER_R3__________________        F16,F17,F18,F19,F20



#define ___________PEJER_RAISE_L1__________________        ________________NUMBER_LEFT________________
#define ___________PEJER_RAISE_L2__________________        ___________________BLANK___________________
#define ___________PEJER_RAISE_L3__________________        ___________________BLANK___________________

#define ___________PEJER_RAISE_R1__________________        ________________NUMBER_RIGHT_______________
#define ___________PEJER_RAISE_R2__________________        _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC
#define ___________PEJER_RAISE_R3__________________        _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END



#define ___________PEJER_ADJUST_L1_________________        RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG
#define ___________PEJER_ADJUST_L2_________________        MU_TOG , CK_TOGG, AU_ON,   AU_OFF,  CG_NORM
#define ___________PEJER_ADJUST_L3_________________        RGB_RMOD,RGB_HUD,RGB_SAD, RGB_VAD, KC_RGB_T

#define ___________PEJER_ADJUST_R1_________________        KC_SEC1, KC_SEC2, KC_SEC3, KC_SEC4, KC_SEC5
#define ___________PEJER_ADJUST_R2_________________        CG_SWAP, QWERTY,  COLEMAK, DVORAK,  WORKMAN
#define ___________PEJER_ADJUST_R3_________________        MG_NKRO, KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT
// clang-format on
