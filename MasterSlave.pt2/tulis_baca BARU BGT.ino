#include <Wire.h>

byte addr;
void setup() {
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  addr = PINB & 0b00000011;
  Wire.begin(addr);
  Serial.begin(9600);
  switch (addr){
    case 2: delay(200); break;
    case 3: delay(300); break;
  }
  Wire.onReceive(receiveEvent);
  Serial.print("MK ");
  Serial.print(addr);
  Serial.print(" ready ...");
}

byte x = 0;
void loop() {
  Wire.begin();
  switch (addr) {
    case 2:
    Wire.beginTransmission(3);
    Wire.write("From 2: ");
    Wire.write(x);
    Wire.endTransmission();
    x +=2;
    break;
    case 3:
    Wire.beginTransmission(2);
    Wire.write("From 3: ");
    Wire.write(x);
    Wire.endTransmission();
    x +=3;
  }
  Wire.begin(addr);
  delay(100);
}

void receiveEvent(int i){
  String s = "";
  char c;
  while (1<Wire.available()){
    c = Wire.read();
    s += c;
  }
  s += Wire.read();
  Serial.println(s);
}