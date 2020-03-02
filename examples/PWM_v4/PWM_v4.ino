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
const int ledChannel2 = 1;
// 8 bits = 0-255
const int resolution = 8;
 
void setup(){
  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledExternal, ledChannel);
  ledcAttachPin(ledInternal, ledChannel2);

}
 
void loop(){
  // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= 200; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);
    ledcWrite(ledChannel2, 200-dutyCycle);
    delay(5);
  }

  // decrease the LED brightness
  for(int dutyCycle = 200; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);   
    ledcWrite(ledChannel2, 200-dutyCycle);
    delay(5);
  }
  

}
