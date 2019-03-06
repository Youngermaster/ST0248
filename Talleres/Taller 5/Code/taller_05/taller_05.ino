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
*/

#define TS 0
#define LGREEN 3
#define LBLUE 5
#define LRED 6
#define LA 7
#define LB 8
#define LC 9
#define LD 10
#define LE 11
#define LF 12
#define LG 13


float temperature;

float getTemperatureOnCelsius(float temperature)
{
  return (temperature * 500) / 1024;
}

int getUnit(float temperature)
{
  return (int) temperature % 10;
}

void turnOnDisplay(int a, int b, int c, int d, int e, int f, int g)
{
  digitalWrite(LA, a);
  digitalWrite(LB, b);
  digitalWrite(LC, c);
  digitalWrite(LD, d);
  digitalWrite(LE, e);
  digitalWrite(LF, f);
  digitalWrite(LG, g);
}

void showNumber(int number)
{
  switch (number)
  {
    case 0:
      turnOnDisplay(1, 1, 1, 1, 1, 1, 0); // 0
      break;

    case 1:
      turnOnDisplay(0, 1, 1, 0, 0, 0, 0); // 1
      break;

    case 2:
      turnOnDisplay(1, 1, 0, 1, 1, 0, 1); // 2
      break;

    case 3:
      turnOnDisplay(1, 1, 1, 1, 0, 0, 1); // 3
      break;

    case 4:
      turnOnDisplay(0, 1, 1, 0, 0, 1, 1); // 4
      break;

    case 5:
      turnOnDisplay(1, 0, 1, 1, 0, 1, 1); // 5
      break;

    case 6:
      turnOnDisplay(1, 0, 1, 1, 1, 1, 1); // 6
      break;

    case 7:
      turnOnDisplay(1, 1, 1, 0, 0, 0, 0); // 7
      break;

    case 8:
      turnOnDisplay(1, 1, 1, 1, 1, 1, 1); // 8
      break;

    case 9:
      turnOnDisplay(1, 1, 1, 1, 0, 1, 1); // 9
      break;
  }
}

void turnOnRGBLED(int color)
{
  switch (color)
  {
    case 1:
      analogWrite(LRED, 255);
      analogWrite(LGREEN, 201);
      analogWrite(LBLUE, 14);
      break;
    case 2:
      analogWrite(LRED, 255);
      analogWrite(LGREEN, 128);
      analogWrite(LBLUE, 0);
      break;
    case 3:
      analogWrite(LRED, 255);
      analogWrite(LGREEN, 0);
      analogWrite(LBLUE, 0);
      break;
    default:
      break;
  }
}

void core()
{
  temperature = analogRead(TS);
  Serial.println(temperature);
  temperature = getTemperatureOnCelsius(temperature);
  Serial.println(temperature);
  Serial.println(getUnit(temperature));
  
  showNumber(getUnit(temperature));

  if (temperature > 32) 
    turnOnRGBLED(3);
  else if (temperature <= 32 && temperature > 30)
    turnOnRGBLED(2);
  else if(temperature <= 28)
    turnOnRGBLED(1);
  
  delay(2000);
}

void setup() 
{
  pinMode(LBLUE, OUTPUT);
  pinMode(LGREEN, OUTPUT);
  pinMode(LRED, OUTPUT);
  pinMode(LA, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(LC, OUTPUT);
  pinMode(LD, OUTPUT);
  pinMode(LE, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LG, OUTPUT);

  digitalWrite(LBLUE, LOW);
  digitalWrite(LGREEN, LOW);
  digitalWrite(LRED, LOW);
  digitalWrite(LA, LOW);
  digitalWrite(LB, LOW);
  digitalWrite(LC, LOW);
  digitalWrite(LD, LOW);
  digitalWrite(LE, LOW);
  digitalWrite(LF, LOW);
  digitalWrite(LG, LOW);

  Serial.begin(9600);

}

void loop() 
{
  core();
}
