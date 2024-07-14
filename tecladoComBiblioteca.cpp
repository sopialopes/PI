//Código com biblioteca
#include <Keypad.h> 
#define LINHAS 4
#define COLUNAS 4

char mapaTeclas[4][4] = {{'1', '2', '3', 'A'},
                         {'4', '5', '6', 'B'},
                         {'7', '8', '9', 'C'},
                         {'*', '0', '#', 'D'}};
byte pinos_linha[LINHAS] = {11, 10, 9, 8}; 
byte pinos_coluna[COLUNAS] = {5, 4, 3, 2}; 

Keypad teclado = Keypad(makeKeymap(mapaTeclas), pinos_linha, pinos_coluna, LINHAS, COLUNAS); 


void setup() {
  Serial.begin(9600); 
}

void loop() {
  char tecla = teclado.getKey(); 
  if(tecla != NO_KEY) {
     Serial.print(tecla);
  }
}

