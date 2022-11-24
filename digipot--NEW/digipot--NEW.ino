#include <SPI.h>

byte address = 0x00;
int CS= 10;

void setup() {
  pinMode (CS, OUTPUT);
  SPI.begin();
}

void loop(){
  for (int i = 0; i <= 128; i++){
  digitalPotWrite(i);
  delay(10);
  }
  delay(500);
  for (int i = 128; i >= 0; i--) {
  digitalPotWrite(i);
  delay(10);
  }
}

int digitalPotWrite(int value) {
  digitalWrite(CS, LOW);
  delay(100);
  SPI.transfer(address);
  SPI.transfer(value);
  delay(100);
  digitalWrite(CS, HIGH);
}