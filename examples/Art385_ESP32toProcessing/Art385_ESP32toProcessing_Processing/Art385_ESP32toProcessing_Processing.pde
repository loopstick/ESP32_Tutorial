 // Processing code for this example

  // This example code is in the public domain.

  import processing.serial.*;

  float redValue = 0;        // red value
  float greenValue = 0;      // green value
  float blueValue = 0;       // blue value

  Serial myPort;

  void setup() {
    size(400, 400);

    // List all the available serial ports
    // if using Processing 2.1 or later, use Serial.printArray()
    printArray(Serial.list());
    //if using Processing 2.1 or earlier, use println(Serial.list()
    //println(Serial.list());

    // Using the printed list of available Serial ports
    // find the port that your ESP32 is connected to
    // open that port - mine was [5] - see below
    myPort = new Serial(this, Serial.list()[5], 9600);
    // don't generate a serialEvent() unless you get a newline character:
    myPort.bufferUntil('\n');
  }

  void draw() {
    // set the background color with the color values:
    background(redValue, greenValue, blueValue);
  }

  void serialEvent(Serial myPort) {
    // get the ASCII string:
    String inString = myPort.readStringUntil('\n');

    if (inString != null) {
      // trim off any whitespace:
      inString = trim(inString);
      // split the string on the commas and convert the resulting substrings
      // into an integer array:
      float[] colors = float(split(inString, ","));
      // if the array has at least three elements, you know you got the whole
      // thing.  Put the numbers in the color variables:
      if (colors.length >= 3) {
        redValue = colors[0];
        greenValue = colors[1];
        blueValue = colors[2];
        
        /*
        // re-mapping not necessary since it already done on the ESP32 side
        // map them to the range 0-255:
        redValue = map(colors[0], 0, 4095, 0, 255);
        greenValue = map(colors[1], 0, 4095, 0, 255);
        blueValue = map(colors[2], 0, 4095, 255, 0);
        */
      }
    }
  }
