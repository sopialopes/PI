//COM FUNÇÃO, SEM CLASSE
#define LED_VERMELHO 8
#define LED_BRANCO 9

void piscar_leds(int tmp) {
  digitalWrite(LED_VERMELHO, HIGH);
  digitalWrite(LED_BRANCO, LOW); 
  delay(tmp);
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_BRANCO, HIGH); 
  delay(tmp);
}

void setup() {
  pinMode(LED_VERMELHO, OUTPUT); 
  pinMode(LED_BRANCO, OUTPUT); 
}

void loop() {
 piscar_leds(1000); 
}

