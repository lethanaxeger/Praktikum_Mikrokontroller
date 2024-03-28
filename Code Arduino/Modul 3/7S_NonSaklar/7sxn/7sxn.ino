//Jika kecepatan scan (fscan) 25 kali per detik maka periode scan (Tscan) adalah 0.04 s
// --> 1 digit mendapat jatah waktu (Tdigit) selama Tscan / 3 = 0.013 s

byte Kode7s[] = { 3, 0x9F, 0X25, 0X0D, 0X99, 0X49, 0X41, 0X1F, 1, 9, 0X0FE };
int i = 124;
float f = 48.6;
char bufferDisplay[5], iDsp=0, scanDsp[] = {0b00011000, 0b00101000, 0b00110000};
long tDsp0=millis(), dt;

void setup() {
  DDRD = 0b11111111;
  PORTB = (PORTB & 0b11000111) | 0b00111000;
  DDRB = 0b00111000;
  //Percetakan ke buffer
  sprintf(bufferDisplay, "%d", i);
}

void loop() {
  // Display
  dt = millis() - tDsp0;
  if ( dt > 5 ){
    tDsp0 = millis();
    PORTD = 255; //blanking
    PORTD = Kode7s[bufferDisplay[iDsp] & 0x0F];
    PORTB = (PORTB & 0b11000111) | scanDsp[iDsp];
    iDsp++;
    if (iDsp == 3) { iDsp = 0; }
    }
  }