/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

int ledExternal = 12;
int ledInternal = 13;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the LED pin as outputs.
  pinMode(ledExternal, OUTPUT);
  pinMode(ledInternal, OUTPUT);

}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability

  if(sensorValue>=2000){
    digitalWrite(ledExternal, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledInternal, LOW);    // turn the LED off by making the voltage LOW 
  } else {
      digitalWrite(ledExternal, LOW);    // turn the LED off by making the voltage LOW
      digitalWrite(ledInternal, HIGH);   // turn the LED on by making the voltage HIGH
  }
}
