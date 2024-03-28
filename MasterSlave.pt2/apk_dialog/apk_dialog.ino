#include <Wire.h>
byte addr;
void setup() {
  char c[30];
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  addr = PINB & 0b00000011;  // baca DIP-SW
  Wire.begin(addr);
  Serial.begin(9600);
  Serial.setTimeout(5000);
  Wire.onReceive(receiveEvent);
  sprintf(c, "MK %d siap...", addr);
  Serial.println(c);
}

void loop() {
  if (Serial.available()){
    byte dest; // alamat tujuan
    String s = "", pesan = "";
    s = Serial.readStringUntil('/');
    dest = s[0]; // ekstraksi String s
    pesan = s.substring(1);
    kirim(pesan, dest);
  }
  delay(100);
}

void kirim(String pesan, byte destAddr){
  char c[160];
  byte i = pesan.length() + 1;
  destAddr -= 0x30;   //ASCII --> nilai
  pesan.toCharArray(c, i);    //String --> array of char
  Wire.begin();   //jadikan IIC master
  Wire.beginTransmission(destAddr);
  Wire.write(c, i);
  Wire.write(addr);
  Wire.endTransmission();
  Wire.begin(addr);   //jadikan IIC slave
}

void receiveEvent(int i){
  char tampilan[160], pesan[160];
  byte senderAddr, j = 0;
  while (1 < Wire.available()){
    pesan[j] = Wire.read();
    j++;
  }
  senderAddr = Wire.read();
  sprintf(tampilan, "%d-> %s", senderAddr, pesan);
  Serial.println();
  Serial.println(tampilan);
}
