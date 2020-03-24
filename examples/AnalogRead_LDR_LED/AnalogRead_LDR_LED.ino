/*
 * PWM example code - March 2020
 * 2 LEDs - internal and external
 * Analog Read - LDR on A0
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

int brightness = 0;
int LDRmin = 2000;
int LDRmax = 3000;
 
void setup(){
  Serial.begin(9600);
  
  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledExternal, ledChannel);
  ledcAttachPin(ledInternal, ledChannel2);

  // initialize the input pin as input
  pinMode(A0, INPUT);
}
 
void loop(){
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability

  sensorValue = constrain(sensorValue, LDRmin, LDRmax);
  
  brightness = map(sensorValue, LDRmin, LDRmax, 0, 255);

    // changing the LED brightness with PWM
    ledcWrite(ledChannel, brightness);   
    ledcWrite(ledChannel2, 255-brightness);
    delay(5);

}
