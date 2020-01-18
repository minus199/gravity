#include <Arduino.h>
#include <dualMotors.h>

Motor motorA(9, 8, 7);
Motor motorB(3, 5, 4);

void setupMotors()
{
    motorA.off();
    // motorB.off();
}

void directionControl()
{
    motorA.on();
    motorA.adjustSpeed(50);
    delay(2000);
    motorA.changeDirection(false);
    delay(2000);
    motorA.off();
}

// This function lets you control speed of the motors
void speedControl()
{
    motorA.on();
    for (int i = 0; i < 100; i++)
    {
        motorA.adjustSpeed(i);
        delay(20);
    }

    for (int i = 100; i < 0; --i)
    {
        motorA.adjustSpeed(i);
        delay(20);
    }

    motorA.off();
}

void loopMotors()
{
    directionControl();
    delay(1000);
    speedControl();
    delay(1000);
}