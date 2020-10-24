int pinLed[9] = {13,12,11,10,9,8,7,6,5};
int x;

float minimo = 200;
float maximo = 1000;
float valorLDR;
float luminosidade;

void setup() {
  // put your setup code here, to run once:
  for(x = 0; x < 9; x++){
     pinMode(pinLed[x], OUTPUT);
  }
  pinMode(A0, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //Recebe o valor da porta analogica A0 variando 
  //de o a 1023 (0V até 5V)
  valorLDR = analogRead(A0);
  luminosidade = ((valorLDR - minimo) / (maximo - minimo)) * 10;
  luminosidade = (luminosidade - 10) * -1;

  for(x = 0; x < 9; x++){
    if (x < luminosidade){
      digitalWrite(pinLed[x], HIGH);
    } else{
      digitalWrite(pinLed[x], LOW);
    }
  }
  delay(500);
  
}
