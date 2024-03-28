#include <Wire.h>
void setup() {
  delay(1);
  Wire.begin();
}

byte x = 0;
void loop() {
  Wire.beginTransmission(4);
  Wire.write("x = ");
  Wire.write(x);

  Wire.endTransmission();
  delay(250);
  x++;
}
