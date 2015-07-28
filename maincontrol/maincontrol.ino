#include <VarSpeedServo.h> 
 
VarSpeedServo corner;  // create servo object to control a servo 
VarSpeedServo arm;          // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 

void setup() 
{ 
  corner.attach(9);  // attaches the servo on pin 9 to the servo object 
  arm.attach(10);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Enter desired servo position");
} 
 
void loop() 
{ 
  String content = "";
  char character;
  
  while (Serial.available())
  {
    character = Serial.read();
    delay(5);
    content.concat(character);
  }
  if (content != "")
  {
    int spos = atoi(content.c_str());
    int ppos = corner.read();
    if (spos + ppos > 66) 
    {
      corner.write(spos + ppos, 30, true);
      Serial.println(spos + ppos);
    } else
    {
      corner.write(66, 30, true);
      Serial.println(spos + ppos);
    }
  }
}

