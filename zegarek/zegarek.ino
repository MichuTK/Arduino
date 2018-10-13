#include <Wire.h>
#include <DS3231.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
DS3231 clock;
RTCDateTime dt;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();

  // Inicjalizacja DS3231
  Serial.println("Initialize DS3231");
  clock.begin();

  // Ustawianmy date i godzne kompilacji szkicu
  clock.setDateTime(__DATE__, __TIME__);

  // Lub recznie (YYYY, MM, DD, HH, II, SS)
  // clock.setDateTime(2014, 4, 13, 19, 21, 00);
  clock.dateFormat("d m y, H:i", dt);
}

void loop() {
  // Odczytujemy i wyswietlamy czas
  dt = clock.getDateTime();

  Serial.print("Raw data: ");
  Serial.print(dt.year);   Serial.print("-");
  Serial.print(dt.month);  Serial.print("-");
  Serial.print(dt.day);    Serial.print(" ");
  Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");

  lcd.setCursor(0, 0);
  lcd.print(clock.dateFormat("H:i  d M y", dt));
  
  
  //lcd.print(dt.hour);   lcd.print(":");
  //lcd.print(dt.minute);  lcd.print(":");
  //lcd.print(dt.second);   lcd.print("   ");
  //lcd.setCursor(0, 1);
  //lcd.print(dt.hour);   lcd.print(":");
  //lcd.print(dt.minute); lcd.print(":");
  //lcd.print(dt.second); lcd.println("");

  delay(1000);
}
