#include QMK_KEYBOARD_H

#if defined VIA_OPENRGB_HYBRID_CUSTOM_KEYCODE
enum via_orgb_keycodes
{
    ORGB_SWITCH = SAFE_RANGE,
};

#define ORGB_SWITCH_KEYCODE ORGB_SWITCH
#else
#define ORGB_SWITCH_KEYCODE KC_V
#define ORGB_SWITCH_KEYCODE_LAYER 0
#define ORGB_SWITCH_KEYCODE_MOD_LAYER 1
#endif

#include "openrgb.h"
bool rgb_matrix_indicators_user(void)
{
    uint8_t layer = get_highest_layer(layer_state|default_layer_state);
    if (layer > 0)
    {
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row)
        {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col)
            {
                uint8_t index = g_led_config.matrix_co[row][col];
#if defined ORGB_SWITCH_KEYCODE_LAYER
                if (index != NO_LED && keycode_at_keymap_location(ORGB_SWITCH_KEYCODE_LAYER, row, col) == ORGB_SWITCH_KEYCODE)
#else
                if (index != NO_LED && keycode_at_keymap_location(layer, row, col) == ORGB_SWITCH_KEYCODE)
#endif
                {
                    if(get_orgb_mode())
                    {
                        rgb_matrix_set_color(index, RGB_WHITE);
                    }
                    else
                    {
                        rgb_matrix_set_color(index, RGB_BLACK);
                    }

                }
            }
        }
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
        case ORGB_SWITCH_KEYCODE:
#if defined ORGB_SWITCH_KEYCODE_MOD_LAYER
            if (get_highest_layer(layer_state|default_layer_state) == ORGB_SWITCH_KEYCODE_MOD_LAYER && record->event.pressed)
#else
            if (record->event.pressed)
#endif
            {
                toggle_orgb_mode();
                return false;
            }

        default:
            return true;

    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi(
        QK_GESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        CTL_T(KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
        KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,
        KC_LCTL,        KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_65_ansi(
        QK_GESC,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_HOME,
        _______,        RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_PSCR, KC_SCRL, KC_PAUS, QK_BOOT, KC_PGUP,
        CTL_T(KC_CAPS), RGB_SPI, RGB_SPD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          EE_CLR,  KC_PGDN,
        KC_LSFT,                 _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______, KC_VOLU, KC_MUTE,
        _______,        _______, _______,                            _______,                   _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),
    [2] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
    ),
    [3] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
    )
};
