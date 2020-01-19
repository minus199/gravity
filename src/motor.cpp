#include <motor.h>

Motor::Motor(MotorControlPin cPin, MotorDirectionPin dPin1, MotorDirectionPin dPin2)
{
    pinMode(cPin, OUTPUT);
    pinMode(dPin1, OUTPUT);
    pinMode(dPin2, OUTPUT);
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

    analogWrite(this->cPin, (int)((255*precent)/100));
}

void Motor::changeDirection(bool right)
{
    digitalWrite(this->dPin1, right ? HIGH : LOW);
	digitalWrite(this->dPin2, !right ? HIGH : LOW);
}