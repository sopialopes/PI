int leds[] = {2,3,4,5,6,7};
#define PORT A0
int valor;

void setup() {
  for(int i=0;i<6;i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(PORT, INPUT); 
}

void acender(int x) {
  for(int j=0;j<x;j++) {

    digitalWrite(leds[j], HIGH);
  }
   for(int k=x;k<6;k++) {
    digitalWrite(leds[k], LOW);
  }
}

void loop() {
 //Com a variável 
 valor = analogRead(pot); 

 //map(valor, 0, 1023, 0, 6); 
 
 acender(map(valor, 0, 1023, 0, 6));
}

