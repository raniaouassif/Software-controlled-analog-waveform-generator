#include <AD9833.h>
#include <digitalWriteFast.h>
#include <SPI.h>

//--------------- Create an AD9833 object ----------------
// Note, SCK and MOSI must be connected to CLK and DAT pins on the AD9833 for SPI
#define FNC_PIN 10       // Can be any digital IO pin
AD9833 gen(FNC_PIN);       // Defaults to 25MHz internal reference frequency

WaveformType waveType;
float frequency;
float phase;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
  gen.Begin();
  // Initial signal
  gen.ApplySignal(SINE_WAVE, REG0, 1000, SAME_AS_REG0, 0);
  gen.EnableOutput(true);   // Turn ON the output - it defaults to OFF
  // There should be a 1 Hz square wave on the output of the AD9833
}

void loop() {
  if(Serial.available()){ // if data is sent from GUI 
    //Waveform type
    char val = Serial.read(); // first char sent by GUI is waveform type
    if(val == 's'){
      waveType = SINE_WAVE;
    } else if(val == 'q'){
      waveType = SQUARE_WAVE;
    } else if(val == 't'){
      waveType = TRIANGLE_WAVE;
    }
    //Amplitude 
    // Cannot send float, so sending each char at a time
    int amplitudeLength = Serial.read(); // second char sent by GUI is length of amplitude
    String a = "";
    for(int i=0; i<amplitudeLength; i++){
      char c = Serial.read();
      a += c;
    }
    float amplitudeValue = a.toFloat();
    // Frequency
    // Sends at most 1 byte (maxValue =255 )
    // So sending one char at a time
    int frequencyLength = Serial.read();
    String f = "";
    for(int i=0; i<frequencyLength; i++){
      char c = Serial.read();
      f += c;
    }
    frequency = (float)f.toInt();
   
    //Phase
    int phaseValue = Serial.read();
    phase = (float)phaseValue;   
  }
}