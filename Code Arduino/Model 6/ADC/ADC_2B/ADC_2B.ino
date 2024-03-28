void setup() {
  Serial.begin(9600);
}

void loop() {
  // baca input analog :
  int NilaiSensor = analogRead(A0);
  //Konversi (0-1023) ke teg.(0 - 5V);
  float volt = NilaiSensor * (5.0/1023.0);
  Serial.print("Volt : ");
  Serial.println(m,);
}
