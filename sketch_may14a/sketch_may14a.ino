#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
}

void loop() {
  clock();
}

void clock() {
  lcd.setCursor(0, 0);
  lcd.write("12:45 ");
  lcd.write("14-05-18");
}

