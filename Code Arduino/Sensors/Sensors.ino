// #include <LiquidCrystal.h>

int dataADC1, dataADC2;
float T, Vin, RLDR, logRK, I;
// LiquidCrystal lcd(13,12,11,10,9,8);

void setup() {
  // TX RX pada LiquidCrystal
  // lcd.begin(16,2);
  Serial.begin(9600);
  }

void loop() {
  /* Sumber data analog ada disini. Rubah bila pin yang digunakan berbeda  */
  // dataADC = analogRead(A0); sesuaikan pin yang digunakan, A0 - A5

  // Luxmeter code
  dataADC1 = analogRead(A4);
  Vin = dataADC1 * 0.00489;
  RLDR = (5000.0 / Vin - 1000.0);
  logRK = log10(RLDR/2136978.55);
  I = pow(10.0, logRK / (-0.52));

  // lcd.setCursor(0,0);
  Serial.print("Data = "); Serial.print(dataADC1);
  Serial.print(", T = "); Serial.print(I); Serial.print(" Lux"); Serial.print(" | ");

  // Voltmeter code
  // dataADC = analogRead(A4);
  // Vin = dataADC * 5.0 / 1023;

  // // lcd.setCursor(0,0); 
  // Serial.print("Data = "); Serial.print(dataADC);
  // // lcd.setCursor(0,1); 
  // Serial.print("V | Input = "); Serial.println(Vin);

  // Thermometer code
  dataADC2 = analogRead(A5);
  T = dataADC2 * 0.489;

  // Serial.setCursor(0,0); 
  Serial.print("Data = "); Serial.print(dataADC2);
  // lcd.setCursor(0,1); 
  Serial.print(", T = "); Serial.print(T); Serial.println(" Derajat");
  
  Serial.println(" "); Serial.println(" "); //Hanya untuk spasi

  // Serial.write(0XDF); Serial.write('C');
  delay(1000);
}
