
// Pin de salida para controlar el motor
int motorSleft = 9;
int motorGleft= 8;
int motorSright = 10;
int motorGright = 11;
int ready = 6;
int selCards = 0;
int totalCards = 0;

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
  Serial.begin(9600);
}

void loop() {
  // Girar el motor en una dirección
  //Serial.println(motorPin);
  on = digitalRead(encendido);
  sel = digitalRead(select);
  delay(1000);
  
  if(on == 1){ // si el circuito esta encendido
    if(totalCards == 18){
      digitalWrite(ready, 255);
    }else if(sel == 1 && selCards <7){// si el usuario selecciona una carta
      // encender motores izq por 500ms
      analogWrite(motorSleft, 255); // Establecer la velocidad máxima (sentido de giro depende de la conexión)
      delay(100);
      analogWrite(motorGleft, 255);
      delay(1000); // Esperar 1 segundos
      // Detener el motor
      analogWrite(motorGleft, 0);
      analogWrite(motorSleft, 0);
      // aumentar contadores
      selCards += 1;
      totalCards += 1;
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
      totalCards += 1;
    }
  }
}