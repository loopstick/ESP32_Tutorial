// Example code for ART 385
//  RGB LED connected to pins 12, 27, 33
// output values adjusted by eye 
// to get equal brightness on each color

 #include <analogWrite.h>
 
// the numbers of the LED pins
const int RedLED = 12;  
const int GreenLED = 27;  
const int BlueLED = 33;  

int delaytime = 400;
 
void setup(){
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(BlueLED, OUTPUT);
}
 
void loop(){

    analogWrite(RedLED, 255);
    delay(delaytime);
    analogWrite(RedLED, 0);
    delay(delaytime/4);

    analogWrite(GreenLED, 35);
    delay(delaytime);
    analogWrite(GreenLED, 0);
    delay(delaytime/4);

    analogWrite(BlueLED, 60);
    delay(delaytime);
    analogWrite(BlueLED, 0);
    delay(delaytime/4);

}
