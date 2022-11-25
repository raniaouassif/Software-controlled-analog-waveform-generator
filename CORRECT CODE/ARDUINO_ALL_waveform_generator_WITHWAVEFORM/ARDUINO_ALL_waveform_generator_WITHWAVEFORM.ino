//test
#include <AD9833.h>
#include <digitalWriteFast.h>
#include <SPI.h>
#include <math.h>

//--------------- Create an AD9833 object ----------------
// Note, SCK and MOSI must be connected to CLK and DAT pins on the AD9833 for SPI
#define FNC_PIN 10      // Can be any digital IO pin
#define Frequency 100
AD9833 gen(FNC_PIN);       // Defaults to 25MHz internal reference frequency

WaveformType waveType;
int frequencyLength;
int amplitudeLength;
int c ;
int c1;
int c2;
int c3;
int c4;
float FREQ = 100;
int myFrequency = 0;
float myAmplitude;
int myPhase;
int myWaveIdx;
WaveformType myWaveformType;
//DIGIPOT MCP4131
int address = 0x00;
int CS1= 9;
float VIN = 0.67;
int ad9833_value;
float ad9833_voltage;
int Dn;

void setup() {
  Serial.begin(9600);
  pinMode (CS1, OUTPUT);
  gen.Begin();
  pinMode(LED_BUILTIN,OUTPUT);
  gen.ApplySignal(SINE_WAVE, REG0, FREQ);
  gen.EnableOutput(true);   // Turn ON the output - it defaults to OFF
  // There should be a 1 Hz square wave on the output of the AD9833
}

void loop() {
  delay(10);

  if(Serial.available() > 0) {
    //FREQUENCY
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
    } else if (frequencyLength ==5) {
      c = Serial.read();
      c1 = Serial.read();
      c2 = Serial.read();
      c3 = Serial.read();
      c4 = Serial.read();
      myFrequency = c * pow(10, 4) + c1 *pow(10, 3) + c2 * pow(10, 2) + c3 * pow(10, 1) + c4; 
    }
    //AMPLITUDE
    amplitudeLength = Serial.read();
    if(amplitudeLength == 1) {
      c = Serial.read();
      myAmplitude = (float) c;
    } else if( amplitudeLength == 3) {
      c = Serial.read();
      delay(1000);
      c1 = Serial.read();
      delay(1000);
      myAmplitude = (float) ( c +  0.1 * c1); //Careful : returns 0.000001 precision 
      // -> precision in compareFloat 
      //ex: 2.900000  
    }
    //PHASE
    myPhase = Serial.read();
    //WAVEFORM TYPE
    myWaveIdx = Serial.read();
    if(myWaveIdx == 1){
      myWaveformType = SINE_WAVE;      
    } else if(myWaveIdx == 2) {
      myWaveformType = SQUARE_WAVE;
    } else if(myWaveIdx == 3) {
      myWaveformType = TRIANGLE_WAVE;
    }
  gen.ApplySignal(myWaveformType, REG0, (float) myFrequency);
  gen.SetPhase(REG0, (float) myPhase);
  Dn = 128 - (128 * (VIN / (myAmplitude + 0.4)));
  }
  digitalPotWrite(Dn);
} 

int digitalPotWrite(int value) {
  digitalWrite(CS1, LOW);
  delay(100);
  SPI.transfer(address);
  SPI.transfer(value);
  delay(100);
  digitalWrite(CS1, HIGH);
}

//compares if the float f1 is equal with f2 and returns 1 if true and 0 if false
int compare_float(float f1, float f2){
  float precision = 0.000001;
  if (((f1 - precision) < f2) && ((f1 + precision) > f2)){
    return 1;
  } else {
    return 0;
  }
}

