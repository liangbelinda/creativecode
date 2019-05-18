/***************************************************************************
  This is a library for the APDS9960 digital proximity, ambient light, RGB, and gesture sensor

  This sketch puts the sensor in proximity mode and enables the interrupt
  to fire when proximity goes over a set value

  Designed specifically to work with the Adafruit APDS9960 breakout
  ----> http://www.adafruit.com/products/3595

  These sensors use I2C to communicate. The device's I2C address is 0x39

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Dean Miller for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include "Adafruit_APDS9960.h"
#include "Volume3.h"

//the pin that the interrupt is attached to
#define INT_PIN 3
int speakerPin = 9;
int button = 2;
// to make alarm sound
float sinVal;
int toneVal;
int v = 500;

bool on = false;
int buttonState;
int startTime, currentTime;
int chance = 0;
int led1 = 4;
int led2 = 5;
int led3 = 6;
int led4 = 7;
int ledState = LOW;             // ledState used to set the LED
unsigned long previousMillis = 0;        // will store last time LED was updated

//create the APDS9960 object
Adafruit_APDS9960 apds;

void setup() {
  Serial.begin(115200);
  pinMode(INT_PIN, INPUT_PULLUP);
  pinMode(button, INPUT);
  pinMode(9, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  if(!apds.begin()){
    Serial.println("failed to initialize device! Please check your wiring.");
  }
  else Serial.println("Device initialized!");

  //enable proximity mode
  apds.enableProximity(true);

  //set the interrupt threshold to fire when proximity reading goes above 35
  apds.setProximityInterruptThreshold(0, 35); 

  //enable the proximity interrupt
  apds.enableProximityInterrupt();
}

void loop() {

  buttonState = digitalRead(button);
  if ((buttonState == LOW) && (chance == 0)){ //if user presses button when there is no "bling" sound
    on = true; //set button to on, so the alarm and lights will always be on
    v = v + 50; //increase volume
    Serial.println("PRESSSSSSS"); //for me to know that the button is pressed
  }

  currentTime = millis()/1000;
  if ((buttonState == LOW) && (chance == 1)){ //if user presses button and there was a "bling" sound
    if (currentTime <= startTime + 3){ //if user presses button within 3 seconds of the "bling" sound
      correct(); //user is correct
      on = false; //turn off buzzer and lights
      chance = 0; //reset chance to default
      v = 500; //reset volume to default
      digitalWrite(led1, LOW);
      
    }
  }
  
  if (currentTime == startTime + 3){ //after 3 seconds from "bling" sound, user no longer has chance to win
    chance = 0;
  }
  
  //print the proximity reading when the interrupt pin goes low
  if(!digitalRead(INT_PIN)){ //if user places hand over sensor
    Serial.println(apds.readProximity());
    play();
    alarm();
    light();
    //clear the interrupt
    apds.clearInterrupt();
  }
  if (on == true){ //if user presses button
    play();
    alarm();
    light();
  }
 
  else{
    vol.noTone();
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
}

void alarm() { //play the alarm sound
  for (int x=0; x<180; x++) {
    // convert degrees to radians then obtain sin value
    sinVal = (sin(x*(3.1412/180)));
    // generate a frequency from the sin value
    toneVal = 2000+(int(sinVal*1000));
    vol.tone(speakerPin, toneVal, v);
    }
    delay(100);
}

void correct(){ //play the "bling" sound
  vol.tone(speakerPin,1025,1023); 
  delay(70);
  uint16_t v = 1000;
  while(v > 0){
    vol.tone(speakerPin, 2090, v); 
    delay(10);
    v-=10;
  }
}

void play(){
  int sound = random(0,35); //pick number between 0 to 35
  if (sound == 1){ // 1 out of 35 chances to play "bling" sound
    vol.tone(speakerPin,1025,1000);
    delay(15);
    startTime = millis() / 1000;
    chance = 1; //user has chance to win
    Serial.println("BLINNNGG");
  }
}

void light(){ //random LED lights
  unsigned long currentMillis = millis();
  int interval = random(100,1000);

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    int numPins = random(0,3); //choose random number of pins
    int counter = 0;
    while (counter <= numPins){ //light number of numPins up
      int pinNum = random(4,8); //randomly light numPins up
      digitalWrite(pinNum, ledState);
      counter = counter + 1;
    }
  }
}
  
