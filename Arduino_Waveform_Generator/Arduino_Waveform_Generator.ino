// Using AD9833 IC, MCP4131 digipot and UA741CP op amp
// this program allows to control waveform parameters using implemented Processing GUI

#include <AD9833.h>
#include <digitalWriteFast.h>
#include <SPI.h>
#include <math.h>

// Create an AD9833 object
#define FNC_PIN 10      // CS for AD9833
AD9833 gen(FNC_PIN);   // Defaults to 25MHz internal reference frequency

int frequencyLength;
int amplitudeLength;
int c;
int c1;
int c2;
int c3;
int c4;
int myFrequency = 0;
float myAmplitude;
int myPhase;
int myWaveIdx;

float FREQ = 100;
WaveformType myWaveformType;

//DIGIPOT MCP4131
int address = 0x00;
int CS1= 9;
float VIN = 0.67; // TO TRY: 0.68
int Dn;

void setup() {
  Serial.begin(9600); //baud rate = 9600
  pinMode (CS1, OUTPUT);
  gen.Begin();
  pinMode(LED_BUILTIN,OUTPUT); // for debugging 
  gen.ApplySignal(SINE_WAVE, REG0, FREQ); // default waveform : Sine, frequency = 100 Hz
  gen.EnableOutput(true);   // Turn ON the output - it defaults to OFF
}

void loop() {
  delay(10);
  if(Serial.available() > 0) {
    //FREQUENCY
    frequencyLength = Serial.read(); // read length of frequency entered in GUI
    delay(1000);
    if(frequencyLength == 3) { 
      c = Serial.read();
      delay(1000);
      c1 = Serial.read();
      delay(1000);
      c2 = Serial.read();
      delay(1000);
      myFrequency = c * pow(10, 2) + c1 *pow(10, 1) + c2;  // then convert to float 
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
  gen.ApplySignal(myWaveformType, REG0, (float) myFrequency); //apply new signal with GUI parameters
  gen.SetPhase(REG0, (float) myPhase); // apply new phase
  Dn = 128 - (128 * (VIN / (myAmplitude + 0.4))); //amplitude on oscilloscope is always off by 0.4, adjusting it here
  }
  digitalPotWrite(Dn); // write the wiper position to digipot
} 

//SPI DIGIPOT
int digitalPotWrite(int value) {
  digitalWrite(CS1, LOW);
  delay(100);
  SPI.transfer(address);
  SPI.transfer(value);
  delay(100);
  digitalWrite(CS1, HIGH);
}