#define pinPIR 7

void setup() {
  // put your setup code here, to run once:
  pinMode(pinPIR, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool valorPIR = digitalRead(pinPIR);

  if (valorPIR){
     Serial.println("DETECTADO");
  }else{
    Serial.println("-----------");
  }
  delay(500);
  
}
