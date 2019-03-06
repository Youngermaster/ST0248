#define LBLUE 3
#define LGREEN 5
#define LRED 6
#define LA 7
#define LB 8
#define LC 9
#define LD 10
#define LE 11
#define LF 12
#define LG 13


int modMethod(float temperature)
{
  if (temperature >= 1000)
    return (int) temperature % 1000;
  
  else if (temperature < 1000 && temperature >= 100)
    return (int) temperature % 100;

  return (int) temperature % 10;
}

void turnOnDisplay(byte a, byte b, byte c, byte d, byte e, byte f, byte g)
{
  digitalWrite(LA, a);
  digitalWrite(LB, b);
  digitalWrite(LC, c);
  digitalWrite(LD, d);
  digitalWrite(LE, e);
  digitalWrite(LF, f);
  digitalWrite(LG, g);
}

void encenderNumero(byte number)
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

void turnOnRGBLED(byte color)
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

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
