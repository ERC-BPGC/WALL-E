#include <Servo.h>
int dir2_left=2;
int dir1_left=7;
int dir1_right=4;
int dir2_right=8;
int speedPinLeft = 13;
int speedPinRight = 12;
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
  pinMode(speedPinLeft, OUTPUT);
  pinMode(dir1_right, OUTPUT);
  pinMode(dir2_right, OUTPUT);
  pinMode(speedPinRight, OUTPUT);

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
  analogWrite(speedPinLeft, mSpeed);
  digitalWrite(dir1_right, LOW);
  digitalWrite(dir2_right, LOW);
  analogWrite(speedPinRight, mSpeed);
}

void forward()
{
  digitalWrite(dir1_left, LOW);
  digitalWrite(dir2_left, HIGH);
  analogWrite(speedPinLeft, mSpeed);
  digitalWrite(dir1_right, LOW);
  digitalWrite(dir2_right, HIGH);
  analogWrite(speedPinRight, mSpeed);
}

void right()
{
  digitalWrite(dir1_left, HIGH);
  digitalWrite(dir2_left, LOW);
  analogWrite(speedPinLeft, mSpeed);
  digitalWrite(dir1_right, LOW);
  digitalWrite(dir2_right, HIGH);
  analogWrite(speedPinRight, mSpeed);
}

void left()
{
  digitalWrite(dir1_left, LOW);
  digitalWrite(dir2_left, HIGH);
  analogWrite(speedPinLeft, mSpeed);
  digitalWrite(dir1_right, HIGH);
  digitalWrite(dir2_right, LOW);
  analogWrite(speedPinRight, mSpeed);
}

void backward()
{
  digitalWrite(dir1_left, HIGH);
  digitalWrite(dir2_left, LOW);
  analogWrite(speedPinLeft, mSpeed);
  digitalWrite(dir1_right, HIGH);
  digitalWrite(dir2_right, LOW);
  analogWrite(speedPinRight, mSpeed);
}
void servoNeckTopRight(){
  posNeckTop = posNeckTop+5;
  ServoNeckTopA.write(posNeckTop);
}
void servoNeckTopLeft(){ 
  posNeckTop = posNeckTop-5;
  ServoNeckTopA.write(posNeckTop);
}
void servoNeckMiddleUp(){
  posNeckMiddle = posNeckMiddle+5;
  ServoNeckMiddle.write(posNeckMiddle);
}
void servoNeckMiddleDown(){
  posNeckMiddle = posNeckMiddle-5;
  ServoNeckMiddle.write(posNeckMiddle);
}
void servoNeckBottomUp(){
  posNeckBottom = posNeckBottom+5;
  ServoNeckBottom.write(posNeckBottom);
}
void servoNeckBottomDown(){
  posNeckBottom = posNeckBottom-5;
  ServoNeckBottom.write(posNeckBottom);
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


void loop() {
}
