#include <Wire.h>

#include <LiquidCrystal_I2C.h>

//Teclado Matricial Digitando no Display 16x2

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

//Define as linhas e colunas do teclado:
int linha1=4,linha2=5,linha3=6,linha4=7;
int coluna1=8, coluna2=9, coluna3=10, coluna4=11;

int pulaLinha=0;//variável para saltar linha
 
void setup()
{
  lcd.begin (16,2);
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.setCursor(7,0);
  lcd.print("PI");
  lcd.setCursor(0,1);
  lcd.print("SOPHIA E HINACIO");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  //Todos os fios das linhas do teclado são definidos como saídas
  pinMode(linha1,OUTPUT);
  pinMode(linha2,OUTPUT);
  pinMode(linha3,OUTPUT);
  pinMode(linha4,OUTPUT);
  //Todos os fios das colunas do teclado são definidos como entradas
  pinMode(coluna1,INPUT);
  pinMode(coluna2,INPUT);
  pinMode(coluna3,INPUT);
  pinMode(coluna4,INPUT);
}
 
void loop() {
  for (int linhaX=4; linhaX<8; linhaX++) {
    digitalWrite(linha1,LOW);
    digitalWrite(linha2,LOW);
    digitalWrite(linha3,LOW);  
    digitalWrite(linha4,LOW);
    //Coloca em 5V a linhaX
    digitalWrite(linhaX,HIGH);
    if (digitalRead(coluna1)==HIGH){
      escreveNoDisplay(linhaX, coluna1);
      while (digitalRead(coluna1)==HIGH){}
    }
    if (digitalRead(coluna2)==HIGH){
      escreveNoDisplay(linhaX, coluna2);
      while (digitalRead(coluna2)==HIGH){}
    }
    if (digitalRead(coluna3)==HIGH){
      escreveNoDisplay(linhaX, coluna3);
      while (digitalRead(coluna3)==HIGH){}
    }
    if (digitalRead(coluna4)==HIGH){
      escreveNoDisplay(linhaX, coluna4);
      while (digitalRead(coluna4)==HIGH){}
    }
  }  
}

//Função para Escrever os caracteres no Display
void escreveNoDisplay(int linha, int coluna) {

 //Pula Linha quando o cursor chega no final da primeira linha
 if (pulaLinha==16) {
  lcd.setCursor(0,1);
 }
 
 if(linha==4 && coluna==8)
 lcd.print("1");
 if(linha==4 && coluna==9)
 lcd.print('2');
 if(linha==4 && coluna==10)
 lcd.print('3');
 if(linha==4 && coluna==11)
 lcd.print('A');
 if(linha==5 && coluna==8)
 lcd.print('4');
 if(linha==5 && coluna==9)
 lcd.print('5');  
 if(linha==5 && coluna==10)
 lcd.print('6');
 if(linha==5 && coluna==11)
 lcd.print('B');
 if(linha==6 && coluna==8)
 lcd.print('7');
 if(linha==6 && coluna==9)
 lcd.print('8');
 if(linha==6 && coluna==10)
 lcd.print('9');
 if(linha==6 && coluna==11)
 lcd.print('C');
 if(linha==7 && coluna==8)
 lcd.print('*');
 if(linha==7 && coluna==9)
 lcd.print('0');
 if(linha==7 && coluna==10)
 lcd.print('#');
 if(linha==7 && coluna==11)
 lcd.print('D');

 pulaLinha+=1;
}
