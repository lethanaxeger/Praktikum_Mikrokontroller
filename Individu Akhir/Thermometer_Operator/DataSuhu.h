// Created and improvised by Group 5 TT2C & helped by Mr. Nur Sulaiman 
// No Chat GPT include in this code, natural dari pemahaman individu dengan menggunakan manipulasi data sederhana
float calculateData(){
  //Thermo data proccess
  int dataADC = analogRead(A0);
  float Temp = dataADC * 0.489;
  return Temp;
}