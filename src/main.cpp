#include <Arduino.h>
#include "accelometer.h"

Motor motorA(6, 5, 4), motorB(10, 12, 11);
MotorControlPin x[4] = {11, 10, 9, 8};
StepMotor stepMotor(x);
ServoMotor xservo(0, 8);
ServoMotor yservo(0, 9);

//map(value, fromLow, fromHigh, toLow, toHigh)

void setup()
{
	Serial.begin(9600);
	setupMPU();
	motorA.off();
	motorB.off();
	// stepMotor.mount();
	xservo.mount();
}

void loop()
{
	// motorA.on();
	// directionControl(motorA);
	// speedControl(motorA);
	loopMPU(&motorA, &stepMotor, &xservo);
}