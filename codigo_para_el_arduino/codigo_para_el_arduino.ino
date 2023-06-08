// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(0, 1, 2, 3, 12, 13);

// Pin de salida para controlar el motor
int motorSleft = 9;
int motorGleft= 8;
int motorSright = 10;
int motorGright = 11;
int ready = 6;
int selCards = 0;
int totalCards = 18;

// pines de entrada
int select = 4;
int encendido = 7;

// variables de lectura
int on;
int sel;


void setup() {
  // Configurar el pin del motor como salida
  pinMode(motorSleft, OUTPUT);
  pinMode(motorGleft, OUTPUT);
  pinMode(motorSright, OUTPUT);
  pinMode(motorGright, OUTPUT);
  pinMode(ready, OUTPUT);

  // configurar pines de entrada
  pinMode(select, INPUT);
  pinMode(encendido, INPUT);

  digitalWrite(select, LOW);
  digitalWrite(ready, LOW);  
  //Serial.begin(9600);

  //Comenzar lcd
  lcd.begin(16,2);
}

void loop() {
  on = digitalRead(encendido);
  sel = digitalRead(select);
  delay(1000);
  lcd.clear();
  if(on == 1){
    lcd.clear();
    //Si el circuito esta encendido
    //Cantidad de cartas seleccionadas por el usuario
    lcd.print("Cant Select:");
    //Cantidad de cartas del Deck restantes
    lcd.setCursor(0,1);
    lcd.print("Restantes:");
    lcd.setCursor(11, 1);
    lcd.print(totalCards);
    lcd.setCursor(13, 0);
    lcd.print(selCards);
    
    if(totalCards == 0){
      digitalWrite(ready, 255);
      // Pantalla LCD Finalizada
      lcd.clear();
      lcd.print("Seleccion");
      lcd.setCursor(0,1);
      lcd.print("Finalizada :)");
      
    // si el usuario selecciona una carta
    }else if(sel == 1){
      if(selCards <7){
      // encender motores izq por 500ms
      analogWrite(motorSleft, 255); 
      // Establecer la velocidad máxima (sentido de giro depende de la conexión)
      delay(100);
      analogWrite(motorGleft, 255);
      delay(1000); // Esperar 1 segundos
      // Detener el motor
      analogWrite(motorGleft, 0);
      analogWrite(motorSleft, 0);
      // aumentar contadores
      selCards += 1;
      totalCards -= 1;
      
      }else{
        while(totalCards != 0){
          analogWrite(motorSright, 255); // Establecer la velocidad máxima (sentido de giro depende de la conexión)
          delay(500);
          analogWrite(motorGright, 255);
          delay(500); // Esperar 1 segundos
        // Detener el motor
          analogWrite(motorGright, 0);
          analogWrite(motorSright, 0);
          // aumentar contadores
         totalCards -= 1;
          }
        lcd.clear();
        lcd.print("Error: Ya no se");
        lcd.setCursor(0,1);
        lcd.print("puede seleccionar");
        }
    }else{
      // encender motores izq por 500ms
      analogWrite(motorSright, 255); // Establecer la velocidad máxima (sentido de giro depende de la conexión)
      delay(100);
      analogWrite(motorGright, 255);
      delay(1000); // Esperar 1 segundos
      // Detener el motor
      analogWrite(motorGright, 0);
      analogWrite(motorSright, 0);
      // aumentar contadores
      totalCards -= 1;
      }
  }else{
    lcd.clear();
    lcd.print("Encender Switch");
    lcd.setCursor(0,1);
    lcd.print("Para Comenzar :)");
  }}
