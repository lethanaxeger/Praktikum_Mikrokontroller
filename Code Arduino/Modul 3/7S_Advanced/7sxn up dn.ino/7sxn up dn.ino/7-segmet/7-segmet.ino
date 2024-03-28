//Jika kecepatan scan (fscan) 25 kali per detik maka periode scan (fscan) adalah 0.04 s
// --> 1 digit mendapat jatah waktu (Tdigit) selama Tscan / 3 = 0.013 s

byte Kode7s[] = { 3, 0x9F, 0X25, 0X0D, 0X99, 0X49, 0X41, 0X1F, 1, 9, 0X0FE};
char bufferDisplay[5], iDsp = 0, scanDsp[] = { 0b00011000, 0b00101000, 0b00110000};
long tDsp0 = millis();

byte stateSw;

int i = 354;
float f = 45.6;

void setup() {
  DDRD = 0b11111111;
  PORTB = (PORTB & 0b11000111) | 0b00111110;
  DDRB = 0b00111000;
  sprintf(bufferDisplay, "%d", i);
}

void loop() {
  //Display
  if ( (millis() - tDsp0) > 5) {
    tDsp0 = millis();
    PORTD = 225; //blanking
    PORTD = Kode7s[bufferDisplay [iDsp] & 0x0F];
    PORTB = (PORTB & 0b11000111) | scanDsp[iDsp];
    iDsp++;
    if (iDsp == 3) { iDsp = 0;}
  }
if ((PINB & 0b00000110) == 0b00000010){
  i++;
  sprintf(bufferDisplay, "%d", i);
  delay(500);
} else if ((PINB & 0b00000110) == 0b00000100){
  i--;
  sprintf(bufferDisplay, "%d", i);
  delay(500);
  }
}

