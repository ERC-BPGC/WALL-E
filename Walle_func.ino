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
int posLArm = 90;

Servo ServoNeckTopA;
Servo ServoNeckMiddle;
Servo ServoNeckBottom;
Servo ServoLArm;
Servo ServoRArm;
Servo ServoLEye;
Servo ServoREye;


Servo myservo;  
void setup() {
  myservo.attach(9);  
  myservo.attach(10);
  myservo.attach(11));
  myservo.attach(A0);
  myservo.attach(3);
  myservo.attach(5);
  myservo.attach(6);

  pinMode(dir1_left, OUTPUT);
  pinMode(dir2_left, OUTPUT);
  pinMode(speedPinLeft, OUTPUT);
  pinMode(dir1_right, OUTPUT);
  pinMode(dir2_right, OUTPUT);
  pinMode(speedPinRight, OUTPUT);


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
void servoNeckTopRight{
  posNeckTop = posNeckTop+5;
  pinServoNeckTopA.write(posNeckTop);
}
void servoNeckTopLeft{ 
  posNeckTop = posNeckTop-5;
  pinServoNeckTopA.write(posNeckTop);
}
void servoNeckMiddleUp{
  posNeckMiddle = posNeckMiddle+5;
  pinServoNeckMiddle.write(posNeckMiddle);
}
void servoNeckMiddleDown{
  posNeckMiddle = posNeckMiddle-5;
  pinServoNeckMiddle.write(posNeckMiddle);
}
void servoNeckBottomUp{
  posNeckBottom = posNeckBottom+5;
  pinServoNeckBottom.write(posNeckBottom);
}
void servoNeckBottomDown{
  posNeckBottom = posNeckBottom-5;
  pinServoNeckBottom.write(posNeckBottom);
}

void motion1{
  sweep4ServosBackward(ServoLArm, 90, 0, ServoRArm, 90, 0, ServoLEye, 90, 0, ServoREye, 90, 0);
  sweep4ServosForward(ServoLArm, 0, 90, ServoRArm, 0, 90, ServoLEye, 0, 45, ServoREye, 0, 45);
}

void motion2{
  sweep4ServosForward(ServoLArm, 0, 120, ServoRArm, 0, 120, ServoLEye, 0, 100, ServoREye, 0, 100);
  sweep4ServosBackward(ServoLArm, 120, 45, ServoRArm, 120, 45, ServoLEye, 100, 30, ServoREye, 100, 30);
}


void loop() {
  myservo.writeMicroseconds(1500);  
  delay(1000); 
}
