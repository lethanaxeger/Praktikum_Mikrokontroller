byte Kode7s[] = {3, 0x9F, 0x25, 0x0D, 0x99, 0x49, 0x41, 0x1F, 1, 9, 0x0FE};

void setup() {
  // put your setup code here, to run once:
  DDRD = 225;
}

int i = 456;
float f = 23.5;

void loop() {
  // put your main code here, to run repeatedly:
  //tampilIntCara1(i);
  //delay(500); blip(); delay(500);
  //tampilIntCara2(i);
  //delay(1000); blip(); delay(1000);
  tampilFloat(f);
  delay(500); blip(); delay(500);
}

void tampilIntCara1(int nilai){
  char angka[] = {0,0,0,0,0};
  
  angka[0] = nilai / 100;
  angka[1] = (nilai - angka[0] * 100) / 10;
  angka[2] = (nilai - angka[0] * 100 - angka[1] * 10);

  for (byte b = 0; b < sizeof(angka); ++b){
    PORTD = Kode7s[angka[b]]; delay(500);
  }
}

void tampilIntCara2(int nilai){
  char kar[5];
  sprintf(kar, "%d", nilai);

  for (byte b =0; kar[b] != 0; ++b){
    PORTD = Kode7s[kar[b] & 0x0F]; delay(500);
  }
}

void tampilFloat(float nilai){
  char kar[5];
  dtostrf(nilai, 4, 1, kar);

  for (byte b = 0; kar[b] != 0; ++b){
    PORTD = Kode7s[kar[b] & 0x0F]; delay(500);
  }
}

void blip(){
  PORTD = 0;
  for(byte b = 0; b<5; ++b){
    PORTD = ~PORTD; delay(100);
  }
  PORTD = 255;
}