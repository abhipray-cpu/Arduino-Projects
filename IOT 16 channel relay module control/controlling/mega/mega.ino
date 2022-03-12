#include <SoftwareSerial.h>
#define  Rx_PIN  3   // Rx pin of HC-12
#define  Tx_PIN 2    // Tx pin of HC-12
SoftwareSerial mySerial(Rx_PIN, Tx_PIN);//rx tx

#define killpin 9 // Please ignore. This is only to activate ext power to transmitter
#define relay1 4
#define relay2 5
#define relay3 6
#define relay4 7
#define relay5 8
#define relay6 9
#define relay7 10
#define relay8 11
#define relay9 12
#define relay10 13
#define relay11 14
#define relay12 15
#define relay13 16
#define relay14 17
#define relay15 18
#define relay16 19

//***************************************
const byte numCharsMaster = 64;
char receivedMasterChars[numCharsMaster];
char tempMasterChars[numCharsMaster];        // temporary array for use when parsing

// variables to hold the parsed data
char messageFromMaster[numCharsMaster] = {0};
int relay1_state;
int relay2_state;
int relay3_state;
int relay4_state;
int relay5_state;
int relay6_state;
int relay7_state;
int relay8_state;
int relay9_state;
int relay10_state;
int relay11_state;
int relay12_state;
int relay13_state;
int relay14_state;
int relay15_state;
int relay16_state;
boolean newData = true; // invert this on Master arduino

static boolean recvInProgress = false;
static byte ndx = 0;
char startMarker = '<';
char endMarker = '>';
char rc;
//***************************************
unsigned long currentMillis1 = 0;
unsigned long previousMillis1 = 0;
long interval1 = 150;           // 150 milliseconds


//***************************************
//============
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(killpin, OUTPUT);// Please ignore. This is only to activate ext power to transmitter
  digitalWrite(killpin, HIGH);// Please ignore. This is only to activate ext power to transmitter
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
  relay_test1();
  relay_test2();
}

void relay_test1()
{
  for(int i=0;i<2;i++)
  {
    digitalWrite(relay1,LOW);
  digitalWrite(relay2,LOW);
  digitalWrite(relay3,LOW);
  digitalWrite(relay4,LOW);
  digitalWrite(relay5,LOW);
  digitalWrite(relay6,LOW);
  digitalWrite(relay7,LOW);
  digitalWrite(relay8,LOW);
  digitalWrite(relay9,LOW);
  digitalWrite(relay10,LOW);
  digitalWrite(relay11,LOW);
  digitalWrite(relay12,LOW);
  digitalWrite(relay13,LOW);
  digitalWrite(relay14,LOW);
  digitalWrite(relay15,LOW);
  digitalWrite(relay16,LOW);
  delay(10000);
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
  digitalWrite(relay16,HIGH);}
  }

void relay_test2()
{
  for(int i=0;i<10;i++)
  {digitalWrite(relay1,LOW);
  delay(10);
  digitalWrite(relay1,HIGH);
  delay(10);
  digitalWrite(relay2,LOW);
  delay(10);
  digitalWrite(relay2,HIGH);
  delay(10);
  digitalWrite(relay3,LOW);
  delay(10);
  digitalWrite(relay3,HIGH);
  delay(10);
  digitalWrite(relay4,LOW);
  delay(10);
  digitalWrite(relay4,HIGH);
  delay(10);
  digitalWrite(relay5,LOW);
  delay(10);
  digitalWrite(relay5,HIGH);
  delay(10);
  digitalWrite(relay6,LOW);
  delay(10);
  digitalWrite(relay6,HIGH);
  delay(10);
  digitalWrite(relay7,LOW);
  delay(10);
  digitalWrite(relay7,HIGH);
  delay(10);
  digitalWrite(relay8,LOW);
  delay(10);
  digitalWrite(relay8,HIGH);
  delay(10);
  digitalWrite(relay9,LOW);
  delay(10);
  digitalWrite(relay9,HIGH);
  delay(10);
  digitalWrite(relay10,LOW);
  delay(10);
  digitalWrite(relay10,HIGH);
  delay(10);
  digitalWrite(relay11,LOW);
  delay(10);
  digitalWrite(relay11,HIGH);
  delay(10);
  digitalWrite(relay12,LOW);
  delay(10);
  digitalWrite(relay12,HIGH);
  delay(10);
  digitalWrite(relay13,LOW);
  delay(10);
  digitalWrite(relay13,HIGH);
  delay(10);
  digitalWrite(relay14,LOW);
  delay(10);
  digitalWrite(relay14,HIGH);
  delay(10);
  digitalWrite(relay15,LOW);
  delay(10);
  digitalWrite(relay15,HIGH);
  delay(10);
  digitalWrite(relay16,LOW);
  delay(10);
  digitalWrite(relay16,HIGH);
  delay(10);}
 }
