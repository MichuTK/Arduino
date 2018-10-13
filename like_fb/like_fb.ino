#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int t = 0;

void setup() {
  Serial.begin(9600);  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.clear();
  
}

void loop() {
  if (Serial.available() > 0) {
    t = Serial.parseInt();

    Serial.print("I received: ");
    Serial.println(t, DEC);
  }
    lcd.print(t);
}

void weather() {
  lcd.setCursor(1, 1);
  lcd.write(byte(1));
  lcd.setCursor(3, 1);
  lcd.print(t);
  lcd.write(byte(2));
  lcd.print("C ");
  lcd.setCursor(10, 1);
  lcd.write(byte(0));
  lcd.setCursor(12, 1);
  lcd.print("--%  ");
}

