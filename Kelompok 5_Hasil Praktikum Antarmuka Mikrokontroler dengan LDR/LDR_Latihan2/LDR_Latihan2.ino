int LDR = A2;
int LED = 9;
int i = 155;
int nilaiLDR = 0; // variabel nilai awal untuk nilai LDR
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(LDR, INPUT);
  Serial.begin(9600);
}

void loop() {
  int LDRValue = analogRead(LDR);
  Serial.print("NilaiLDR=");
  Serial.println(LDRValue);
  int brightness = map(LDRValue, 150, 650 , 255, 0);
  analogWrite(LED, brightness);
}


