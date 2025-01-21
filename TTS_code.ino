
const int  bir = 3; // The values in this and the next two lines indicate which pins you have connected the buttons to.
const int iki = 4;
const int uc = 5;  
const int A = 2; // indicates the pin servo motor attached to. 

int U = 0; // servo motor's initial position in degrees. 
int B = 90; 

#include<Servo.h>
Servo THS; 

void setup()  {
  pinMode(bir, INPUT);
  pinMode(iki, INPUT);
  pinMode(uc, INPUT); 
  THS.attach(A);
}
void loop() {
  if (digitalRead(bir) == HIGH) {
    THS.write(B); 
    delay(300); // The values ​​in the parentheses of the delay functions indicate the contact time of the stimulus.
   //For example, in this code, the first, second, and third buttons provide contact for 300, 500, and 1000 ms, respectively.
    THS.write(U);  
  }
  if (digitalRead(iki) == HIGH) {
    THS.write(B);
    delay(500); 
    THS.write(U);  
  }
    if (digitalRead(uc) == HIGH) {
    THS.write (B);
    delay (1000); 
    THS.write(U);  }
}