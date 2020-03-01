/*
  Hello World
  A "Hello, World!" program generally is a computer program that 
  outputs or displays the message "Hello, World!". 
  Such a program is very simple in most programming languages, 
  and is often used to illustrate the basic syntax of a programming language. 
  It is often the first program written by people learning to code
*/


void setup() {
//initialize serial communication at a 9600 baud rate
Serial.begin(9600);
}

void loop(){
//send 'Hello, world!' over the serial port
Serial.println("Hello, world!");
//wait 100 milliseconds 
delay(1000);
// before sending the message again
// so we don't drive ourselves crazy 
}
