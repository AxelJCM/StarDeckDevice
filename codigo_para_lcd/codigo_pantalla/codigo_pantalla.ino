// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(0, 1, 2, 3, 12, 13);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Cantidad de cartas seleccionadas por el usuario
  lcd.print("Error: Ya no se");
  // Cantidad de cartas del Deck restantes
  lcd.setCursor(0,1);
  lcd.print("puede seleccionar");
  
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  //lcd.setCursor(11, 1);
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);

  //lcd.setCursor(13, 0);
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
}