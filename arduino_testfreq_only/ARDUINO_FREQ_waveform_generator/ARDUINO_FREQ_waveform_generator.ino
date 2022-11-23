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
int frequencyLength;
int c ;
int c1;
int c2;
int c3;
int c4;
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
}

void loop() {
  if(Serial.available() > 0) {
      frequencyLength = Serial.read(); // WORKSà
      delay(1000);
      if(frequencyLength == 3) {
      c = Serial.read();
      delay(1000);
      c1 = Serial.read();
      delay(1000);
      c2 = Serial.read();
      delay(1000);
      myFrequency = c * pow(10, 2) + c1 *pow(10, 1) + c2; 
      if(compare_float((float) myFrequency, (float) 649)){
        for(int i=0; i<1; i++){
          digitalWrite(LED_BUILTIN,HIGH);
          delay(1000);
          digitalWrite(LED_BUILTIN,LOW);
          delay(1000);
        }
      }
    } else if (frequencyLength == 4) {
      c = Serial.read();
      delay(1000);
      c1 = Serial.read();
      delay(1000);
      c2 = Serial.read();
      delay(1000);
      c3 = Serial.read();
      delay(1000);
      myFrequency = c * pow(10, 3) + c1 *pow(10, 2) + c2 * pow(10, 1) + c3; 
      if(compare_float((float) myFrequency, (float) 4932)){
        for(int i=0; i<2; i++){
          digitalWrite(LED_BUILTIN,HIGH);
          delay(1000);
          digitalWrite(LED_BUILTIN,LOW);
          delay(1000);
        }
      }
    
    } else if (frequencyLength ==5) {
      c = Serial.read();
      c1 = Serial.read();
      c2 = Serial.read();
      c3 = Serial.read();
      c4 = Serial.read();
      myFrequency = c * pow(10, 4) + c1 *pow(10, 3) + c2 * pow(10, 2) + c3 * pow(10, 1) + c4; 
      if(compare_float((float) myFrequency, (float) 10000)){
      for(int i=0; i<2; i++){
        digitalWrite(LED_BUILTIN,HIGH);
        delay(1000);
        digitalWrite(LED_BUILTIN,LOW);
        delay(1000);
      }
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