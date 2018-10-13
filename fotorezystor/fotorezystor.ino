int fotoPin = 0;    
int fotoDane;  
   
void setup(void) {
  Serial.begin(9600);  
}

void loop(void) {
  fotoDane = analogRead(fotoPin);  
  Serial.print("Oswietlenie = ");
  Serial.println(fotoDane);     
  delay(1000);
}
