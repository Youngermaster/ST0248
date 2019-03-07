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

#define TS 0 // This PIN refers to the temperature sensor.
#define LGREEN 3 // This PIN refers to green value of LED RGB.
#define LBLUE 5 // This PIN refers to blue value of LED RGB.
#define LRED 6 // This PIN refers to red value of LED RGB,
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
 * This method returns the temperature on Celcius (°C).
 */
float getTemperatureOnCelsius(float temperature)
{
  return (temperature * 500) / 1024; // Divides the temperature by 1024 and times 500.
}

/**
 * @parameters temperature -> float
 * @return the temperature unit
 * This method returns the unit of the temperature.
 */
int getUnit(float temperature)
{
  return (int) temperature % 10;
}

/**
 * @parameters none
 * @return void
 * Set in low (turn off) all the outputs.
 */
void turnOffOutputs()
{
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
}

/**
 * @parameters a, b, c, d, e, f, g -> int
 * @return void
 * This method brings turn on or turn off any LED of the seven-segment display.
 */ 
void turnOnDisplay(int a, int b, int c, int d, int e, int f, int g)
{
  digitalWrite(LA, a); // Can turn on or turn off 'a' LED of the seven-segment display (SSD).
  digitalWrite(LB, b); // Can turn on or turn off 'b' LED of the seven-segment display (SSD).
  digitalWrite(LC, c); // Can turn on or turn off 'c' LED of the seven-segment display (SSD).
  digitalWrite(LD, d); // Can turn on or turn off 'd' LED of the seven-segment display (SSD).
  digitalWrite(LE, e); // Can turn on or turn off 'e' LED of the seven-segment display (SSD).
  digitalWrite(LF, f); // Can turn on or turn off 'f' LED of the seven-segment display (SSD).
  digitalWrite(LG, g); // Can turn on or turn off 'g' LED of the seven-segment display (SSD).
}

/**
 * @parameters number -> int
 * @return void
 * This method  shows the parameter on the seven-segment display (SSD).
 */ 
void showNumber(int number)
{
  switch (number)
  {
    case 0:
      turnOnDisplay(0, 0, 0, 0, 0, 0, 1); // Show '0' on the seven-segment display (SSD).
      break;

    case 1:
      turnOnDisplay(1, 0, 0, 1, 1, 1, 1); // Show '1' on the seven-segment display (SSD).
      break;

    case 2:
      turnOnDisplay(0, 0, 1, 0, 0, 1, 0); // Show '2' on the seven-segment display (SSD).
      break;

    case 3:
      turnOnDisplay(0, 0, 0, 0, 1, 1, 0); // Show '3' on the seven-segment display (SSD).
      break;

    case 4:
      turnOnDisplay(1, 0, 0, 1, 1, 0, 0); // Show '4' on the seven-segment display (SSD).
      break;

    case 5:
      turnOnDisplay(0, 1, 0, 0, 1, 0, 0); // Show '5' on the seven-segment display (SSD).
      break;

    case 6:
      turnOnDisplay(0, 1, 0, 0, 0, 0, 0); // Show '6' on the seven-segment display (SSD).
      break;

    case 7:
      turnOnDisplay(0, 0, 0, 1, 1, 1, 1); // Show '7' on the seven-segment display (SSD).
      break;

    case 8:
      turnOnDisplay(0, 0, 0, 0, 0, 0, 0); // Show '8' on the seven-segment display (SSD).
      break;

    case 9:
      turnOnDisplay(0, 0, 0, 1, 1, 0, 0); // Show '9' on the seven-segment display (SSD).
      break;
  }
}

/**
 * @parameters color -> int
 * @return void
 * This method can show three different colors depending of the case.
 */ 
void turnOnRGBLED(int color)
{
  switch (color)
  {
    case 1: // Shows yellow
      analogWrite(LRED, 255);
      analogWrite(LGREEN, 201);
      analogWrite(LBLUE, 14);
      break;
    case 2: // Shows orange
      analogWrite(LRED, 255);
      analogWrite(LGREEN, 128);
      analogWrite(LBLUE, 0);
      break;
    case 3: // Shows red
      analogWrite(LRED, 255);
      analogWrite(LGREEN, 0);
      analogWrite(LBLUE, 0);
      break;
    default: // Shows nothing
      break;
  }
}

/**
 * @parameters none
 * @return void
 * This is the core of the program.
 */
void core()
{
  temperature = analogRead(TS); // Get the temperature of the environment.
  temperature = getTemperatureOnCelsius(temperature); // Convert the temperature to Celcius.
  
  showNumber(getUnit(temperature)); // Shows the unit on the SSD.

  if (temperature > 32) // If the temperature is higher than 32 shows a color.
    turnOnRGBLED(3); // Shows red color.
  else if (temperature <= 32 && temperature > 30) // If temperature is 32-30 range shows a color.
    turnOnRGBLED(2); // Shows orange color.
  else if(temperature <= 28) // If the temperature is lower than 28 shows a color.
    turnOnRGBLED(1); // Shows yellow color.
}

void setup() 
{
  pinMode(LBLUE, OUTPUT); // Defines LBLUE as OUTPUT.
  pinMode(LGREEN, OUTPUT); // Defines LGREEN as OUTPUT.
  pinMode(LRED, OUTPUT); // Defines LRED as OUTPUT.
  pinMode(LA, OUTPUT); // Defines LA as OUTPUT.
  pinMode(LB, OUTPUT); // Defines LB as OUTPUT.
  pinMode(LC, OUTPUT); // Defines LC as OUTPUT.
  pinMode(LD, OUTPUT); // Defines LD as OUTPUT.
  pinMode(LE, OUTPUT); // Defines LE as OUTPUT.
  pinMode(LF, OUTPUT); // Defines LF as OUTPUT.
  pinMode(LG, OUTPUT); // Defines LG as OUTPUT.

  turnOffOutputs(); // turn off the outputs.
}

void loop() 
{
  core(); // Execute the core function.
}
