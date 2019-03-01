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
#define SNL 5
#define SNH 4
#define EV 8
#define BH 9
#define AM 13

//Definir variables

int counter = 0;
bool startCondition = false;

//Subrutinas y/o funciones

void core()
{
    while(digitalRead(STOP) == LOW)
    {
      if (digitalRead(START) == HIGH)
        startCondition = true;
        
      if (startCondition) 
      {
        while(digitalRead(SNH) == LOW)
          digitalWrite(BH, HIGH);
        
          digitalWrite(BH, LOW);
          while (counter < 5) 
          {
            delay(10000);
            digitalWrite(AM, HIGH);
            delay(30000);
            digitalWrite(AM, LOW);
            counter++;
          } 
        counter = 0;
        digitalWrite(BH, LOW);
        while (digitalRead(SNL) == LOW) 
          digitalWrite(EV, HIGH);

        digitalWrite(EV, LOW);
        startCondition = false;
      }
    }
}


void setup()
{
  pinMode(START, INPUT);
  pinMode(STOP, INPUT);
  pinMode(SNL, INPUT);
  pinMode(SNH, INPUT);
  pinMode(EV, OUTPUT);
  pinMode(BH, OUTPUT);
  pinMode(AM, OUTPUT);

  digitalWrite(EV, LOW);
  digitalWrite(BH, LOW);
  digitalWrite(AM, LOW);
  Serial.begin(9600);
}

void loop()
{
  core();
}