// LIDAR_FINAL.ino
#include "Servo.h"

int Position=0;
int PanAngle=0;				//Will also be the output Pan Angle. Pan Angle measured from right to left. All the way right would theoretically be 0. Theta
int TiltAngle=0;
int TiltAngleOut=0;			//Output Tilt Angle in degrees. Will be measured in degrees from the positive vertical. Pointing directly ahead would be 90; straight up would be 0. Phi
int Distance1=0;
int Distance2=0;
int Distance3=0;
int Distance4=0;
int Distance5=0;
int TenXDistance=0;			//Final Distance (has been averaged and multiplied by 10)
int SensorPin=A0;			//Pin the distance sensor is plugged in to. MUST BE ANALOG INPUT
int RunOnce=0;				//Will be used to make the for loops only run once
Servo Pan;
Servo Tilt;


void setup()
{
  analogReference(EXTERNAL);
  Pan.attach(9);			//Attaches Pan servo to pin 9
  Tilt.attach(10);			//Attaches Tilt servo to pin 11
  Serial.begin(9600);
  Serial.print("A=[");		//Preparing the data to be written to the serial monitor in a format readable by MATLAB as a matrix, A.
}

void loop() 
{
	if (RunOnce ==0)
	{
		for(int PanAngle=30; PanAngle<155; PanAngle+=1)
		{
			Pan.write(PanAngle);

			for(int TiltAngle=70; TiltAngle<115; TiltAngle+=1)
			{
		      Tilt.write(TiltAngle);										//Tilt the sensor
		      delay(100);													//Give the servo time to reach its position
		      //Collect Data
		      Distance1=analogRead(SensorPin);
		      delay(10);													//Stop between readings
		      Distance2=analogRead(SensorPin);
		      delay(10);													//Stop between readings
		      Distance3=analogRead(SensorPin);
		      delay(10);													//Stop between readings
		      Distance4=analogRead(SensorPin);
		      delay(10);													//Stop between readings
		      Distance5=analogRead(SensorPin);

		      //Average the distance readings
		      TenXDistance=((Distance1 + Distance2 + Distance3 + Distance4 + Distance5)*10)/5;  //Distances multiplied by 10 to keep values integers. Will be divided out in MATLAB. This works because x/5, where x is an integer, will have a maximum of one decimal point.

		      //Calculated outputted tilt angle

		      TiltAngleOut=180-TiltAngle;

		      //Print formatted data to serial monitor.
		      Serial.print(PanAngle);				// The data will be exported to matlab as a matrix, A.
		      Serial.print(",");					// The matrix will have the following form
		      Serial.print(TiltAngleOut);			//		PanAngle1	TiltAngle1	Distance1*10
		      Serial.print(",");					//		PanAngle2	TiltAngle2	Distance2*10
		      Serial.print(TenXDistance);			//			...			...			...
		      Serial.println(";");				// These should correspond to spherical coordinates (theta, phi, r) 
  			}
		}
		Serial.print("]");
		RunOnce++;
	}
}