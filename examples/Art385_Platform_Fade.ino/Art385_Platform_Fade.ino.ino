// Example code for ART 385
//  RGB LED connected to pins 12, 27, 33

 #include <analogWrite.h>
 
// the numbers of the LED pins
const int RedLED = 12;  
const int GreenLED = 27;  
const int BlueLED = 33;  

const int LDR = A0;  
const int POT = A1;  

int LDRval = 0;
int POTval= 0;

int delaytime = 5;
 
void setup(){
  Serial.begin(9600);

  pinMode(POT, INPUT);
  pinMode(LDR, INPUT);
    
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(BlueLED, OUTPUT);
}
 
void loop(){

    LDRval = analogRead(LDR);
    Serial.print("LDRval: ");
    Serial.print(LDRval);
    
    POTval = analogRead(POT);   
    Serial.print("\t POTval: ");
    Serial.println(POTval);

    delaytime = map(POTval, 0, 4095, 5, 100);

    
// RED FADE UP+++++++++++++++++++++++++++++++++++++++++++++++++++++
  // increase the RED LED brightness
  for(int brightness = 0; brightness <= 255; brightness++){   
    // changing the LED brightness with PWM
    analogWrite(RedLED, brightness);
    delay(delaytime);
  }
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// PURPLE

// BLUE FADE DOWN +++++++++++++++++++++++++++++++++++++++++++++++++
  // decrease the BLUE LED brightness
  for(int brightness = 127; brightness >= 0; brightness--){
    // changing the LED brightness with PWM
    analogWrite(BlueLED, brightness);   
    delay(delaytime);
  }
 // +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// RED
 
// GREEN FADE UP+++++++++++++++++++++++++++++++++++++++++++++++++++++
  // increase the GREEN LED brightness
  for(int brightness = 0; brightness <= 127; brightness++){   
    // changing the LED brightness with PWM
    analogWrite(GreenLED, brightness);
    delay(delaytime);
  }
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// YELLOW

// RED FADE DOWN +++++++++++++++++++++++++++++++++++++++++++++++++
  // decrease the LED brightness
  for(int brightness = 255; brightness >= 0; brightness--){
    // changing the LED brightness with PWM
    analogWrite(RedLED, brightness);   
    delay(delaytime);
  }
 // +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//GREEN

 // BLUE FADE UP+++++++++++++++++++++++++++++++++++++++++++++++++++++
  // increase the BLUE LED brightness
  for(int brightness = 0; brightness <= 127; brightness++){   
    // changing the LED brightness with PWM
    analogWrite(BlueLED, brightness);
    delay(delaytime);
  }
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// AQUA

// GREEN FADE DOWN +++++++++++++++++++++++++++++++++++++++++++++++++
  // decrease the LED brightness
  for(int brightness = 127; brightness >= 0; brightness--){
    // changing the LED brightness with PWM
    analogWrite(GreenLED, brightness);   
    delay(delaytime);
  }
 // +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//BLUE
 



}
