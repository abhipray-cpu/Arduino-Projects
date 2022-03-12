/*
encoder1 controls the base motor of heavy arm
encoder2 controls the next level motor of heavy arm
encoder3 controlls the level 3 motor of heavr arm
encoder4 controls the level 4 motor of heavy arm
encoder5 controls the level 5 motor of heavy arm
encoder6 contrls the level 6 motor of heavy arm
encoder 7 controls the claw motor of light robot arm
encoder 8 controls the arm motors of light robot arm
encoderr9 controls the base motor of light robot arm
*/

#include<Servo.h>
#define CLK1 51
#define DT1 52
#define SW1 53

#define CLK2 48
#define DT2 49
#define SW2 50

#define CLK3 45
#define DT3 46
#define SW3 47

#define CLK4 42
#define DT4 43
#define SW4 44

#define CLK5 39
#define DT5 40
#define SW5 41

#define CLK6 36
#define DT6 37
#define SW6 38

#define CLK7 33
#define DT7 34
#define SW7 35

#define CLK8 30
#define DT8 31
#define SW8 32

#define CLK9 27
#define DT9 28
#define SW9 29


int counter1 = 0;
int currentStateCLK1;
int lastStateCLK1;
String currentDir1 ="";
unsigned long lastButtonPress1 = 0;

int counter2 = 60;
int currentStateCLK2;
int lastStateCLK2;
String currentDir2 ="";
unsigned long lastButtonPress2 = 0;

int counter3 = 110;
int currentStateCLK3;
int lastStateCLK3;
String currentDir3 ="";
unsigned long lastButtonPress3 = 0;

int counter4 = 40;
int currentStateCLK4;
int lastStateCLK4;
String currentDir4 ="";
unsigned long lastButtonPress4 = 0;

int counter5 = 0;
int currentStateCLK5;
int lastStateCLK5;
String currentDir5 ="";
unsigned long lastButtonPress5 = 0;

int counter6 = 180;
int currentStateCLK6;
int lastStateCLK6;
String currentDir6 ="";
unsigned long lastButtonPress6 = 0;

int counter7 = 119;
int currentStateCLK7;
int lastStateCLK7;
String currentDir7 ="";
unsigned long lastButtonPress7 = 0;

int counter8 = 0;
int currentStateCLK8;
int lastStateCLK8;
String currentDir8 ="";
unsigned long lastButtonPress8 = 0;

int counter9 = 0;
int currentStateCLK9;
int lastStateCLK9;
String currentDir9 ="";
unsigned long lastButtonPress9 = 0;


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

void setup() {
  myServo1.attach(13);
  myServo2.attach(12);
  myServo3.attach(11);
  myServo4.attach(10);
  myServo5.attach(9);
  myServo6.attach(8);
  myServo7.attach(7);
  myServo8.attach(6);
  myServo9.attach(5);
  myServo10.attach(4);
  myServo1.write(0);
  myServo2.write(0);
  myServo3.write(0);
  myServo4.write(0);
  myServo5.write(0);
  myServo6.write(0);
  myServo7.write(0);
  myServo8.write(0);
  myServo9.write(0);
  myServo10.write(0);
  // Set encoder pins as inputs
  pinMode(CLK1,INPUT);
  pinMode(DT1,INPUT);
  pinMode(SW1, INPUT_PULLUP);

  pinMode(CLK2,INPUT);
  pinMode(DT2,INPUT);
  pinMode(SW2, INPUT_PULLUP);

  pinMode(CLK3,INPUT);
  pinMode(DT3,INPUT);
  pinMode(SW3, INPUT_PULLUP);

  pinMode(CLK4,INPUT);
  pinMode(DT4,INPUT);
  pinMode(SW4, INPUT_PULLUP);

  pinMode(CLK5,INPUT);
  pinMode(DT5,INPUT);
  pinMode(SW5, INPUT_PULLUP);

   pinMode(CLK6,INPUT);
  pinMode(DT6,INPUT);
  pinMode(SW6, INPUT_PULLUP);

  pinMode(CLK7,INPUT);
  pinMode(DT7,INPUT);
  pinMode(SW7, INPUT_PULLUP);

   pinMode(CLK8,INPUT);
  pinMode(DT8,INPUT);
  pinMode(SW8, INPUT_PULLUP);

  pinMode(CLK9,INPUT);
  pinMode(DT9,INPUT);
  pinMode(SW9, INPUT_PULLUP);
  // Setup Serial Monitor
  Serial.begin(9600);

  // Read the initial state of CLK
  lastStateCLK1 = digitalRead(CLK1);
  lastStateCLK2 = digitalRead(CLK2);
  lastStateCLK3 = digitalRead(CLK3);
  lastStateCLK4 = digitalRead(CLK4);
  lastStateCLK5 = digitalRead(CLK5);
   lastStateCLK6 = digitalRead(CLK6);
  lastStateCLK7 = digitalRead(CLK7);
  lastStateCLK8 = digitalRead(CLK8);
  lastStateCLK9 = digitalRead(CLK9);
}

