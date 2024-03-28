void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){
    // Menunggu port serial terhubung. Dibutuhkan Universal Serial Bus
    Serial.print("Jika teks ini muncul, maka sudah Serial Port sudah terhubung");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
