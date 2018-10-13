#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu ukladu na 0x27
String inData;

void setup() {
    Serial.begin(9600);
    lcd.backlight();
}

void loop() {

    while (Serial.available() > 0)
    {
        char recieved = Serial.read();
        inData += recieved; 
        
        if (recieved == '*')
        {
            inData.remove(inData.length() - 1, 1);
            lcd.setCursor(0,0);
            lcd.print("GPU Temp.: " + inData + char(223)+"C ");
            inData = ""; 
            
            if(inData == "DIS")
            {   
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("Disconnected!");
            }
        } 
        
        if (recieved == '#')
        {
            inData.remove(inData.length() - 1, 1);
            lcd.setCursor(0,1);
            lcd.print("CPU Temp.: " + inData + char(223)+"C ");
            inData = ""; 
        }
    }
}
