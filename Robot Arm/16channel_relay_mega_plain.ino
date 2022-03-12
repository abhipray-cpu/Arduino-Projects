#include<Arduino.h>
#define relay1 53
#define relay2 52
#define relay3 51
#define relay4 50
#define relay5 49
#define relay6 48
#define relay7 47
#define relay8 46
#define relay9 45
#define relay10 44
#define relay11 43
#define relay12 42
#define relay13 41
#define relay14 40
#define relay15 39
#define relay16 38
#define sensor1 A0  //linear hall sensor
#define sensor2 A1 //flame sensor
#define sensor3 A2 //reed switch
#define sensor4 A3 //digital temperature sensor
#define sensor5 A4 //capacitive touch sensor
#define sensor6 37 // tilt switch sensor
#define sensor7 36 //this is a shock sensor
#define sensor8 35 // light blocking sensor
#define sensor9 34 // this is a tap sensor
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(relay1,OUTPUT);
pinMode(relay2,OUTPUT);
pinMode(relay3,OUTPUT);
pinMode(relay4,OUTPUT);
pinMode(relay5,OUTPUT);
pinMode(relay6,OUTPUT);
pinMode(relay7,OUTPUT);
pinMode(relay8,OUTPUT);
pinMode(relay9,OUTPUT);
pinMode(relay10,OUTPUT);
pinMode(relay11,OUTPUT);
pinMode(relay12,OUTPUT);
pinMode(relay13,OUTPUT);
pinMode(relay14,OUTPUT);
pinMode(relay15,OUTPUT);
pinMode(relay16,OUTPUT);
pinMode(sensor1,INPUT);
pinMode(sensor2,INPUT);
pinMode(sensor3,INPUT);
pinMode(sensor4,INPUT);
pinMode(sensor5,INPUT);
pinMode(sensor6,INPUT);
pinMode(sensor7,INPUT);
pinMode(sensor8,INPUT);
pinMode(sensor9,INPUT);
pinMode(sensor10,INPUT);
for(int i=0;i<=100;i++)
{
  delay(10);
  }
  Serial.println("TURNING ON ALL RELAY CHANNELS");
  digitalWrite(relay1,HIGH);
  digitalWrite(relay2,HIGH);
  digitalWrite(relay3,HIGH);
  digitalWrite(relay4,HIGH);
  digitalWrite(relay5,HIGH);
  digitalWrite(relay6,HIGH);
  digitalWrite(relay7,HIGH);
  digitalWrite(relay8,HIGH);
  digitalWrite(relay9,HIGH);
  digitalWrite(relay10,HIGH);
  digitalWrite(relay11,HIGH);
  digitalWrite(relay12,HIGH);
  digitalWrite(relay13,HIGH);
  digitalWrite(relay14,HIGH);
  digitalWrite(relay15,HIGH);
  digitalWrite(relay16,HIGH);
  delay(100);
  Serial.println("Testing all the relay channels");
  for(int i=0;i<=0;i++)
  {
    Serial.println("Switching off relay1");
    digitalWrite(relay1,LOW);
    delay(100);
    Serial.println("Switching off relay2");
    digitalWrite(relay2,LOW);
    delay(100);
    Serial.println("Switching off relay3");
    digitalWrite(relay3,LOW);
    delay(100);
    Serial.println("Switching off relay4");
    digitalWrite(relay4,LOW);
    delay(100);
    Serial.println("Switching off relay5");
    digitalWrite(relay5,LOW);
    delay(100);
    Serial.println("Switching off relay6");
    digitalWrite(relay6,LOW);
    delay(100);
    Serial.println("Switching off relay7");
    digitalWrite(relay7,LOW);
    delay(100);
    Serial.println("Switching off relay8");
    digitalWrite(relay8,LOW);
    delay(100);
    Serial.println("Switching off relay9");
    digitalWrite(relay9,LOW);
    delay(100);
    Serial.println("Switching off relay10");
    digitalWrite(relay10,LOW);
    delay(100);
    Serial.println("Switching off relay11");
    digitalWrite(relay11,LOW);
    delay(100);
    Serial.println("Switching off relay12");
    digitalWrite(relay12,LOW);
    delay(100);
    Serial.println("Switching off relay13");
    digitalWrite(relay13,LOW);
    delay(100);
    Serial.println("Switching off relay14");
    digitalWrite(relay14,LOW);
    delay(100);
    Serial.println("Switching off relay15");
    digitalWrite(relay15,LOW);
    delay(100);
    Serial.println("Switching off relay16");
    digitalWrite(relay16,LOW);
    delay(100);
    Serial.println("Switching on relay1");
    digitalWrite(relay1,HIGH);
    delay(100);
    Serial.println("Switching on relay2");
    digitalWrite(relay2,HIGH);
    delay(100);
    Serial.println("Switching on relay3");
    digitalWrite(relay3,HIGH);
    delay(100);
    Serial.println("Switching on relay4");
    digitalWrite(relay4,HIGH);
    delay(100);
    Serial.println("Switching on relay5");
    digitalWrite(relay5,HIGH);
    delay(100);
    Serial.println("Switching on relay6");
    digitalWrite(relay6,HIGH);
    delay(100);
    Serial.println("Switching on relay7");
    digitalWrite(relay7,HIGH);
    delay(100);
    Serial.println("Switching on relay8");
    digitalWrite(relay8,HIGH);
    delay(100);
    Serial.println("Switching on relay9");
    digitalWrite(relay9,HIGH);
    delay(100);
    Serial.println("Switching on relay10");
    digitalWrite(relay10,HIGH);
    delay(100);
    Serial.println("Switching on relay11");
    digitalWrite(relay11,HIGH);
    delay(100);
    Serial.println("Switching on relay12");
    digitalWrite(relay12,HIGH);
    delay(100);
    Serial.println("Switching on relay13");
    digitalWrite(relay13,HIGH);
    delay(100);
    Serial.println("Switching on relay14");
    digitalWrite(relay14,HIGH);
    delay(100);
    Serial.println("Switching on relay15");
    digitalWrite(relay15,HIGH);
    delay(100);
    Serial.println("Switching on relay16");
    digitalWrite(relay16,HIGH);
    delay(100);
    }
}

