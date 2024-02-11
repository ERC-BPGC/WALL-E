//Freee Pins = 12,13
#include <Servo.h>
int dir2_left=2;
int dir1_left=7;
int dir1_right=4;
int dir2_right=8;

int mSpeed = 255;  // max speed
#define pinServoNeckTopA A0;
int pinServoNeckMiddle = 5;
int pinServoNeckBottom = 6;
int pinServoLArm = 9;
int pinServoRArm = 10;
int pinServoLEye = 11;
int pinServoREye = 3;
int posNeckTop = 90;
int posNeckMiddle = 90;
int posNeckBottom = 90;
int posLArm = 90;

Servo ServoNeckTopA;
Servo ServoNeckMiddle;
Servo ServoNeckBottom;
Servo ServoLArm;
Servo ServoRArm;
Servo ServoLEye;
Servo ServoREye;


 
void setup() {
  ServoLArm.attach(pinServoLArm);  
  ServoRArm.attach(pinServoRArm);
  ServoLEye.attach(pinServoLEye);
  ServoNeckTopA.attach(A0);
  ServoREye.attach(pinServoREye);
  ServoNeckMiddle.attach(pinServoNeckMiddle);
  ServoNeckBottom.attach(pinServoNeckBottom);

  pinMode(dir1_left, OUTPUT);
  pinMode(dir2_left, OUTPUT);
  
  pinMode(dir1_right, OUTPUT);
  pinMode(dir2_right, OUTPUT);
  

  ServoNeckTopA.writeMicroseconds(1500); 
  ServoNeckMiddle.writeMicroseconds(1500); 
  ServoNeckBottom.writeMicroseconds(1500); 
  ServoLArm.writeMicroseconds(1500); 
  ServoRArm.writeMicroseconds(1500); 
  ServoLEye.writeMicroseconds(1500); 
  ServoREye.writeMicroseconds(1500);
  delay(1000); 

  Serial.begin(9600);

}

void stop()
{
  digitalWrite(dir1_left, LOW);
  digitalWrite(dir2_left, LOW);
  
  digitalWrite(dir1_right, LOW);
  digitalWrite(dir2_right, LOW);
  
}

void forward()
{
  digitalWrite(dir1_left, LOW);
  digitalWrite(dir2_left, HIGH);
  
  digitalWrite(dir1_right, LOW);
  digitalWrite(dir2_right, HIGH);
  
}

void right()
{
  digitalWrite(dir1_left, HIGH);
  digitalWrite(dir2_left, LOW);
  
  digitalWrite(dir1_right, LOW);
  digitalWrite(dir2_right, HIGH);
  
}

void left()
{
  digitalWrite(dir1_left, LOW);
  digitalWrite(dir2_left, HIGH);
  
  digitalWrite(dir1_right, HIGH);
  digitalWrite(dir2_right, LOW);
  
}

void backward()
{
  digitalWrite(dir1_left, HIGH);
  digitalWrite(dir2_left, LOW);
  
  digitalWrite(dir1_right, HIGH);
  digitalWrite(dir2_right, LOW);
  
}
void servoNeckTopRight(){
  while(posNeckTop<160){
  posNeckTop = posNeckTop+5;
  ServoNeckTopA.write(posNeckTop);
  }
}
void servoNeckTopLeft(){ 
  while(posNeckTop>30){
  posNeckTop = posNeckTop-5;
  ServoNeckTopA.write(posNeckTop);
  }
}
void servoNeckMiddleUp(){
  while(posNeckMiddle<160){
  posNeckMiddle = posNeckMiddle+5;
  ServoNeckMiddle.write(posNeckMiddle);
  }
}
void servoNeckMiddleDown(){
  while(posNeckMiddle>10){
  posNeckMiddle = posNeckMiddle-5;
  ServoNeckMiddle.write(posNeckMiddle);
  }
}
void servoNeckBottomUp(){
  while(posNeckBottom<100){
  posNeckBottom = posNeckBottom+5;
  ServoNeckBottom.write(posNeckBottom);
  }
}
void servoNeckBottomDown(){
  while(posNeckBottom>10){
  posNeckBottom = posNeckBottom-5;
  ServoNeckBottom.write(posNeckBottom);
  }
}

