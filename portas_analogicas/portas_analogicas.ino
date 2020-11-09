int pinos[1] = {13};

float valorLDR;
float minimo = 85;
float maximo = 1025;
float luminosidade;

void setup() {
  // put your setup code here, to run once:
  for(int x = 0; x < 2; x++){
     pinMode(pinos[x], OUTPUT);
  }
  pinMode(A0, INPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  valorLDR = analogRead(A0);

  luminosidade = ((valorLDR - minimo ) / (maximo - minimo)) * 10;
  luminosidade = (luminosidade - 10) * -1;
  for (int y = 0; y < 2; y++){
    if (y < luminosidade){
      digitalWrite(pinos[y], HIGH);  
    }else{
       digitalWrite(pinos[y], LOW);   
    }
  }  
  delay(200);  
}
