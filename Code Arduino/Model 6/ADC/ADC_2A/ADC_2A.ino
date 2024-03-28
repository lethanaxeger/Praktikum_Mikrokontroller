int analogPin = A0;
int lang = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  lang = analogRead(analogPin);
  delay(100);
  Serial.print("Data : ");
  Serial.println(lang);
}
