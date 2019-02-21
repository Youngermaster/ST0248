/**
* Electrónica Digital
* Taller 3
* Members:
*          - Camila Barona Cabrera
*          - Maria Antonia Rincón
*          - Valeria Suarez
*          - Sofia Uribe
*          - Juan Manuel Young Hoyos
*
* Teacher: David Velásquez
*
* Description: 
*/

#define REDLED 7
#define YELLOWLED 6
#define BLUELED 5
#define GREENLED 4
#define POTENTIOMETER 0

// It saves the potentiometer's value.
float potenMeterV = 0; 

void turnOnLed(int ledNumber) 
{
  switch(ledNumber) 
  {
  	case 1:
      turnOffLeds();
      digitalWrite(GREENLED, HIGH);
      break;
    case 2:
      turnOffLeds();
      digitalWrite(BLUELED, HIGH);
      break;
    case 3:
      turnOffLeds();
      digitalWrite(YELLOWLED, HIGH);
      break;
    case 4:
      turnOffLeds();
      digitalWrite(REDLED, HIGH);
    default:
      break;
  }
}

void turnOffLeds()
{
  digitalWrite(REDLED, LOW);
  digitalWrite(BLUELED, LOW);
  digitalWrite(GREENLED, LOW);
  digitalWrite(YELLOWLED, LOW);
}

void core()
{
  potenMeterV = analogRead(POTENTIOMETER);
  Serial.print("Voltage value: ");
  Serial.println(potenMeterV * 5.0 / 1023.0);
  
  if (potenMeterV <= 1023 && potenMeterV >= 767)
  {
    turnOnLed(1);
  } else if (potenMeterV < 767 && potenMeterV >= 511)
  { 
    turnOnLed(2);
  } else if (potenMeterV < 511 && potenMeterV >= 256)
  { 
    turnOnLed(3);
  } else if (potenMeterV < 256 && potenMeterV > 0)
  { 
    turnOnLed(4);
  }
  
}

void setup()
{
  pinMode(REDLED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);
  pinMode(BLUELED, OUTPUT);
  pinMode(GREENLED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  core();
}