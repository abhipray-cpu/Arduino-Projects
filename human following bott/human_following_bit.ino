// human following robot
/*
we will be using a servo motor
to maintain the ultrasound sensor
and ir sensor position and the motor will be rotated as per
the input from these sensors
*/

#include<Servo.h>
#include<NewPing.h>
#include<AFMotor.h>

AF_DCMotor Motor1(1,MOTOR12_1KHZ);
AF_DCMotor Motor2(2,MOTOR12_1KHZ);
AF_DCMotor Motor3(3,MOTOR34_1KHZ);
AF_DCMotor Motor4(4,MOTOR34_1KHZ);
#define RIGHT A5
#define LEFT A3
#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 100
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

Servo myServo;
void setup()
{
  Serial.begin(9600);
  pinMode(RIGHT,INPUT);
  pinMode(LEFT,INPUT);
  myServo.attach(10);
 myServo.write(90);
 for(int pos=90;pos<=180;pos++)
  {
    myServo.write(pos);
    delay(10);
    }
    for(int pos=180;pos>=90;pos--)
  {
    myServo.write(pos);
    delay(10);
    }
    for(int pos=90;pos>=0;pos--)
  {
    myServo.write(pos);
    delay(10);
    }
 for(int pos=0;pos<=90;pos++)
  {
    myServo.write(pos);
    delay(10);
    }
    
    
}
void loop()
{

   unsigned int distance = sonar.ping_cm();
   int left_val = digitalRead(LEFT);
   int right_val= digitalRead(RIGHT);
   Serial.print("RIGHT:");
   Serial.println(right_val);
   Serial.print("LEFT");
   Serial.println(left_val);
   

 if(left_val == 1 && right_val ==1) //both left and right IR sensors are active in this case we will check for the conditions
 {
  if(distance > 0  && distance < 5)
  {
    Serial.println("BACKWARD");
    backward();
    delay(500);
    }
    else if(distance > 5 && distance < 20)
    {
      Serial.println("FORWARD");
      forward();
      delay(500);
      }
      else
      {
        brake();
        delay(1000);
        }
  }
  else if(left_val ==0 && right_val == 1) //left is active and right is inactive
{
  Serial.println("Left");
  right();
 
  delay(500);
}
else if(left_val ==1 && right_val == 0) //left is inactive and right is active
{
  Serial.println("Right");
  left();
  delay(500);
 
  }
  else
  {
   brake();
        delay(1000);
    }
  
}

void forward()  //forward
{
  Motor1.setSpeed(150);
  Motor1.run(FORWARD);
  Motor2.setSpeed(150);
  Motor2.run(FORWARD);
  Motor3.setSpeed(150);
  Motor3.run(FORWARD);
  Motor4.setSpeed(150);
  Motor4.run(FORWARD);
  }
void backward()//backward
{
   Motor1.setSpeed(150);
  Motor1.run(BACKWARD);
  Motor2.setSpeed(150);
  Motor2.run(BACKWARD);
  Motor3.setSpeed(150);
  Motor3.run(BACKWARD);
  Motor4.setSpeed(150);
  Motor4.run(BACKWARD);
  }
void left() //left
  {Motor1.setSpeed(200);
   Motor1.run(BACKWARD);
  Motor2.setSpeed(200);
  Motor2.run(BACKWARD);
  Motor3.setSpeed(200);
  Motor3.run(FORWARD);
  Motor4.setSpeed(200);
  Motor4.run(FORWARD);
  }
void right() //right
{
  Motor1.setSpeed(200);
  Motor1.run(FORWARD);
  Motor2.setSpeed(200);
  Motor2.run(FORWARD);
  Motor3.setSpeed(200);
  Motor3.run(BACKWARD);
  Motor4.setSpeed(200);
  Motor4.run(BACKWARD);
    }
void brake() //stop the car
{
    Motor1.setSpeed(0);
  Motor1.run(RELEASE);
  Motor2.setSpeed(0);
  Motor2.run(RELEASE);
  Motor3.setSpeed(0);
  Motor3.run(RELEASE);
  Motor4.setSpeed(0);
  Motor4.run(RELEASE);
    }
   
