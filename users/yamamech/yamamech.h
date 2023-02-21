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
// clang-format off
#define FN      MO(_FN)
#define LM_LALT LM(_LM, MOD_LALT)
// clang-format on

#if defined(HHKB_ENABLE)
#    include "hhkb/hhkb.h"
#endif

enum layers { _BASE = 0, _FN, _LM };

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
