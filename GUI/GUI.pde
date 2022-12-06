import controlP5.*; // import controlP5
import processing.serial.*;

Serial port;
ControlP5 cp5; // create ControlP5 object
RadioButton r;
Textfield amplitude;
Textfield frequency;
Textfield phase; 
Button generate;
String error1;
String error2;
Integer error;


void setup() {
  textSize(18);
  fill(0, 0, 0);
  error = 0;  
  error1 = "Error: All the parameters must be filled in";
  error2 = "Error: Ranges must be Amplitude : 2.5 - 5 V, Frequency : 100 Hz - 10Khz, Phase : 0 - 180 degrees.";

  size(800, 200); // window size (width, height)
  printArray(Serial.list());
  
  // Adjust index depending on port connected to Arduino
  String portName = Serial.list()[2];
  println(portName);
  port = new Serial(this,portName,9600);
  cp5 = new ControlP5(this);
  
  
  // -------WAVEFORM TYPES : SINE, SQUARE, TRIANGLE  -------//
  r = cp5.addRadioButton("radio",20,70)
  .setSpacingRow(15)
  .setSize(20,20)
  .addItem("Sine", 1)
  .addItem("Square", 2)
  .addItem("Triangle", 3);
  ; 
  r.getItem(0).getCaptionLabel().setVisible(false);
  r.getItem(1).getCaptionLabel().setVisible(false);
  r.getItem(2).getCaptionLabel().setVisible(false);
  
  // ------------------AMPLITUDE ----------------------//
  amplitude = cp5.addTextfield("Amplitude")
     .setPosition(200,70)
     .setSize(100,20)
     .setFont(createFont("arial", 13))
     .setColorValue(0x00)         
     .setColorBackground(color(255,255,255))  
     .setColorCursor(0)
     .setAutoClear(false) //disable enter key 
     .setInputFilter(ControlP5.FLOAT)

     ;
   
   amplitude.getCaptionLabel().setVisible(false); // to not show label

   // ------------------FREQUENCY RANGE----------------------//
   frequency = cp5.addTextfield("Frequency")
     .setPosition(380,70)
     .setSize(100,20)
     .setFont(createFont("arial", 13))
     .setColorValue(0x00)         
     .setColorBackground(color(255,255,255))  
     .setColorCursor(0)
     .setAutoClear(false)
     .setInputFilter(ControlP5.INTEGER)
     ;
     
   frequency.getCaptionLabel().setVisible(false); // to not show label
    // ------------------PHASE ----------------------//
  phase = cp5.addTextfield("Phase")
     .setPosition(560,70)
     .setSize(100,20)
     .setFont(createFont("arial",13))
     .setColorValue(0x00)         
     .setColorBackground(color(255,255,255))  
     .setColorCursor(0)
     .setAutoClear(false) 
     .setInputFilter(ControlP5.INTEGER)
     ;
     
   phase.getCaptionLabel().setVisible(false); // to not show label
    
  // GENERATE WAVEFORM BUTTON
  generate = cp5.addButton("GENERATE")
     .setValue(0)
     .setPosition(650,140)
     .setSize(100,40)
     ;

};

void draw() { //similar to Arduino loop()
  background(220,220,220); // background color of window
  
  text("Waveform Type", 20, 50); 
  text("Amplitude (V)", 200 , 50);
  text("Frequency (Hz)", 380, 50);
  text("Phase (degrees)", 560, 50);
  
  //Radio button labels
  text("Sine", 50, 85);
  text("Square", 50, 122);
  text("Triangle", 50, 157);
  
  if(error == 0) {
    drawError("");
  }
  if(error == 1) {
    drawError(error1);  
  }
  if(error == 2) {
    drawError(error2);  
  }
};

void controlEvent(ControlEvent theEvent) {
  if(theEvent.isFrom(generate)) {
    println("number of bytes available: "+port.available());
    error = 0;
    println("got an event from Generate Button: \n");
    try{
      float ampliudeFloat = Float.parseFloat(amplitude.getText());
      int phaseInt = Integer.valueOf(phase.getText());
      int frequencyInt = Integer.valueOf(frequency.getText());
      if ( phaseInt > 180 || ampliudeFloat < 1.5 || ampliudeFloat > 5 || frequencyInt < 100 || frequencyInt > 10000) {
        error = 2;  // Out of bounds values
      } else 
      {
        
        //FREQUENCY
        println("Frequency value is : "+frequency.getText());
        String f = frequency.getText();
        println("String Frequency value is : "+f);
        port.write(f.length());
        println(f.length());
        for(int i=0; i< f.length();i++){
          int c = Character.getNumericValue(f.charAt(i));
          println(c);
          port.write(c);
        }
        //AMPLITUDE
        println("Amplitude value is : "+amplitude.getText());
        String a = amplitude.getText();
        println("Amplitude length is : "+a.length());
        println("numeric char at 0 is length is : "+Character.getNumericValue(a.charAt(0)));
        port.write(a.length());
        if(a.length() == 1) {
          port.write(Character.getNumericValue(a.charAt(0)));
        }else if (a.length() == 3) {
          port.write(Character.getNumericValue(a.charAt(0)));
          println("numeric char at 2 is length is : "+Character.getNumericValue(a.charAt(2)));

          port.write(Character.getNumericValue(a.charAt(2)));
        }
       //PHASE
       println("Phase value is : "+phase.getText());
       port.write(phaseInt);
       //WAVEFORM TYPE
       if(r.getValue()==1.0){
          println("The radio button value is sine");
          port.write(1);
       } else if(r.getValue()==2.0){
          println("The radio button value is square");
          port.write(2);
       } else if(r.getValue()==3.0){
          println("The radio button value is triangle");
          port.write(3);
       }
      }
    } catch (Exception e){
      error = 1; //Empty parameters
    }
   }
  }

void drawError(String s) {
  float xoffset = 280;
  pushStyle();
  for (int i = 0; i < s.length(); i++) {
    char c = s.charAt(i);
    textSize(12);
    fill(#cc0000);
    text(c, xoffset, 192);
    xoffset += textWidth(c);
  }
  popStyle();
}