void loop() {
  encoder1();
  encoder2();
  encoder3();
  encoder4();
  encoder5();
  encoder6();
  encoder7();
  encoder8();
  encoder9();

  
}

void encoder1()
{
  // Read the current state of CLK
  currentStateCLK1 = digitalRead(CLK1);

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK1 != lastStateCLK1  && currentStateCLK1 == 1){

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT1) != currentStateCLK1) {
      counter1=counter1-10;
      currentDir1 ="CCW";
    } else {
      // Encoder is rotating CW so increment
      counter1=counter1+10;
      currentDir1 ="CW";
    }
    if(counter1 < 0)
    {
      counter1=0;}
      if(counter1 > 179)
      {
        counter1=179;}

    Serial.print("Direction1: ");
    Serial.print(currentDir1);
    Serial.print(" | Counter1: ");
    Serial.println(counter1);
    myServo1.write(counter1);
    
  }

  // Remember last CLK state
  lastStateCLK1 = currentStateCLK1;

  // Read the button state
  int btnState1 = digitalRead(SW1);

  //If we detect LOW signal, button is pressed
  if (btnState1 == LOW) {
    //if 50ms have passed since last LOW pulse, it means that the
    //button has been pressed, released and pressed again
    if (millis() - lastButtonPress1 > 50) { 
      Serial.println("Button1 pressed!");
    }

    // Remember last button press event
    lastButtonPress1 = millis();
  }

  // Put in a slight delay to help debounce the reading
  //delay(1);
  }

//encoder2
void encoder2()
{
  // Read the current state of CLK
  currentStateCLK2 = digitalRead(CLK2);

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK2 != lastStateCLK2  && currentStateCLK2 == 1){

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT2) != currentStateCLK2) {
      counter2=counter2-10;
      currentDir2 ="CCW";
    } else {
      // Encoder is rotating CW so increment
      counter2=counter2+10;
      currentDir2 ="CW";
    }
    if(counter2 < 0)
    {
      counter2=0;}
      
      if(counter2 > 179)
      {
        counter2=179;}

    Serial.print("Direction2: ");
    Serial.print(currentDir2);
    Serial.print(" | Counter2: ");
    Serial.println(counter2);
    myServo2.write(counter2);
  
    
  }

  // Remember last CLK state
  lastStateCLK2 = currentStateCLK2;

  // Read the button state
  int btnState2 = digitalRead(SW2);

  //If we detect LOW signal, button is pressed
  if (btnState2 == LOW) {
    //if 50ms have passed since last LOW pulse, it means that the
    //button has been pressed, released and pressed again
    if (millis() - lastButtonPress2 > 50) {
      Serial.println("Button2 pressed!");
    }

    // Remember last button press event
    lastButtonPress2 = millis();
  }

  // Put in a slight delay to help debounce the reading
  //delay(1);
  }
 //encoder3

void encoder3()
{
  // Read the current state of CLK
  currentStateCLK3 = digitalRead(CLK3);

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK3 != lastStateCLK3  && currentStateCLK3 == 1){

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT3) != currentStateCLK3) {
      counter3=counter3-10;
      currentDir3 ="CCW";
    } else {
      // Encoder is rotating CW so increment
      counter3=counter3+10;;
      currentDir3 ="CW";
    }
    if(counter3 < 80)
    {
      counter3=80;}
      if(counter3 > 179)
      {
        counter3=179;}

    Serial.print("Direction3: ");
    Serial.print(currentDir3);
    Serial.print(" | Counter3: ");
    Serial.println(counter3);
    myServo3.write(counter3);
  }

  // Remember last CLK state
  lastStateCLK3 = currentStateCLK3;

  // Read the button state
  int btnState3 = digitalRead(SW3);

  //If we detect LOW signal, button is pressed
  if (btnState3 == LOW) {
    //if 50ms have passed since last LOW pulse, it means that the
    //button has been pressed, released and pressed again
    if (millis() - lastButtonPress3 > 50) {
      Serial.println("Button3 pressed!");
    }

    // Remember last button press event
    lastButtonPress3 = millis();
  }

  // Put in a slight delay to help debounce the reading
  //delay(1);
  }

