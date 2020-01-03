#include <Adafruit_NeoPixel.h>

#include "silent_night.h"
//#include "tetris.h"
#define TEMPO 125

/* The melody and rhythm are defined in the header above. */
int const melody[] = MELODY; //contains the notes frequencies

/* rhythm[] contains the notes durations in multiples of the shortest duration
 * so a 2 should be played two times longer than a 1 an a 3 three times as long
 * e.g. if the smalles note value in the song is a quarter note each 1 is a quarter note and each 2 is a half note (<- important if you want to code your own music)
 */
int const rhythm[] = RHYTHM;

/********************************************************/
/* TODO: 
   3.) Define a constant LOUDSPEAKER_PIN containing the
   number of the digital pin you just connected the
   "+" pin of your loudspeaker to.
*/
#define LOUDSPEAKER_PIN 4
/********************************************************/

void play(int note, long duration) { // a long is an int but can contain larger numbers
  /********************************************************/
  /* The variable note gives you a frequency in Hz.
     The variable duration is given in milliseconds.
    
     TODO:
     5.) Generate a rectangular wave with the given
     frequency and duration.
     To do so, change the value at the loudspeaker pin
     to HIGH and to LOW for a sufficient number of
     times and wait an appropriate time after you set
     each value.

     Hint: Think about the resolutions you need!
     You may want to use more percise functions.
  */
  //long numberOfCycles = duration * note;
  int waitTime = (duration*1000)/(note*2);//waitTime is wrong!!!
  for(long i = 0; i < duration * 1000L; i+= note ){
    
    digitalWrite(LOUDSPEAKER_PIN, HIGH);
    delayMicroseconds(waitTime);
    digitalWrite(LOUDSPEAKER_PIN, LOW);
    delayMicroseconds(waitTime);
  }
  

  /********************************************************/
}

/* the setup routine runs once when you press reset: */
void setup() {
  pinMode(LOUDSPEAKER_PIN, OUTPUT);
}

/* the loop routine runs over and over again forever: */
void loop() {
  /********************************************************/
  /* TODO:
     4.) Look at the included melody.
     How can you determine how long it is?

     Call play(int, long) with each note in the melody.
     Play the shortest note for 125ms.
  */
  

  //play(440, 500);
  for (int j = 0; j < sizeof(melody)/2; j++) {
    int note = melody[j];
    int duration = rhythm[j] * TEMPO;

    play(note, duration);

  }



  
  /********************************************************/

  delay(1000); //wait 1s until the song repeats
}
