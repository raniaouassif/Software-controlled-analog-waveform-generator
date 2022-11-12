#include <SPI.h>
int CS = 10 ; // initialising variable CS pin as pin 10 of arduino
int address = 0b00010001;

void setup() {
    pinMode (CS , OUTPUT) ; // initialising 10 pin as output pin
    SPI.begin() ; // this begins Serial peripheral interfece
    //Serial.begin(9600);
    digitalPotWrite(0x00);
    delay(1000);
    digitalPotWrite(0x80);
    delay(1000);
    digitalPotWrite(0xFF);
    delay(1000);
}
void loop() {
  for (int i = 0; i <= 255; i++){
      digitalPotWrite(i) ; // this writes level i to ic which determines resistance of ic
      delay(10);
  };
  delay(500);
  for (int i = 255; i >= 0; i--){
      digitalPotWrite(i) ; // this writes level i to ic which determines resistance of ic
      delay(10);
  };
}
int digitalPotWrite(int value){
  digitalWrite(CS, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(CS, HIGH);
}

