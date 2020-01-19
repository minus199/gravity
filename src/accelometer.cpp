#include <Arduino.h>
#include "MPU6050.h"
#include "sensorModels.h"

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

void setupI2C()
{
	Serial.print("Initializing I2C devices...");
	Wire.begin();
	mpu.initialize();
	Serial.print("...Testing device connections...");
	if (mpu.testConnection())
	{
		Serial.println("...MPU6050 connection successful");
	}
	debugI2C_setup();
}

void loop22()
{
	mpu.getMotion6(&acc.x, &acc.y, &acc.z, &gravity.x, &gravity.y, &gravity.z);

	acc.sumX += acc.x;
	acc.sampleCountX += 1;
	acc.avgX = acc.sumX / acc.sampleCountX;
	acc.deltaX = acc.x - acc.prevX;

	gravity.sumX += gravity.x;
	gravity.sampleCountX += 1;
	gravity.avgX = gravity.sumX / gravity.sampleCountX;
	gravity.deltaX = gravity.x - gravity.prevX;
	// moveSteps(acc.y > 0, 50, 2);

	if (acc.x > 0)
	{
		if (abs(acc.x) < 500)
		{
			Serial.printf("%7s", "---");
		}
		else
		{
			Serial.printf("%7s", acc.x > 0 ? " ===> " : " <=== ");
		}
	}
	else
	{
		if (abs(acc.y) < 400)
		{
			Serial.printf("%7s", "---");
		}
		else
		{
			Serial.printf("%7s", acc.y > 0 ? " ^^^^ " : " VVVV ");
		}
	}
	Serial.print("\tacc -> x: [");
	Serial.printf("%6d", acc.x);
	Serial.print("]\ty: [");
	Serial.printf("%6d", acc.y);
	Serial.print("] \t\t");
	gravity.prevDeltaX = gravity.deltaX;

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
	Serial.write('\r');

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
