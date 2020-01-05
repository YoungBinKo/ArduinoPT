#include <Adafruit_NeoPixel.h>
#include <cstdlib>
#define PIN 18
#define STARSAMETIME 1

Adafruit_NeoPixel strip = Adafruit_NeoPixel(30, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}



// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
      //strip.setPixelColor(i, j);
    }
    strip.show();
    delay(wait);
  }
}

bool isInArr(int number, int arr[], int len){
  for(int i=0; i<len;i++){
    if(arr[i]==number){
      return true;
    }
  }
  return false;
}




void stars(int count, uint8_t wait){
  for(int j=0; j<count;j++){

    int num[STARSAMETIME]; 
    for(int i=0;i<STARSAMETIME;i++){

      int r = rand()%30+1;
      while(isInArr(r,num,STARSAMETIME)){
        r = rand()%30+1;
      }
      num[i]=r;
      
    }
    strip.clear();
    for(int brightness=255;brightness>=0;brightness--){
      for(int k=0; k<STARSAMETIME;k++){
        strip.setPixelColor(num[k], brightness,brightness,0);
        
      }
      strip.show();
      delay(wait);
    }
  }
  
  /*TODO: 
   * Implementiere hier den stars Effekt.
   * Dabei sollen nacheinander <count> viele LEDs gelb aufleuchten und langsam ausdimmen (die Geschwindigkeit wird von wait beeinflusst) bevor die nächste LED aufleuchtet. 
   */
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}



void loop() {
  // Some example procedures showing how to display to the pixels:
  colorWipe(strip.Color(255, 0, 0), 50); // Red
  colorWipe(strip.Color(0, 255, 0), 50); // Green
  colorWipe(strip.Color(0, 0, 255), 50); // Blue

  stars(30, 1);

  rainbow(20);
  rainbowCycle(20);
}
