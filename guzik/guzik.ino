int guzik = 12;
int dioda = 1;

void setup() {
  pinMode(dioda, OUTPUT);
  pinMode(guzik, INPUT);

}

void loop() {
  if(digitalRead(guzik) == HIGH)
    digitalWrite(dioda, HIGH);

}
