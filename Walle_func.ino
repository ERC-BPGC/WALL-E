//Aadit is the dumbest person that wall e has ever met
#include <Servo.h>
int dir2_left=2;
int dir1_left=7;
int dir1_right=4;
int dir2_right=8;
int speedPinLeft = 13;
int speedPinRight = 12;
int mSpeed = 255;  // max speed
int pinServoNeckTopA = A0;
int pinServoNeckMiddle = 5;
int pinServoNeckBottom = 6;
int pinServoLArm = 9;
int pinServoRArm = 10;
int pinServoLEye = 11;
int pinServoREye = 3;
int posNeckTop = 90;
int posNeckMiddle = 90;
int posLArm = 90;



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
void ServoArmSad{
  pinServoLArm.write(90);
  pinServoRArm.write(90);
  while(1){
  posLArm = posLArm-5;
  pinServoLArm.write(posLArm);
  posRArm = posRArm-5;
  pinServoRArm.write(posRArm);
  delay(15);
  if(posLArm<=0||posRArm<=0)
  break;
  }
}
void ServoEyeSad{
  pinServoLEye.write(90);
  pinServoREyewrite(90);
  while(1){
  posLEye = posLEye-2;
  pinServoLEye.write(posLEye);
  posREye = posREye-2;
  pinServoREye.write(posREye);
  delay(15);
  if(posLEye<=0||posREye<=0)
  break;
  }
}

void ServoArmHappy{
  int cnt=0;
  pinServoRArm.write(0);
  pinServoLArm.write(0);
  int posArm = 0;
  if(posArm==0){
  for(1;posArm<=180;posArm+=5){
  pinServoRArm.write(posArm);
  pinServoLArm.write(posArm);
  delay(15);
  }
  }
  if(posArm==180&&cnt<=3){
  for(1;posArm>=0;posArm-=5){
  pinServoRArm.write(posArm);
  pinServoLArm.write(posArm);
  delay(15);
  }
  cnt++;
  }
}

void ServoEyeHappy{
  int cnt=0;
  pinServoLEye.write(0);
  pinServoREye.write(0);
  int posEye = 0;
  if(posEye==0){
  for(1;posEye<=180;posEye+=5){
  pinServoREye.write(posEye);
  pinServoLEye.write(posEye);
  delay(15);
  }
  }
  if(posEye==180&&cnt<=3){
  for(1;posEye>=0;posEye-=5){
  pinServoREye.write(posArm);
  pinServoLEye.write(posArm);
  delay(15);
  }
  cnt++;
  }
}



void loop() {
  myservo.writeMicroseconds(1500);  
  delay(1000); 
}
