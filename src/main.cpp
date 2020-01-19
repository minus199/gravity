#include <Arduino.h>
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include "dualMotors.h"
#include <motor.h>

Motor motorA(9, 8, 7);
Motor motorB(3, 5, 4);

void setup()
{
	Serial.begin(9600);
	// setupI2C();
	motorA.off();
	// motorB.off();
}

void loop()
{
	directionControl(motorA);
	delay(1000);
	speedControl(motorA);
	delay(1000);
}
