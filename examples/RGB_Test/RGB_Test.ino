// Example code for ART 385
//  RGB LED connected to pins 12, 27, 33

 #include <analogWrite.h>
 
// the numbers of the LED pins
const int RedLED = 12;  
const int GreenLED = 27;  
const int BlueLED = 33;  

int delaytime = 500;
 
void setup(){
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(BlueLED, OUTPUT);
}
 
void loop(){

    analogWrite(RedLED, 127);
    delay(delaytime);
    analogWrite(RedLED, 0);
    delay(delaytime);

    analogWrite(GreenLED, 127);
    delay(delaytime);
    analogWrite(GreenLED, 0);
    delay(delaytime);

    analogWrite(BlueLED, 127);
    delay(delaytime);
    analogWrite(BlueLED, 0);
    delay(delaytime);

}
