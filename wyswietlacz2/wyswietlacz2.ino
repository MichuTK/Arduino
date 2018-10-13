#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu ukladu na 0x27

#define a 13
#define b 12
#define c 11
#define d 10
#define e 9
#define f 8
#define g 7

//#define a2 0
//#define b2 1
#define c2 2
#define d2 3
#define e2 4
#define f2 5
#define g2 6

int op = 10;
int x;
String inData;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  lcd.begin(16, 2);  // Inicjalizacja LCD 2x16
  lcd.print("Hello");
  delay(1000);
  lcd.clear();
}

void loop() {
  if (Serial.available() > 0) {
    x = Serial.parseInt();
    Serial.println(x, DEC);
  }



  while (Serial.available() > 0)
  {
    char recieved = Serial.read();
    inData += recieved;

    if (recieved == '*')
    {
      inData.remove(inData.length() - 1, 1);
      lcd.setCursor(0, 0);
      lcd.print("GPU Temp.: " + inData + char(223) + "C ");
      inData = "";

      if (inData == "DIS")
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Disconnected!");
      }
    }

    if (recieved == '#')
    {
      inData.remove(inData.length() - 1, 1);
      lcd.setCursor(0, 1);
      lcd.print("CPU Temp.: " + inData + char(223) + "C ");
      inData = "";
    }
  }



  if (x < 100) {
    switch (x % 10) {
      case 0: zerob(); break;
      case 1: jedenb(); break;
      case 2: dwab(); break;
      case 3: trzyb(); break;
      case 4: czteryb(); break;
      case 5: piecb(); break;
      case 6: szescb(); break;
      case 7: siedemb(); break;
      case 8: osiemb(); break;
      case 9: dziewiecb(); break;
    }

    switch (x / 10) {
      case 0: zero(); break;
      case 1: jeden(); break;
      case 2: dwa(); break;
      case 3: trzy(); break;
      case 4: cztery(); break;
      case 5: piec(); break;
      case 6: szesc(); break;
      case 7: siedem(); break;
      case 8: osiem(); break;
      case 9: dziewiec(); break;
    }
  } else {
    ol();
  }
}

void ol() {
  //O
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
  //L
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(c2, HIGH);
  digitalWrite(d2, LOW);
  digitalWrite(e2, LOW);
  digitalWrite(f2, LOW);
  digitalWrite(g2, HIGH);
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
  delay(op);
}

void jeden() {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
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
  delay(op);
}

void zerob() {
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(c2, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(e2, LOW);
  digitalWrite(f2, LOW);
  digitalWrite(g2, HIGH);
  delay(op);
}

void jedenb() {
  digitalWrite(A0, HIGH);
  digitalWrite(A1, LOW);
  digitalWrite(c2, LOW);
  digitalWrite(d2, HIGH);
  digitalWrite(e2, HIGH);
  digitalWrite(f2, HIGH);
  digitalWrite(g2, HIGH);
  delay(op);
}

void dwab() {
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(c2, HIGH);
  digitalWrite(d2, LOW);
  digitalWrite(e2, LOW);
  digitalWrite(f2, HIGH);
  digitalWrite(g2, LOW);
  delay(op);
}

void trzyb() {
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(c2, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(e2, HIGH);
  digitalWrite(f2, HIGH);
  digitalWrite(g2, LOW);
  delay(op);
}

void czteryb() {
  digitalWrite(A0, HIGH);
  digitalWrite(A1, LOW);
  digitalWrite(c2, LOW);
  digitalWrite(d2, HIGH);
  digitalWrite(e2, HIGH);
  digitalWrite(f2, LOW);
  digitalWrite(g2, LOW);
  delay(op);
}

void piecb() {
  digitalWrite(A0, LOW);
  digitalWrite(A1, HIGH);
  digitalWrite(c2, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(e2, HIGH);
  digitalWrite(f2, LOW);
  digitalWrite(g2, LOW);
  delay(op);
}

void szescb() {
  digitalWrite(A0, LOW);
  digitalWrite(A1, HIGH);
  digitalWrite(c2, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(e2, LOW);
  digitalWrite(f2, LOW);
  digitalWrite(g2, LOW);
  delay(op);
}

void siedemb() {
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(c2, LOW);
  digitalWrite(d2, HIGH);
  digitalWrite(e2, HIGH);
  digitalWrite(f2, HIGH);
  digitalWrite(g2, HIGH);
  delay(op);
}

void osiemb() {
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(c2, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(e2, LOW);
  digitalWrite(f2, LOW);
  digitalWrite(g2, LOW);
  delay(op);
}

void dziewiecb() {
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(c2, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(e2, HIGH);
  digitalWrite(f2, LOW);
  digitalWrite(g2, LOW);
  delay(op);
}
