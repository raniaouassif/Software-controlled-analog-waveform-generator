void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(Serial.available());
  while(Serial.available() > 0) {
//  if(Serial.available()>0){
    Serial.println("something is printing");
    char val = Serial.read();
    if(val == 's'){
      Serial.println("Waveform type: Sine");
//      for(int i=0; i<=10; i++){
//        digitalWrite(LED_BUILTIN,HIGH);
//        delay(1000);
//        digitalWrite(LED_BUILTIN,LOW);
//        delay(1000);
//      }
    } else if(val == 'q'){
      Serial.println("Waveform type: Square");
//      for(int i=0; i<=4; i++){
//        digitalWrite(LED_BUILTIN,HIGH);
//        delay(1000);
//        digitalWrite(LED_BUILTIN,LOW);
//        delay(1000);
//      }
    } else if(val == 't'){
      Serial.println("Waveform type: Triangle");
//      for(int i=0; i<=6; i++){
//        digitalWrite(LED_BUILTIN,HIGH);
//        delay(1000);
//        digitalWrite(LED_BUILTIN,LOW);
//        delay(1000);
//      }
    }
    int amplitudeValue = Serial.read();
    //Serial.println(amplitudeValue);
    if(amplitudeValue == 5){
      Serial.println("Amplitude = 5 V")l
//      for(int i=0; i<=4; i++){
//        digitalWrite(LED_BUILTIN,HIGH);
//        delay(1000);
//        digitalWrite(LED_BUILTIN,LOW);
//        delay(1000);
//      }

    }

    int frequencyValue = Serial.parseInt();
    if(frequencyValue == 1000){
      Serial.println("Frequency = 1000 Hz");
//      for(int i=0; i<=5; i++){
//        digitalWrite(LED_BUILTIN,HIGH);
//        delay(1000);
//        digitalWrite(LED_BUILTIN,LOW);
//        delay(1000);
//      }

    }
    int phaseValue = Serial.read();
    if(phaseValue == 180){
      Serial.println("Phase = 180 degrees");
//      for(int i=0; i<=2; i++){
//        digitalWrite(LED_BUILTIN,HIGH);
//        delay(1000);
//        digitalWrite(LED_BUILTIN,LOW);
//        delay(1000);
//      }

    }
    
    
  }

}
