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
#define BH 9 // This is for a hydraulic bomb, It fills the tank to the maximum level. 
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
    while(digitalRead(STOP) == LOW)
    {
      if (digitalRead(START) == HIGH)
        startCondition = true;
        
      if (startCondition) 
      {
        while(digitalRead(SNH) == LOW)
          digitalWrite(BH, HIGH);
        
          digitalWrite(BH, LOW);
          shake();
        counter = 0;
        digitalWrite(BH, LOW);
        while (digitalRead(SNL) == LOW) 
          digitalWrite(EV, HIGH);

        digitalWrite(EV, LOW);
        startCondition = false;
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

/**
 * @parameters none.
 * @returns void.
 * Execute the core function.
 */
void loop()
{
  core();
}