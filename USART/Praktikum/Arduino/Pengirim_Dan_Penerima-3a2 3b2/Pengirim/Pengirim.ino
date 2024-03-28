#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
}

byte x = 0;

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(8);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  x++;
  delay(1000);
}
