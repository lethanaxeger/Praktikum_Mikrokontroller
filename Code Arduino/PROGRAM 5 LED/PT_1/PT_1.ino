int ledArray[] = {8, 9, 10, 11, 12};
int count;
int timer = 250;
void setup() {
  // put your setup code here, to run once:
  for (count=0;count<5;count++){
    pinMode(ledArray[count], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(count=0;count<5;count++){
    digitalWrite(ledArray[count], HIGH);
    delay(timer);
    digitalWrite(ledArray[count], LOW);
    delay(timer);
  }
}
