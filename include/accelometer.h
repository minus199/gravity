#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"

#include "motor.h"
#include "stepMotor.h"
#include <Servo.h>

void setupMPU();
void loopMPU(Motor *motor, StepMotor *stepMotor, Servo *xservo);