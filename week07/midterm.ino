#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include "RTClib.h"
#ifdef __AVR__
  #include <avr/power.h>
#endif

#if defined(ARDUINO_ARCH_SAMD)
// for Zero, output on USB Serial console, remove line below if using programming port to program the Zero!
   #define Serial SerialUSB
#endif

RTC_DS1307 rtc;

#define PIN 5

#define NUM_LEDS 60

#define BRIGHTNESS 50

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  #ifndef ESP8266
  while (!Serial); // for Leonardo/Micro/Zero
  #endif

  Serial.begin(57600);
  
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  
}

void loop() {
  // Get current time
  DateTime now = rtc.now();
  
  //Read brightness from potentiometer (0-1023)
  int potValue = analogRead(0);
  Serial.println(potValue);
  int bright = map(potValue, 0, 1023, 0, 255); //map value from potentiometer to LEDs
  strip.setBrightness(bright);
/*
  int hour = 2;
  int minute = 10;
  */

  int hour;
  Serial.println(now.hour()); //12 hour clock
  if (now.hour() > 12){ //if hour is greater than 12, subtract hour
    hour = now.hour() - 12;
  }
  else{
    hour = now.hour();
  }
  int minute = now.minute(); //get minutes
  Serial.println(now.hour());
  Serial.println(now.minute());

  for (int i = 0; i < strip.numPixels(); i++){
    if ((i + 1 == minute) && (minute % 5 == 0)){ //if pin represents min and hour, set pin to red
      strip.setPixelColor(i, strip.Color(255, 0, 0));
    }
    else if (((i+1) % 5 == 0) && (i < hour * 5)){ //if pin is hour pin, set to yellow
      strip.setPixelColor(i, strip.Color(255, 255, 0));
    }
    else if (i < minute){ //if pin is less than current minute, set to white
      strip.setPixelColor(i, strip.Color(255, 255, 255));
    }
    else{ //otherwise, pin should be off
      strip.setPixelColor(i, strip.Color(0, 0, 0));
    }
  }

  strip.show();
  delay(100);

}
