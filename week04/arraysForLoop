int ledPin[4] = {5,6,9,10};
int potPin = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < 4; i++){
    pinMode(ledPin[i], OUTPUT);
  }
  pinMode(potPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int val = analogRead(potPin);    // read the value from the sensor
  Serial.println(val);

  
  if (val < 256){
    analogWrite(ledPin[0], val);
    for (int i = 0; i < 4; i++){
      analogWrite(ledPin[i], 0);
    }
  }
  else if (val > 255 && val < 512){
    analogWrite(ledPin[0], 255);
    analogWrite(ledPin[1], (val % 256));
    for (int i = 0; i < 4; i++){
      analogWrite(ledPin[i], 0);
    }
  }
  else if (val > 511 && val < 768){
    analogWrite(ledPin[0], 255);
    analogWrite(ledPin[1], 255);
    analogWrite(ledPin[2], (val % 256));
    for (int i = 0; i < 4; i++){
      analogWrite(ledPin[i], 0);
    }
  }
  else{
    analogWrite(ledPin[0], 255);
    analogWrite(ledPin[1], 255);
    analogWrite(ledPin[2], 255);
    analogWrite(ledPin[3], (val % 256));    
    for (int i = 0; i < 4; i++){
      analogWrite(ledPin[i], 0);
    }
  }
}
