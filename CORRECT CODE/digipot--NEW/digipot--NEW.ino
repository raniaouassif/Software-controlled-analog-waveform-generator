#include <SPI.h>

int address = 0x00;
int CS= 10;

void setup(){
pinMode (CS, OUTPUT);
SPI.begin();
}

void loop()
{
for (int i = 0; i <= 112; i++)
{
digitalPotWrite(i);
delay(10);
}
delay(500);
for (int i = 112; i >= 0; i--)
{
digitalPotWrite(i);
delay(10);
}
}

int digitalPotWrite(int value)
{
digitalWrite(CS, LOW);
SPI.transfer(address);
SPI.transfer(value);
digitalWrite(CS, HIGH);
}