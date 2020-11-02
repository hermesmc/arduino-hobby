int pinos[4] = {12,11,10,9};
int total = 3;

void setup() {
  // put your setup code here, to run once:
  for(int x = 0; x <= total; x++){
     pinMode(pinos[x], OUTPUT);
  } 
}

void loop() {
  // put your main code here, to run repeatedly:  
   int num = random(4);
   digitalWrite(pinos[num], HIGH); 
   delay(100);  
   digitalWrite(pinos[num], LOW); 
 }
