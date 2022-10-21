import controlP5.*; // import controlP5

ControlP5 cp5; // create ControlP5 object
RadioButton r;

void setup() {
  size(800, 500); // window size (width, height)
  
  cp5 = new ControlP5(this);
  // CheckBox = multiple choice
  // RadioButton = single choice
  // Radio has been deprecated, should not be used anymore
  r = cp5.addRadioButton("radio",10,90);
  r.addItem("Sine", 1);
  r.addItem("Square", 2);
  r.addItem("Triangle", 3);
  
  for(Toggle t:r.getItems()) {
       t.getCaptionLabel().getStyle().moveMargin(-7,0,0,-3);
       t.getCaptionLabel().getStyle().movePadding(7,0,0,3);
       t.getCaptionLabel().getStyle().backgroundWidth = 45;
       t.getCaptionLabel().getStyle().backgroundHeight = 13;
  };
  
  
  cp5.addTextfield("input")
     .setPosition(150,70)
     .setSize(100,20)
     .setFont(createFont("arial",15))
     .setFocus(true)
     .setColor(color(0,0,0))
     ;
  
};

void draw() { //similar to Arduino loop()
  background(220,220,220); // background color of window
  
  text("Waveform Type", 0, 50); //  
  text("Amplitude", 150 , 50);
};


void keyPressed() {
  switch(key) {
    case('0'): r.deactivateAll(); break;
    case('1'): r.activate(0); break;
    case('2'): r.activate(1); break;
    case('3'): r.activate(2); break;
  }
};

void controlEvent(ControlEvent theEvent) {
  if(theEvent.isFrom(r)) {
    print("got an event from "+theEvent.getName()+"\t");
    for(int i=0;i<theEvent.getGroup().getArrayValue().length;i++) {
      print(int(theEvent.getGroup().getArrayValue()[i]));
    }
    println("\t "+theEvent.getValue());
  }
};

void radioButton(int a) {
  println("a radio Button event: "+a);
  println(a);
};


public void input(String theText) {
  // automatically receives results from controller input
  println("a textfield event for controller 'input' : "+theText);
}