void loop() {
   int val1=value1();
   control_relay1(val1);
   int val2=value2();
   control_relay2(val2);
   int val3=value3();
   control_relay3(val3);
   int val4=value4();
   control_relay4(val4);
   int val5=value5();
   control_relay5(val5);
   int val6=value6();
   control_relay6(val6);
   int val7=value7();
   control_relay7(val7);
   int val8=value8();
   control_relay8(val8);
   int val9=value9();
   control_relay9(val9);

}
int value1()
{
  int val;
  val=analogRead(sensor1);
  if(val <=600)
  {
    return 1;}
    else if(val > 600)
    {
      return 0;}
  }

 int value2()
 {
  int val = analogRead(sensor2);
  if(val<10)
  {
    return 0;
    }
    else if(val>10)
    {
      return 1;}
  }
  int value3()
  {
    int val=analogRead(sensor3);
    
    if(val==1 || val==0 || val==2 ||val==3)
    {
      return 0;}
      else
      {return 1;}
    }
  int value4()
  {
    int val=analogRead(sensor4);
    
    if(val<10)
    {
      return 0;}
      else if(val >10)
      {return 1;}
    }
  int value5()
  {
    int val=analogRead(sensor5);
    if(val<300 && val > 100)
    {
      return 0;}
      else if(val > 300)
      {
        return 1;}
        else
        {return 1;}
    }
  int value6()
  {
    int val=digitalRead(sensor6);
    Serial.println(val);
    if(val == 0)
    {
      return 0;}
      else
      return 1;
    }
 int value7()
 {
  int val=digitalRead(sensor7);
  if(val == 0)
    {
      return 0;
      delay(1000);
      }
      else
      return 1;
    
  
  }
  int value8()
  {
    int val=digitalRead(sensor8);
    if(val == 0)
    {
      return 1;
      }
      else
      return 0;}

   int value9()
   {
    int val=digitalRead(sensor9);
    if(val == 0)
    {
      return 1;
      }
      else
      return 0;
    }

   

void control_relay1(int val)
{
  if(val == 0)
  {
    digitalWrite(relay1,LOW);
    }
    else if(val == 1)
    {
      digitalWrite(relay1,HIGH);
      }
  }
  void control_relay2(int val)
{
  if(val == 0)
  {
    digitalWrite(relay2,LOW);
    }
    else if(val == 1)
    {
      digitalWrite(relay2,HIGH);
      }
  }
  void control_relay3(int val)
{if(val == 0)
  {
    digitalWrite(relay3,LOW);
    }
    else if(val == 1)
    {
      digitalWrite(relay3,HIGH);
      }
  }
  void control_relay4(int val)
{if(val == 0)
  {
    digitalWrite(relay4,LOW);
    }
    else if(val == 1)
    {
      digitalWrite(relay4,HIGH);
      }
  }
  void control_relay5(int val)
{
  if(val == 0)
  {
    digitalWrite(relay5,LOW);
    }
    else if(val == 1)
    {
      digitalWrite(relay5,HIGH);
      }
  }
  void control_relay6(int val)
{if(val == 0)
  {
    digitalWrite(relay6,LOW);
    }
    else if(val == 1)
    {
      digitalWrite(relay6,HIGH);
      }
  }
  void control_relay7(int val)
{if(val == 0)
  {
    digitalWrite(relay7,LOW);
    }
    else if(val == 1)
    {
      digitalWrite(relay7,HIGH);
      }
  }
  void control_relay8(int val)
{if(val == 0)
  {
    digitalWrite(relay8,LOW);
    }
    else if(val == 1)
    {
      digitalWrite(relay8,HIGH);
      }
  }
  void control_relay9(int val)
{
  if(val == 0)
  {
    digitalWrite(relay9,LOW);
    delay(10000);
    }
    else if(val == 1)
    {
      digitalWrite(relay9,HIGH);
      }
  }
  void control_relay10(int val)
{if(val == 0)
  {
    digitalWrite(relay10,LOW);
    }
    else if(val == 1)
    {
      digitalWrite(relay10,HIGH);
      }
  }
  void control_relay11(int val)
{if(val == 0)
  {
    digitalWrite(relay11,LOW);
    }
    else if(val == 1)
    {
      digitalWrite(relay11,HIGH);
      }
  }
  void control_relay12(int val)
{if(val == 0)
  {
    digitalWrite(relay12,LOW);
    }
    else if(val == 1)
    {
      digitalWrite(relay12,HIGH);
      }
  }
  void control_relay13(int val)
{if(val == 0)
  {
    digitalWrite(relay13,LOW);
    }
    else if(val == 1)
    {
      digitalWrite(relay13,HIGH);
      }
  }
  void control_relay14(int val)
{if(val == 0)
  {
    digitalWrite(relay14,LOW);
    }
    else if(val == 1)
    {
      digitalWrite(relay14,HIGH);
      }
  }
  void control_relay15(int val)
{if(val == 0)
  {
    digitalWrite(relay15,LOW);
    }
    else if(val == 1)
    {
      digitalWrite(relay15,HIGH);
      }
  }
  void control_relay16(int val)
{if(val == 0)
  {
    digitalWrite(relay16,LOW);
    }
    else if(val == 1)
    {
      digitalWrite(relay16,HIGH);
      }
  }
