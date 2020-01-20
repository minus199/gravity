#include <Arduino.h>
#include "MPU6050.h"
#include "sensorModels.h"
#include "accelometer.h"
#include "motor.h"
#include "dualMotors.h"

stats acc, gravity;
MPU6050 mpu;

void debugI2C_setup()
{
	// when you need to calibrate the gravity acceleration, you can set the offset here and eliminate the note
	// accelgyro.setXAccelOffset(-1200);
	// accelgyro.setYAccelOffset(-2500);
	// accelgyro.setZAccelOffset(1988);

	Serial.print("X.Y.Z offset :\t");
	Serial.print(mpu.getXAccelOffset());
	Serial.print("\t");
	Serial.print(mpu.getYAccelOffset());
	Serial.print("\t");
	Serial.print(mpu.getZAccelOffset());
	Serial.print("\n");
}

void setupMPU()
{
	Serial.print("Initializing I2C devices...");
	Wire.begin();
	Serial.print("2Initializing I2C devices...");

	mpu.initialize();
	Serial.print("...Testing device connections...");
	if (mpu.testConnection())
	{
		Serial.println("...MPU6050 connection successful");
	}
	debugI2C_setup();
}

long maxServoDeg = 180;
long currentServoDeg = 90;

void loopMPU(Motor *motor, StepMotor *stepMotor, Servo *xservo)
{
	mpu.getMotion6(&acc.x, &acc.y, &acc.z, &gravity.x, &gravity.y, &gravity.z);

	acc.xsum += acc.x;
	acc.xSampleCount += 1;
	acc.xavg = acc.xsum / acc.xSampleCount;
	acc.xdelta = acc.x - acc.xprev;
	acc.xmax = acc.xmax > abs(acc.x) ? acc.xmax : abs(acc.x);
	
	gravity.xsum += gravity.x;
	gravity.xSampleCount += 1;
	// gravity.avgX = gravity.sumX / gravity.sampleCountX;
	gravity.xdelta = gravity.x - gravity.xprev;

	float xAccRatio = ((float)acc.x / (float)acc.xmax);
	long newxServoDeg = map(acc.x, acc.xmax * -1, acc.xmax, 0, maxServoDeg);
	
	Serial.write('\r');
	Serial.printf("%7s", acc.x > 0 ? " ===> " : " <=== ");
	Serial.print("\tacc -> x: [");
	Serial.printf("%6d", acc.x);
	Serial.print("]\t x%: [");
	Serial.printf("%6d", xAccRatio);
	Serial.print("]\t servo next deg: [");
	Serial.printf("%6d", newxServoDeg);
	Serial.print("]\t\ty: [");
	Serial.printf("%6d", acc.y);
	Serial.print("]\t\tz: [");
	Serial.printf("%6d", acc.z);
	Serial.print("] \t\t");

	// Serial.print(xservo->readMicroseconds)
	Serial.write('\r');

	gravity.xprevDelta = gravity.xdelta;
	int minLeft = 89;
	int maxLeft = 0;
	
	int resetPos = 90;
	
	int minRight = 91;
	int maxRight = 180;

	//reset to full_left -> 0 to 90
	//reset to full_right -> 90 to 180
	//reset to full_left to full right -> 0 to 90
	//reset to full_left -> 0 to 90
	//reset to full_left -> 0 to 90

	if (acc.xmax > 1000)
	{
		
		xservo->write(newxServoDeg);
		delay(15);
		
	}
	// motor->adjustSpeed(newSpeed);
	/*
	for (int i = 0; i < 100; i++)
	{
		stepMotor->step(acc.x < 0);
		delay(3);
	}
	*/

	// motor->changeDirection(acc.x > 0);
	// moveSteps(acc.y > 0, 50, 2);
	/*
	if (acc.x > 0)
	{

		motor->adjustSpeed(20);
		motor->changeDirection(true);
	}
	else
	{
		motor->adjustSpeed(20);
		motor->changeDirection(false);
	}
*/
	// Serial.print("]\tdelta x: [");
	// Serial.printf("%6d", gravity.deltaX);
	// Serial.print("]\tp d avg x: [");
	// Serial.printf("%6d", gravity.prevDeltaX);

	// Serial.print("]\td sum x: [");
	// Serial.printf("%15d", gravity.sumX);
	// Serial.print("]\tsample count: [");
	// Serial.printf("%15d", gravity.sampleCountX);

	// Serial.print((gravity.x - gravity.prevDeltaX)/gravity.x);

	// Serial.print(z > 1 ? "BIG       ": "SMALL        ");
	// if (abs(deltaAvgAx/prevDeltaAx) > 0.5)
	// {

	//   Serial.print("\taX: [");
	//   Serial.printf("%6d", ax);
	//   Serial.print("]\tAvgAx: [");
	//   Serial.printf("%6d", avgAx);
	//   Serial.print("]\tdeltaAvgAx: [");
	//   Serial.printf("%6d", deltaAvgAx);
	//   Serial.print("]");
	// }

	// if (abs(deltaAvgAy - prevDeltaAy) > 100)
	// {
	//   Serial.printf("\taY: [");
	//   Serial.printf("%6d", ay);
	//   Serial.printf("]\tAvgY: [");
	//   Serial.printf("%6d", avgAy);
	//   Serial.print("]\tDelta AvgY: [");
	//   Serial.printf("%6d", deltaAvgAy);
	//   Serial.print("]");
	// }

	// delay(100);
	/*Serial.print("ax:");
   Serial.print(ax); 
   Serial.print(" | gx:");
   Serial.print(gx); 
   
   Serial.print("\tay:");
   Serial.print(ay); 
   Serial.print("\taz:");
   Serial.println(az); 
   */

	/*for (int j = 0; j < 8; j++) {
   // Output low level to latchPin
   digitalWrite(latchPin, LOW);
   // Send serial data to 74HC595
   shiftOut(dataPin, clockPin, LSBFIRST, x);
   // Output high level to latchPin, and 74HC595 will update the data to the parallel output port.
   digitalWrite(latchPin, HIGH);
   // make the variable move one bit to left once, then the bright LED move one step to the left once.
   x <<= 1;

   }*/
}
