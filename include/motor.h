#include <Arduino.h>

void setupMotor();
void loopMotor();
void moveOneStep(bool dir);
void moveSteps(bool dir, int steps, byte ms) ;
