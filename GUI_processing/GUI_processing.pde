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
  String portName = Serial.list()[1];
  println(portName);
  port = new Serial(this,portName,9600);

  cp5 = new ControlP5(this);
  
  // -------WAVEFORM TYPES : SINE, SQUARE, TRIANGLE  -------//
  r = cp5.addRadioButton("radio",20,70)
  .setSpacingRow(15)
  //.setColorActive(color(100,11,100))

  .addItem("Sine", 1)
  .addItem("Square", 2)
  .addItem("Triangle", 3);
  ; //x,y
   
  
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
    error = 0;
    println("got an event from Generate Button: \n");
    try{
     float amp = Float.parseFloat(amplitude.getText());
     int ph = Integer.valueOf(phase.getText());
     int freq = Integer.valueOf(phase.getText());
     if ( amp < 2.5 || amp > 5 || freq < 100 ||freq > 10000 || ph > 180) {
       error = 2;
    } else {
     if(r.getValue()==1.0){
      println("The radio button value is sine");
      //port.write('s');
    } else if(r.getValue()==2.0){
      println("The radio button value is square");
      //port.write('q');
    }else if(r.getValue()==3.0){
      println("The radio button value is square");
      //port.write('t');
    }
     println("Amplitude value is : "+amplitude.getText());
     //port.write(amp);

     println("Frequency value is : "+frequency.getText());
     String f = frequency.getText();
     port.write(f.length());
     for(int i=0; i< f.length();i++){
        char c = f.charAt(i);
        //port.write(c);
     }
     println("Phase value is : "+phase.getText());
     //port.write(ph);
  }
    } catch (Exception e){
      error = 1;
    }
  }
  }


void drawError(String s) {
  float xoffset = 120;
  pushStyle();
 ;  // fade the whole string by amt
  for (int i = 0; i < s.length(); i++) {
    char c = s.charAt(i);
    textSize(12);
    fill(#cc0000);
    text(c, xoffset, 160);
    xoffset += textWidth(c);
  }
  popStyle();
}
