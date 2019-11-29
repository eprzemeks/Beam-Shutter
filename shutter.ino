bool ser1=1, ser2=1, ser3=1, ser4=1;
#include <Servo.h>

Servo s1;
Servo s2;
Servo s3;
Servo s4;

char servo=0;

void setup() {
  s1.attach(9);
  s2.attach(10);
  s3.attach(11);
  s4.attach(12);

  pinMode(2, OUTPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, OUTPUT);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  pinMode(13, INPUT_PULLUP);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, OUTPUT);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(2, ser1);
  digitalWrite(5, ser2);
  digitalWrite(8, ser3);
  digitalWrite(A1, ser4);
  s1.write(180*ser1);
  s2.write(180*ser2);
  s3.write(180*ser3);
  s4.write(180*ser4);
  if (!digitalRead(3))
  {
    delay(100);
    if (!digitalRead(3))
    {
      ser1=0;
    }
  }
  if (!digitalRead(4))
  {
    delay(100);
    if (!digitalRead(4))
    {
      ser1=1;
    }
  }
  if (!digitalRead(6))
  {
    delay(100);
    if (!digitalRead(6))
    {
      ser2=0;
    }
  }
  if (!digitalRead(7))
  {
    delay(100);
    if (!digitalRead(7))
    {
      ser2=1;
    }
  }
  if (!digitalRead(13))
  {
    delay(100);
    if (!digitalRead(13))
    {
      ser3=0;
    }
  }
  if (!digitalRead(A0))
  {
    delay(100);
    if (!digitalRead(A0))
    {
      ser3=1;
    }
  }
  if (!digitalRead(A2))
  {
    delay(100);
    if (!digitalRead(A2))
    {
      ser4=0;
    }
  }
  if (!digitalRead(A3))
  {
    delay(100);
    if (!digitalRead(A3))
    {
      ser4=1;
    }
  }
  if(Serial.available()>0)
  {
    servo=Serial.read();

    switch  (servo)
    {
      case 'A':
      {
        ser1='0'-Serial.read()+1;
        break;
      }
      case 'B':
      {
        ser2='0'-Serial.read()+1;
        break;
      }
      case 'C':
      {
        ser3='0'-Serial.read()+1;
        break;
      }
      case 'D':
      {
        ser4='0'-Serial.read()+1;
        break;
      }
      case 'S':
      {
        Serial.print(!ser1, DEC);
        Serial.print(!ser2, DEC);
        Serial.print(!ser3, DEC);
        Serial.println(!ser4, DEC);
      }
    }
  }
}
