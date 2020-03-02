/*
 * PWM example code
 * 2 LEDs - internal and external
 */

// the number of the LED pin
const int ledExternal = 12;  
const int ledInternal = 13;  

// setting PWM properties
// variable PWM frequency (5000 is plenty for LEDs)
const int freq = 5000;
// 16 PWM channels available (0-15)
const int ledChannel = 0;
// 8 bits = 0-255
const int resolution = 8;
 
void setup(){
  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledExternal, ledChannel);
  ledcAttachPin(ledInternal, ledChannel);

}
 
void loop(){
  // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }

  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);   
    delay(15);
  }
  

}
