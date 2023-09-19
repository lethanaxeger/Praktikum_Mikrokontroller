const int switch1Pin = 0; //pin unuk switch 1
const int switch2Pin = 1; //pin untuk switch 2
const int ledPin = 2; //pin untuk LED
int delayTime = 500; //delay awal (nilai deafault)
void setup() {
  
 pinMode(switch1Pin, INPUT_PULLUP);
 pinMode(switch2Pin, INPUT_PULLUP);
 pinMode(ledPin, OUTPUT);
}

void loop() {
  // BACA STATUS SWITCH 1 DAN SWITCH 2 :
  bool switch1State = digitalRead(switch1Pin) == LOW;
  bool switch2State = digitalRead(switch2Pin) == LOW;

  //UBAH DELAY SESUAI DENGAN STATUS SWITCH
  if (switch2State) {
    delayTime = 1000;
  } else if (switch1State) {
    delayTime = 100;
  }
//nyala LED selama delaytime
digitalWrite(ledPin, HIGH);
delay(delayTime);
digitalWrite(ledPin, LOW);
delay(delayTime);

}
