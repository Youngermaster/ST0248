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

// You can change the pins
#define START 7 // This for a button, It gives the start of the process.
#define STOP 6 // This is for a button, It give the end of the process.
#define SNL 5 // This is for a sensor level, indicates the minimum water level.
#define SNH 4 // This is for a sensor level, indicates the maximum water level.
#define EV 8 // This is for a electro valve of 12 Volts, It allows the passage of water.
#define BH 9 // This is for a hydraulic pump, It fills the tank to the maximum level. 
#define AM 13 // This is a mechanical agitator.

unsigned int counter = 0;  // This variable will be iterable for do cycles.
bool startCondition = false; // Indicates if the process have to start or not.


/**
 * Simaulate the bottle shake and it do this process 5 times.
 * @parameters none
 * @return void 
 */
void shake()
{
  while (counter < 5) 
  {
    delay(10000);  // Wait 10 seconds.
    digitalWrite(AM, HIGH); // Turn on the motor.
    delay(30000);  // Wait 30 seconds.
    digitalWrite(AM, LOW); // Turn off the motor.
    counter++; // Increments the counter.
  } 
}

/**
 * This is the core of the program
 * @parameters none
 * @return void
 */
void core()
{
    while(digitalRead(STOP) == LOW) // while we don't push STOP button this will be execute.
    {
      if (digitalRead(START) == HIGH) // If We push START button we allow the access to the next methods.
        startCondition = true; // Changes to true the startCondition boolean.
        
      if (startCondition) // If previously we push START this will be executed.
      {
        while(digitalRead(SNH) == LOW) // While water don't reach the maximum level this will be executed.
          digitalWrite(BH, HIGH); // Keeps the hydraulic pump open. 
        
          digitalWrite(BH, LOW); // Close the hydraulic pump.
          shake(); // Calls the shake method.
        counter = 0; // Set the iterable counter to zero.
        digitalWrite(BH, LOW); // Close the hydraulic pump.
        while (digitalRead(SNL) == LOW) // While water don't reach the minimum level this will be executed.
          digitalWrite(EV, HIGH); // Keeps the electro valve open.

        digitalWrite(EV, LOW); // Close the electro valve.
        startCondition = false; // Set the startCondition to false.
      }
    }
}

/**
 * @parameters none.
 * @returns void.
 * Runs once and setting up your Arduino for the rest of the program.
 */
void setup()
{
  pinMode(START, INPUT); // Defines START as INPUT.
  pinMode(STOP, INPUT); // Defines STOP as INPUT.
  pinMode(SNL, INPUT); // Defines SNL as INPUT.
  pinMode(SNH, INPUT); // Defines SNH as INPUT.
  pinMode(EV, OUTPUT); // Defines EV as OUTPUT.
  pinMode(BH, OUTPUT); // Defines BH as OUTPUT.
  pinMode(AM, OUTPUT); // Defines AM as OUTPUT.

  digitalWrite(EV, LOW); // Close the electro valve.
  digitalWrite(BH, LOW); // Close the hydraulic pump.
  digitalWrite(AM, LOW); // Turn off the agitator motor.
  Serial.begin(9600); // Sets the data rate in bits per second (baud) for serial data transmission.
}

/**
 * @parameters none.
 * @returns void.
 * Execute the core function.
 */
void loop()
{
  core(); // Calls the core function.
}