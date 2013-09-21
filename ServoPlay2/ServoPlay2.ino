// ServoPlay2.ino
#include "Servo.h"

int Position=0;
Servo Pan;
Servo Tilt;


void setup()
{
	Pan.attach(9);			//Attaches Pan to pin 9
	Tilt.attach(10);		//Attaches Tilt to pin 11
	Serial.begin(9600);
}

void loop() 
{
  Pan.write(40);
Tilt.write(90);


}

