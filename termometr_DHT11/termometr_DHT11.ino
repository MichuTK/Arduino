#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHT11_PIN 2

DHT dht;
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

byte hum[] = {
  B00100,
  B00100,
  B01010,
  B01010,
  B10001,
  B10001,
  B10001,
  B01110
};

byte temp[] = {
  B00100,
  B01010,
  B01010,
  B01110,
  B01110,
  B11111,
  B11111,
  B01110
};

byte c[] = {
  B11100,
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

void setup() {
  Serial.begin(9600);
  dht.setup(DHT11_PIN);

  lcd.begin(16, 2);
  lcd.createChar(0, hum);
  lcd.createChar(1, temp);
  lcd.createChar(2, c);
  lcd.clear();
}

void loop() {
  //Pobranie informacji o wilgotnosci
  int wilgotnosc = dht.getHumidity();
  //Pobranie informacji o temperaturze
  int temperatura = dht.getTemperature();

  if (dht.getStatusString() == "OK") {
    lcd.setCursor(1, 0);
    lcd.write(byte(1));
    lcd.setCursor(3, 0);
    lcd.print(temperatura);
    lcd.write(byte(2));
    lcd.print("C ");

    lcd.setCursor(10, 0);
    lcd.write(byte(0));
    lcd.setCursor(12, 0);
    lcd.print(wilgotnosc);
    lcd.print("% ");
  }

  delay(dht.getMinimumSamplingPeriod()); //Odczekanie wymaganego czasu
}