//============
void loop() {
  recvWithStartEndMarkers();
  if (newData == true) {
    strcpy(tempMasterChars, receivedMasterChars);// this temporary copy is necessary to protect the original data because strtok() used in parseData() replaces the commas with \0
    parseData();
    showParsedData();
    newData = false;
  

  control_relay1(relay1_state);
  control_relay2(relay2_state);
  control_relay3(relay3_state);
  control_relay4(relay4_state);
  control_relay5(relay5_state);
  control_relay6(relay6_state);
  control_relay7(relay7_state);
  control_relay8(relay8_state);
  control_relay9(relay9_state);
  control_relay10(relay10_state);
  control_relay11(relay11_state);
  control_relay12(relay12_state);
  control_relay13(relay13_state);
  control_relay14(relay14_state);
  control_relay15(relay15_state);
  control_relay16(relay16_state);
  
  }
  
} // end of loop
//============
void recvWithStartEndMarkers() {
  while (mySerial.available() > 0 && newData == false) {
    rc = mySerial.read();
    if (recvInProgress == true) {
      if (rc != endMarker) {
        receivedMasterChars[ndx] = rc;
        ndx++;
        if (ndx >= numCharsMaster) {
          ndx = numCharsMaster - 1;
        }
      }
      else {
        receivedMasterChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        newData = true;
      }
    }
    else if (rc == startMarker) {
      recvInProgress = true;
    }
  }
}
//============
void parseData() {      // split the data into its parts
  char * strtokIndx; // this is used by strtok() as an index
  strtokIndx = strtok(tempMasterChars, ",");     // get the first part - the string
  strcpy(messageFromMaster, strtokIndx); // copy it to messageFromMaster
  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  relay1_state = atoi(strtokIndx);     // convert this part to an integer
  strtokIndx = strtok(NULL, ",");
  relay2_state = atof(strtokIndx);     // convert this part to a float
  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  relay3_state = atoi(strtokIndx);     // convert this part to an integer
  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  relay4_state = atoi(strtokIndx);     // convert this part to an integer
  strtokIndx = strtok(NULL, ",");
  relay5_state = atof(strtokIndx);     // convert this part to a float
  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  relay6_state = atoi(strtokIndx);     // convert this part to an integer
   strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  relay7_state = atoi(strtokIndx);     // convert this part to an integer
  strtokIndx = strtok(NULL, ",");
  relay8_state = atof(strtokIndx);     // convert this part to a float
  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  relay9_state = atoi(strtokIndx);     // convert this part to an integer
  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  relay10_state = atoi(strtokIndx);     // convert this part to an integer
  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  relay11_state = atoi(strtokIndx);     // convert this part to an 
  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  relay12_state = atoi(strtokIndx);     // convert this part to an 
  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  relay13_state = atoi(strtokIndx);     // convert this part to an 
  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  relay14_state = atoi(strtokIndx);     // convert this part to an 
  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  relay15_state = atoi(strtokIndx);     // convert this part to an 
  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  relay16_state = atoi(strtokIndx);     // convert this part to an 
  
 }
