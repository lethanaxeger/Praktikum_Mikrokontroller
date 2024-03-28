const int switch1Pin = 1; // Switch 1 Located
const int switch2Pin = 2; // Switch 2 Located
const int ledPin = 3;     // LED located
int delayTimer = 500;     // Default Timer 500ms

void setup() {
  // put your setup code here, to run once:
  pinMode(switch1Pin, INPUT_PULLUP);
  pinMode(switch2Pin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool switch1State = digitalRead(switch1Pin) == LOW;
  bool switch2State = digitalRead(switch2Pin) == LOW;

  if(switch2State)
  {
    delayTimer = 1000;
  }
  else if(switch1State)
  {
    delayTimer = 100;
  }
  digitalWrite(ledPin, HIGH);
  delay(delayTimer);
  digitalWrite(ledPin, LOW);
  delay(delayTimer);
}
