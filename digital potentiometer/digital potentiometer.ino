#include <SPI.h>
int CS = 10 ; // initialising variable CS pin as pin 10 of arduino
int x ; // initialising variable x
float Voltage ; // initialising variable voltage
int I ; // this is the variable which changes in steps and hence changes resistance accordingly.
float minVin = 0.038;
float maxVin = 0.65;
long Rab = 10000;
float Ra;
float Rb;
float Vin;
float Vo;
float rawVo;
float rawVin;

float minVo;
float maxVo;
void setup()
{
//pinMode (CS , INPUT) ; // initialising 10 pin as output pin
pinMode (A0, OUTPUT) ; // initialising pin A0 as input pin
//pinMode(A1, INPUT);
//SPI.begin() ; // this begins Serial peripheral interfece
Serial.begin(9600) ; // this begins serial communications between arduino and ic.
}
void loop()
{
// for (int i = 0; i <= 255; i++)// this run loops from 0 to 255 step with 10 ms delay between each step
// {
// digitalPotWrite(i) ; // this writes level i to ic which determines resistance of ic
//  Ra = (Rab*(256-i))/256;
//  Rb = (Rab*i)/256;
// // Serial.print("i= ") ;
// // Serial.println(i) ;
//  Serial.print("Ra= ") ;
//  Serial.println(Ra) ;
//  Serial.print("Rb= ") ;
//  Serial.println(Rb) ;
// // minVo = minVin*(1+(Rb/Ra));
// // maxVo = maxVin*(1+(Rb/Ra));
// delay(10);
// rawVo = analogRead(A0) ; // read analog values from pin A0
// Vo = rawVo*(5.0/1023.0);
// rawVin = analogRead(A1) ; // read analog values from pin A0
// Vin = rawVin*(5.0/1023.0);
// //Vin = analogRead(A1) ;
// //Voltage = x; // this converts the analog value to corresponding voltage level
// //Serial.print("Level i = " ) ; // these serial commands print value of i or level and voltage across wiper
// //Serial.print(i) ; // and gnd on Serial monitor of arduino IDE
// //Serial.print("\t Value = ") ;
// //Serial.print("Vin= ") ;
// //Serial.println(Vin) ;
// Serial.println() ;
// //Serial.print("Vin= ") ;
// //Serial.println(Vin) ;
// Serial.print("Vo= ") ;
// Serial.println(Vo) ;
// Serial.println() ;
// delay(1000);

// }
delay(500);
rawVo = analogRead(A0) ; // read analog values from pin A0
Vo = rawVo*(5.0/1023.0);
Serial.print("Vo= ") ;
Serial.println(Vo) ;
// for (int i = 255; i >= 0; i--) // this run loops from 255 to 0 step with 10 ms delay between each step
// {
// digitalPotWrite(i) ;
// delay(10) ;
// x = analogRead(A0) ;
// Voltage = x; // this converts the analog value to corresponding voltage level
// Serial.print("Level i = " ) ; // these serial commands print value of i or level and voltage across wiper
// Serial.print(i); // and gnd on Serial monitor of arduino IDE
// Serial.print("\t value = ");
// //Serial.println(Voltage,3);
// }
}
int digitalPotWrite(int value) // this block is explained in coding section
{
digitalWrite(CS, LOW);
SPI.transfer(B00010010);
SPI.transfer(value);
digitalWrite(CS, HIGH);
}
