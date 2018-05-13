int r = 9;
int g = 10;
int b = 11;

void setup() {
  pinMode(r, OUTPUT); 
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}

void loop() {
  /*
  digitalWrite(r, LOW);
  digitalWrite(g, HIGH);
  digitalWrite(b, HIGH);
  delay(500);

  digitalWrite(r, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(b, HIGH);
  delay(500);

  digitalWrite(r, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(b, LOW);
  delay(500);
  */
  analogWrite(r, analogRead(A0)/4);
  analogWrite(g, analogRead(A1)/4);
  analogWrite(b, analogRead(A2)/4);
}
