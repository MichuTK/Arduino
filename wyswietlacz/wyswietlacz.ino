#define a 8
#define b 7
#define c 6
#define d 5
#define e 4
#define f 3
#define g 2
#define dp 9
#define button 10
int op = 1;


void setup() {
  Serial.begin(9600);
  
  pinMode(button, INPUT);

  for (int i = 2; i < 10; i++) {
    pinMode(i, OUTPUT);
    Serial.println(i);
  }

}

void loop() {
  //int sensorValue = analogRead(A0) / 100;
  //delay(1);

  int buttonState = digitalRead(pushButton);

  switch (sensorValue) {
    case 1:
      jeden();
      break;

    case 2:
      dwa();
      break;

    case 3:
      trzy();
      break;

    case 4:
      cztery();
      break;

    case 5:
      piec();
      break;

    case 6:
      szesc();
      break;

    case 7:
      siedem();
      break;

    case 8:
      osiem();
      break;

    case 9:
      dziewiec();
      break;

    case 0:
      zero();
      break;

    default:
      kropka();
      break;
  }


  /*
    jeden();
    dwa();
    trzy();
    cztery();
    piec();
    szesc();
    siedem();
    osiem();
    dziewiec();
    zero();*/

}

void kropka() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, LOW);
}

void jeden() {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, HIGH);
  delay(op);
}

void dwa() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(dp, HIGH);
  delay(op);
}

void trzy() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(dp, HIGH);
  delay(op);
}

void cztery() {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, HIGH);
  delay(op);
}

void piec() {
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, HIGH);
  delay(op);
}

void szesc() {
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, HIGH);
  delay(op);
}

void siedem() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, HIGH);
  delay(op);
}

void osiem() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, HIGH);
  delay(op);
}

void dziewiec() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, HIGH);
  delay(op);
}

void zero() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
  digitalWrite(dp, HIGH);
  delay(op);
}

