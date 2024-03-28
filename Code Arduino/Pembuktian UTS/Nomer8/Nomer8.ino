long tDsp0 = millis();
char iDsp = 0, scanDsp[] = { 0b00000000, 0b00000001, 0b00000010, 0b00000100, 0b00000111};
void setup() {
  DDRB	= 0b00000111;
	PORTB	= (PORTB & 0b00000111) | 0b00000000;  
}

void loop() {
  PORTB	= (PORTB & 0b11111000) | scanDsp[1];
  delay(250);
  PORTB	= (PORTB & 0b11111000) | scanDsp[0];

  for (int j = 0; j < 2; j++) {
		PORTB	= (PORTB & 0b11111000) | scanDsp[4];
    delay(300);
    PORTB	= (PORTB & 0b11111000) | scanDsp[0];
    delay(300);
  }

  PORTB	= (PORTB & 0b11111000) | scanDsp[3];
  delay(250);
  PORTB	= (PORTB & 0b11111000) | scanDsp[0];
  delay(250);

  for (int j = 0; j < 4; j++) {
		PORTB	= (PORTB & 0b11111000) | scanDsp[4];
    delay(500);
    PORTB	= (PORTB & 0b11111000) | scanDsp[0];
    delay(500);
  }
  PORTB	= (PORTB & 0b11111000) | scanDsp[4];
  delay(250);
  PORTB	= (PORTB & 0b11111000) | scanDsp[1];
}