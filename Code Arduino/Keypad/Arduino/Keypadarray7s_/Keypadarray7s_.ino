byte Kode7s[] = { 3, 0x9F, 0x25, 0x0D, 0x99, 0x49, 0x41, 0x1F, 1, 9, 0x0FE };
char bufferDisplay = 10;

const byte scanBA = 0b00011100, scanBB = 0b00101100, scanBC = 0b00110100, scanBD = 0b00111000;
byte keyScan[] { scanBA, scanBB, scanBC, scanBD }, iKeyB = 0, iKeyC, keyDetect, keyBuff;
char listKey[4][5] = { {"789/"}, {"456X"}, {"123-"}, {"C0=+"} };
long tDsp0 = millis(), tScan0 = millis();

void setup() {
  DDRD = 0b11111111;
  PORTB = (PORTB & 0b11000011) | 0b00111100;
  DDRB = 0b00111100;
  PORTC = (PORTC & 0b11000011) | 0b00111100;
  DDRC = 0b00000000;
}

void loop() {
  if ((millis () - tDsp0) > 13) {
    tDsp0 = millis();
    PORTD = Kode7s[bufferDisplay];
}

  if ((millis() - tScan0) > 10) {
    tScan0 = millis();
    PORTB = (PORTB & 0b11000011) | keyScan[iKeyB];
    delay(10);
    keyDetect = PINC & 0b00111100;
    if (keyDetect != 0b00111100) {
          switch (keyDetect) {
            case scanBA: iKeyC = 0; break;
            case scanBB: iKeyC = 1; break;
            case scanBC: iKeyC = 2; break;
            case scanBD: iKeyC = 3; break;
          }
          keyBuff = listKey[iKeyB][iKeyC];
      } 
      if ((keyBuff >= 0x30) & (keyBuff <= 0X39) ){bufferDisplay = keyBuff & 0X0F; }
      else {bufferDisplay = 10;}

    ++iKeyB;
    if (iKeyB == 4) { iKeyB = 0;}
  }   
}