void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(Serial.available());
  if(Serial.available()>0){
    Serial.println("something is printing");
    char val = Serial.read();
    if(val == 's'){
      for(int i=0; i<=10; i++){
        digitalWrite(LED_BUILTIN,HIGH);
        delay(1000);
        digitalWrite(LED_BUILTIN,LOW);
        delay(1000);
      }
    } else if(val == 'q'){
      for(int i=0; i<=4; i++){
        digitalWrite(LED_BUILTIN,HIGH);
        delay(1000);
        digitalWrite(LED_BUILTIN,LOW);
        delay(1000);
      }
    } else if(val == 't'){
      for(int i=0; i<=6; i++){
        digitalWrite(LED_BUILTIN,HIGH);
        delay(1000);
        digitalWrite(LED_BUILTIN,LOW);
        delay(1000);
      }
    }
    int amplitudeValue = Serial.read();
    //Serial.println(amplitudeValue);
    if(amplitudeValue == 5){
      for(int i=0; i<=4; i++){
        digitalWrite(LED_BUILTIN,HIGH);
        delay(1000);
        digitalWrite(LED_BUILTIN,LOW);
        delay(1000);
      }

    }

    int frequencyValue = Serial.read();
    if(frequencyValue == 100){
      for(int i=0; i<=5; i++){
        digitalWrite(LED_BUILTIN,HIGH);
        delay(1000);
        digitalWrite(LED_BUILTIN,LOW);
        delay(1000);
      }

    }
    int phaseValue = Serial.read();
    //Serial.println(amplitudeValue);
    if(phaseValue == 180){
      for(int i=0; i<=2; i++){
        digitalWrite(LED_BUILTIN,HIGH);
        delay(1000);
        digitalWrite(LED_BUILTIN,LOW);
        delay(1000);
      }

    }
    
    
  }

}
