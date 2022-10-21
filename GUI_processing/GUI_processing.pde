import controlP5.*; // import controlP5
import processing.serial.*;

Serial port;
ControlP5 cp5; // create ControlP5 object
RadioButton r;

void setup() {
  textSize(18);
  fill(0, 0, 0);

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
  Textfield amplitude = cp5.addTextfield("Amplitude")
     .setPosition(200,70)
     .setSize(100,20)
     .setFocus(true)
     .setFont(createFont("arial", 15))
     .setColorValue(0x00)         
     .setColorBackground(color(255,255,255))  
     ;
   
   amplitude.getCaptionLabel().setVisible(false); // to not show label

   // ------------------FREQUENCY RANGE----------------------//
  Textfield frequency = cp5.addTextfield("Frequency")
     .setPosition(380,70)
     .setSize(100,20)
     .setFocus(true)
     .setFont(createFont("arial", 15))
     .setColorValue(0x00)         
     .setColorBackground(color(255,255,255))   
     ;
     
   frequency.getCaptionLabel().setVisible(false); // to not show label
   
    // ------------------PHASE ----------------------//
  Textfield phase = cp5.addTextfield("Phase")
     .setPosition(560,70)
     .setSize(100,20)
     .setFocus(true)
     .setFont(createFont("arial", 15))
     .setColorValue(0x00)         
     .setColorBackground(color(255,255,255))  
     ;
     
   phase.getCaptionLabel().setVisible(false); // to not show label
    
    
   // GENERATE WAVEFORM BUTTON

  cp5.addButton("GENERATE")
     .setValue(0)
     .setPosition(650,140)
     .setSize(100,40)
     ;

};

void draw() { //similar to Arduino loop()
  background(220,220,220); // background color of window
  
  text("Waveform Type", 20, 50); //  
  text("Amplitude (V)", 200 , 50);
  text("Frequency (Hz)", 380, 50);
  text("Phase (degrees)", 560, 50);

};


//void keyPressed() {
//  switch(key) {
//    case('0'): r.deactivateAll(); break;
//    case('1'): r.activate(0); break;
//    case('2'): r.activate(1); break;
//    case('3'): r.activate(2); break;
//  }
//};

void controlEvent(ControlEvent theEvent) {
  if(theEvent.isFrom(r)) {
    print("got an event from "+theEvent.getName()+"\t");
    for(int i=0;i<theEvent.getGroup().getArrayValue().length;i++) {
      print(int(theEvent.getGroup().getArrayValue()[i]));
    }
    println("\t "+theEvent.getValue());
    if(theEvent.getValue()==1.0){
      port.write('s');
    } else if(theEvent.getValue()==2.0){
      port.write('q');
    }else if(theEvent.getValue()==3.0){
      port.write('t');
    }

  }
};

void radioButton(int a) {
  println("a radio Button event: "+a);
  println(a);
};


//public void input(String theText) {
//  // automatically receives results from controller input
//  println("a textfield event for controller 'input' : "+theText);
//}
