#ifndef SERVOMOTOR_H_
#define SERVOMOTOR_H_

#include "sensorModels.h"
#include "MPU6050.h"
#include <Servo.h>

class ServoMotor
{
private:
    Servo servo;
    int posPin;    // variable to store the servo position
    int signalPin; // define the pin of servo signal line

    const long maxServoDeg = 180;
    long currentServoDeg = 90;
    MPUStats *mpuStats;

	const int resetPos = 90;
    const int minLeft = 89;
	const int maxLeft = 0;
	const int minRight = 91;
	const int maxRight = 180;
public:
    ServoMotor(int posPin, int signalPin);
    ~ServoMotor();
    long correlateValToMpu(MPUStats mpuStats);
    void mount();
    void unmount();
    void gotoDeg(long deg);
};

#endif