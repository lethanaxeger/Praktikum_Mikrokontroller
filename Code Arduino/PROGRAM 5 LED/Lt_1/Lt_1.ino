int led1Pin = 8;
int led2Pin = 9;
int ledState = LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(ledState == LOW){
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, LOW);
    ledState = HIGH;
  } else {
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, HIGH);
    ledState = LOW;
  }
  delay(300);
}