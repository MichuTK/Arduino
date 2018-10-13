int red = 9;
int green = 10;
int blue = 11;
int mode = 0;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  setColourRgb(0, 0, 0);
}

void loop() {
  unsigned int rgbColour[3];
  // Start off with red.
  rgbColour[0] = 255;
  rgbColour[1] = 0;
  rgbColour[2] = 0;

  if (Serial.available() > 0) {
    mode = Serial.parseInt();
    Serial.println(mode, DEC);
    if (mode == 0) {
      digitalWrite(red, HIGH);
      digitalWrite(green, HIGH);
      digitalWrite(blue, HIGH);
    } else if (mode == 1) {
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
      digitalWrite(blue, HIGH);
    } else if (mode == 2) {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(blue, HIGH);
    } else if (mode == 3) {
      digitalWrite(red, HIGH);
      digitalWrite(green, HIGH);
      digitalWrite(blue, LOW);
    } else if (mode == 4) {
      for (int decColour = 0; decColour < 3; decColour += 1) {
        int incColour = decColour == 2 ? 0 : decColour + 1;
        // cross-fade the two colours.
        for (int i = 0; i < 255; i += 1) {
          rgbColour[decColour] -= 1;
          rgbColour[incColour] += 1;
          setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
          delay(5);
        }
      }
    }
  }
}

void setColourRgb(unsigned int r, unsigned int g, unsigned int b) {
  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);
}
