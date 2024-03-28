// Created and improvised by Group 5 TT2C & helped by Mr. Nur Sulaiman 
// No Chat GPT include in this code, natural dari pemahaman individu dengan menggunakan manipulasi data sederhana
#include <Wire.h>
#include "DataLux.h"
byte addr;
char pesan[30];
char tampilan[160];
byte senderAddr;
bool status;
char luX[5];

void setup() {
  char c[30];
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  addr = PINB & 0b00000011;  // baca DIP-SW
  Wire.begin(addr);
  Serial.begin(9600);
  Serial.setTimeout(5000);
  Wire.onReceive(receiveEvent);
  sprintf(c, "MK %d (Luxmeter) siap...", addr);
  Serial.println(c);
}

void loop() {

  calculateLux();
  // Sending Message
  if (Serial.available()){
    byte dest; // alamat tujuan
    String s = "", pesan = "";
    s = Serial.readStringUntil('/');
    dest = s[0]; // ekstraksi String s
    pesan = s.substring(1);
    kirim(pesan, dest);
  }

  if(status == true){
    // Converting char to String + remove space
    String message = String(pesan);
    message.trim();

    //Checking the variable content
    if(message == "l" | message == "L"){
      // Notification
      Serial.println();
      Serial.print("Proccesing Request to MK "); Serial.println(senderAddr);

      for(int i = 0; i < 5; i++){  
        kirimData(calculateLux(),senderAddr);
        // Serial.print(s);
      }
      Serial.print("Data has sended.");
    }
    // For Debugging only
    else{
      // Serial.println("Gagal mengirimkan data");
    }
    status = false;

  }
}

// Message Send Function
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

// Message send data Function
void kirimData(float lux, byte senderAddr){
  char satuan[4] = " Lux";
  int sender = senderAddr;
  float Lux = lux;
  dtostrf(Lux,5,2,luX);

  for(int x = 0; x < 5; x++){
    Wire.begin();
    Wire.beginTransmission(senderAddr);
    Wire.write(luX,5);
    Wire.write(addr);
    Wire.endTransmission();
    delay(250);
  }
  Wire.begin(addr);
}

void receiveEvent(int i){
  char cal[160];
  byte j = 0;
  while (1 < Wire.available()){
    pesan[j] = Wire.read();
    j++;
  }
  senderAddr = Wire.read();
  sprintf(tampilan, "%d-> %s", senderAddr,  pesan);
  Serial.println();
  Serial.print(tampilan);

  status = true;
}
