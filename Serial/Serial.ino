int valorx;
int valory;
int valorz;
boolean bola1;
boolean bola2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  valorx = 10;
  valory = 500;
  valorz = valorx + valory;
  bola1 = HIGH;  
  bola2 = LOW;
  Serial.print("Valorx = ");
  Serial.println(valorx);
  Serial.print("Valory = ");
  Serial.println(valory);
  Serial.print("Valorz = ");
  Serial.println(valorz, BIN);  
  // Serial.println(valorz, BIN);
  Serial.print("Bola1 = ");
  Serial.println(bola1);
  Serial.print("Bola2 = ");
  Serial.println(bola2);
}

void loop() {
  // put your main code here, to run repeatedly:

}
