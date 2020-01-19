#ifndef MOTOR_H
#define MOTOR_H

typedef int MotorControlPin; // on, off, speed
typedef int MotorDirectionPin;
#include <Arduino.h>

class Motor
{

private:
    MotorControlPin cPin;
    MotorDirectionPin dPin1;
    MotorDirectionPin dPin2;

public:
    Motor(MotorControlPin cPin, MotorDirectionPin dPin1, MotorDirectionPin dPin2);
    ~Motor();

    void on();
    void off();
    void adjustSpeed(double precent);
    void changeDirection(bool right);
};


#endif