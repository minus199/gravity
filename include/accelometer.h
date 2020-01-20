#ifndef ACCELO_H_
#define ACCELO_H_

#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"

#include "motor.h"
#include "stepMotor.h"
#include <servo.h>

void setupMPU();
void loopMPU(Motor *motor, StepMotor *stepMotor, ServoMotor *xservo);

#endif