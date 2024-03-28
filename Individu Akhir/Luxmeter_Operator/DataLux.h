// Created and improvised by Group 5 TT2C & helped by Mr. Nur Sulaiman 
// No Chat GPT include in this code, natural dari pemahaman individu dengan menggunakan manipulasi data sederhana
int dataADC;
float Vin, RLDR, logRK, I;

float calculateLux(){
  // Lux data proccess
  dataADC = analogRead(A0);
  Vin = dataADC * 0.00489;
  RLDR = (5000.0 / Vin - 1000.0);
  logRK = log10(RLDR/127262.2);
  I = pow(10.0, logRK / (-0.858));

  return I;
}