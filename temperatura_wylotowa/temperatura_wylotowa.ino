#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
DHT dht;

byte c[] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

int temp;
int min;
int max;

void setup() {
  lcd.begin(16, 2);
  dht.setup(2);
  lcd.setCursor(0, 0);
  lcd.print("Temp  Min   Max");
  lcd.createChar(0, c); // Symbol stopni
  temp = dht.getTemperature();
  min = temp;
  max = temp;
}



void loop() {
  temp = dht.getTemperature();
  
  if (temp > max) max = temp;
  if (temp < min || min == 0) min = temp;

  lcd.setCursor(0, 1);
  lcd.print(temp);
  lcd.write(byte(0));
  lcd.print("C ");
  lcd.setCursor(6, 1);
  lcd.print(min);
  lcd.write(byte(0));
  lcd.print("C ");
  lcd.setCursor(12, 1);
  lcd.print(max);
  lcd.write(byte(0));
  lcd.print("C ");


  delay(dht.getMinimumSamplingPeriod());
  delay(dht.getMinimumSamplingPeriod());

}
