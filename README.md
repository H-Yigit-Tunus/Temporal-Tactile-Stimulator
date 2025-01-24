# Temporal-Tactile-Stimulator (TTS)

While there are many tools such as Psychopy and E-prime that allow researchers to present visual and auditory stimulation at precise durations, there is no such optionality for tactile stimuli, as very little number of the ones exist require components that are quite unreachable (e.g, pneumatic cylinders for Tactile Stimulation Device [1]. In this context, I present the TTS, which is low cost, easy to use, and requires highly accessible units to build. Before going into more detail, I must point out that if you think that the installation of this device requires any prior technical knowledge, you are mistaken. Even if you have no knowledge of electronics or coding (as I did before this research), you can install a fully functional device by following the simple steps explained in further sections.

TTS provides tactile stimulation with a silicon material attached to its tip for a desired duration (as short as 150 ms). While it can be used to provide stimulation for long durations, such as seconds or minutes, its core research functionality operates within durations under a second. The rationale behind this claim comes from several studies from Eagleman and others [2, 3] that have suggested that for time periods shorter than one second, duration judgment is mostly determined by the magnitude of the neural activity evoked. Therefore, using TTS, one can study sub-second duration judgment by manipulating the size of the stimulus, the contact time, or by considering the differences in sensory nerve density in body parts. For example, the study that led to the construction of TTS was investigating duration judgment by providing 300, 500, and 700 ms of tactile stimulation to the individual's palm and wrist, based on the differences in size of the regions where these body parts represented in the somatosensory cortex and sensory nerve densities, as demonstrated below.

![Image](https://github.com/user-attachments/assets/18e3907a-fef4-45d3-95fe-d0cbfbaab86f) 

Note. This is the first version of TTS that was utilized in the original experiment. However, working on this open-acces version, I’ve realized that I could develop a simpler and more universal version of TTS. So don't get confused when the device you construct is slightly different from the version in the figure. 

 ## Building TTS

As mentioned, TTS is quite easy to build since it involves assembling easily accessible and inexpensive circuit elements, which are: Arduino uno R3 (A), SG90 RC Mini Servo Motor (B), a 80 x 55 or larger breadboard (C), resistors (D), push buttons (as much as the time conditions you want to add) (E), and jumper cables. Connect the circuit elements as shown in the diagram below. The most important detail I want to draw attention to here is that all the cables connected from the buttons to the Arduino are connected to the breadboard row with code I, indicated by the red rectangle. Though as long as these cables are connected between the legs of the resistors, they would provide the same function too (for this specific setup, the row J would do the trick too, as an example). The rest of the setup is not more technical than plugging a flash drive into a USB port. Just apply gentle pressure to the pins. 

![Image](https://github.com/user-attachments/assets/2436caad-26f0-4b3a-9839-2131ef04a51c)

You can also make other setups that will provide the same function. However, assuming you get a large breadboard to add extra time conditions, you should know that some large breadboards split the power rails (parallel row used to distribute power and ground) into two, and this is usually indicated with a broken row. If this is not the case for you, you can create alternative setups that uses the whole row, such as demonstrated in the TTS_diagram.png (see files). However, If the breadboard you get is splited, only half of it will work. You can fix this problem by connecting both sides with jumper wires as demonstrated below. 
![Image](https://github.com/user-attachments/assets/4c5d4233-1480-40dd-9120-4e193bd8a44f)


To run TTS, you need to download the Arduino IDE software **[arduino.cc/en/software](https://arduino.cc/en/software)**, which is completely free. After completing the installation, plug TTS into any USB port on your computer, run the software, and follow the steps below:

1. From the top toolbar of the Arduino IDE, click Tools → Board → Arduino AVR Boards → Arduino UNO

![Image](https://github.com/user-attachments/assets/8d1a5391-57e1-4ae3-8c3f-a0a2022db4ad)

2. Click Tools → Ports. You will probably only see one port here and that is all you need to select. However, if you have more than one port option like I did, disconnect the Arduino and see which port is missing. Then reconnect the Arduino and select the port that reappeared.

![Image](https://github.com/user-attachments/assets/4069d269-e518-4033-89ed-364d3cd0c8fa)

3. Paste the code below to the software and click upload button (highlighted with red rectangle)

![Image](https://github.com/user-attachments/assets/f2188654-78ed-4d0c-8b9b-62a8504c2f82)
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
    THS.write (B);
    delay (1000); 
    THS.write(U);  }
}
```

As stated in the code, the values ​​in the delay functions correspond to the contact time. You can manipulate these values ​​according to your own study. Also, if you have provided your connections with different pins, you can change the values ​​specified in the code. Just bear in the mind that for every change to be utilized, you need to reupload the code to the Arduino again. Now youre all set software-wise!

To attach the TTS to the participants body you can use easily accessible double-sided medical tapes, dermatological adhesives such as Dermabond, or simply skin-friendly cosmetic tapes that provides the same function.

The characteristics of the contact stimulus will vary depending on the context of your study. For example, you may need a higher object to stimulate deep areas such as the palm, while for flat areas such as the arm, an object slightly higher than the servo motor would do the job, as demonstrated below. In this context, you can use silicone due to its ease of shaping and ability to be easily attached to the servo, or alternatively, you may directly use servo horns with different qualities.


With all that's discussed so far, I hope I have conveyed all the necessary information about the utilization of TTS clearly enough. If you have any technical suggestions or need help with the installation, you can send an e-mail to yigittunus@hotmail.com



References

Dresel, C., Parzinger, A., Rimpau, C., Zimmer, C., Ceballos-Baumann, A. O., & Haslinger, B. (2008). A new device for tactile stimulation during fMRI. Neuroimage, 39(3), 1094-1103.

Eagleman, D. M. (2008). Human time perception and its illusions. Current Opinion in Neurobiology, 18(2), 131-136.

Eagleman, D. M., & Pariyadath, V. (2009). Is subjective duration a signature of coding efficiency?. Philosophical Transactions of the Royal Society B: Biological Sciences, 364(1525), 1841-1851.
