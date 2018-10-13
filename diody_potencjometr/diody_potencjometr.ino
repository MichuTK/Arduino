void setup() {
  for(int i = 1; i < 12; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(A0, INPUT);
}

void loop() {
  int rnd = random(10) + 1; 
  
  for(int i = 0; i < 12; i++){
    digitalWrite(i+1, LOW);
  }
  for(int i = 1; i < analogRead(A0)/100 + 1; i++){
    digitalWrite(i+1, HIGH);
  }

}
