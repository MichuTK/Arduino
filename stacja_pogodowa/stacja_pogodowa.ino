#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DS3231.h>
#include "DHT.h"

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
DS3231 clock;
RTCDateTime dt;
DHT dht;

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
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};


void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, hum); // Symbol wilgotnosci
  lcd.createChar(1, temp); // Symbol temperatury
  lcd.createChar(2, c); // Symbol stopni
  lcd.setCursor(5, 0);
  lcd.print("STACJA");
  lcd.setCursor(4, 1);
  lcd.print("POGODOWA");
  delay(1000);
  lcd.clear();

  Serial.begin(9600);

  // Inicjalizacja DS3231
  clock.begin();

  dht.setup(2);

  // Ustawianmy date i godzne kompilacji szkicu
  clock.setDateTime(__DATE__, __TIME__);

}

void loop() {
  dt = clock.getDateTime();
  lcd.setCursor(0, 0);
  lcd.print(clock.dateFormat("H:i  d M y", dt));
  Serial.println(clock.dateFormat("H:i:s  d M y", dt));

  weather();

  delay(dht.getMinimumSamplingPeriod());
}

void weather() {
  int humidity = dht.getHumidity();
  int temperature = dht.getTemperature();

  delay(dht.getMinimumSamplingPeriod());

  lcd.setCursor(1, 1);
  lcd.write(byte(1));
  lcd.setCursor(3, 1);
  lcd.print(temperature);
  lcd.write(byte(2));
  lcd.print("C ");
  lcd.setCursor(10, 1);
  lcd.write(byte(0));
  lcd.setCursor(12, 1);
  lcd.print(humidity);
  lcd.print("% ");
  
}

