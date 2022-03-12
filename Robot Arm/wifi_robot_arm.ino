/*how to use the bord for esp8266
while uploading code (5,6,7 are on) and press mode after it TX-Rx=0
while connecting to database from board(5 and 6 are on)press mode after it Tx-Rx=0
the board to select is LOLIN WEMON R-D2 and mini
add the url by going to preferences and there paste it
install esp8266 by going to board managaer
add mobitz library using add .zip library 
*/

#include <FirebaseESP8266.h>

#include <ESP8266WiFi.h>
#include<Servo.h>
#define FIREBASE_HOST "robotarm-99f0a-default-rtdb.firebaseio.com/" //Without http:// or https:// schemes
#define FIREBASE_AUTH "fDvRmZCxSJnuD1TshI3fVTbGaA3mNAgKezOFodZE"
#define WIFI_SSID "STARNET_A"
#define WIFI_PASSWORD "kamalanita1@"

FirebaseData firebaseData;
FirebaseJson json;
Servo myServo1;
Servo myServo2;
Servo myServo3;
Servo myServo4;
Servo myServo5;
Servo myServo6;
Servo myServo7;
Servo myServo8;
Servo myServo9;
Servo myServo10;

void setup()
{
  
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
   
   Serial.println();
   Serial.print("Connected with IP: ");
   Serial.println(WiFi.localIP());
   Serial.println();

   Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
   
   for(int val=0;val<=180;val=val+80)
  {
    Firebase.setInt(firebaseData, "/motor1",val);
    Firebase.setInt(firebaseData, "/motor2",val);
    Firebase.setInt(firebaseData, "/motor3",val);
    Firebase.setInt(firebaseData, "/motor4",val);
    Firebase.setInt(firebaseData, "/motor5",val);
    Firebase.setInt(firebaseData, "/motor6",val);
    Firebase.setInt(firebaseData, "/motor7",val);
    Firebase.setInt(firebaseData, "/motor8",val);
    Firebase.setInt(firebaseData, "/motor9",val);
    Firebase.setInt(firebaseData, "/motor10",val);
    }

// do not use pin 11 to attach the motor as it breaks the connection
    myServo1.attach(53);
    myServo2.attach(52);
    myServo3.attach(51);
    myServo4.attach(50);
    myServo5.attach(49);
    myServo6.attach(48);
    myServo7.attach(47);
    myServo8.attach(46);
    myServo9.attach(45);
    myServo10.attach(44);
   
}
void loop()
{  
  
  encoder1();
  encoder2();
  encoder3();
  encoder4();
  encoder5();
  encoder6();
  encoder7();
  encoder8();
  encoder9();
  encoder10();
}

//using these function we will read values from database
void encoder1()
{
  if (Firebase.getInt(firebaseData, "/motor1")){
    Serial.print("The value written to Motor1:");
    Serial.println(firebaseData.intData());
     myServo1.write(firebaseData.intData());
    
  }
  delay(100);
 
  }
void encoder2()
{
  if (Firebase.getInt(firebaseData, "/motor2")){
    Serial.print("The value written to Motor2:");
    Serial.println(firebaseData.intData());
     myServo2.write(firebaseData.intData());
    
  }
  delay(100);
 
  }
void encoder3()
{
  if (Firebase.getInt(firebaseData, "/motor3")){
    Serial.print("The value written to Motor3:");
    Serial.println(firebaseData.intData());
     myServo3.write(firebaseData.intData());
    
  }
  delay(100);
 
  }
void encoder4()
{
  if (Firebase.getInt(firebaseData, "/motor4")){
    Serial.print("The value written to Motor4:");
    Serial.println(firebaseData.intData());
     myServo4.write(firebaseData.intData());
    
  }
  delay(100);
 
  }
void encoder5()
{
  if (Firebase.getInt(firebaseData, "/motor5")){
    Serial.print("The value written to Motor5:");
    Serial.println(firebaseData.intData());
     myServo5.write(firebaseData.intData());
    
  }
  delay(100);
 
  }
void encoder6()
{
 if (Firebase.getInt(firebaseData, "/motor6")){
  Serial.print("The value written to Motor6:");
    Serial.println(firebaseData.intData());
     myServo6.write(firebaseData.intData());
    
  }
  delay(100); 
 
  }
  void encoder7()
{
  if (Firebase.getInt(firebaseData, "/motor7")){
    Serial.print("The value written to Motor7:");
    Serial.println(firebaseData.intData());
     myServo7.write(firebaseData.intData());
    
  }
  delay(100);
 
  }
void encoder8()
{
 if (Firebase.getInt(firebaseData, "/motor8")){
  Serial.print("The value written to Motor8:");
    Serial.println(firebaseData.intData());
     myServo8.write(firebaseData.intData());
    
  }
  delay(100); 
 
  }
 void encoder9()
{
  if (Firebase.getInt(firebaseData, "/motor9")){
    Serial.print("The value written to Motor9:");
    Serial.println(firebaseData.intData());
     myServo9.write(firebaseData.intData());
  
  }
  delay(100);
 
  }
void encoder10()
{
  if (Firebase.getInt(firebaseData, "/motor10")){
    Serial.print("The value written to Motor10:");
    Serial.println(firebaseData.intData());
     myServo10.write(firebaseData.intData());
   
  }
  delay(100);
 
  }

  
