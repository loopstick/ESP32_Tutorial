/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
 */

// Pin 13 has the red LED connected on the ESP32

// give it a name:
int ledExternal = 12;
int ledInternal = 13;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(ledExternal, OUTPUT);
  pinMode(ledInternal, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(ledExternal, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(ledExternal, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second

  digitalWrite(ledInternal, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(ledInternal, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
