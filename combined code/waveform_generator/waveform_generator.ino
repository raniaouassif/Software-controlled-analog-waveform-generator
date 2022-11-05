#include <AD9833.h>
#include <digitalWriteFast.h>
#include <SPI.h>

#define FNC_PIN 10       // Can be any digital IO pin
#define Frequency 1      // Frequency = 1Hz

//--------------- Create an AD9833 object ----------------
// Note, SCK and MOSI must be connected to CLK and DAT pins on the AD9833 for SPI
AD9833 gen(FNC_PIN);       // Defaults to 25MHz internal reference frequency

WaveformType waveType;
float frequency;
float phase;
// int CS = 10;
// int x ; // initialising variable x
// float Voltage ; // initialising variable voltage
// int I ; // this is the variable which changes in steps and hence changes resistance accordingly.
// byte address = B00010001;

void setup() {
  // put your setup code here, to run once:
  //pinMode (CS , OUTPUT) ; // initialising 10 pin as output pin
 // pinMode (A0, INPUT) ; // initialising pin A0 as input pin
  //SPI.begin() ; // this begins Serial peripheral interfece
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
  //gen.Begin();

  // Apply a 1000 Hz sine wave using REG0 (register set 0). There are two register sets: REG0 and REG1.
  // Each one can be programmed for:
  //   Signal type - SINE_WAVE, TRIANGLE_WAVE, SQUARE_WAVE, and HALF_SQUARE_WAVE
  //   Frequency - 0 to 12.5 MHz
  //   Phase - 0 to 360 degress (this is only useful if it is 'relative' to some other signal
  //           such as the phase difference between REG0 and REG1).
  // In ApplySignal, if Phase is not given, it defaults to 0.
  //gen.ApplySignal(waveType, REG0, frequency,SAME_AS_REG0,phase);

  //gen.EnableOutput(true);   // Turn ON the output - it defaults to OFF
  // There should be a 1 Hz square wave on the output of the AD9833
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(Serial.available());
 // while(Serial.available() > 0) {
  if(Serial.available()>0){
    //Serial.println("something is printing");
    char val = Serial.read();
    //Serial.println("Val=");
    //Serial.print(val);
    if(val == 's'){
     // Serial.println("Waveform type: Sine");
     waveType = SINE_WAVE;
     for(int i=0; i<=10; i++){
       digitalWrite(LED_BUILTIN,HIGH);
       delay(1000);
       digitalWrite(LED_BUILTIN,LOW);
       delay(1000);
     }
    } else if(val == 'q'){
      //Serial.println("Waveform type: Square");
       waveType = SQUARE_WAVE;
     for(int i=0; i<=4; i++){
       digitalWrite(LED_BUILTIN,HIGH);
       delay(1000);
       digitalWrite(LED_BUILTIN,LOW);
       delay(1000);
     }
    } else if(val == 't'){
     // Serial.println("Waveform type: Triangle");
      waveType = TRIANGLE_WAVE;
     for(int i=0; i<=6; i++){
       digitalWrite(LED_BUILTIN,HIGH);
       delay(1000);
       digitalWrite(LED_BUILTIN,LOW);
       delay(1000);
     }
    }
    int amplitudeLength = Serial.read();
    String a = "";
    for(int i=0; i<amplitudeLength; i++){
      char c = Serial.read();
      a += c;
    }
    float amplitudeValue = a.toFloat();
   // Serial.println("amplitude= ");
    //Serial.print(amplitudeValue);
    if(amplitudeValue == 2.5){
     // Serial.println("Amplitude = 5 V");
     for(int i=0; i<=4; i++){
       digitalWrite(LED_BUILTIN,HIGH);
       delay(1000);
       digitalWrite(LED_BUILTIN,LOW);
       delay(1000);
     }

    }
    int frequencyLength = Serial.read();
    String f = "";
    for(int i=0; i<frequencyLength; i++){
      char c = Serial.read();
      f += c;
    }
    int frequencyValue = f.toInt();
    //Serial.println("frequency= ");
    //Serial.print(frequencyValue);
    frequency = (float)frequencyValue;
    if(frequency == 10000.00){
    //  Serial.println("Frequency = 1000 Hz");
     for(int i=0; i<=5; i++){
       digitalWrite(LED_BUILTIN,HIGH);
       delay(1000);
       digitalWrite(LED_BUILTIN,LOW);
       delay(1000);
     }

    }
    int phaseValue = Serial.read();
   // Serial.println("phase= ");
   // Serial.print(phaseValue);
    phase = (float)phaseValue;
    if(phase == 180.00){
     // Serial.println("Phase = 180 degrees");
     for(int i=0; i<=2; i++){
       digitalWrite(LED_BUILTIN,HIGH);
       delay(1000);
       digitalWrite(LED_BUILTIN,LOW);
       delay(1000);
     }

    }
    
    
  }
   //Serial.println(analogRead(A0));

    //delay(10);
  // I = 255;
  // digitalPotWrite(I);
  // x = analogRead(A0);

}

// int digitalPotWrite(int value)
// {
//   digitalWrite(CS, LOW);
//   SPI.transfer(address);
//   SPI.transfer(value);
//   digitalWrite(CS, HIGH);
// }
