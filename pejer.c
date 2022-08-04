#include "pejer.h"
userspace_config_t user_config;
__attribute__((weak)) void keyboard_pre_init_keymap(void) {}

void keyboard_pre_init_user(void) {
    user_config.raw = eeconfig_read_user();
    keyboard_pre_init_keymap();
}
__attribute__((weak)) void matrix_init_keymap(void) {}

__attribute__((weak)) void keyboard_post_init_keymap(void) {}

void keyboard_post_init_user(void) {
//#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
//    keyboard_post_init_rgb();
//#endif
  user_config.raw = eeconfig_read_user();

  // Lets set up the configs
  user_config.trackball_scroll      = false;
  user_config.trackball_speed_fast  = false;
  user_config.trackball_led_on      = true;
  
  keyboard_post_init_keymap();
}

__attribute__((weak)) void shutdown_keymap(void) {}

void rgb_matrix_update_pwm_buffers(void);

void shutdown_user(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_color_all(0xFF, 0x00, 0x00);
    rgb_matrix_update_pwm_buffers();

#endif  // RGB_MATRIX_ENABLE
    shutdown_keymap();
}

__attribute__((weak)) void suspend_power_down_keymap(void) {}

void suspend_power_down_user(void) { suspend_power_down_keymap(); }

__attribute__((weak)) void suspend_wakeup_init_keymap(void) {}

void suspend_wakeup_init_user(void) { suspend_wakeup_init_keymap(); }

__attribute__((weak)) void matrix_scan_keymap(void) {}

// No global matrix scan code, so just run keymap's matrix
// scan function
void matrix_scan_user(void) {
    static bool has_ran_yet;
    if (!has_ran_yet) {
        has_ran_yet = true;
        startup_user();
    }
    matrix_scan_keymap();
}

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }

// on layer change, no matter where the change was initiated
// Then runs keymap's layer change check
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SYMBOL0, _SYMBOL1, _RAISE);

    return layer_state_set_keymap(state);
}

__attribute__((weak)) layer_state_t default_layer_state_set_keymap(layer_state_t state) { return state; }

// Runs state check and changes underglow color and animation
layer_state_t default_layer_state_set_user(layer_state_t state) {
    state = default_layer_state_set_keymap(state);
    return state;
}

__attribute__((weak)) void led_set_keymap(uint8_t usb_led) {}

void led_set_user(uint8_t usb_led) { led_set_keymap(usb_led); }


bool hasAllBitsInMask(uint8_t value, uint8_t mask) {
    value &= 0xF;
    mask &= 0xF;

    return (value & mask) == mask;
}


__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return process_record_keymap(keycode, record) ; 
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
    }
    else if (index == 1) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
#endif

#ifdef POINTING_DEVICE_ENABLE
uint8_t tb_multiplier = 0;
uint8_t tb_accMultiplier = 1;
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (user_config.trackball_scroll) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = -mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    } else {
        // mouse_report.x *= (abs(mouse_report.x) * tb_accMultiplier) + tb_multiplier;
        // mouse_report.y *= (abs(mouse_report.y) * tb_accMultiplier) + tb_multiplier;
        mouse_report.x = -mouse_report.x;
        mouse_report.y = -mouse_report.y;
    }
    return mouse_report;
}
#endif
