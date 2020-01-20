#include <motor.h>

Motor::Motor(MotorControlPin cPin, MotorDirectionPin dPin1, MotorDirectionPin dPin2)
{
    pinMode(cPin, OUTPUT);
    pinMode(dPin1, OUTPUT);
    pinMode(dPin2, OUTPUT);
    this->cPin = cPin;
    this->dPin1 = dPin1;
    this->dPin2 = dPin2;
    this->off();
}

Motor::~Motor()
{
}

void Motor::on()
{
    this->changeDirection(true);
}

void Motor::off()
{
    digitalWrite(this->dPin1, LOW);
    digitalWrite(this->dPin2, LOW);
}

void Motor::adjustSpeed(double precent)
{
     if (precent < 0 || precent > 100){
        Serial.print("Value must be a precentage(any number between 0 and 100, inclusive).");
    }

    int newSpeedAbs = (int)((255*precent)/100);
    analogWrite(this->cPin, newSpeedAbs);
}

void Motor::changeDirection(bool right)
{
    digitalWrite(this->dPin1, right ? HIGH : LOW);
	digitalWrite(this->dPin2, !right ? HIGH : LOW);
}