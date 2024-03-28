// Created and improvised by Group 5 TT2C & helped by Mr. Nur Sulaiman 
// No Chat GPT include in this code, natural dari pemahaman individu dengan menggunakan manipulasi data sederhana
int dataADC;
float V;

float teganganCount(){
  
  dataADC = analogRead(A0);
  V = dataADC * 0.00489;

  return V;
}