void sweep4ServosBackward(Servo servo1, int starter1, int ender1, Servo servo2, int starter2, int ender2, Servo servo3, int starter3, int ender3, Servo servo4, int starter4, int ender4)
{
  for (int angle1 = starter1, angle2 = starter2, angle3 = starter3, angle4 = starter4; angle1 >= ender1 || angle2 >= ender2 || angle3 >= ender3 || angle4 >= ender4; angle1 -= 5, angle2 -= 5, angle3 -= 5 , angle4 -= 5)
  {
    if (angle1 >= ender1)
      servo1.write(angle1);
    if (angle2 >= ender2)
      servo2.write(angle2);
    if (angle3 >= ender3)
      servo3.write(angle3);
    if (angle4 >= ender4)
      servo4.write(angle4);
    delay(15);
  }
}

void sweep4ServosForward(Servo servo1, int starter1, int ender1, Servo servo2, int starter2, int ender2, Servo servo3, int starter3, int ender3, Servo servo4, int starter4, int ender4)
{
  for (int angle1 = starter1, angle2 = starter2, angle3 = starter3, angle4 = starter4; angle1 <= ender1 || angle2 <= ender2 || angle3 <= ender3 || angle4 <= ender4; angle1 += 5, angle2 += 5, angle3 += 5 , angle4 += 5)
  {
    if (angle1 <= ender1)
      servo1.write(angle1);
    if (angle2 <= ender2)
      servo2.write(angle2);
    if (angle3 <= ender3)
      servo3.write(angle3);
    if (angle4 <= ender4)
      servo4.write(angle4);
    delay(15);
  }
}

void motion1(){
  sweep4ServosBackward(ServoLArm, 90, 0, ServoRArm, 90, 0, ServoLEye, 90, 0, ServoREye, 90, 0);
  sweep4ServosForward(ServoLArm, 0, 90, ServoRArm, 0, 90, ServoLEye, 0, 45, ServoREye, 0, 45);
}

void motion2(){
  sweep4ServosForward(ServoLArm, 0, 120, ServoRArm, 0, 120, ServoLEye, 0, 100, ServoREye, 0, 100);
  sweep4ServosBackward(ServoLArm, 120, 45, ServoRArm, 120, 45, ServoLEye, 100, 30, ServoREye, 100, 30);
}

void motion3(){
  
  sweep4ServosForward(ServoLEye, 0, 90, ServoREye, 0, 90, ServoNeckMiddle, 0, 45, ServoNeckBottom, 0, 45);
  sweep4ServosBackward(ServoLEye, 90, 0, ServoREye, 90, 0, ServoNeckMiddle, 45, 0, ServoNeckBottom, 45, 0);

}

void motion4(){
  sweep4ServosForward(ServoLEye, 0, 45, ServoREye, 0, 45, ServoLArm, 0, 120, ServoRArm, 0, 120);
  sweep4ServosBackward(ServoLEye, 45, 0, ServoREye, 45, 0, ServoLArm, 120, 0, ServoRArm, 120, 0);
}

/*void motion5(){
  sweep4ServosForward(ServoLArm, 0, 60, ServoRArm, 0, 30, ServoLEye 0, 60, ServoREye, 0, 60);
  sweep4ServosBackward(ServoLArm, 60, 0, ServoRArm, 30, 0, ServoLEye 60, 0, ServoREye, 60, 0);
}*/


void loop() {
  String data1;
  char data2;
  if (Serial.available() > 0) {
    data1 = Serial.readStringUntil('\n');
    data2 = data1[0];
  }
  switch (data2) {
    case 'A':
           forward();
           break;
    case 'B':
           backward();
           break;
    case 'C':
           right();
           break;
    case 'D':
           left();
           break;
    case 'E':
           stop();
           break;
    case 'F':
           servoNeckTopRight();
           break;
    case 'G':
           servoNeckTopLeft();
           break;
    case 'H':
           servoNeckMiddleUp();
           break;
    case 'I':
           servoNeckMiddleDown();
           break;
    case 'J':
           servoNeckBottomUp();
           break;
    case 'K':
           servoNeckBottomDown();
           break;
    case 'L':
           servoNeckBottomUp();
           break;
    case 'M':
           motion1();
           break;
    case 'N':
           motion2();
           break;
    case 'O':
           motion3();
           break;
    case 'P':
           motion4();
           break;
    /*case 'Q':
           motion5();
           break;*/

  }

}
