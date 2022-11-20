#include <AD9833.h>
#include <digitalWriteFast.h>
#include <SPI.h>

//--------------- Create an AD9833 object ----------------
// Note, SCK and MOSI must be connected to CLK and DAT pins on the AD9833 for SPI
#define FNC_PIN 10       // Can be any digital IO pin
#define Frequency 1000
AD9833 gen(FNC_PIN);       // Defaults to 25MHz internal reference frequency

WaveformType waveType;
float frequency;
float phase;
float frequencies[] = {1000, 1000};
float amplitudes[] = {2.5, 3} ;
float phases[] = {0, 0};
WaveformType waveTypes[] = {SINE_WAVE, SINE_WAVE};
int index = 0;

void setup() {
  Serial.begin(9600);
  //pinMode(LED_BUILTIN,OUTPUT);
  gen.Begin();
 // gen.ApplySignal(SQUARE_WAVE, REG0, frequencies[(sizeof(frequencies) / sizeof(frequencies[0])) - 1]);
  gen.EnableOutput(true);   // Turn ON the output - it defaults to OFF
}

void loop() {
  if(Serial.available()){ // if data is sent from GUI 
    //Waveform type
    index++;
    Serial.print("Inside");
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
  frequencies[1] = frequency;
  waveTypes[1] = waveType;

  gen.ApplySignal(waveTypes[(sizeof(waveTypes) / sizeof(waveTypes[0])) - 1], REG0, frequencies[(sizeof(frequencies) / sizeof(frequencies[0])) - 1]);

  
}