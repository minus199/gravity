#include <servo.h>

ServoMotor::ServoMotor(int posPin, int signalPin)
{
    this->posPin = posPin;
    this->signalPin = signalPin;
}

ServoMotor::~ServoMotor()
{
}

long ServoMotor::correlateValToMpu(MPUStats mpuStats)
{
    return map(mpuStats.acc.x, mpuStats.acc.xmax * -1, mpuStats.acc.xmax, 0, 180);
}

void ServoMotor::mount()
{
    servo.attach(this->signalPin);
}

void ServoMotor::unmount()
{
    servo.detach();
}

void ServoMotor::gotoDeg(long deg)
{
    this->servo.write(deg);
}
