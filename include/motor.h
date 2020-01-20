#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>


typedef uint8_t MotorControlPin; // on, off, speed
typedef uint8_t MotorDirectionPin;

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