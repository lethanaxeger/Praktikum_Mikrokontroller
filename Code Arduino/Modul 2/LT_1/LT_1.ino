const int switch1Pin = 1; // Switch 1 Located
const int switch2Pin = 2; // Switch 2 Located
const int ledPin = 3;     // LED located

int buttonState1 = 0;
int buttonState2 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(switch1Pin, INPUT_PULLUP);
  pinMode(switch2Pin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  // set ledPinState = LOW;
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState1 = digitalRead(switch1Pin);
  buttonState2 = digitalRead(switch2Pin);

  if(buttonState2 == HIGH)
  {
    digitalWrite(ledPin, LOW);
  }
  else if(buttonState1 == HIGH) {
    digitalWrite(ledPin, HIGH);
  }
 
}
