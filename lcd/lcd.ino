/*
   LCM1602 & Arduino Uno
   VCC - > 5 V
   GND - GND
   SCL -> A5
   SDA -> A4
*/

#include <Wire.h>   // standardowa biblioteka Arduino
#include <LiquidCrystal_I2C.h> // dolaczenie pobranej biblioteki I2C dla LCD

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu ukladu na 0x27

void setup() {
  lcd.begin(16, 2);  // Inicjalizacja LCD 2x16
  lcd.backlight(); // zalaczenie podwietlenia
  lcd.setCursor(0, 0); // Ustawienie kursora w pozycji 0,0 (pierwszy wiersz, pierwsza kolumna
  lcd.clear();
  Serial.begin(9600);
  Serial.println("<Arduino is ready>");
}

int incomingByte = 0;

void loop() {


  if (Serial.available() > 0) {
    incomingByte = Serial.parseInt();

    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }

  lcd.setCursor(0, 0);
  lcd.print(incomingByte);
  delay(1000);
}
