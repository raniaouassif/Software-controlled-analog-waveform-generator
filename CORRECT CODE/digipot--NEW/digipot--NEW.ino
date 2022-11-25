#include <SPI.h>

int address = 0x00;
int CS= 10;

void setup(){
  pinMode (CS, OUTPUT);
  SPI.begin();
}

void loop(){
  
  digitalPotWrite(112);
  delay(10);
 
}

int digitalPotWrite(int value) {
  digitalWrite(CS, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(CS, HIGH);
}