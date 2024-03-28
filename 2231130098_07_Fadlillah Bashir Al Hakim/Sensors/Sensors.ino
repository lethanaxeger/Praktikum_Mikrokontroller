// #include <LiquidCrystal.h>

int dataADC;
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
  dataADC = analogRead(A5);
  Vin = dataADC * 0.00489;
  RLDR = (5000.0 / Vin - 1000.0);
  logRK = log10(RLDR/127262.2);
  I = pow(10.0, logRK / (-0.858));

  // lcd.setCursor(0,0);
  Serial.print("Data = "); Serial.print(dataADC);
  // lcd.setCursor(0,1);
  Serial.print(" | T = "); Serial.print(I); Serial.println(" Lux");

  // // Voltmeter code
  
  // dataADC = analogRead(A4);
  // Vin = dataADC * 5.0 / 1023;

  // // lcd.setCursor(0,0); 
  // Serial.print("Data = "); Serial.print(dataADC);
  // // lcd.setCursor(0,1); 
  // Serial.print("V | Input = "); Serial.println(Vin);

  // Thermometer code
  dataADC = analogRead(A3);
  T = dataADC * 0.489;

  // Serial.setCursor(0,0); 
  Serial.print("Data = "); Serial.print(dataADC);
  // lcd.setCursor(0,1); 
  Serial.print(" | T = "); Serial.print(T); Serial.println(" Celcius");
  
  Serial.println(" "); Serial.println(" "); //Hanya untuk spasi

  // Serial.write(0XDF); Serial.write('C');
  delay(250);
}
