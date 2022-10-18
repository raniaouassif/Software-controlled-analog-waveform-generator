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
}

void draw() { //similar to Arduino loop()
  background(220,220,220); // background color of window
  
  text("Waveform Type", 0, 50); //  
}
