//Etiquetado de pines
#define LR 2 //Segmento rojo del RGB en el pin PWM2
#define LG 3 //Segmento rojo del RGB en el pin PWM3
#define LB 4 //Segmento rojo del RGB en el pin PWM4
//Definicion de constantes
const unsigned long TR = 3000; //Constante de tiempo total para el segmento rojo en 3 secs
const unsigned long TG = 2000; //Constante de tiempo total para el segmento verde en 2 secs
const unsigned long TB = 1000; //Constante de tiempo total para el segmento azul en 1 secs
//Configuracion
void setup() {
  //Decir que es entrada y que es salida
  pinMode(LR, OUTPUT); //Segmento rojo como salida
  pinMode(LG, OUTPUT); //Segmento verde como salida
  pinMode(LB, OUTPUT); //Segmento azul como salida
  //Limpieza de salidas fisicas
  digitalWrite(LR, LOW); //Apago segmento rojo
  digitalWrite(LG, LOW); //Apago segmento rojo
  digitalWrite(LB, LOW); //Apago segmento rojo
  //Comunicaciones
  Serial.begin(9600); //Comunicaciones seriales con el PC (Serial0) a 9600 bauds
}

//Ejecucion
void loop() {
  for (int i = 0; i <= 255; i++) { //Recorro todo el PWM desde 0% (0) hasta 100% (255)
    analogWrite(LR, i); //Envio el valor del contador al segmento rojo
    Serial.print("R: " + String(i) + " G: 0 B: 0"); //Imprimo en el monitor serial
    delay(TR / 255); //Retardo la señal lo que debe durar cada iteracion para un total de TR secs
  }
  for (int i = 0; i <= 255; i++) { //Recorro todo el PWM desde 0% (0) hasta 100% (255)
    analogWrite(LG, i); //Envio el valor del contador al segmento verde
    Serial.print("R: 0 G: " + String(i) + " B: 0"); //Imprimo en el monitor serial
    delay(TG / 255); //Retardo la señal lo que debe durar cada iteracion para un total de TG secs
  }
  for (int i = 0; i <= 255; i++) { //Recorro todo el PWM desde 0% (0) hasta 100% (255)
    analogWrite(LB, i); //Envio el valor del contador al segmento azul
    Serial.print("R: 0 G: 0 B: " + String(i)); //Imprimo en el monitor serial
    delay(TB / 255); //Retardo la señal lo que debe durar cada iteracion para un total de TB secs
  }
}
