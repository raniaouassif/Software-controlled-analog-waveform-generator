#include <SPI.h>

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
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(Serial.available());
 // while(Serial.available() > 0) {
  if(Serial.available()>0){
    //Serial.println("something is printing");
    char val = Serial.read();
    //Serial.println("Val="+ val);
    if(val == 's'){
     // Serial.println("Waveform type: Sine");
     for(int i=0; i<=10; i++){
       digitalWrite(LED_BUILTIN,HIGH);
       delay(1000);
       digitalWrite(LED_BUILTIN,LOW);
       delay(1000);
     }
    } else if(val == 'q'){
      //Serial.println("Waveform type: Square");
     for(int i=0; i<=4; i++){
       digitalWrite(LED_BUILTIN,HIGH);
       delay(1000);
       digitalWrite(LED_BUILTIN,LOW);
       delay(1000);
     }
    } else if(val == 't'){
     // Serial.println("Waveform type: Triangle");
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
    //Serial.println(amplitudeValue);
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
    if(frequencyValue == 10000){
    //  Serial.println("Frequency = 1000 Hz");
     for(int i=0; i<=5; i++){
       digitalWrite(LED_BUILTIN,HIGH);
       delay(1000);
       digitalWrite(LED_BUILTIN,LOW);
       delay(1000);
     }

    }
    int phaseValue = Serial.read();
    if(phaseValue == 180){
     // Serial.println("Phase = 180 degrees");
     for(int i=0; i<=2; i++){
       digitalWrite(LED_BUILTIN,HIGH);
       delay(1000);
       digitalWrite(LED_BUILTIN,LOW);
       delay(1000);
     }

    }
    
    
  }
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
