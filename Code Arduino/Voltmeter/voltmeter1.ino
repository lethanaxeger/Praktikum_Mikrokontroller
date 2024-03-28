int dataADC;
int n;

void setup() {
  // put your setup code here, to run once:
DDRD = B11111111;
DDRB = B00000011;
}

void loop() {
  // put your main code here, to run repeatedly:
dataADC = analogRead(A0);

for(byte n=0; n<10; n++);
  digitalWrite(n, bitRead(dataADC,n));

delay(100);
}
