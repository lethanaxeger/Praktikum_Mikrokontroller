// #include <LiquidCrystal.h>

int dataADC;
float Vin, RLDR, logRK, I;
// LiquidCrystal lcd(13,12,11,10,9,8);

void setup(){
  // lcd.begin(16, 2);
}

void loop(){
  /* put your main code here, to run repeatedly. */
  dataADC = analogRead(A0);

  Vin = dataADC * 0.00489;
  RLDR = (5000.0 / Vin - 1000.0);
  logRK = log10(RLDR/127262.2); //RLDR dibagi dengan persamaan cahaya dari kemampuan LDR
  I = pow(10.0, logRK / (-0.858));

  /* Setup untuk LiquidCrystal LCD */
  // lcd.setCursor(0,0);
  // lcd.print("Data = "); lcd.print(dataADC);
  // lcd.setCursor(0,1);
  // lcd.print("T = "); lcd.print(I);; lcd.print(" Lux");
  // delay(100);
}