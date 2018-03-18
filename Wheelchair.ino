#include <MyoController.h>
#include<Servo.h>

#define DOUBLETAP_PIN 6
Servo servo1; Servo servo2;
int cons = 0;

MyoController myo = MyoController();

void setup() {
  pinMode(DOUBLETAP_PIN, OUTPUT);
  servo1.attach(5);
  servo2.attach(9);
  Serial.begin(9600);
  myo.initMyo();
  servo1.write(20);
   servo2.write(20);
   delay(50);
   servo1.write(40);
   servo2.write(40);
   delay(50);
   servo1.write(20);
   servo2.write(20);
   delay(50);
   
}

void loop()
{
   myo.updatePose();
   switch ( myo.getCurrentPose() ) {
    case rest:
      if(cons == 0){
        servo1.write(20);
        servo2.write(20);
        }
      else{
          servo1.write(20);
          servo2.write(20);
          delay(50);
          servo1.write(140);
          servo2.write(140);
          }  
      break;
    case fist:
          servo1.write(140);
          servo2.write(140);
          delay(50);
          servo1.write(20);
          servo2.write(20);
          cons = 0;
      break;
    case waveIn:
          servo1.write(20);
          servo2.write(20);
          delay(50);
          servo1.write(140);
          servo2.write(20);
      break;
    case waveOut:
  servo1.write(0);
          servo1.write(20);
          servo2.write(20);
          delay(50);
          servo1.write(20);
          servo2.write(140);
      break;
    case fingersSpread:
          servo1.write(20);
          servo2.write(20);
          delay(50);
          servo1.write(140);
          servo2.write(140);
          cons = 1;
      break;
    case doubleTap:
      digitalWrite(DOUBLETAP_PIN,HIGH);
      delay(1000);
      digitalWrite(DOUBLETAP_PIN, LOW);
      break;
   } 
   delay(100);
}
