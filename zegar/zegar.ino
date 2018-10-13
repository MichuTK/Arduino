#include <Wire.h>   // standardowa biblioteka Arduino
#include <LiquidCrystal_I2C.h> // dolaczenie pobranej biblioteki I2C dla LCD

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu ukladu na 0x27

int setupButton = 2;

void setup() {
  lcd.begin(16, 2);  // Inicjalizacja LCD 2x16

  lcd.backlight(); // zalaczenie podwietlenia

  pinMode(setupButton, INPUT);
}

int h = 12;
int m = 56;
int s = 50;
int day = 12;
int month = 5;
int year = 2018;

void loop() {
  if (digitalRead(setupButton) == HIGH) {
    m++;
  }
  data();
  time();
  delay(999);
}

void time() {
  s++;

  if (s == 60) {
    m++;
    s = 0;////
  }
  if (m == 60) {
    h++;
    m = 0;
  }
  if (h == 24) {
    h = 0;
    day++;
  }

  lcd.setCursor(4, 1);
  if (h < 10) lcd.print("0");
  lcd.print(h);
  lcd.print(":");
  if (m < 10) lcd.print("0");
  lcd.print(m);
  lcd.print(":");
  if (s < 10) lcd.print("0");
  lcd.print(s);
  lcd.print("    ");
}

void data() {
  lcd.setCursor(3, 0);
  lcd.print(day);
  pmonth(month);
  lcd.setCursor(9, 0);
  lcd.print(year);
  lcd.print("   ");
}

void pmonth(int m) {
  lcd.setCursor(5, 0);
  if (m == 1) lcd.print("-01-");
  if (m == 2) lcd.print("-02-");
  if (m == 3) lcd.print("-03-");
  if (m == 4) lcd.print("-04-");
  if (m == 5) lcd.print("-05-");
  if (m == 6) lcd.print("-06-");
  if (m == 7) lcd.print("-07-");
  if (m == 8) lcd.print("-08-");
  if (m == 9) lcd.print("-09-");
  if (m == 10) lcd.print("-10-");
  if (m == 11) lcd.print("-11-");
  if (m == 12) lcd.print("-12-");
}
