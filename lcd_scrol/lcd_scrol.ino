#include <LiquidCrystal_I2C.h> // dolaczenie pobranej biblioteki I2C dla LCD

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu ukladu na 0x27

void setup() {
  lcd.begin(16, 2);  // Inicjalizacja LCD 2x16
  lcd.setCursor(0, 0);
  lcd.print("MIERNIK SWIATLA");
}

void loop() {
  int sensorValue = analogRead(A0);
  int light = sensorValue * (100.0 / 1023.0);
  lcd.setCursor(6, 1);
  lcd.print(light);
  lcd.print("%  ");
  delay(100);
}
