// LIDAR.ino
#include "Servo.h"

int Position=0;
int PanAngle=0;
int TiltAngle=0;
int Distance1=0;
int Distance2=0;
int Distance3=0;
int Distance4=0;
int Distance5=0;
int TenXDistance=0;				//Final Distance (has been averaged)
int SensorPin=0;			//Pin the distance sensor is plugged into. MUST BE ANALOG INPUT
Servo Pan;
Servo Tilt;


void setup()
{
	Pan.attach(9);			//Attaches Pan servo to pin 9
	Tilt.attach(10);		//Attaches Tilt servo to pin 11
	Serial.begin(9600);
	Serial.print("A=[")		//Preparing the data to be written to the serial monitor in a format readable by MATLAB as a matrix, A.
}

void loop() 
{
	//Pan.writeMicroseconds(1000);
	//Pan.writeMicroseconds(1000);

//Where we could put pushbutton scan start
	for(int PanAngle=10; PanAngle<170; PanAngle+=10)
	{
		Pan.write(PanAngle);

		for(int TiltAngle=10; TiltAngle<170; TiltAngle+=10)
		Tilt.write(TiltAngle);										//Tilt the sensor
		delay(500);													//Give the servo time to reach its position
		//Collect Data
		Distance1=analogRead(SensorPin);
		delay(20);													//Stop between readings
		Distance2=analogRead(SensorPin);
		delay(20);													//Stop between readings
		Distance3=analogRead(SensorPin);
		delay(20);													//Stop between readings
		Distance4=analogRead(SensorPin);
		delay(20);													//Stop between readings
		Distance5=analogRead(SensorPin);
		//Average the distance readings
		TenXDistance=((Distance1 + Distance2 + Distance3 + Distance4 + Distance5)*10)/5  //Distances multiplied by 10 to keep values integers. Will be divided out in MATLAB. This works because x/5, where x is an integer, will have a maximum of one decimal point.
		
		//Print formatted data to serial monitor.


	}

}

