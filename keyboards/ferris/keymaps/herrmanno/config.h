/*
Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// Smaller values lead to mistriggered Shifts, especially /w z-w rolls
#define TAPPING_TERM 250
// Modfiers need a longer tapping term, b/c it seems I'm tapping them slower...
#define ONESHOT_TAPPING_TERM 400
// Needed to define custom tapping term for modifier keys
#define TAPPING_TERM_PER_KEY

#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS
#define ONESHOT_TIMEOUT 2000
#define ONESHOT_TAP_TOGGLE 2
// #define TAP_CODE_DELAY 100

