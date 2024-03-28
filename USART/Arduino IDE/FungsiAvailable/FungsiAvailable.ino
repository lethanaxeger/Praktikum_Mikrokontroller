// Inisialisasi Byte

int incomingByte = 0; //Variabel untuk menyimpan jumlah 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Membuat syarat ketika menerima data, maka serial port akan mengirimkan data
  if(Serial.available() > 0) {
    // membaca data yang diterima
    incomingByte = Serial.read();
    // membalas
    Serial.print("I received : ");
    Serial.println(incomingByte, DEC);
  }
}
