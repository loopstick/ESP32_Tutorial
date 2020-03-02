/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/

// A0 has the pushbutton attached to it. Give it a name:
int pushButton = A0;
// assign variables to LED pins 
int ledExternal = 12;
int ledInternal = 13;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
   // initialize the LED pin as outputs.
  pinMode(ledExternal, OUTPUT);
  pinMode(ledInternal, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);
  delay(1);        // delay in between reads for stability

   if(buttonState == HIGH){
    digitalWrite(ledExternal, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledInternal, LOW);    // turn the LED off by making the voltage LOW 
  } else {
      digitalWrite(ledExternal, LOW);    // turn the LED off by making the voltage LOW
      digitalWrite(ledInternal, HIGH);   // turn the LED on by making the voltage HIGH
  }
}