//============
void showParsedData() {
  Serial.print("messageFromMaster ");
  Serial.print(messageFromMaster);
  Serial.print("State of relay 1:");
  Serial.println(relay1_state);
   Serial.print("State of relay 2:");
  Serial.println(relay2_state);
   Serial.print("State of relay 3:");
  Serial.println(relay3_state);
   Serial.print("State of relay 4:");
  Serial.println(relay4_state);
   Serial.print("State of relay 5:");
  Serial.println(relay5_state);
   Serial.print("State of relay 6:");
  Serial.println(relay6_state);
   Serial.print("State of relay 7:");
  Serial.println(relay7_state);
   Serial.print("State of relay 8:");
  Serial.println(relay8_state);
   Serial.print("State of relay 9:");
  Serial.println(relay9_state);
   Serial.print("State of relay 10:");
  Serial.println(relay10_state);
   Serial.print("State of relay 11:");
  Serial.println(relay11_state);
   Serial.print("State of relay 12:");
  Serial.println(relay12_state);
   Serial.print("State of relay 13:");
  Serial.println(relay13_state);
   Serial.print("State of relay 14:");
  Serial.println(relay14_state);
   Serial.print("State of relay 15:");
  Serial.println(relay15_state);
   Serial.print("State of relay 16:");
  Serial.println(relay16_state);
}

// these functions are used to control the channels of relay module
void control_relay1(int val)
{
  if(val == 0)
  {
    digitalWrite(relay1,HIGH);
    }
    else if(val == 1)
    {
      digitalWrite(relay1,LOW);
      }
}


void control_relay2(int val)
{
  if(val == 0)
  {
    digitalWrite(relay2,HIGH);
    }
    else if(val == 1)
    {
      digitalWrite(relay2,LOW);
      }
}

void control_relay3(int val)
{
  if(val == 0)
  {
    digitalWrite(relay3,HIGH);
    }
    else if(val == 1)
    {
      digitalWrite(relay3,LOW);
      }
}

void control_relay4(int val)
{
  if(val == 0)
  {
    digitalWrite(relay4,HIGH);
    }
    else if(val == 1)
    {
      digitalWrite(relay4,LOW);
      }
}

void control_relay5(int val)
{
  if(val == 0)
  {
    digitalWrite(relay5,HIGH);
    }
    else if(val == 1)
    {
      digitalWrite(relay5,LOW);
      }
}

void control_relay6(int val)
{
  if(val == 0)
  {
    digitalWrite(relay6,HIGH);
    }
    else if(val == 1)
    {
      digitalWrite(relay6,LOW);
      }
}

void control_relay7(int val)
{
  if(val == 0)
  {
    digitalWrite(relay7,HIGH);
    }
    else if(val == 1)
    {
      digitalWrite(relay7,LOW);
      }
}

void control_relay8(int val)
{
  if(val == 0)
  {
    digitalWrite(relay8,HIGH);
    }
    else if(val == 1)
    {
      digitalWrite(relay8,LOW);
      }
}

void control_relay9(int val)
{
  if(val == 0)
  {
    digitalWrite(relay9,HIGH);
    }
    else if(val == 1)
    {
      digitalWrite(relay9,LOW);
      }
}

void control_relay10(int val)
{
  if(val == 0)
  {
    digitalWrite(relay10,HIGH);
    }
    else if(val == 1)
    {
      digitalWrite(relay10,LOW);
      }
}

void control_relay11(int val)
{
  if(val == 0)
  {
    digitalWrite(relay11,HIGH);
    }
    else if(val == 1)
    {
      digitalWrite(relay11,LOW);
      }
}

void control_relay12(int val)
{
  if(val == 0)
  {
    digitalWrite(relay12,HIGH);
    }
    else if(val == 1)
    {
      digitalWrite(relay12,LOW);
      }
}

void control_relay13(int val)
{
  if(val == 0)
  {
    digitalWrite(relay13,HIGH);
    }
    else if(val == 1)
    {
      digitalWrite(relay13,LOW);
      }
}

void control_relay14(int val)
{
  if(val == 0)
  {
    digitalWrite(relay14,HIGH);
    }
    else if(val == 1)
    {
      digitalWrite(relay14,LOW);
      }
}

void control_relay15(int val)
{
  if(val == 0)
  {
    digitalWrite(relay15,HIGH);
    }
    else if(val == 1)
    {
      digitalWrite(relay15,LOW);
      }
}

void control_relay16(int val)
{
  if(val == 0)
  {
    digitalWrite(relay16,HIGH);
    }
    else if(val == 1)
    {
      digitalWrite(relay16,LOW);
      }
}
