int ledArray[] = {8, 9, 10, 11, 12};
int count, fatih, ulang, bareng;
int timer = 100;
void setup() {
  // put your setup code here, to run once:
  for (count=0;count<5;count++){
    pinMode(ledArray[count], OUTPUT);
  }
  for (count=5;count>0;count--){
    pinMode(ledArray[count], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(fatih=0;fatih<=2;fatih++){
    for(count=0;count<5;count++){
    digitalWrite(ledArray[count], HIGH);
    delay(timer);
    digitalWrite(ledArray[count], LOW);
    delay(timer);
    }
    for(count=5;count>=0;count--){
      digitalWrite(ledArray[count], HIGH);
      delay(timer);
      digitalWrite(ledArray[count], LOW);
      delay(timer);
    }
    if(fatih==2){
      for(bareng=0;bareng<=2;bareng++){
        for(ulang=0;ulang<5;ulang++){
        digitalWrite(ledArray[ulang], HIGH);
        // digitalWrite(ledArray[2], LOW);
        // delay(timer);
        }
        delay(250);
        for(ulang=5;ulang>=0;ulang--){
        digitalWrite(ledArray[ulang], LOW);
        }
        delay(250);
      }
    }
  }
}
