#include <Wire.h>   // standardowa biblioteka Arduino
#include <LiquidCrystal_I2C.h> // dolaczenie pobranej biblioteki I2C dla LCD

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu ukladu na 0x27

byte s[] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};

void setup() {
  lcd.begin(16, 2);  // Inicjalizacja LCD 2x16
  lcd.backlight(); // zalaczenie podwietlenia
  lcd.clear();
  lcd.createChar(0, s);
  lcd.setCursor(1, 0); // Ustawienie kursora w pozycji 0,0 (pierwszy wiersz, pierwsza kolumna
  lcd.print("Test");
  lcd.setCursor(2,1);
  //lcd.print("Kocham Cie ");
  
  /*lcd.write(byte(0));
  lcd.write(byte(0));
  lcd.write(byte(0));
  lcd.write(byte(0));
  lcd.write(byte(0));
  lcd.write(byte(0));
  lcd.write(byte(0));
  lcd.write(byte(0));
  lcd.write(byte(0));
  lcd.write(byte(0));
  lcd.write(byte(0));
  lcd.write(byte(0));*/
  
}

void loop() {

}

