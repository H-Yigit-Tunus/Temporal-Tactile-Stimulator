# Temporal-Tactile-Stimulator (TTS)
TTS is a device initially developed as a class project to provide tactile stimulation to various parts of the body for a desired duration.


While there are many tools such as Psychopy and E-prime that allow researchers to present visual and auditory stimulation at precise durations, there is no such optionality for tactile stimuli, as very little number of the ones exist require components that are quite unreachable (e.g, pneumatic cylinders for Tactile Stimulation Device (TSD) developed by Dresel et al., (2008). In this context, I present the TTS, which is low cost, easy to use, and requires highly accessible units to build.

TTS provides tactile stimulation with a silicon material attached to its tip for a desired duration (as short as 100 ms). While it can be used to provide stimulation for long durations, such as seconds or minutes, its core scientific functionality operates within durations under a second. The rationale under this claim comes from several studies from Eagleman and others that have suggested that for periods of time below one second, duration judgment is mostly determined by the magnitude of the neural activity evoked. Therefore, using TTS, one can study sub-second duration judgment by manipulating the size of the stimulus, the contact time, or by considering the differences in sensory nerve density in body parts. For example, the study that led to the construction of TTS was investigating duration judgment by providing 300, 500, and 700 ms of tactile stimulation to the individual's palm and wrist, based on the differences in size of the regions where these regions represented in the somatosensory cortex and sensory nerve densities.
![Image](https://github.com/user-attachments/assets/18e3907a-fef4-45d3-95fe-d0cbfbaab86f)

Note. This is the first version of TTS that was utilized in the original experiment. However, working on this open-acces version, I’ve realized that I could develop a simpler and more universal version of TTS. So don't get confused when the device you build is different with the version in the figure. Additional details are discussed in the following sections. 

 ## Building TTS

Testing code upload

```cpp
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
```
## ABC
abcd

### SS
asasa
