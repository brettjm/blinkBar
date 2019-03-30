#define POT_PIN   A3
#define ONOFF_PIN 13
#define LED_1     2
#define LED_2     3
#define LED_3     4
#define LED_4     5
#define LED_5     6
#define LED_6     7
#define LED_7     8
#define LED_8     9
#define LED_9     10
#define LED_10    11
#define LED_11    12

int i = LED_1;  // start with first pin
int dir = 1;    // 1 increments, 0 decrements

void setup() 
{
  pinMode(LED_1,  OUTPUT);
  pinMode(LED_2,  OUTPUT);
  pinMode(LED_3,  OUTPUT);
  pinMode(LED_4,  OUTPUT);
  pinMode(LED_5,  OUTPUT);
  pinMode(LED_6,  OUTPUT);
  pinMode(LED_7,  OUTPUT);
  pinMode(LED_8,  OUTPUT);
  pinMode(LED_9,  OUTPUT);
  pinMode(LED_10, OUTPUT);
  pinMode(LED_11, OUTPUT);

  pinMode(ONOFF_PIN, INPUT);
  pinMode(POT_PIN,   INPUT);
}

int getDelayVal()
{
  int readVal = analogRead(POT_PIN);  

  // readVal values range from 0 to 900
  // delay values range from 40 to 80
  if (readVal < 100)
    return 40;
  else if (readVal >= 100 && readVal < 200)
    return 45;
  else if (readVal >= 200 && readVal < 300)
    return 50;
  else if (readVal >= 300 && readVal < 400)
    return 55;
  else if (readVal >= 400 && readVal < 500)
    return 60;
  else if (readVal >= 500 && readVal < 600)
    return 65;
  else if (readVal >= 600 && readVal < 700)
    return 70;
  else if (readVal >= 700 && readVal < 800)
    return 75;
  else if (readVal >= 800 && readVal < 900)
    return 80;
  else if (readVal >= 900)
    return 85;
}

void loop() 
{ 
//  int onOff = digitalRead(ONOFF_PIN);
  if (digitalRead(ONOFF_PIN))
  { 
    digitalWrite(i, HIGH);
    delay(getDelayVal());
    digitalWrite(i, LOW);
  }
  else
  {
    digitalWrite(i, LOW);
  }

  if (dir)
    i++;
  else
    i--;

  if (i == 2)
    dir = 1;
  else if (i == 12)
    dir = 0;
}
