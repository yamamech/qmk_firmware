#pragma once

#include "quantum.h"
// clang-format off
#define FN      MO(_FN)
#define LM_LALT LM(_LM, MOD_LALT)
// clang-format on

enum layers { _BASE = 0, _FN, _LM };

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
