int ledPin[6] = {13,12,11,10,9,8};

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 6; i++){
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //1 vs 5 pattern
  digitalWrite(ledPin[0], HIGH);
  delay(500);
  digitalWrite(ledPin[0], LOW);
  delay(500);
  for (int i = 1; i < 6; i++){
    digitalWrite(ledPin[i], HIGH);
  }
  delay(500);
  for (int i = 1; i < 6; i++){
    digitalWrite(ledPin[i], LOW);
  }
  delay(1000);

  //2 vs 4 pattern
  digitalWrite(ledPin[0], HIGH);
  digitalWrite(ledPin[1], HIGH);
  delay(500);
  digitalWrite(ledPin[0], LOW);
  digitalWrite(ledPin[1], LOW);
  delay(500);
  for (int i = 2; i < 6; i++){
    digitalWrite(ledPin[i], HIGH);
  }
  delay(500);
  for (int i = 2; i < 6; i++){
    digitalWrite(ledPin[i], LOW);
  }
  delay(1000);

  //3 vs 3 pattern
  digitalWrite(ledPin[0], HIGH);
  digitalWrite(ledPin[1], HIGH);
  digitalWrite(ledPin[2], HIGH);
  delay(500);
  digitalWrite(ledPin[0], LOW);
  digitalWrite(ledPin[1], LOW);
  digitalWrite(ledPin[2], LOW);
  delay(500);
  for (int i = 3; i < 6; i++){
    digitalWrite(ledPin[i], HIGH);
  }
  delay(500);
  for (int i = 3; i < 6; i++){
    digitalWrite(ledPin[i], LOW);
  }
  delay(1000);

  //4 vs 2 pattern
  digitalWrite(ledPin[0], HIGH);
  digitalWrite(ledPin[1], HIGH);
  digitalWrite(ledPin[2], HIGH);
  digitalWrite(ledPin[3], HIGH);
  delay(500);
  digitalWrite(ledPin[0], LOW);
  digitalWrite(ledPin[1], LOW);
  digitalWrite(ledPin[2], LOW);
  digitalWrite(ledPin[3], LOW);
  delay(500);
  for (int i = 4; i < 6; i++){
    digitalWrite(ledPin[i], HIGH);
  }
  delay(500);
  for (int i = 4; i < 6; i++){
    digitalWrite(ledPin[i], LOW);
  }
  delay(1000);

  //5 vs 1 pattern
  digitalWrite(ledPin[0], HIGH);
  digitalWrite(ledPin[1], HIGH);
  digitalWrite(ledPin[2], HIGH);
  digitalWrite(ledPin[3], HIGH);
  digitalWrite(ledPin[4], HIGH);
  delay(500);
  digitalWrite(ledPin[0], LOW);
  digitalWrite(ledPin[1], LOW);
  digitalWrite(ledPin[2], LOW);
  digitalWrite(ledPin[3], LOW);
  digitalWrite(ledPin[4], LOW);
  delay(500);
  for (int i = 5; i < 6; i++){
    digitalWrite(ledPin[i], HIGH);
  }
  delay(500);
  for (int i = 5; i < 6; i++){
    digitalWrite(ledPin[i], LOW);
  }
  delay(1000);

  //6 vs 0 pattern
  digitalWrite(ledPin[0], HIGH);
  digitalWrite(ledPin[1], HIGH);
  digitalWrite(ledPin[2], HIGH);
  digitalWrite(ledPin[3], HIGH);
  digitalWrite(ledPin[4], HIGH);
  digitalWrite(ledPin[5], HIGH);
  delay(500);
  digitalWrite(ledPin[0], LOW);
  digitalWrite(ledPin[1], LOW);
  digitalWrite(ledPin[2], LOW);
  digitalWrite(ledPin[3], LOW);
  digitalWrite(ledPin[4], LOW);
  digitalWrite(ledPin[5], LOW);
  delay(1000);
}
