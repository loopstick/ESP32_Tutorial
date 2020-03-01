# ArduinoTutorial

### Arduino Hands-on Introduction Workshop

This workshop created by:
Michael Shiloh and Judy Castro for *Teach Me To Make*

Revised by Sudhu Tewari 2020

##### Arduino Examples - coming soon!

The workshop will focus on getting you up and running with Arduino quickly, so that you will understand the basic procedures for working with Arduino and can explore further on your own.

We will cover how to install Arduino on your laptop; how to understand, modify, and write Arduino programs; how to connect sensors to Arduino and read them from a program; and how to connect actuators (LEDs, motors, speakers) and control them from a program. Other topics will be covered as interest dictates and time permits.

#### Additional Resources
Lady Ada's [Learn Arduino](https://learn.adafruit.com/ladyadas-learn-arduino-lesson-number-0?view=all) lessons are great. The [tour](https://learn.adafruit.com/ladyadas-learn-arduino-lesson-number-0?view=all#take-a-tour) of Arduino architecture is particularly useful for understanding Arduino.

#### Before the Workshop
Arduino software (IDE) runs on Windows, Mac OSX, and Linux. Please download the (free) Arduino software prior to the workshop from http://arduino.cc/en/Main/Software, and install as much as you can.  
Instructions at http://arduino.cc/en/Guide/HomePage  
Please bring your laptop with the software installed to the workshop.

An Arduino kit will be provided for use during the workshop or you may bring your own.

What is Arduino anyway?
	Read about Arduino: https://www.arduino.cc/en/Guide/Introduction

If you have questions prior to or after the workshop please contact Sudhu: loopstick@hotmail.com

#### At the Workshop
 - Please interrupt any time with questions.

