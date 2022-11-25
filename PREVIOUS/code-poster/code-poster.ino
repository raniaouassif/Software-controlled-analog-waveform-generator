#include <AD9833.h>
#include <SPI.h>
//--------------- Create an AD9833 object ----------------
#define FNC_PIN 10      // CS for AD9833
AD9833 gen(FNC_PIN);   // Defaults to 25MHz internal reference frequency
//DIGIPOT MCP4131
int address = 0x00;
int CS1= 9;
float VIN = 0.67; // TO TRY: 0.68
//...
void setup() {
  Serial.begin(9600);
  pinMode (CS1, OUTPUT);
  gen.Begin(); 
  gen.ApplySignal(SINE_WAVE, REG0, FREQ); // Default Waveform: Sine 100Hz
}
void loop() {
  if(Serial.available() > 0) {
    frequencyLength = Serial.read(); 
    if(frequencyLength == 3) {
      c = Serial.read();
      c1 = Serial.read();
      c2 = Serial.read();
      myFrequency = c * pow(10, 2) + c1 *pow(10, 1) + c2; 
    } else if (frequencyLength == 4) {
      c = Serial.read();
      c1 = Serial.read();
      c2 = Serial.read();
      c3 = Serial.read();
      myFrequency = c * pow(10, 3) + c1 *pow(10, 2) + c2 * pow(10, 1) + c3; 
    } else if (frequencyLength ==5) {
      c = Serial.read();
      c1 = Serial.read();
      c2 = Serial.read();
      c3 = Serial.read();
      c4 = Serial.read();
      myFrequency = c * pow(10, 4) + c1 *pow(10, 3) + c2 * pow(10, 2) + c3 * pow(10, 1) + c4; 
    }
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
    myPhase = Serial.read();
    myWaveIdx = Serial.read();
    if(myWaveIdx == 1){ //SINE
      myWaveformType = SINE_WAVE;      
    } else if(myWaveIdx == 2) { //SQUARE
      myWaveformType = SQUARE_WAVE;
    } else if(myWaveIdx == 3) { // TRIANGLE
      myWaveformType = TRIANGLE_WAVE;
    }
    gen.ApplySignal(myWaveformType, REG0, (float) myFrequency);
    gen.SetPhase(REG0, (float) myPhase);
    Dn = 128 - (128 * (0.68 / (myAmplitude + 0.4))); // Wiper Position
  }
  digitalPotWrite(Dn);
} 
//SPI DIGIPOT
int digitalPotWrite(int value) {
  digitalWrite(CS1, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(CS1, HIGH);
}
