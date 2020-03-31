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


int delaytime = 500;
 
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

    delaytime = map(POTval, 0, 4095, 30, 1000);
  
    analogWrite(RedLED, 255);
    delay(delaytime);
    analogWrite(RedLED, 0);
    delay(delaytime);

    analogWrite(GreenLED, 35);
    delay(delaytime);
    analogWrite(GreenLED, 0);
    delay(delaytime);

    analogWrite(BlueLED, 40);
    delay(delaytime);
    analogWrite(BlueLED, 0);
    delay(delaytime);

}
