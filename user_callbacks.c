__attribute__((weak)) void keyboard_post_init_keymap(void) {}
void                       keyboard_post_init_user(void) {
    keyboard_post_init_keymap();
}

__attribute__((weak)) void matrix_scan_keymap(void) {}
void                       matrix_scan_user(void) {
    matrix_scan_keymap();
}

__attribute__ ((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }
bool                        process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keymap(keycode, record)) { return false; }
    return true;
}

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }
layer_state_t                       layer_state_set_user(layer_state_t state) {
    state = layer_state_set_keymap(state);
    return state;
}

__attribute__ ((weak)) void led_set_keymap(uint8_t usb_led) {}
void                        led_set_user(uint8_t usb_led) {
    led_set_keymap(usb_led);
}

__attribute__ ((weak)) void suspend_power_down_keymap(void) {}
void                        suspend_power_down_user(void) {
    suspend_power_down_keymap();
}

__attribute__ ((weak)) void suspend_wakeup_init_keymap(void) {}
void                        suspend_wakeup_init_user(void) {
    suspend_wakeup_init_keymap();
}


__attribute__ ((weak)) void shutdown_keymap(void) {}
void                        shutdown_user (void) {
    shutdown_keymap();
}

__attribute__ ((weak)) void eeconfig_init_keymap(void) {}
void                   eeconfig_init_user(void) {
    eeconfig_update_user(0);
    eeconfig_init_keymap();
}
