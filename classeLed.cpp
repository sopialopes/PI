class Led {
private:
  int porta; 
  
public: 
  Led(int p) {
    porta = p; 
  }

  void init() {
    pinMode(porta, OUTPUT); 
  }

  void alternar()  {
    if(digitalRead(porta) == HIGH) {
      digitalWrite(porta, LOW); 
    } else {
      digitalWrite(porta, HIGH);       
    }
  }
};

Led vermelho(8); 
Led verde(9);

void setup() {
  vermelho.init();
  verde.init(); 
}

void loop() {
  delay(500); 
  vermelho.alternar(); 
  verde.alternar(); 
}

