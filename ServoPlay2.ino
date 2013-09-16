// ServoPlay2.ino
#include "Servo.h"


Servo Pan;
Servo Tilt;


void setup()
{
	Pan.attach(9);			//Attaches Pan to pin 9
	Tilt.attach(11);		//Attaches Tilt to pin 11
}

void loop() 
{
	Pan.writeMicroseconds(1500);
	Pan.writeMicroseconds(1500);

//Where we could put pushbutton scan start
	for(int PanPosition=1000; PanPosition<2000; PanPosition+=50)
	{
		Pan.writeMicroseconds(PanPosition);
		delay(500);
	}

}

