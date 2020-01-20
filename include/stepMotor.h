#ifndef STEPMOTOR_H
#define STEPMOTOR_H

#include <Arduino.h>
#include <motor.h>

class StepMotor
{

private:
    uint8_t inPorts[4];

public:
    StepMotor(MotorControlPin inPorts[4]);
    ~StepMotor();

    void mount();
    void on();
    void off();
    void step(bool right);
};

#endif