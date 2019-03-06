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

#define TS 0 // This PIN refers to the temperature sensor
#define LGREEN 3 // This PIN refers to green value of LED RGB
#define LBLUE 5 // This PIN refers to blue value of LED RGB
#define LRED 6 // This PIN refers to red value of LED RGB
#define LA 2 // This PIN refers to 'a' LED of the seven-segment display (SSD).
#define LB 3 // This PIN refers to 'b' LED of the seven-segment display (SSD).
#define LC 4 // This PIN refers to 'c' LED of the seven-segment display (SSD).
#define LD 5 // This PIN refers to 'd' LED of the seven-segment display (SSD).
#define LE 6 // This PIN refers to 'e' LED of the seven-segment display (SSD).
#define LF 7 // This PIN refers to 'f' LED of the seven-segment display (SSD).
#define LG 8 // This PIN refers to 'g' LED of the seven-segment display (SSD).

float temperature; // Saves the temperature of the environment.

/**
 * @parameters temperature -> float
 * @return temperature times 500 and divide by 1024
 * This method returns the temperature on Celcius (°C)
 */
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
      turnOnDisplay(0, 0, 0, 0, 0, 0, 1); // 0
      break;

    case 1:
      turnOnDisplay(1, 0, 0, 1, 1, 1, 1); // 1
      break;

    case 2:
      turnOnDisplay(0, 0, 1, 0, 0, 1, 0); // 2
      break;

    case 3:
      turnOnDisplay(0, 0, 0, 0, 1, 1, 0); // 3
      break;

    case 4:
      turnOnDisplay(1, 0, 0, 1, 1, 0, 0); // 4
      break;

    case 5:
      turnOnDisplay(0, 1, 0, 0, 1, 0, 0); // 5
      break;

    case 6:
      turnOnDisplay(0, 1, 0, 0, 0, 0, 0); // 6
      break;

    case 7:
      turnOnDisplay(0, 0, 0, 1, 1, 1, 1); // 7
      break;

    case 8:
      turnOnDisplay(0, 0, 0, 0, 0, 0, 0); // 8
      break;

    case 9:
      turnOnDisplay(0, 0, 0, 1, 1, 0, 0); // 9
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
  //core();
  int counter = 0;

  while(counter < 10)
  {
    showNumber(counter);
    counter++;
    delay(1000);
  }
  counter = 0;
}
