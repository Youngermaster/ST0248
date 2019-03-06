#define decrementButton 35
#define incrementButtton 34
#define LR 4 //Segmento rojo del RGB en el pin PWM2
#define LG 3 //Segmento rojo del RGB en el pin PWM3
#define LB 5 //Segmento rojo del RGB en el pin PWM4

unsigned int counter = 0;
unsigned int pressed_1;
unsigned int pressed_2;

void encender(int a, int b, int c, int d, int e, int f, int g)
{
  digitalWrite (29, a);
  digitalWrite (28, b);
  digitalWrite (27, c);
  digitalWrite (26, d);
  digitalWrite (25, e);
  digitalWrite (24, f);
  digitalWrite (23, g);
}

void encenderNumero(int numero)
{
  switch (numero)
  {
    case 0:
      encender (1, 1, 1, 1, 1, 1, 0); // 0
      encenderLED(1);
      break;

    case 1:
      encender (0, 1, 1, 0, 0, 0, 0); // 1
      encenderLED(2);
      break;

    case 2:
      encender (1, 1, 0, 1, 1, 0, 1); // 2
      encenderLED(3);
      break;

    case 3:
      encender (1, 1, 1, 1, 0, 0, 1); // 3
      encenderLED(4);
      break;

    case 4:
      encender (0, 1, 1, 0, 0, 1, 1); // 4
      encenderLED(1);
      break;

    case 5:
      encender (1, 0, 1, 1, 0, 1, 1); // 5
      encenderLED(2);
      break;

    case 6:
      encender (1, 0, 1, 1, 1, 1, 1); // 6
      encenderLED(3);
      break;

    case 7:
      encender (1, 1, 1, 0, 0, 0, 0); // 7
      encenderLED(4);
      break;

    case 8:
      encender (1, 1, 1, 1, 1, 1, 1); // 8
      encenderLED(1);
      break;

    case 9:
      encender (1, 1, 1, 1, 0, 1, 1); // 9
      encenderLED(2);
      break;
  }
}

void encenderLED(int color)
{
  switch (color)
  {
    case 1:
      analogWrite(LR, 255);
      analogWrite(LG, 0);
      analogWrite(LB, 0);
      break;
    case 2:
      analogWrite(LR, 0);
      analogWrite(LG, 255);
      analogWrite(LB, 0);
      break;
    case 3:
      analogWrite(LR, 0);
      analogWrite(LG, 0);
      analogWrite(LB, 255);
      break;
    case 4:
      analogWrite(LR, 255);
      analogWrite(LG, 255);
      analogWrite(LB, 255);
      break;
    default:
      break;
  }
}

void setup()
{
  pinMode(29, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(LR, OUTPUT);
  pinMode(LG, OUTPUT);
  pinMode(LB, OUTPUT);

  pinMode(decrementButton, INPUT);
  pinMode(incrementButtton, INPUT);
}

void loop()
{

  encenderNumero(counter);

  if (digitalRead(incrementButtton) == HIGH) {

    delay(500);
    while (digitalRead(incrementButtton) == HIGH);

    counter++;

    if (counter > 9)
      counter = 0;
  }




  /**
    if (digitalRead(decrementButton) == LOW)
      pressed_2 = 1;

    if (digitalRead(decrementButton) == HIGH && pressed_2 == 1)
    {
      pressed_2 = 0;
      counter--;

      if (counter < 0)
        counter = 0;
    }
  */
}
