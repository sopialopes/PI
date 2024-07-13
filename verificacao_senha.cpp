#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Teclado Matricial Digitando no Display 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);  // define o endereço do LCD como 0x27 para um display de 16 caracteres e 2 linhas

// Define as linhas e colunas do teclado:
int linha[4] = {4, 5, 6, 7};
int coluna[4] = {8, 9, 10, 11};

String senha = "A23";
String entrada = ""; // variável para armazenar a entrada do usuário

void escreveTela(int linha, int coluna, String palavra) {
  lcd.setCursor(linha, coluna);
  lcd.print(palavra);
}
void setup() {
  lcd.begin(16, 2);
  lcd.init(); // inicia o LCD
  lcd.backlight();
  escreveTela(7, 0, "PI"); 
  escreveTela(0, 1, "SOPHIA E HINACIO"); 
  delay(1000); 
  lcd.clear();
  lcd.setCursor(0, 0);

  // Configura as linhas do teclado como saídas
  for (int i = 0; i < 4; i++) {
    pinMode(linha[i], OUTPUT);
  }

  // Configura as colunas do teclado como entradas
  for (int j = 0; j < 4; j++) {
    pinMode(coluna[j], INPUT);
  }
}

void loop() {
  for (int linhaX = 4; linhaX < 8; linhaX++) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(linha[i], LOW);
    }
    // Coloca em 5V a linhaX
    digitalWrite(linhaX, HIGH);
    for (int j = 0; j < 4; j++) {
      if (digitalRead(coluna[j]) == HIGH) {
        escreveNoDisplay(linhaX, coluna[j]);
        while (digitalRead(coluna[j]) == HIGH) {}
      }
    }
  }
}

// Função para Escrever os caracteres no Display
void escreveNoDisplay(int linha, int coluna) {
  char tecla = getTecla(linha, coluna); // Função para obter a tecla pressionada
  if (tecla != 0) {
    lcd.print('*'); // Mostra * no lugar do caractere real
    entrada += tecla; // Armazena o caractere real na variável de entrada

    if (entrada.length() == senha.length()) {
      lcd.setCursor(0, 1);
      if (entrada == senha) {
        lcd.print("Senha correta");
      } else {
        lcd.print("Senha incorreta");
      }
      delay(2000);
      lcd.clear();
      entrada = "";
      lcd.setCursor(0, 0);
    }
  }
}

// Função para mapear a linha e coluna para a tecla correspondente
char getTecla(int linha, int coluna) {
  if (linha == 4 && coluna == 8) return '1';
  if (linha == 4 && coluna == 9) return '2';
  if (linha == 4 && coluna == 10) return '3';
  if (linha == 4 && coluna == 11) return 'A';
  if (linha == 5 && coluna == 8) return '4';
  if (linha == 5 && coluna == 9) return '5';
  if (linha == 5 && coluna == 10) return '6';
  if (linha == 5 && coluna == 11) return 'B';
  if (linha == 6 && coluna == 8) return '7';
  if (linha == 6 && coluna == 9) return '8';
  if (linha == 6 && coluna == 10) return '9';
  if (linha == 6 && coluna == 11) return 'C';
  if (linha == 7 && coluna == 8) return '*';
  if (linha == 7 && coluna == 9) return '0';
  if (linha == 7 && coluna == 10) return '#';
  if (linha == 7 && coluna == 11) return 'D';
  return 0;
}
