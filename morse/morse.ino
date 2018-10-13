void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
    // .
   for(int i = 0; i < 3; i++){
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(500);
    }
    // -
    for(int i = 0; i < 3; i++){
      digitalWrite(13, HIGH);
      delay(300);
      digitalWrite(13, LOW);
      delay(500);
    }
    // .
    for(int i = 0; i < 3; i++){
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(500);
    }
    delay(1000);
}
