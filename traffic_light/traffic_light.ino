#define red1 10
#define yellow1 9
#define green1 8
#define red2 4
#define green2 3
#define button 2

void setup() {
  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(button, INPUT);
  pinMode(green2, OUTPUT);
  pinMode(red2, OUTPUT);
  digitalWrite(green1, HIGH);
  digitalWrite(red2, HIGH);
}

void loop() {
  if (digitalRead(button) == HIGH) {
    delay(15);
    if (digitalRead(button) == HIGH) {
      delay(2000);
      changeLights();
      delay(10000); // wait for 15 seconds
    }
  }
}

void changeLights() {
  //yellow
  digitalWrite(yellow1, HIGH);
  digitalWrite(green1, LOW);
  delay(3000);

  //red
  digitalWrite(red1, HIGH);
  digitalWrite(yellow1, LOW);
  digitalWrite(green1, LOW);
  digitalWrite(green2, HIGH);
  digitalWrite(red2, LOW);
  delay(3000);

  //red and yellow
  digitalWrite(yellow1, HIGH);
  digitalWrite(green2, LOW);
  digitalWrite(red2, HIGH);
  delay(2000);

  //green
  digitalWrite(red1, LOW);
  digitalWrite(yellow1, LOW);
  digitalWrite(green1, HIGH);
  delay(5000);


}
