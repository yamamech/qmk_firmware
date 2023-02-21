/* Copyright 2023 Yamamech
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"
#include "hhkb.h"
#include "yamamech.h"

bool dip_switch_update_mask_user(uint32_t state) {
    keymap_config.raw = eeconfig_read_keymap();

    hhkb_dip_switch_config.layout = state & (3UL << 0);
    hhkb_dip_switch_config.sw3    = state & (1UL << 2);
    hhkb_dip_switch_config.sw4    = state & (1UL << 3);
    hhkb_dip_switch_config.sw5    = state & (1UL << 4);
    hhkb_dip_switch_config.sw6    = state & (1UL << 5);

    if (hhkb_dip_switch_config.layout == INVALID) {
        hhkb_dip_switch_config.layout = HHKB;
    }

    // SW5 - Swap GUI and ALT keys -- This option is ignored when running in Mac mode.
    // NOTE: This dipswitch breaks support for LM(LAYER, MOD_LALT) keybinds.
    keymap_config.swap_lalt_lgui = keymap_config.swap_ralt_rgui = hhkb_dip_switch_config.sw5;
    if (hhkb_dip_switch_config.layout == MAC) {
        keymap_config.swap_lalt_lgui = keymap_config.swap_ralt_rgui = false;
    }

    eeconfig_update_keymap(keymap_config.raw);
    clear_keyboard();

    return true;
}

bool process_record_hhkb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BACKSPACE:
            // SW3 - Swap backspace and delete
            if (hhkb_dip_switch_config.sw3) {
                if (record->event.pressed) {
                    register_code(KC_DELETE);
                    return false;
                } else {
                    unregister_code(KC_DELETE);
                    return false;
                }
            }
            return true;

        // Layout differences
        case KC_PWR:
            if (hhkb_dip_switch_config.layout != MAC) {
                if (record->event.pressed) {
                    register_code(KC_TRNS);
                } else {
                    unregister_code(KC_TRNS);
                }
                return false;
            }
            return true;

        // NUBS and Grave are swapped around on MacOS for some reason (thanks Apple)
        // So we pre-swap them here, so that MacOS swaps them back for us
        case KC_NUBS:
            return code_if_macos(KC_GRV, record->event.pressed);
        case KC_GRV:
            return code_if_macos(KC_NUBS, record->event.pressed);
    }
    return true;
}

bool code_if_macos(uint16_t keycode, bool pressed) {
    if (hhkb_dip_switch_config.layout != MAC) return true;

    if (pressed)
        register_code(keycode);
    else
        unregister_code(keycode);
    return false;
}
