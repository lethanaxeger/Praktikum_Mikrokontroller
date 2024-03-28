float v = 5.0, t = 31.8, l = 28.7;
int incomingByte = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  Serial.println("");
  Serial.print("\r\r=- Data Service -= \r\rV/v = Tegangan\r  L/l = Intensitas Cahaya\r  T/t = Thermometer\r");
  Serial.write("- Enter data:");
  while(Serial.available()==0){}
  String input=Serial.readString();
  input.trim();
  // incomingByte = Serial.read();
  // Serial.print(incomingByte);
  if(input=="v" | input=="V"){
    Serial.println("\r \r=- Tegangan -=\rData Voltmeter = ");
    Serial.print(v);
    Serial.write(" Volt");
    // delay(500);
  }
  else 
  if(input=="l" | input=="L"){
    Serial.print("\r \r=- Lux -=\rData Luxmeter = ");  
    Serial.print(l);
    Serial.write(" Lux");
    // delay(500);
  }
  else
  if(input=="t" | input=="T"){
    Serial.write("\r \r=- Thermo -=\rData Thermometer = ");
    Serial.print(t);
    Serial.write(" Celcius");
    // delay(500);
  }
  else{
    Serial.write("\r \r404\r");
  }
}