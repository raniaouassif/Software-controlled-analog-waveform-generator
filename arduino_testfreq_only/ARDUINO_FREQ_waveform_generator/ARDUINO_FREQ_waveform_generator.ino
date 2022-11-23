#include <AD9833.h>
#include <digitalWriteFast.h>
#include <SPI.h>
#include <math.h>

//--------------- Create an AD9833 object ----------------
// Note, SCK and MOSI must be connected to CLK and DAT pins on the AD9833 for SPI
#define FNC_PIN 10       // Can be any digital IO pin
#define Frequency 3
AD9833 gen(FNC_PIN);       // Defaults to 25MHz internal reference frequency

WaveformType waveType;
float frequency;
float phase;
bool myBool;
bool equal;
int myFrequencyLength;
int frequencyLength;
int frequencyLength3;

int frequencyLength1;
int frequencyLength2;

int result;
int c ;
int c1;
int c2;
float FREQ = 100;
int myFrequency = 0;
int frequencies[1];
float amplitudes[2] = {2.5, 3} ;
float phases[2] = {0, 0};
WaveformType waveTypes[2] = {SINE_WAVE, SINE_WAVE};
int index = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
  result = 6 * pow(10, 2) + 4 * pow(10, 1) + 9 * pow(10, 0);
  myBool = true;
}

void loop() {
  if(Serial.available() > 0) {
    frequencyLength = Serial.read(); // WORKS
    int myFrequencyLength = &frequencyLength;
    delay(1000);
    frequencyLength1 = (*myFrequencyLength - 1); // 1
    frequencyLength2 = (*myFrequencyLength  - 2); // 2
    frequencyLength3 =  (*myFrequencyLength  - 3);

    delay(1000); 
    c = Serial.read();
    delay(1000);
    c1 = Serial.read();
    delay(1000);
    c2 = Serial.read();
    delay(1000);
    if(*myFrequencyLength == 3){
      for(int i=0; i<1; i++){
        digitalWrite(LED_BUILTIN,HIGH);
        delay(1000);
        digitalWrite(LED_BUILTIN,LOW);
        delay(1000);
      }
    }
    if(c == 6){
      for(int i=0; i<1; i++){
        digitalWrite(LED_BUILTIN,HIGH);
        delay(1000);
        digitalWrite(LED_BUILTIN,LOW);
        delay(1000);
      }
    }
    if(c1 == 4){
      for(int i=0; i<1; i++){
        digitalWrite(LED_BUILTIN,HIGH);
        delay(1000);
        digitalWrite(LED_BUILTIN,LOW);
        delay(1000);
      }
    }
    if(c2 == 9){
      for(int i=0; i<1; i++){
        digitalWrite(LED_BUILTIN,HIGH);
        delay(1000);
        digitalWrite(LED_BUILTIN,LOW);
        delay(1000);
      }
    }
    myFrequency = c * pow(10, frequencyLength1) + c1 *pow(10, frequencyLength2) + c2 * pow(10, frequencyLength3); 
    if(myFrequency == 649){
      for(int i=0; i<1; i++){
        digitalWrite(LED_BUILTIN,HIGH);
        delay(1000);
        digitalWrite(LED_BUILTIN,LOW);
        delay(1000);
      }
    }
  }
}

//compares if the float f1 is equal with f2 and returns 1 if true and 0 if false
 int compare_float(float f1, float f2)
 {
  float precision = 0.001;
  if (((f1 - precision) < f2) && 
      ((f1 + precision) > f2))
   {
    return 1;
   }
  else
   {
    return 0;
   }
 }

// int getFrequency() {
//     frequencyLength = Serial.read(); // WORKS
//     for(int i=1; i<=3; i++){
//       c = Serial.read();
//       if(c == 6 || c == 4 || c == 9){
//         digitalWrite(LED_BUILTIN,LOW);
//         delay(1000);
//         digitalWrite(LED_BUILTIN,HIGH);
//         delay(1000);
//         digitalWrite(LED_BUILTIN,LOW);
//         delay(1000);
//         digitalWrite(LED_BUILTIN,HIGH);
//         delay(1000);
//       }
//     }
//     return myFrequency;
//  }
 