### First steps: Verifying correct installation
All of this is in the Arduino Getting Started guide for your operating system. [https://www.arduino.cc/en/Guide/HomePage](https://www.arduino.cc/en/Guide/HomePage).

1. Connect Arduino via USB cable
   - Windows? Might see “New Hardware Discovered” and later might see “New Hardware Ready for Use”.
   - Mac OS X? Might see “New Network Interface Found”. Click “Network Preferences…”,  click “Apply”, and when it finishes, click “Close”. It doesn’t matter if the configuration fails.
   - Linux? Nothing to do here

2. Open Arduino software (IDE)

3. Select _Tools -> Board_
   - You have an Uno.

4. Select _Tools -> Serial Port_
   - Windows? Chose the largest COM number
     - No COMs? Raise your hand for help or visit [troubleshooting](http://arduino.cc/en/Guide/Troubleshooting)
   - Mac OS X? Chose either usbmodem
     - No usbmodem? Raise your hand for help or visit [troubleshooting](http://arduino.cc/en/Guide/Troubleshooting)
   - Linux? There is only one choice

5. Open _File->Examples->Basics->Blink_
   - Click “Upload”
   - Look for errors in the bottom window of the program
     - Errors? Raise your hand for help or visit [troubleshooting](http://arduino.cc/en/Guide/Troubleshooting)
   - Look for the amber LED on your Arduino to be blinking
     - No blinking? Raise your hand for help or visit [troubleshooting](http://arduino.cc/en/Guide/Troubleshooting)


### Is this thing on?
Copy the code below into a new Arduino sketch or download and open the example sketch: [HelloWorld.ino](https://github.com/loopstick/ArduinoTutorial/blob/master/examples/HelloWorld/HelloWorld/HelloWorld.ino)


```cpp
/*
  Hello World
  A "Hello, World!" program generally is a computer program that
	outputs or displays the message "Hello, World!".
	Such a program is very simple in most programming languages,
	and is often used to illustrate the basic syntax of a programming language.
	It is often the first program written by people learning to code
*/

void setup() {
//initialize serial communications at 9600 baud rate
Serial.begin(9600);
}

void loop(){
//send 'Hello, world!' over the serial port
Serial.println("Hello, world!");
//wait 100 milliseconds so we don't drive ourselves crazy
delay(1000);
}
```
The _Serial_ commands allow Arduino to send a message to your laptop. In order to see this message you need to open the _Serial Monitor_ by clicking on the magnifying glass near the top right corner.

a little code anatomy:
The [setup()](https://www.arduino.cc/reference/en/language/structure/sketch/setup/) function is called when a sketch starts. Use it to initialize variables, pin modes, start using libraries, etc. The setup() function will only run once, after each powerup or reset of the Arduino board.

The [loop()](https://www.arduino.cc/reference/en/language/structure/sketch/loop/) After creating a setup() function, which initializes and sets the initial values, the loop() function does precisely what its name suggests, and _loops_ consecutively through your list of instructions to control the Arduino.


More on the specific functions and variables soon! Let's make something happen in the real world first.

### How to use Arduino to turn something ON and OFF
How does the program (sketch) do this? (all described in the [Blink tutorial](http://arduino.cc/en/Tutorial/Blink))
```cpp
/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
```
some more code anatomy - info about an Arduino [Sketch](https://www.arduino.cc/en/tutorial/sketch)


#### Using a solderless Breadboard to connect Arduino to other things (LEDs, motors, speakers, sensors, etc.)

The Solderless Breadboard (SparkFun [tutorial:](https://learn.sparkfun.com/tutorials/how-to-use-a-breadboard))

![Breadboard](/images/Breadboard_st.jpg)

![Breadboard underside](/images/BreadboardUnderside_st.jpg)

[Breadboard connections](http://wiring.org.co/learning/tutorials/breadboard/)


Use it to add an external LED. LEDs must always be used with resistors so they don’t burn out. The resistor value can be anywhere from 220 ohm to 1k ohm. The lower the resistance, the brighter the light:

Here’s a picture showing how to connect the LED and resistor on the breadboard:

![LED_Resistor Pic](/images/LED_Breadboard2.jpg)

Here is another view of this circuit:

![Fritzing: LED resistor pic](/images/2-Blink-an-LED_SMALL.jpg)

And here is a schematic of this circuit:

![Fritzing: LED resistor schematic](/images/Arduino_LED_Resistor_schem.jpg)

Use the Blink sketch: _File -> Examples -> Basics -> Blink_
	Does your LED blink?
		(think about why)

### Exercise 1:
Move LED to a different pin (e.g. pin 8).
	See if you can figure out how to do this on your own

Now the LED won’t blink until you change the program, since the program is only turning pin 13 on and off. Change the program to control pin 8.

### Exercise 2:
If you changed the program to control only pin 8, then the built-in LED on pin 13 is no longer blinking. Can you change the program to make them both blink?

Are we limited to LEDs? No; we could replace the LED (and its resistor) with any other suitable device, with some considerations. We’ll learn more about this later.

#### How to use a sensor: analogRead()
So far we’ve only used Arduino as an output device, to control something in the physical world (the LED). The other way of interfacing to the physical world is as an input device, using a sensor to get information about the physical world. We’ll start with a photoresistor, also called a light dependent resistor or LDR. It’s a resistor whose resistance depends on the light: the more light, the lower the resistance. (The resistor we used above with the LED is a fixed resistor.)
The LDR indicates the amount of light by changing its resistance, but Arduino can not measure resistance. But, Arduino can measure voltage! Fortunately, we can easily convert a varying resistance to a varying voltage using a fixed resistor to create a [voltage divider](https://learn.sparkfun.com/tutorials/voltage-dividers/all). This time the fixed resistor needs a larger resistance, so select a 10k ohm resistor and build the circuit below. You don’t need to remove the LED circuit as there should be room on your breadboard for both, and we’ll use the LED again later.

![CircuitExample](/images/Arduino_LDR_VoltageDiv.jpg)

Open and upload this sketch:
_File->Examples->Basics->AnalogReadSerial_

How do you know if anything is working? Arduino might be reading the sensor, but is it telling you anything? 

Arduino is connected to your computer, so they can communicate - just like we did earlier with Hello World, but now your Ardunio is sending sensor DATA!
 - this line:	```cpp Serial.println(sensorValue);``` allows Arduino to send a message to your laptop. 
In order to see this message you need to open the _Serial Monitor_ by clicking on the magnifying glass near the top right corner. Read the Arduino [AnalogRead tutorial](http://arduino.cc/en/Tutorial/AnalogReadSerial) to find out more. Also see _File->Examples->Communication_ for more examples of other types of Serial communication).

Now that we've got sensor data coming in (as a range of values) what can we do with the data?

We could do some math to calculate the voltage we're measuring:
_File->Examples->Basics->AnalogReadVoltage_

What other kinds of sensors are there?
- [Sensor workshop at ITP](https://itp.nyu.edu/physcomp/lessons/sensors-the-basics/),

That's nice, but what if we want to use the sensor data to control some kind of physical reaction (light, heat, motion) to the data?

Let's shift our focus, for a moment, to outputting a range of voltages. Then we'll put the input and output together to get real world input to control real world output. 



#### analogWrite(): Controlling speed or brightness
If digitalWrite() can turn an LED on and off, and analogRead() can read a range of values, what would you guess analogWrite() might do?

Move the LED to pin 9:

Now upload this sketch:
_File -> Examples -> Basics -> Fade_

What’s the LED doing? Can you figure out how the sketch is doing this?
```cpp
analogWrite(led, brightness);
and then
brightness = brightness + fadeAmount;
How does it know to start fading down when it reaches the maximum value?
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
```

Why did I ask you to move the LED to pin 9?
	It turns out analogWrite() only works on certain pins which are capable of [PWM](https://www.arduino.cc/en/tutorial/PWM) output: 3, 5, 6, 9, 10, and 11.
	see the[Arduino Uno Board Pins reference](https://www.arduino.cc/en/Reference/Board)for more info


#### Sensor ranges, calibration, and mapping


We lit up an LED using _analogWrite()_ based on sensor data _analogRead()_!

What else can _analogWrite()_ do?
	_analogWrite()_ also works well to control the speed of a motor. However now we need to consider whether our motor is compatible with Arduino’s outputs.


#### Arduino outputs: Voltage and current
- When used as outputs, two things must be considered: the voltage and the current. Our Arduino can deliver 5 v, and at most 40 mA.
- The voltage is determined by Arduino, but the current is determined by whatever we’re trying to control. In the case of the LEDs, they only need 20 mA or less. The motor we have might take more than 40 mA. In the worst case, when it’s stalled, it might want a 200 mA.
- The important thing to realize is that Arduino does not have the ability to limit this current. It will try to deliver whatever is asked of it, even if it overheats and damages itself.
- If we want to control a device that might take more than 40 mA, we have to use an intermediary.

#### Controlling large loads with a transistor
The transistor is like a bicycle gear: you control it with a small amount of current, and it in turn can control a lot more current. The transistor also allows us to use a higher voltage than the 5V Arduino can deliver.

Use a transistor to control a higher current for a motor.
 - There are hundreds of transisors that will work for this application. 
   - here are a few that I commonly use:
	- [TIP120](https://cdn-shop.adafruit.com/datasheets/TIP120.pdf) - Darlington sold by Adafruit
	- [IRF520](https://www.vishay.com/docs/91017/91017.pdf)
	- [IRF8721](https://cdn-shop.adafruit.com/datasheets/irlb8721pbf.pdf) - MOSFET sold by Adafruit
  - never assume the pinout of a transistor or IC.
    - ALWAYS look up the pinout before applying power.
      - or else 爆炸
      

![CircuitExample](/images/MotorTransistor_AA.jpg)


You can test this with either
	_File -> Examples -> Basics -> Blink_
	
or

	_File -> Examples -> Basics -> Fade_

It's important to note that we are now using a separate power source for the motor. There are good reasons for doing so...

![CircuitExample](/images/Transistor_Motor.jpg)
	
##### References:
- [Arduino Transistor Motor Control](https://www.arduino.cc/en/Tutorial/TransistorMotorControl)
- [Using a Transistor to Control Hight Current Loads](http://itp.nyu.edu/physcomp/labs/motors-and-transistors/using-a-transistor-to-control-high-current-loads-with-an-arduino/)



#### More to explore
- digitalRead()
- What is a switch?
- _Arduino->File->Examples->Basics->DigitalReadSerial_
- [Digital Read Serial](http://arduino.cc/en/Tutorial/DigitalReadSerial) tutorial
- Making sounds: [Melody](https://itp.nyu.edu/physcomp/labs/labs-arduino-digital-and-analog/tone-output-using-an-arduino/) tutorial
- Joining inputs and outputs: switch controls speed, switch choses between two brightness levels, thermistor or other sensor changes behavior, etc.
- Multiple output devices: play melody while controlling motor speed, etc.
- The problem with, and a solution to, delay(): 
- [BlinkWithoutDelay(http://arduino.cc/en/Tutorial/BlinkWithoutDelay) tutorial
- Boolean logic, tests, and conditionals


#### Resources!!!
- [Dr Sudhu's resources page](https://github.com/loopstick/ResourcesForClasses)






