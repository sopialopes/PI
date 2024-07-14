//SEM FUNÇÃO E SEM CLASS
#define LED_VERMELHO 8
#define LED_BRANCO 9

void setup() {
  pinMode(LED_VERMELHO, OUTPUT); 
  pinMode(LED_BRANCO, OUTPUT); 
}

void loop() {
  digitalWrite(LED_VERMELHO, HIGH); 
  digitalWrite(LED_BRANCO, LOW); 
  delay(100); 
  digitalWrite(LED_VERMELHO, LOW); 
  digitalWrite(LED_BRANCO, HIGH); 
  delay(100); 
}

