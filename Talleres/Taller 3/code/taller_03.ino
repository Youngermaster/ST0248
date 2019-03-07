/*------------------------------------------------
* Electrónica Digital                            *
* Taller 3                                       *
*                                                *
* Description:                                   *
*                                                *
*                                                *
* Members:                                       *
*          - Camila Barona Cabrera               *
*          - Maria Antonia Rincón                *
*          - Valeria Suarez                      *
*          - Sofia Uribe                         *
*          - Juan Manuel Young Hoyos             *
*                                                *
* Teacher: David Velásquez                       *
*                                                *
* Created 25/02/2019  (DD/MM/YYYY)               *
*                                                *
-------------------------------------------------*/

// These are the elements that will be conect to the arduino's pins
// You can modify they.
#define RED_LED 7        // This allude to the red led.
#define YELLOW_LED 6     // This allude to the yellow led.
#define BLUE_LED 5       // This allude to the blue led.
#define GREEN_LED 4      // This allude to the green led.
#define POTENTIOMETER 0 // This allude to the potentiometer.

float potenMeterV = 0; // It saves the potentiometer's value.

/**
 * parameters: ledNumber -> int.
 * returns: void.
 * Depending of the parameter the method choose which color turn on.
 */
void turnOnLed(int ledNumber) 
{
  switch(ledNumber) 
  {
  	case 1: // Case 1: turn on the green LED.
      digitalWrite(GREEN_LED, HIGH);
      break;
    case 2: // Case 2: turn on the blue LED.
      digitalWrite(BLUE_LED, HIGH);
      break;
    case 3: // Case 3: turn on the yellow LED.
      digitalWrite(YELLOW_LED, HIGH);
      break;
    case 4: // Case 4: turn on the red LED.
      digitalWrite(RED_LED, HIGH);
    default: // default: do nothing.
      break;
  }
}

/**
 * parameters: ledNumber -> int.
 * returns: void.
 * Turn off all the LEDs.
 */
void turnOffLed(int ledNumber)
{
    switch(ledNumber) 
    {
         case 1: // Case 1: turn off the green LED.
             digitalWrite(GREEN_LED, LOW);
             break;
         case 2:  // Case 2: turn off the blue LED.
             digitalWrite(BLUE_LED, LOW);
             break;
         case 3:  // Case 3: turn off the yellow LED.
             digitalWrite(YELLOW_LED, LOW);
             break;
         case 4:  // Case 4: turn off the red LED.
             digitalWrite(RED_LED, LOW);
	     break;
         default:
         break;
  }
}

/**
 * parameters: potentMeter -> float.
 * returns: void.
 * Prints the voltage with the potentMeter value.
 */
void printsVoltage(float potentMeter)
{
  Serial.print("Voltage value: ");
  Serial.println(potentMeter * 5.0 / 1023.0);
}

/**
 * parameters: none.
 * returns: void.
 * This is core of the program and this have the conditionals to determine which
 * LED it should turn on.
 */
void core()
{
  potenMeterV = analogRead(POTENTIOMETER); // Reads the 'value' of the potentiometer
  printsVoltage(potenMeterV);              // Prints the potentiometer's voltage

  if (potenMeterV <= 1023 && potenMeterV >= 767)  // Turn on all the LEDs
  {
    turnOnLed(1);
    turnOnLed(2);
    turnOnLed(3);
    turnOnLed(4);
  } else if (potenMeterV < 767 && potenMeterV >= 511) // Turn on 2, 3, 4 and turn off the Green LED
  { 
    turnOffLed(1);
    turnOnLed(2);
    turnOnLed(3);
    turnOnLed(4);
  } else if (potenMeterV < 511 && potenMeterV >= 256) // Turn on 3, 4 and turn off the Green and Blue LED
  { 
    turnOffLed(1);
    turnOffLed(2);
    turnOnLed(3);
    turnOnLed(4);
  } else if (potenMeterV < 256 && potenMeterV > 0)  // Turn on 4 and turn off the Green, Blue and Red LED
  { 
    turnOffLed(1);
    turnOffLed(3);
    turnOffLed(3);
    turnOnLed(4);
  }
}

/**
 * parameters: none.
 * returns: void.
 * Runs once and setting up your Arduino for the rest of the program.
 */
void setup()
{
  pinMode(RED_LED, OUTPUT);      // Defines the led red as a output
  pinMode(YELLOW_LED, OUTPUT);   // Defines the led yellow as a output
  pinMode(BLUE_LED, OUTPUT);     // Defines the led blue as a output
  pinMode(GREEN_LED, OUTPUT);    // Defines the led green as a output
  // Sets the data rate in bits per second (baud) for serial data transmission
  Serial.begin(9600);            
}

/**
 * parameters: none.
 * returns: void.
 * Execute the core function.
 */
void loop()
{
  core();
}
