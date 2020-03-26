/*
 * PWM example code - March 2020
 */
 
 
 #include <analogWrite.h>

 // the number of the LED pin
const int ledPin = 12;  // 12 corresponds to GPIO16

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
 
void loop(){
  // increase the LED brightness
  for(int brightness = 0; brightness <= 255; brightness++){   
    // changing the LED brightness with PWM
    analogWrite(ledPin, brightness);
    Serial.println(brightness);
    delay(15);
  }

 
  // decrease the LED brightness
  for(int brightness = 255; brightness >= 0; brightness--){
    // changing the LED brightness with PWM
    analogWrite(ledPin, brightness);   
    Serial.println(brightness);
    delay(15);
  }

}
