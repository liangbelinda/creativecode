int potPin = 0;
int buzzPin = 9;
int val = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  val = analogRead(potPin);    // read the value from the sensor
  Serial.println(val);

  if (val < 342) { //play Happy Birthday
    tone(buzzPin, 294, 100); //d
    delay(500);
    tone(buzzPin, 294, 100); //d
    delay(500);
    tone(buzzPin, 329); //e
    delay(500);
    tone(buzzPin, 294); //d
    delay(500);
    tone(buzzPin, 392); //g
    delay(500);
    tone(buzzPin, 349, 500); //f
    delay(2000);
  }

  if (val >= 342 && val < 683){ //play Jingle Bell
    tone(buzzPin, 329,100); //e
    delay(500);
    tone(buzzPin, 329, 100); //e
    delay(500);
    tone(buzzPin, 329, 100); //e
    delay(1000); 
    tone(buzzPin, 329, 100); //e
    delay(500); 
    tone(buzzPin, 329, 100); //e
    delay(500); 
    tone(buzzPin, 329, 100); //e
    delay(1000); 
    tone(buzzPin, 329, 100); //e
    delay(500); 
    tone(buzzPin, 392); //g
    delay(500); 
    tone(buzzPin, 261); //c
    delay(500); 
    tone(buzzPin, 294); //d
    delay(500); 
    tone(buzzPin, 329, 500); //e
    delay(2000);
  }     

  if (val >=  683){ //play London Bridge
    tone(buzzPin, 392); //g
    delay(500);
    tone(buzzPin, 440); //a
    delay(500);
    tone(buzzPin, 392); //g
    delay(500);
    tone(buzzPin, 349); //f
    delay(500);
    tone(buzzPin, 329); //e
    delay(500);
    tone(buzzPin, 349); //f
    delay(500);
    tone(buzzPin, 392, 500); //g
    delay(2000);
  }
  
 }
