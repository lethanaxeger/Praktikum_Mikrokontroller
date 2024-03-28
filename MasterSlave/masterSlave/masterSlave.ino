#include <Wire.h>
void setup() {
  delay(1);
  Wire.begin(4);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  Serial.println(" ");
  Serial.println("Enter a character and press Enter : ");
}

byte x = 0;
void loop() {
  while(Serial.available() == 0){
    // Buffer
  }
  char inputChar = Serial.read();
  Wire.beginTransmission(4);
  Wire.write(inputChar);
  Wire.endTransmission();
  if(x == 0){
    Serial.print("Aku : "); Serial.write(inputChar);
  } else {
    Serial.write(inputChar);
  }
  x++;
  delay(100);
}

byte y = 0;
void receiveEvent(int jmlData){
  while(1 < Wire.available()){
    char c = Wire.read();
    Serial.print(c);
  }
  char c = Wire.read();
  if(y == 0){
    Serial.print("Dia : "); Serial.write(c);
  } else {
    Serial.write(c);
  }
  y++;
  if (y == c){
    y = 0;
    return y;
  }
}