//encoder3

void encoder4()
{
  // Read the current state of CLK
  currentStateCLK4 = digitalRead(CLK4);

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK4 != lastStateCLK4  && currentStateCLK4 == 1){

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT4) != currentStateCLK4) {
      counter4=counter4-10;
      currentDir4 ="CCW";
    } else {
      // Encoder is rotating CW so increment
      counter4=counter4+10;;
      currentDir4 ="CW";
    }
    if(counter4 < 0)
    {
      counter4=0;}
      if(counter4 > 179)
      {
        counter4=179;}

    Serial.print("Direction4: ");
    Serial.print(currentDir4);
    Serial.print(" | Counter4: ");
    Serial.println(counter4);
    myServo4.write(counter4);
  }

  // Remember last CLK state
  lastStateCLK4 = currentStateCLK4;

  // Read the button state
  int btnState4 = digitalRead(SW4);

  //If we detect LOW signal, button is pressed
  if (btnState4 == LOW) {
    //if 50ms have passed since last LOW pulse, it means that the
    //button has been pressed, released and pressed again
    if (millis() - lastButtonPress4 > 50) {
      Serial.println("Button4 pressed!");
    }

    // Remember last button press event
    lastButtonPress4 = millis();
  }

  // Put in a slight delay to help debounce the reading
  //delay(1);
  }

//encoder4

void encoder5()
{
  // Read the current state of CLK
  currentStateCLK5 = digitalRead(CLK5);

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK5 != lastStateCLK5  && currentStateCLK5 == 1){

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT5) != currentStateCLK5) {
      counter5=counter5-10;
      currentDir5 ="CCW";
    } else {
      // Encoder is rotating CW so increment
      counter5=counter5+10;;
      currentDir5 ="CW";
    }
    if(counter5 < 0)
    {
      counter5=0;}
      if(counter5 > 179)
      {
        counter5=179;}

    Serial.print("Direction5: ");
    Serial.print(currentDir5);
    Serial.print(" | Counter5: ");
    Serial.println(counter5);
    myServo5.write(counter5);
  }

  // Remember last CLK state
  lastStateCLK5 = currentStateCLK5;

  // Read the button state
  int btnState5 = digitalRead(SW5);

  //If we detect LOW signal, button is pressed
  if (btnState5 == LOW) {
    //if 50ms have passed since last LOW pulse, it means that the
    //button has been pressed, released and pressed again
    if (millis() - lastButtonPress5 > 50) {
      Serial.println("Button5 pressed!");
    }

    // Remember last button press event
    lastButtonPress5 = millis();
  }

  // Put in a slight delay to help debounce the reading
  //delay(1);
  }


void encoder6()
{
  // Read the current state of CLK
  currentStateCLK6 = digitalRead(CLK6);

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK6 != lastStateCLK6  && currentStateCLK6 == 1){

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT6) != currentStateCLK6) {
      counter6=counter6-10;
      currentDir6 ="CCW";
    } else {
      // Encoder is rotating CW so increment
      counter6=counter6+10;;
      currentDir6 ="CW";
    }
    if(counter6 < 109)
    {
      counter6=109;}
      if(counter6 > 179)
      {
        counter6=179;}

    Serial.print("Direction6: ");
    Serial.print(currentDir6);
    Serial.print(" | Counter6: ");
    Serial.println(counter6);
    myServo6.write(counter6);
  }

  // Remember last CLK state
  lastStateCLK6 = currentStateCLK6;

  // Read the button state
  int btnState6 = digitalRead(SW6);

  //If we detect LOW signal, button is pressed
  if (btnState6 == LOW) {
    //if 50ms have passed since last LOW pulse, it means that the
    //button has been pressed, released and pressed again
    if (millis() - lastButtonPress6 > 50) {
      Serial.println("Button6 pressed!");
    }

    // Remember last button press event
    lastButtonPress6 = millis();
  }

  // Put in a slight delay to help debounce the reading
  //delay(1);
  }

