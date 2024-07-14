#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2); 

void setup() {
  lcd.begin(16, 2); 
  lcd.clear(); 
}

void loop() {
  lcd.setCursor(3, 0; 
  lcd.print(*TESTE*); 
  lcd.setCursor(4, 1; 
  lcd.print(*PI*); 
  delay(1000); 

  for(int i = 0; i < 3; i++) {
    lcd.scrollDisplayLeft(); 
    delay(100); 
  }

  for(int i = 0; i < 6; i++) {
    lcd.scrollDisplayRight(); 
    delay(100); 
  }

   for(int i = 0; i < 3; i++) {
    lcd.scrollDisplayLeft(); 
    delay(100); 
  }
  
    delay(100); 
    lcd.noDisplay(); 
    delay(100); 
    lcd.display(); 
    delay(100); 
    lcd.noDisplay(); 
    delay(100); 
    lcd.display(); 
    delay(100); 
    lcd.noDisplay(); 
    delay(100); 
}



