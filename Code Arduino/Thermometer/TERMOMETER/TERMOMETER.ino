#include <LiquidCrystal.h>

int dataADC;
float T;
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

void setup() {
lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
dataADC = analogRead(A0);

T = dataADC * 0.489;

lcd.setCursor(0,0); lcd.print("Data="); lcd.print(dataADC);
lcd.setCursor(0,1); lcd.print("T="); lcd.print(T);
lcd.write(0XDF); lcd.write('C');
delay(100);
}
