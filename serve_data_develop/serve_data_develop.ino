#include<SoftwareSerial.h>
SoftwareSerial mySerial(3,2);

#include <Adafruit_NeoPixel.h>
#define MAX_VAL 64  // 0 to 255 for brightness
#define DELAY_TIME 50 
#define DELAY_TIME2 20

Adafruit_NeoPixel strip = Adafruit_NeoPixel(16+16, 0, NEO_GRB + NEO_KHZ800);

void setup(){
  mySerial.begin(115200);
  Serial.begin(115200);

  mySerial.listen();
  pinMode(13,OUTPUT);

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

//  int jewelry = random(0,15);
//  Serial.println(jewelry);
}

void loop(){
  if(mySerial.available()){
    String led = (mySerial.readStringUntil(';'));
    Serial.println(led);
    if(led.compareTo("led;")){
      delay(5);
      int player=(mySerial.read());
      int number = (mySerial.read());
      int red = (mySerial.read());
      int green = (mySerial.read());
      int blue = (mySerial.read());
      strip.setPixelColor(player*16+number, red,green,blue);
    }
  }
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);//第一引数:LEDの位置、第二引数:(3つの数値)
      strip.show();
      delay(wait);
  }
}
//
//void rainbow(uint8_t wait) {
//  uint16_t i, j;
// 
//  for(j=0; j<256; j++) {
//    for(i=0; i<strip.numPixels(); i++) {
//      strip.setPixelColor(i, Wheel((i+j) & 255));
//    }
//    strip.show();
//    delay(wait);
//  }
//}
//
//// Slightly different, this makes the rainbow equally distributed throughout
//void rainbowCycle(uint8_t wait) {
//  uint16_t i, j;
// 
//  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
//    for(i=0; i< strip.numPixels(); i++) {
//      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
//    }
//    strip.show();
//    delay(wait);
//  }
//}
//
//// Input a value 0 to 255 to get a color value.
//// The colours are a transition r - g - b - back to r.
//uint32_t Wheel(byte WheelPos) {
//  if(WheelPos < 85) {
//   return strip.Color((WheelPos * 3)*MAX_VAL/255, (255 - WheelPos * 3)*MAX_VAL/255, 0);
//  } else if(WheelPos < 170) {
//   WheelPos -= 85;
//   return strip.Color((255 - WheelPos * 3)*MAX_VAL/255, 0, (WheelPos * 3)*MAX_VAL/255);
//  } else {
//   WheelPos -= 170;
//   return strip.Color(0, (WheelPos * 3)*MAX_VAL/255, (255 - WheelPos * 3)*MAX_VAL/255);
//  }
//}
