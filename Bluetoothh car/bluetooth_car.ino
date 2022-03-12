#include <AFMotor.h>

//initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ); 
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

char command; 
int speed_motor=255;

void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}

void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop(); //initialize with motors stoped
    //Change pin mode only if new command is different from previous.   
    //Serial.println(command);
    switch(command){
    case 'F':  
      forward();
      break;
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
    case 'x':  
      hand_brake('x');
      break;
    case 'X':  
       hand_brake('X');
      break;
    case 'v':  
      sound('v');
      break;
    case 'V':
      sound('V');
      break; 
      case 'w':  
      front_lights('w');
      break;
    case 'W':  
       front_lights('W');
      break;
    case 'u':  
      rear_lights('u');
      break;
    case 'U':
      rear_lights('U');
      break;
      case 'q':  
      speed_motor=255;
      break;
    case '9':  
       speed_motor=225;
      break;
    case '8':  
      speed_motor=200;
      break;
    case '7':
      speed_motor=175;
      break;
    case '6':  
      speed_motor=150;
      break;
    case '5':  
       speed_motor=125;
      break;
    case '4':  
      speed_motor=100;
      break;
    case '3':
      speed_motor=75;
      break; 
      case '2':  
      speed_motor=50;
      break;
    case '1':  
       speed_motor=25;
      break;
    case '0':  
      speed_motor=0;
      break;
    
    }
  } 
}

void forward()
{
  motor1.setSpeed(speed_motor); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(speed_motor); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(speed_motor);//Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(speed_motor);//Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
}

void back()
{
  motor1.setSpeed(speed_motor); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(speed_motor); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(speed_motor); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(speed_motor); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}

void left()
{
  motor1.setSpeed(speed_motor); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(speed_motor); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(speed_motor); //Define maximum velocity
  motor3.run(FORWARD);  //rotate the motor clockwise
  motor4.setSpeed(speed_motor); //Define maximum velocity
  motor4.run(FORWARD);  //rotate the motor clockwise
}

void right()
{
  motor1.setSpeed(speed_motor); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(speed_motor); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(speed_motor); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(speed_motor); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
} 

void Stop()
{
  motor1.setSpeed(0); //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0); //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
  motor3.setSpeed(0); //Define minimum velocity
  motor3.run(RELEASE); //stop the motor when release the button
  motor4.setSpeed(0); //Define minimum velocity
  motor4.run(RELEASE); //stop the motor when release the button
}
void sound(char code)
{
  if(code == 'V')
  {
    Serial.println("Horn is switched on");
    //pinMode(pin,HIGH);
    }
    else
    {
      Serial.println("Horn is switched off");
      //pinMode(pin,LOW);
      
      }
  }
void rear_lights(char code)
{
  if(code == 'U')
  {
    Serial.println("Rear lights are switched on");
    //pinMode(pin,HIGH);
    }
    else
    {
      Serial.println("Rear lights are off");
      //pinMode(pin,LOW);
      
      }}
void front_lights(char code)
{
  if(code == 'W')
  {
    Serial.println("Front lights are switched on");
    //pinMode(pin,HIGH);
    }
    else
    {
      Serial.println("Front lights are off");
      //pinMode(pin,LOW);
      
      }
  
  }
void hand_brake(char code)
{
  if(code == 'X')
  {Serial.println("Hand brake is on");
    Stop();
  delay(1000);
  
    }
  
  }
