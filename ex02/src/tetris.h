#ifndef TETRIS_H
#define TETRIS_H
#include "notes.h"

#ifndef MELODY
#  define MELODY {NOTE_E6, NOTE_B5, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_B5, NOTE_A5, NOTE_A5, NOTE_C6, NOTE_E6, NOTE_D6, NOTE_C6, NOTE_B5, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_C6, NOTE_A5, NOTE_A5,/**/ NOTE_D6, NOTE_F6, NOTE_A6, NOTE_G6, NOTE_F6, NOTE_E6, NOTE_C6, NOTE_E6, NOTE_D6, NOTE_C6, NOTE_B5, NOTE_B5, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_C6, NOTE_A5, NOTE_A5, 0}
#  define RHYTHM {      2,       1,       1,       2,       1,       1,       2,       1,       1,       2,       1,       1,       3,       1,       2,       2,       2,       2,       2,/**/       2,       1,       2,       1,       1,       3,       1,       2,       1,       1,       2,       1,       1,       2,       2,       2,       2,       2, 0};
#else
#  error "Do not include more than one melody file!"
#endif /* MELODY */

#endif /* TETRIS */
