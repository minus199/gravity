#include <Arduino.h>
#include <motor.h>


void directionControl(Motor motor, bool right)
{
    motor.on();
    motor.adjustSpeed(50);
    delay(2000);
    motor.changeDirection(right);
    delay(2000);
    motor.off();
}

// This function lets you control speed of the motors
void speedControl(Motor motor)
{
    motor.on();
    for (int i = 0; i < 100; i++)
    {
        motor.adjustSpeed(i);
        delay(20);
    }

    for (int i = 100; i < 0; --i)
    {
        motor.adjustSpeed(i);
        delay(20);
    }

    motor.off();
}

