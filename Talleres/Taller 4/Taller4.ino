
/**
  Electrónica Digital
  Taller 4
  Members:
           - Camila Barona Cabrera
           - Maria Antonia Rincón
           - Valeria Suarez
           - Sofia Uribe
           - Juan Manuel Young Hoyos

  Teacher: David Velásquez
  Description:
*/

//Etiquetado de pines

#define START 7
#define STOP 6
#define SNL 4
#define SNH 5
#define EV 8
#define BH 9
#define AM 10

//Definir variables

int contador = 0;
bool inicio = false;

//Subrutinas y/o funciones

void agitar() {
  if (digitalRead(SNH) == HIGH) {
    while (contador < 5) {
      delay(10000);
      digitalWrite(AM, HIGH);
      delay(30000);
      digitalWrite(AM, LOW);
      contador++;
    }
  }
}

void vaciar() {
  if (digitalRead(SNL) == HIGH) {
    digitalWrite(EV, HIGH);
  }
}

void core() {
  if (digitalRead(START)==HIGH){
    inicio=true;
  }

  if (inicio) {
    digitalWrite(BH,HIGH);
    agitar();
    contador=0;
    vaciar();
    inicio=false;
  }
}

void setup() {
  pinMode(START, INPUT);
  pinMode(STOP, INPUT);
  pinMode(SNL, INPUT);
  pinMode (SNH, INPUT);
  pinMode (EV, OUTPUT);
  pinMode(BH, OUTPUT);
  pinMode (AM, OUTPUT);

  digitalWrite(EV, LOW);
  digitalWrite(BH, LOW);
  digitalWrite(AM, LOW);
  Serial.begin(9600);

}

void loop() {
  core();
}
