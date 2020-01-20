#include <Arduino.h>
#include "MPU6050.h"
#include "sensorModels.h"
#include "accelometer.h"
#include "motor.h"
#include "dualMotors.h"

#include "servo.h"

MPUStats mpuStats;
MPU6050 mpu;

void printDebugI2CSetup()
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
	Serial.println("\n");
}

void printMPUDebug(long newxServoDeg)
{
	Serial.write('\r');
	Serial.printf("%7s", mpuStats.acc.x > 0 ? " ===> " : " <=== ");
	Serial.print("\tacc -> x: [");
	Serial.printf("%6d", mpuStats.acc.x);
	Serial.print("]\t servo next deg: [");
	Serial.printf("%6d", newxServoDeg);
	Serial.print("]\t\ty: [");
	Serial.printf("%6d", mpuStats.acc.y);
	Serial.print("]\t\tz: [");
	Serial.printf("%6d", mpuStats.acc.z);
	Serial.print("] \t\t");
	Serial.write('\r');
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
	printDebugI2CSetup();
}

void loopMPU(Motor *motor, StepMotor *stepMotor, ServoMotor *xservo)
{
	mpuStats.fromMPU(&mpu);
	long newxServoDeg = xservo->correlateValToMpu(mpuStats);
	printMPUDebug(newxServoDeg);
	if (mpuStats.acc.xmax > 5000)
	{
		
		xservo->gotoDeg(newxServoDeg);
		delay(15);
	}
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

/*for (int j = 0; j < 8; j++) {
   // Output low level to latchPin
   digitalWrite(latchPin, LOW);
   // Send serial data to 74HC595
   shiftOut(dataPin, clockPin, LSBFIRST, x);
   // Output high level to latchPin, and 74HC595 will update the data to the parallel output port.
   digitalWrite(latchPin, HIGH);
   // make the variable move one bit to left once, then the bright LED move one step to the left once.
   x <<= 1;

   }
}
*/
