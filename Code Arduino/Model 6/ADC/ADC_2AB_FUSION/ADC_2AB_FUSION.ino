int analogPin = A0;
int lang = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  lang = analogRead(analogPin);
  delay(100);
  Serial.print("Data : ");
  Serial.print(lang);

  //baca input analog:
  int NilaiSensor = analogRead(A0);
  //Konversi (0 - 1023) ke teg.(0 - 5V);
  float volt = NilaiSensor * (5.0/1023.0);
  Serial.print("         Volt : ");
  Serial.println(volt);
}