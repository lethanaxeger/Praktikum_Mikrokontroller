const int switchPin = 2;
const int ledPin = 9;

bool switchState = false;
int brightness;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  switchState = digitalRead(switchPin);

  if (switchState == LOW){
    for (brightness = 0; brightness <= 255; brightness += 5) {
    analogWrite(ledPin, brightness);
    delay(100);
    }
    for (brightness = 255; brightness >= 0; brightness -= 5){
    analogWrite(ledPin, brightness);
    delay(100);
   }
  }else{
  analogWrite(ledPin, 0);
  }
}
  


