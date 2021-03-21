/*
*/

#pragma once
#include QMK_KEYBOARD_H

#include "version.h"
#include "eeprom.h"
#include "wrappers.h"
#include "pointing_device.h"

/* Define layer names */
enum userspace_layers {
    _QWERTY  = 0,
    _NUMLOCK = 0,
    _MOUSE,
    _DVORAK,
    _WORKMAN,
    _NORMAN,
    _MALTRON,
    _EUCALYN,
    _CARPLAX,
    _MODS, /* layer 8 */
    _SYMBOL0,
    _SYMBOL1,
    _NUMBERS,
    _MEDIA,
    _LOWER,
    _RAISE,
    _ADJUST
};

bool          mod_key_press_timer(uint16_t code, uint16_t mod_code, bool pressed);
bool          mod_key_press(uint16_t code, uint16_t mod_code, bool pressed, uint16_t this_timer);
void          matrix_init_keymap(void);
void          shutdown_keymap(void);
void          suspend_power_down_keymap(void);
void          suspend_wakeup_init_keymap(void);
void          matrix_scan_keymap(void);
layer_state_t layer_state_set_keymap(layer_state_t state);
layer_state_t default_layer_state_set_keymap(layer_state_t state);
void          led_set_keymap(uint8_t usb_led);
void          eeconfig_init_keymap(void);
bool          hasAllBitsInMask(uint8_t value, uint8_t mask);

// clang-format off
typedef union {
    uint32_t raw;
    struct {
        bool    rgb_layer_change     :1;
        bool    is_overwatch         :1;
        bool    nuke_switch          :1;
        uint8_t unicode_mod          :4;
        bool    swapped_numbers      :1;
        bool    rgb_matrix_idle_anim :1;
    };
} userspace_config_t;
// clang-format on

extern userspace_config_t userspace_config;


