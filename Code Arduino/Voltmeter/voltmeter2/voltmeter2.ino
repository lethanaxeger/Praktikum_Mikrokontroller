#include <LiquidCrystal.h>

int dataADC;
float Vin;
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

void setup() {
lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
dataADC = analogRead(A0);

Vin = dataADC * 5.0 / 1023;

lcd.setCursor(0,0); lcd.print("Data="); lcd.print(dataADC);
lcd.setCursor(0,1); lcd.print("Vin="); lcd.print(Vin);
delay(100);
}