//encoder4

void encoder7()
{
  // Read the current state of CLK
  currentStateCLK7 = digitalRead(CLK7);

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK7 != lastStateCLK7  && currentStateCLK7 == 1){

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT7) != currentStateCLK7) {
      counter7=counter7-10;
      currentDir7 ="CCW";
    } else {
      // Encoder is rotating CW so increment
      counter7=counter7+10;;
      currentDir7 ="CW";
    }
    if(counter7 < 119)
    {
      counter7=119;}
      if(counter7 > 219)
      {
        counter7=219;}

    Serial.print("Direction7: ");
    Serial.print(currentDir7);
    Serial.print(" | Counter7: ");
    Serial.println(counter7);
    myServo7.write(counter7);
   
  }

  // Remember last CLK state
  lastStateCLK7 = currentStateCLK7;

  // Read the button state
  int btnState7 = digitalRead(SW7);

  //If we detect LOW signal, button is pressed
  if (btnState7 == LOW) {
    //if 50ms have passed since last LOW pulse, it means that the
    //button has been pressed, released and pressed again
    if (millis() - lastButtonPress7 > 50) {
      Serial.println("Button7 pressed!");
    }

    // Remember last button press event
    lastButtonPress7 = millis();
  }

  // Put in a slight delay to help debounce the reading
  //delay(1);
  }

  void encoder8()
{
  // Read the current state of CLK
  currentStateCLK8 = digitalRead(CLK8);

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK8 != lastStateCLK8  && currentStateCLK8 == 1){

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT8) != currentStateCLK8) {
      counter8=counter8-10;
      currentDir8 ="CCW";
    } else {
      // Encoder is rotating CW so increment
      counter8=counter8+10;;
      currentDir8 ="CW";
    }
    if(counter8 < 0)
    {
      counter8=0;}
      if(counter8 > 179)
      {
        counter8=179;}

    Serial.print("Direction8: ");
    Serial.print(currentDir8);
    Serial.print(" | Counter8: ");
    Serial.println(counter8);
    
    myServo10.write(counter8);
    myServo9.write(counter8 );
    
  }

  // Remember last CLK state
  lastStateCLK8 = currentStateCLK8;

  // Read the button state
  int btnState8 = digitalRead(SW8);

  //If we detect LOW signal, button is pressed
  if (btnState8 == LOW) {
    //if 50ms have passed since last LOW pulse, it means that the
    //button has been pressed, released and pressed again
    if (millis() - lastButtonPress8 > 50) {
      Serial.println("Button8 pressed!");
    }

    // Remember last button press event
    lastButtonPress7 = millis();
  }

  // Put in a slight delay to help debounce the reading
  //delay(1);
  }

void encoder9()
{
  // Read the current state of CLK
  currentStateCLK9 = digitalRead(CLK9);

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK9 != lastStateCLK9  && currentStateCLK9 == 1){

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT9) != currentStateCLK9) {
      counter9=counter9-10;
      currentDir9 ="CCW";
    } else {
      // Encoder is rotating CW so increment
      counter9=counter9+10;;
      currentDir9 ="CW";
    }
    if(counter9 < 0)
    {
      counter9=0;}
      if(counter9 > 179)
      {
        counter9=179;}

    Serial.print("Direction9: "); 
    Serial.print(currentDir9);
    Serial.print(" | Counter9: ");
    Serial.println(counter9);
    myServo8.write(counter9);
  }

  // Remember last CLK state
  lastStateCLK9 = currentStateCLK9;

  // Read the button state
  int btnState9 = digitalRead(SW9);

  //If we detect LOW signal, button is pressed
  if (btnState9 == LOW) {
    //if 50ms have passed since last LOW pulse, it means that the
    //button has been pressed, released and pressed again
    if (millis() - lastButtonPress9 > 50) {
      Serial.println("Button9 pressed!");
    }

    // Remember last button press event
    lastButtonPress9 = millis();
  }

  // Put in a slight delay to help debounce the reading
  //delay(1);
  }
