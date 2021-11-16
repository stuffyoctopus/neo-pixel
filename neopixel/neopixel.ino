// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library
#include <Wire.h>
#include "Adafruit_MCP9808.h"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        13 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 8 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 50 // Time (in milliseconds) to pause between pixels

void setup() {
  Serial.begin(9600);
  while (!Serial);
  if (!tempsensor.begin(0x18)) {
    Serial.println("Couldn't find MCP9808! Check your connections and verify the address is correct.");
    while (1);
  }
  Serial.println("Found MCP9808!");
  tempsensor.setResolution(3);
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
  float c = tempsensor.readTempC();
  float f = tempsensor.readTempF();
  int x = (f - 77) * 0.636;
  Serial.print("Temp: ");

  Serial.print(f, 4); Serial.println("*F.");

  delay(200);


  //------------------------------------------
  if (x > 1) {
    pixels.setPixelColor(0, pixels.Color(0, 150, 0));
    pixels.show();
    delay(DELAYVAL);
  } else {
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();
  }
  //------------------------------------------
    if (x > 2) {
    pixels.setPixelColor(1, pixels.Color(0, 150, 0));
    pixels.show();
    delay(DELAYVAL);
  } else {
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.show();
  }
  //------------------------------------------
    if (x > 3) {
    pixels.setPixelColor(2, pixels.Color(0, 150, 0));
    pixels.show();
    delay(DELAYVAL);
  } else {
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));
    pixels.show();
  }
  //------------------------------------------
    if (x > 4) {
    pixels.setPixelColor(3, pixels.Color(0, 150, 0));
    pixels.show();
    delay(DELAYVAL);
  } else {
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));
    pixels.show();
  }
  //------------------------------------------
    if (x > 5) {
    pixels.setPixelColor(4, pixels.Color(0, 150, 0));
    pixels.show();
    delay(DELAYVAL);
  } else {
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));
    pixels.show();
  }
  //------------------------------------------










}
