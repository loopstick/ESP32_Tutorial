// Example code for ART 385
//  RGB LED connected to pins 12, 27, 33

// the numbers of the LED pins
const int RedLED = 12;  
const int GreenLED = 27;  
const int BlueLED = 33;  

// setting PWM properties
// variable PWM frequency (5000 is plenty for LEDs)
const int freq = 5000;
// 16 PWM channels available (0-15)
const int RedChannel = 0;
const int GreenChannel = 1;
const int BlueChannel = 2;
// 8 bits = 0-255
const int resolution = 8;
 
void setup(){
  // configure LED PWM functionalitites
  ledcSetup(RedChannel, freq, resolution);
  ledcSetup(GreenChannel, freq, resolution);
  ledcSetup(BlueChannel, freq, resolution);
  
  // attach the channels to the GPIO to be controlled
  ledcAttachPin(RedLED, RedChannel);
  ledcAttachPin(GreenLED, GreenChannel);
  ledcAttachPin(BlueLED, BlueChannel);
}
 
void loop(){
// RED FADE UP+++++++++++++++++++++++++++++++++++++++++++++++++++++
  // increase the RED LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(RedChannel, dutyCycle);
    delay(15);
  }
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// RED FADE DOWN +++++++++++++++++++++++++++++++++++++++++++++++++
  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(RedChannel, dutyCycle);   
    delay(15);
  }
 // +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 // GREEN FADE UP+++++++++++++++++++++++++++++++++++++++++++++++++++++
  // increase the GREEN LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(GreenChannel, dutyCycle);
    delay(15);
  }
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// GREEN FADE DOWN +++++++++++++++++++++++++++++++++++++++++++++++++
  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(GreenChannel, dutyCycle);   
    delay(15);
  }
 // +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 
 // BLUE FADE UP+++++++++++++++++++++++++++++++++++++++++++++++++++++
  // increase the BLUE LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(BlueChannel, dutyCycle);
    delay(15);
  }
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// BLUE FADE DOWN +++++++++++++++++++++++++++++++++++++++++++++++++
  // decrease the BLUE LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(BlueChannel, dutyCycle);   
    delay(15);
  }
 // +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

}
