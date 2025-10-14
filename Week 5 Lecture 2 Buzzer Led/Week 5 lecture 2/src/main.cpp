// PWM LED Brightness Fade With Buzzer
//Week 5 Lecture 2
//M.ADEEL ZIA         23-NTU-CS-1057
#include<Arduino.h>

#define LED1  5
#define LED2  18
#define buzzer  27
#define channel1  0
#define channel2  2
#define channel3  8
#define frequency1  5000
#define frequency2 10000
#define frequency3  2000


#define resulotion  8



void setup() {
  ledcSetup(channel1, frequency1, resulotion);
  ledcAttachPin(LED1, channel1);

  ledcSetup(channel2, frequency2, resulotion);
  ledcAttachPin(LED2, channel2);

  ledcSetup(channel3, frequency3, resulotion);
  ledcAttachPin(buzzer, channel3);
}

void loop() {
  for(int i = 0; i < 255; i++){
    ledcWrite(channel1, i);
    ledcWrite(channel3, i);
    delay(10);
  }

  for(int d = 0; d<255;d+=50){
    ledcWrite(channel2, d);
    delay(15);
  }

  for(int i = 255; i >0; i-=50){
    ledcWrite(channel2, i);
    delay(15);
  }

  for(int i = 255; i >0; i--){
    ledcWrite(channel1, i);
    ledcWrite(channel3, i);
    delay(10);
  }
}