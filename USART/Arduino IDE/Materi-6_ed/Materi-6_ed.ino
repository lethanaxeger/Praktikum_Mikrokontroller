#include <Wire.h>
void setup() {
  // put your setup code here, to run once:
  Wire.begin(2);
  Wire.onRequest(requestEvent);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
}

void requestEvent(){
  Wire.write("Test kak, saya pengirim");
}
