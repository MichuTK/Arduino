void setup() {
  Serial.begin(9600); // zaczynam transmisję
  Serial.println("Start programu");
  pinMode(13, OUTPUT);

}

  double x = 14; 
  double y = 6;

void loop() {
  Serial.print("Dodawanie: ");
  Serial.println(x + y);

  Serial.print("Odejmowanie: ");
  Serial.println(x - y);

  Serial.print("Mnożenie: ");
  Serial.println(x * y);

  /*
  Serial.print("Dzielenie całkowite: ");
  Serial.print(x / y);
  Serial.print(" reszty ");
  Serial.println(x % y);
  */

  Serial.print("Dzielenie: ");
  Serial.println(x / y);

  Serial.println(); // odstęp
  delay(3000);

  
}
