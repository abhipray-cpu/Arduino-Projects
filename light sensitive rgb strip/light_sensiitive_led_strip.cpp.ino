#define resistor A0
#define Relay 10
void setup() {
  pinMode(resistor,INPUT);
  pinMode(Relay,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 int value=analogRead(resistor);
 Serial.println(value);
  //if value of resistance is greater then a threshold value we will switch on the led strip
  if(value >9.5)
  { 
    High();
    delay(1000);
    }
    else
{
  Low();
  }

  
  
}
void High()
{
   Serial.println("Switching on the led strip");
   digitalWrite(Relay,HIGH);
  }
void Low()
{
  Serial.println("Switching off the led strip");
   digitalWrite(Relay,LOW);
  }
