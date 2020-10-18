void setup() {
  // put your setup code here, to run once:

  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(11, HIGH);
  delay(3000);
  digitalWrite(11, LOW);  
  digitalWrite(9, HIGH);
  delay(5000);
  digitalWrite(9, LOW);
  digitalWrite(13, HIGH);
  delay(10000);
  digitalWrite(13, LOW);
  
}
