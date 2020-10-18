void setup() {
  // put your setup code here, to run once:
  pinMode(7, INPUT_PULLUP);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int estadoBotao = digitalRead(7);  
  digitalWrite(9, estadoBotao); 
  digitalWrite(10, estadoBotao);  
}
