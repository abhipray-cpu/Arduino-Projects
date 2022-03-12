// 4 axis robot arm
#include<Servo.h>
#define clk1 49
#define dt1 47
#define clk2 45
#define dt2 43
#define clk3 41
#define dt3 39
#define clk4 37
#define dt4 35
//encoder1
int counter1=0;
int currStateclk1=1;
int lastStateclk1=1;
String currDir1="";
//encoder2
int counter2=0;
int currStateclk2=1;
int lastStateclk2=1;
String currDir2="";
//encoder3
int counter3=0;
int currStateclk3=1;
int lastStateclk3=1;
String currDir3="";
//encoder4
int counter4=0;
int currStateclk4=1;
int lastStateclk4=1;
String currDir4="";


Servo myServo1;
Servo myServo2;
Servo myServo3;
Servo myServo4;
Servo myServo5;

void setup()
{
  Serial.begin(9600);
  //attach motors to respective pins
lastStateclk1=digitalRead(clk1);
lastStateclk2=digitalRead(clk2);
lastStateclk3=digitalRead(clk3);
lastStateclk4=digitalRead(clk4);
  }
  

void loop()
{
  encoder1();
  delay(10);
  encoder2();
  delay(10);
  encoder3();
  delay(10);
  encoder4();
  delay(10);

}
void encoder1()
{
currStateclk1=digitalRead(clk1);
if(currStateclk1 != lastStateclk1 && currStateclk1 == 1)
 {
  if(digitalRead(dt1) != currStateclk1 )
  {
    counter1--;
    currDir1="Anti clockwise";
    }
    else
    {
      counter1++;
      currDir1="Clockwise";
      }
  Serial.println("Direction of encoder1:");
  Serial.print(currDir1);
  Serial.println("Value of counter1:");
  Serial.print(counter1);
  myServo1.write(counter1);
  } 
  }
void encoder2()
{
  currStateclk2=digitalRead(clk2);
if(currStateclk2 != lastStateclk2 && currStateclk2 == 1)
 {
  if(digitalRead(dt2) != currStateclk2 )
  {
    counter2--;
    currDir2="Anti clockwise";
    }
    else
    {
      counter2++;
      currDir2="Clockwise";
      }
  Serial.println("Direction of encoder2:");
  Serial.print(currDir2);
  Serial.println("Value of counter2:");
  Serial.print(counter2);
  myServo2.write(counter2);
  myServo3.write(counter3);
  } 
  }
void encoder3()
{
  currStateclk3=digitalRead(clk3);
if(currStateclk3 != lastStateclk3 && currStateclk3 == 1)
 {
  if(digitalRead(dt3) != currStateclk3 )
  {
    counter3--;
    currDir3="Anti clockwise";
    }
    else
    {
      counter3++;
      currDir3="Clockwise";
      }
  Serial.println("Direction of encoder3:");
  Serial.print(currDir3);
  Serial.println("Value of counter3:");
  Serial.print(counter3);
  myServo4.write(counter3);
  } 
  }
void encoder4()
{
  currStateclk4=digitalRead(clk4);
if(currStateclk4 != lastStateclk4 && currStateclk4 == 1)
 {
  if(digitalRead(dt4) != currStateclk4 )
  {
    counter4--;
    currDir4="Anti clockwise";
    }
    else
    {
      counter4++;
      currDir4="Clockwise";
      }
  Serial.println("Direction of encoder4:");
  Serial.print(currDir4);
  Serial.println("Value of counter4:");
  Serial.print(counter4);
  myServo5.write(counter4);
  } 
  }
