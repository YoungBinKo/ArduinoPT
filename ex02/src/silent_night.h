#ifndef SILENT_NIGHT_H
#define SILENT_NIGHT_H
#include "notes.h"

#ifndef MELODY
#  define MELODY {NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D5, NOTE_D5, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4,/**/ NOTE_A4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4,/**/ NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4,/**/ NOTE_D5, NOTE_D5, NOTE_F5, NOTE_D5, NOTE_B4,/**/ NOTE_C5, NOTE_E5, NOTE_C5, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_C4, 0}
#  define RHYTHM {      3,       1,       2,       6,       3,       1,       2,       6,       4,       2,       6,       4,       2,       6,       4,       2,       3,       1,       2,       3,       1,       2,       6,/**/       4,       2,       3,       1,       2,/**/       3,       1,       2,       6,/**/       4,       2,       3,       1,       2,/**/       4,       6,       3,       1,       2,       3,       1,       2,      12, 0}
#else
#  error "Do not include more than one melody file!"
#endif /* MELODY */

#endif /* SILENT_NIGHT_H */
