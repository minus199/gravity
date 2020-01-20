#include <Arduino.h>
#include "stepMotor.h"

StepMotor::StepMotor(MotorControlPin inPorts[4])
{
  for (int i = 0; i < 4; i++)
  {
    this->inPorts[i] = inPorts[i];
  }
}

StepMotor::~StepMotor(){}
void StepMotor::mount()
{
  for (int i = 0; i < 4; i++)
  {
    pinMode(this->inPorts[i], OUTPUT);
  }
}

void StepMotor::on() {}
void StepMotor::off() {}
void StepMotor::step(bool right)
{
  static byte out = 0x01; // Define a variable, use four low bit to indicate the state of port

  if (!right)
  {
    out != 0x08 ? out = out << 1 : out = 0x01;
  }
  else
  {
    out != 0x01 ? out = out >> 1 : out = 0x08;
  }
  
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(this->inPorts[i], (out & (0x01 << i)) ? HIGH : LOW);
  }
}
  // moveSteps(false, 32 * 64, 2);

