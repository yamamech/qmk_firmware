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

#pragma once

#include "quantum.h"

bool process_record_hhkb(uint16_t keycode, keyrecord_t *record);

bool code_if_macos(uint16_t keycode, bool pressed);

typedef union {
    uint8_t raw;
    struct {
        uint8_t layout : 2;
        bool    sw3 : 1;
        bool    sw4 : 1;
        bool    sw5 : 1;
        bool    sw6 : 1;
    };
} hhkb_dip_switch_config_t;

hhkb_dip_switch_config_t hhkb_dip_switch_config;

enum layouts { HHKB = 0, WINDOWS = 1, MAC = 2, INVALID = 3 };
