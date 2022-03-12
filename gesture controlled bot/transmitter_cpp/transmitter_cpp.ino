#include<SPI.h>
#include<RF24.h>
#include<nRF24L01.h>
#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;
//create an RF24 object
RF24 radio(9, 10);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";
struct Data
{
  int pitch;
  int roll;
  
 };

Data send_data;
void setup() 
{
  Serial.begin(9600);

  Serial.println("Initialize MPU6050");
  radio.

  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }

  
  radio.begin();

  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();
   Serial.println("Initialize MPU6050");
}

void loop()
{
  // Read normalized values 
  Vector normAccel = mpu.readNormalizeAccel();

  // Calculate Pitch & Roll
  int pitch = -(atan2(normAccel.XAxis, sqrt(normAccel.YAxis*normAccel.YAxis + normAccel.ZAxis*normAccel.ZAxis))*180.0)/M_PI;
  int roll = (atan2(normAccel.YAxis, normAccel.ZAxis)*180.0)/M_PI;
  

 //Output
 Serial.print(" Pitch = ");
 Serial.println(pitch);
 Serial.print(" Roll = ");
 Serial.println(roll);
 send_data.pitch=pitch;
 send_data.roll=roll;
 if((radio.write(&send_data, sizeof(Data))))
 {
  Serial.println("Mja avigayo bapu");
  }
  else
  {
    Serial.println("Iski maa ka bhosda");
    }
}
