/*
 * PWM example code - March 2020
 * 2 LEDs - internal and external
 * Analog Read - LDR on A0
 */

#include <analogWrite.h>

// the number of the LED pin
const int ledExternal = 12;  
const int ledInternal = 13;  

int brightness = 0;
int LDRmin = 1000;
int LDRmax = 2800;
 
void setup(){
  // start Serial communication at 9600 baud
  Serial.begin(9600);
  // initialize the input pin as input
  pinMode(A0, INPUT);
}
 
void loop(){
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.print("sensorValue: ");
  Serial.print(sensorValue);
  // delay in between reads for stability
  delay(1);        

  sensorValue = constrain(sensorValue, LDRmin, LDRmax); 
  brightness = map(sensorValue, LDRmin, LDRmax, 0, 255);
    Serial.print("\t brightness: ");
    Serial.println(brightness);

    // change external LED brightness with value read from LDR
    analogWrite(ledExternal, brightness);
    // do the oppposite at the internal LED 
    analogWrite(ledInternal, 255-brightness);
    delay(5);

}
