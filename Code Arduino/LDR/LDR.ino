int LDR = A2;
int LED = 13;
int nilaiLDR = 0; // variabel nilai awal untuk nilai LDR
void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  nilaiLDR = analogRead(LDR);
  Serial.print("NilaiLDR =");  //menampilkan teks nilaiLDR=
  Serial.println(nilaiLDR); //menampilkan nilai dari variabel nilaiLDR
  if(nilaiLDR<500){           //jika nilai dari LDR lebih dari 500i (intensitas cahaya)
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
}


