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
	//Pan.writeMicroseconds(1000);
	//Pan.writeMicroseconds(1000);

//Where we could put pushbutton scan start
	for(int PanPosition=10; PanPosition<170; PanPosition+=10)
	{
		Pan.write(PanPosition);
		Tilt.write(PanPosition);
		delay(1000);

	}

}

