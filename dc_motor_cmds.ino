int dir2_left=2;
int dir1_left=3;
int dir1_right=4;
int dir2_right=5;
int speedPinLeft = 10;
int speedPinRight = 11;
int mSpeed = 255;  // max speed

void setup() {
  // put your setup code here, to run once:
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

void loop() {
  // put your main code here, to run repeatedly:

void Happy{
  servoLArm.write(90)
  servoRArm.write(90)
  servoLEye.write(45)
  int posArm = 90;
  for (
}

}

}


//function for another file, testing here
void sweep2ServosForward(Servo servo1, int starter1, int ender1, Servo servo2, int starter2, int ender2){
  for (int angle1 = starter1, angle2 = starter2; angle1 <= ender1 || angle2 <= ender2; angle1 += 5, angle2 += 5){
    if (angle1<=ender1)
    servo1.write(angle1);
    if (angle2<=ender2)
    servo2.write(angle2);
    delay(15);
  }
}

//for 4 servos together
void sweep4ServosForward(Servo servo1, int starter1, int ender1, Servo servo2, int starter2, int ender2, Servo servo3, int starter3, int ender3, Servo servo4, int starter4, int ender4)
{
  for (int angle1 = starter1, angle2 = starter2, angle3 = starter3, angle4 = starter4; angle1 <= ender1 || angle2 <= ender2 || angle3 <= ender3 || angle4 <= ender4; angle1 += 5, angle2 += 5, angle3 += 5 , angle4 += 5)
  {
    if (angle1 <= ender1)
      servo1.write(angle1);
    if (angle2 <= ender2)
      servo2.write(angle2);
    if (angle3 <= ender3)
      servo2.write(angle3);
    if (angle4 <= ender4)
      servo2.write(angle4);
    delay(15);
  }
}





