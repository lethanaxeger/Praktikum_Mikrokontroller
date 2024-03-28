// Created and improvised by Group 5 TT2C & helped by Mr. Nur Sulaiman 
// No Chat GPT include in this code, natural dari pemahaman individu dengan menggunakan manipulasi data sederhana
#include <Wire.h>
#include "DataSuhu.h"
float celcius;
byte addr;
char  pesan[30];
byte senderAddr;
bool status;
char temP[5];

void setup() {
  char c[30];
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  addr = PINB & 0b00000011;  // baca DIP-SW
  Wire.begin(addr);
  Serial.begin(9600);
  Serial.setTimeout(5000);
  Wire.onReceive(receiveEvent);
  sprintf(c, "MK %d (Thermometer) siap...", addr);
  Serial.println(c);
}

void loop() {
  calculateData();
  // Sending Message
  if (Serial.available()){
    byte dest; // alamat tujuan
    String s = "", pesan = "";
    s = Serial.readStringUntil('/');
    dest = s[0]; // ekstraksi String s
    pesan = s.substring(1);
    kirim(pesan, dest);
  }
  delay(100);
  if(status == true){
    String message = String(pesan);
    message.trim();

    if(message == "t" | message == "T"){
      // Notification
      Serial.println();
      Serial.print("Proccesing Request to MK "); Serial.println(senderAddr);

      for(int i = 0; i < 5; i++){ 
          kirimData(calculateData(),senderAddr);
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
void kirimData(float suhu, byte senderAddr){
  char data[160];
  float Suhu = suhu;
  dtostrf(Suhu,5,2,temP);
  sprintf(data, temP, " Celcius");

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
  sprintf(tampilan, "%d-> %s", senderAddr, pesan);
  Serial.println();
  Serial.print(tampilan);
  
  status = true;
}
