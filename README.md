# Software-Controlled Analog Waveform Generator
Capstone Design Project group DP09

Team members :
  - Rania Ouassif 
  - Sansitha Panchadsaram 
  - Anandamoyi Saha

## Project description 
Build a software-controlled analog waveform generator with digitally controllable 

Waveform type: Sine, triangle, square

Amplitude: 2.5 - 5 V

Frequency: 100 Hz - 10 KHz

Phase: 0 - 180 degrees

## Design Choices 
Hardware:
- Arduino Uno R3
- AD9833 IC (breakout board)
- MCP4131 digital potentiometer
- UA741CP operational amplifier

Software:
- Arduino programming language on Arduino IDE 
- Processing language on Procesing IDE

## Running instructions
1. Download Arduino software using the link https://www.arduino.cc/en/software, and following the instructions: https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing

2. Download Processing software using the link https://processing.org/download

3. Download our Github software-controlled-analog-waveform-generator project

4. (Optional) If the Arduino board is new, open Arduino Waveform Generator folder, and open Arduino Waveform Generator.ino file

4.1. This will open up Arduino IDE, click compile first to make sure the code has no error, then upload to run the program on the board

5. To run the GUI, open GUI folder, and open GUI.pde file

5.1. This will open up Processing IDE, click on the run button on the top-left

5.2. After running, all the ports available will be listed, as shown as for example
  <img width="641" alt="Screen Shot 2022-12-05 at 7 53 34 PM" src="https://user-images.githubusercontent.com/59747858/205779219-c629ed04-0786-4e03-8112-24877d77efb9.png">
  Get the array index of the port which looks something like (in the example above it's number 2):  
  /dev/cu.usbmodemxxxxx. 

5.3. Stop the execution on the Processing IDE (button next to run)

5.4. Replace the following line of code by your port number (in the example it is 2)
<img width="531" alt="Screen Shot 2022-12-05 at 8 01 03 PM" src="https://user-images.githubusercontent.com/59747858/205779992-3a63404f-3fac-44b4-96bc-30fd77c3abd2.png">

5.5 Save the processing file (to not have to fix this anymore) 

5.6 Run the processing file 


6. Build the prototype circuit 
![315306921_535303201572557_4521541644535460577_n](https://user-images.githubusercontent.com/59747858/205777551-af24368b-e26e-4e26-9d98-7bd95d42be67.png)

7. Enter parameters in the GUI and observe the waveform
