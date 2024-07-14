#define LED 8
#define AN5 A5  

void setup() {
  pinMode(LED, OUTPUT); 
  pinMode(AN5, INPUT); 

}

void loop() {
  //Analógico 0 a 1023
  //PWM 0 A 255
  
  /*Sem a função MAP
  analogWrite(LED, analogRead(AN5)/4)); 
  */

  //Com a função MAP
  analogWrite(LED, map(analogRead(AN5),0,1023,0,255)); 
}

