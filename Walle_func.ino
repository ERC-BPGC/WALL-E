//Freee Pins = 12,13
#include <Servo.h>
int dir2_left=2;
int dir1_left=7;
int dir1_right=4;
int dir2_right=8;

char data2 = 'Z';

int mSpeed = 255;  // max speed

int pinServoNeckMiddle = 5;
int pinServoNeckBottom = 6;
int pinServoLArm = 9;
int pinServoRArm = 10;
int pinServoLEye = 11;
int pinServoREye = 3;
int posNeckTop = 90;
int posNeckMiddle = 60;
int posNeckBottom = 90;
int posLArm = 90;
int posRArm = 90;
int posLEye = 180;
int posREye = 0;

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
  

  ServoNeckTopA.write(90); 
  ServoNeckMiddle.write(90); 
  ServoNeckBottom.write(90); 
  ServoLArm.write(90); 
  ServoRArm.write(90); 
  ServoLEye.write(165); 
  ServoREye.write(15);
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

void backward()
{
  digitalWrite(dir1_left, LOW);
  digitalWrite(dir2_left, HIGH);
  
  digitalWrite(dir1_right, LOW);
  digitalWrite(dir2_right, HIGH);
  
}

void left()
{
  digitalWrite(dir1_left, HIGH);
  digitalWrite(dir2_left, LOW);
  
  digitalWrite(dir1_right, LOW);
  digitalWrite(dir2_right, HIGH);
  
}

void right()
{
  digitalWrite(dir1_left, LOW);
  digitalWrite(dir2_left, HIGH);
  
  digitalWrite(dir1_right, HIGH);
  digitalWrite(dir2_right, LOW);
  
}

void forward()
{
  digitalWrite(dir1_left, HIGH);
  digitalWrite(dir2_left, LOW);
  
  digitalWrite(dir1_right, HIGH);
  digitalWrite(dir2_right, LOW);
  
}
void servoNeckTopRight(){
  while(posNeckTop<160){
  posNeckTop = posNeckTop+1;
  ServoNeckTopA.write(posNeckTop);
  delay(100);
  }
}
void servoNeckTopLeft(){ 
  while(posNeckTop>30){
  posNeckTop = posNeckTop-1;
  ServoNeckTopA.write(posNeckTop);
  delay(100);
  }
}
void servoNeckMiddleUp(){
  while(posNeckMiddle<160){
  posNeckMiddle = posNeckMiddle+1;
  ServoNeckMiddle.write(posNeckMiddle);
  delay(25);
  }
}
void servoNeckMiddleDown(){
  while(posNeckMiddle>10){
  posNeckMiddle = posNeckMiddle-1;
  ServoNeckMiddle.write(posNeckMiddle);
  delay(25);
  }
}
void servoNeckBottomUp(){
  while(posNeckBottom<110){
  posNeckBottom = posNeckBottom+5;
  ServoNeckBottom.write(posNeckBottom);
  delay(100);
  }
}
void servoNeckBottomDown(){
  while(posNeckBottom>60){
  posNeckBottom = posNeckBottom-5;
  ServoNeckBottom.write(posNeckBottom);
  delay(100);
  }
}
void LArmDown(){
  while(posLArm > 0){
    posLArm = posLArm-5;
    ServoLArm.write(posLArm);
    delay(10);
  }
}
void LArmUp(){
  while(posLArm < 100){
    posLArm = posLArm+5;
    ServoLArm.write(posLArm);
    delay(10);
  }
}
void RArmDown(){
  while(posRArm < 180){
    posRArm = posRArm+5;
    ServoRArm.write(posRArm);
    delay(10);
  }
}
void RArmUp(){
  while(posRArm > 75){
    posRArm = posRArm-5;
    ServoRArm.write(posRArm);
    delay(10);
  }
}
void centre(){
  ServoNeckTopA.write(90); 
  delay(10);
  ServoNeckMiddle.write(90); 
  delay(10);
  ServoNeckBottom.write(90); 
  delay(10);
  ServoLArm.write(100); 
  delay(10);
  ServoRArm.write(100); 
  delay(10);
  ServoLEye.write(165); 
  delay(10);
  ServoREye.write(15);
  delay(10);
}
/*
void LEyeUp(){
  while(posLEye < 180){
    posLEye = posLEye+1;
    ServoLEye.write(posLEye);
    delay(10);
  }
}
void LEyeDown(){
  while(posLEye > 150){
    posLEye = posLEye-1;
    ServoLEye.write(posLEye);
    delay(10);
  }
}
void REyeUp(){
  while(posREye < 30){
    posREye = posREye+1;
    ServoREye.write(posREye);
    delay(10);
  }
}
void REyeDown(){
  while(posREye > 0){
    posREye = posREye-1;
    ServoREye.write(posREye);
    delay(10);
  }
}
*/



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

// angle constraints for LEye: 180 to 150, REye = 0 to 30
//angle constraints for LArm: 180(top) to 75(down)
//angle constraint for RArm: 0(top) to 105(down)
void motion1(){
  sweep4ServosBackward(ServoLArm, 100, 0, ServoRArm, 180, 80, ServoLEye, 180, 150, ServoREye, 30, 0);
  sweep4ServosForward(ServoLArm, 0, 100, ServoRArm, 80, 180, ServoLEye, 150, 180, ServoREye, 0, 30);
}

void motion2(){
  sweep4ServosForward(ServoLArm, 0, 75, ServoRArm, 130, 180, ServoLEye, 170, 180, ServoREye, 0, 15);
  sweep4ServosBackward(ServoLArm, 75, 0, ServoRArm, 180, 130, ServoLEye, 180, 170, ServoREye, 15, 0);
}

void motion3(){
  
  sweep4ServosForward(ServoLEye, 150, 180, ServoREye, 0, 30, ServoNeckMiddle, 75, 160, ServoNeckBottom, 90, 20);
  sweep4ServosBackward(ServoLEye, 180, 150, ServoREye, 30, 0, ServoNeckMiddle, 160, 75, ServoNeckBottom, 20, 90);

}

void motion4(){
  sweep4ServosForward(ServoLEye, 150, 180, ServoREye, 0, 30, ServoLArm, 0, 69, ServoRArm, 110, 180);
  sweep4ServosBackward(ServoLEye, 180, 150, ServoREye, 30, 0, ServoLArm, 69, 0, ServoRArm, 180, 110);
}

void motion5(){
  sweep4ServosForward(ServoLArm, 35, 100, ServoRArm, 135, 180, ServoLEye, 180, 165, ServoREye, 0, 15);
  sweep4ServosBackward(ServoLArm, 100, 35, ServoRArm, 180, 135, ServoLEye, 165, 180, ServoREye, 15, 0);
}


void loop() {
  String data1;
  // char data2 = 'Z';  dont remove this comment 
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
           motion1();
           break;
    case 'M':
           motion2();
           break;
    case 'N':
           motion3();
           break;
    case 'O':
           motion4();
           break;
    case 'P':
           motion5();
           break;
    case 'Q':
          LArmDown();
          break;
    case 'R':
          LArmUp();
          break;
    case 'S':
          RArmDown();
          break;
    case 'T':
          RArmUp();
          break;
          
   /* case 'U':
          REyeUp();
          break;
    case 'V':
          REyeDown();
          break;
    case 'W':
          LEyeUp();
          break;
    case 'X':
          REyeDown();
          break;  */
    case 'Y':
          centre();
          break;


  }

}
