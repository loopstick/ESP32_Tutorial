/*
  Hello World
  A "Hello, World!" program generally is a computer program that 
  outputs or displays the message "Hello, World!". 
  Such a program is very simple in most programming languages, 
  and is often used to illustrate the basic syntax of a programming language. 
  It is often the first program written by people learning to code
*/

// Pin 13 has the red LED connected on the ESP32

// give it a name:
int led = 13;

void setup() {
  //initialize serial communication at a 9600 baud rate
  Serial.begin(9600);
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);  
}

void loop(){
  //send 'Hello, world!' over the serial port
  Serial.println("Hello, world!");
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
