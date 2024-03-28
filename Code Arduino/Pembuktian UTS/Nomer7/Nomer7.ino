long tDsp0 = millis();
char iDsp = 0, scanDsp[] = {0b00000010, 0b00000000};
void setup() {
		PORTB	= (PORTB & 0b11111000) | 0b00000000;
    DDRB	= 0b00000010;
}

void loop() {
 	for (int i = 0; i < 5; i++) {
    if(i > 4){
      delay(1000);
    }
    else if((millis() - tDsp0) > 500) {
      tDsp0 = millis();
			PORTB	= (PORTB & 0b11111000) | scanDsp[iDsp];
      iDsp++;
      if(iDsp ==  2){
        iDsp  = 0; 
      }
		}		
  }
}