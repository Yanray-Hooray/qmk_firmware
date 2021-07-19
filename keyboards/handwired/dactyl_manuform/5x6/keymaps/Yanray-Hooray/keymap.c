/* A standard layout for the Dactyl Manuform 5x6 Keyboard */
#include QMK_KEYBOARD_H

enum layers {
_QWERTY,
_FUNCTION,
};


#define FUNCTION MO(_FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
        KC_ESC ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                         KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
        KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,                         KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_EQUAL,
        KC_LGUI,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,                         KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
        KC_LCTL,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,                         KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLASH,
                        KC_LALT,KC_GRV,                                                          KC_LBRC,KC_RBRC,
                                                KC_LSFT,KC_SPC ,         KC_BSPC,FUNCTION,
                                                KC_ENT ,KC_HOME ,        KC_END ,KC_ENT,
                                                SH_TT  ,KC_APP  ,        _______,_______
  ),

  [_FUNCTION] = LAYOUT_5x6(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                         KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
        _______,KC_VOLD,KC_MUTE,KC_VOLU,_______,_______,                         _______,_______,_______,_______,_______,_______,
        _______,KC_MPRV,KC_MPLY,KC_MNXT,_______,_______,                         _______,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______,
        _______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,
                        _______,RESET  ,                                                         _______,_______,
                                                _______,_______,         _______,_______,
                                                _______,_______,         _______,_______,
                                                _______,_______,         _______,_______
  ),
};

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {

    case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }

    }
    return true;
};
