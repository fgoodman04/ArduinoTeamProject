
/* Programmers: Luke Marchand & Faith Goodman
   Date: 1.6.20

*/
#include <LiquidCrystal.h>

const int rs = 24, en = 22, d4 = 52, d5 = 47, d6 = 43, d7 = 40;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Welcome");

}

void loop() {
  // Turn off the display:
  lcd.noDisplay();
  delay(500);
  // Turn on the display:
  lcd.display();
  delay(500);
}
