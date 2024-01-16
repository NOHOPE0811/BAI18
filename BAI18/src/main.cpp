#include <Arduino.h>

#define led 23
#define kenh 0
#define tanso 5000
#define sobit 7
#define bt 0

void sangdan();
void tatdan();

byte a = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(bt, INPUT_PULLUP);
  ledcSetup(kenh, tanso, sobit);
  ledcAttachPin(led, 0);
}

void loop()
{
  sangdan();
}

void sangdan()
{
  if ((digitalRead(bt)) == 0)
  {
    a+=2;
    ledcWrite(kenh, a);
    Serial.println(a);
    while ((digitalRead(bt)) == 0)
    {
      delay(15);
    }
  }
}
void tatdan()
{
  for (int j = 255; j > 0; j--)
  {
    ledcWrite(kenh, j);
    delay(15);
  }
}