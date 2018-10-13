#include <Wire.h>   // standardowa biblioteka Arduino
#include <LiquidCrystal_I2C.h> // dolaczenie pobranej biblioteki I2C dla LCD

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu ukladu na 0x27

void setup() {
  lcd.begin(16, 2);  // Inicjalizacja LCD 2x16

  lcd.backlight(); // zalaczenie podwietlenia
  lcd.setCursor(0, 0); // Ustawienie kursora w pozycji 0,0 (pierwszy wiersz, pierwsza kolumna)

  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  lcd.print("Miernik  Swiatla");
  lcd.setCursor(2, 1);
  lcd.print("Jasnosc:");
  //lcd.setCursor(11,1);

  int sensorValue = analogRead(A0);
  int swiatlo = sensorValue * (100.0 / 1023.0);
  lcd.setCursor(11, 1);
  lcd.print(swiatlo);
  Serial.println(swiatlo);
  lcd.print("%        ");

  if (swiatlo < 30) {
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
  }

  delay(500);

}
