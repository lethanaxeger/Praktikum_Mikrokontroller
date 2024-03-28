const int switchPin1 = 2; // Pin untuk saklar 1
const int switchPin2 = 3; // Pin untuk saklar 2
const int ledPins[] = {4, 5, 6, 7}; // Array untuk pin LED-1 hingga LED-4

int currentLED = 0; // Variabel untuk melacak LED saat ini yang menyala

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT); // Mengatur pin LED sebagai OUTPUT
  }
  pinMode(switchPin1, INPUT_PULLUP); // Mengatur pin saklar 1 sebagai INPUT_PULLUP (dalam kondisi awal HIGH)
  pinMode(switchPin2, INPUT_PULLUP); // Mengatur pin saklar 2 sebagai INPUT_PULLUP (dalam kondisi awal HIGH)
}
void loop() {
  // Membaca status saklar 1 dan saklar 2
  int switchState1 = digitalRead(switchPin1);
  int switchState2 = digitalRead(switchPin2);

  // Jika saklar 1 ditekan, LED berpindah dari LED-1 ke LED-4
  if (switchState2 == LOW) {
    for (int i = 0; i < 4; i++) {
      for (int i = 0; i < 4; i++) {
      digitalWrite(ledPins[i], LOW); // Matikan semua LED 
      delay(200);
      }
    }
  } 
  // Jika saklar 2 ditekan, matikan semua LED
  else if (switchState1 == LOW) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPins[i], HIGH); // Nyalakan semua LED 
      delay(200);
    }
  }
}