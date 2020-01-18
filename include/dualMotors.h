#include <Arduino.h>

typedef int MotorControlPin; // on, off, speed
typedef int MotorDirectionPin;

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
    this->changeDirection();
}

void Motor::off()
{
    digitalWrite(this->dPin1, LOW);
    digitalWrite(this->dPin2, LOW);
}

void Motor::adjustSpeed(double precent)
{
     if (precent < 0 || precent > 100){
        throw "Value must be a precentage(any number between 0 and 100, inclusive).";
    }

    analogWrite(this->cPin, (int)((255*precent)/100));
}

void Motor::changeDirection(bool right)
{
    digitalWrite(this->dPin1, right ? HIGH : LOW);
	digitalWrite(this->dPin2, !right ? HIGH : LOW);
}

void setupMotors();
void loopMotors();