void setup() {
  // put your setup code here, to run once:
  DDRB = B00000011;  
  DDRB = DDRB|B11111011;
}

void loop() {
  // put your main code here, to run repeatedly:
  // PORTD |= B00001000;
}
