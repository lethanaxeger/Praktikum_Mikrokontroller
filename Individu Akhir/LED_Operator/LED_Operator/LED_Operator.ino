// Created and improvised by Group 5 TT2C & helped by Mr. Nur Sulaiman 
// No Chat GPT include in this code, natural dari pemahaman individu dengan menggunakan manipulasi data sederhanas
#include <Wire.h>
#include "teganganCount.h"

byte addr;
char pesan[30];
byte senderAddr;
bool status;
char vleD[5];

void setup() {
  char c[30];

  //Register Port
  DDRD = 0b11111100;
  // DIP-SW
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  addr = PINB & 0b00000011;  // baca DIP-SW
  Wire.begin(addr);
  // Serial.setTimeout(5000);
  Wire.onReceive(receiveEvent);
  // sprintf(c, "MK %d (LED Operator) siap...", addr);
  // Serial.println(c);
}

void loop() {

  teganganCount();

  if(status == true){
    String message = String(pesan);
    message.trim();

    if(message == "on" | message == "ON"){
      // Manipulate the Port
      PORTD = (DDRD & PORTD) | 0b00000100;
    }
    else if(message == "off" | message == "OFF"){
      // Manipulate the Port
      PORTD = (DDRD & PORTD) & 0b00000000;
    }
    else if(message == "ls" | message == "LS"){
      for(int i = 0; i < 5; i++){
        kirimData(teganganCount(),senderAddr);
      }
    }
    // For Debugging only
    else{
      // Serial.println("Gagal mengirimkan data");
    }
    status = false;
  }
}

//Message send data Function
void kirimData(float Vled, byte senderAddr){
  char data[160];
  float V = Vled;
  dtostrf(V,5,2,vleD);
  sprintf(data, vleD, " Volt");
  //Satuan
  for(int x = 0; x < 5; x++){
    Wire.begin();
    Wire.beginTransmission(senderAddr);
    Wire.write(data);
    Wire.write(addr);
    Wire.endTransmission();
    delay(250);
  }
  Wire.begin(addr);
}

void receiveEvent(int i){
  char tampilan[160], cal[160];
  byte j = 0;
  while (1 < Wire.available()){
    pesan[j] = Wire.read();
    j++;
  }
  senderAddr = Wire.read();

  status = true;
}
