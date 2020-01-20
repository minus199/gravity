#include <Arduino.h>

#include "accelometer.h"

Motor motorA(6, 5, 4), motorB(10, 12, 11);
MotorControlPin x[4] = {11, 10, 9, 8};
StepMotor stepMotor(x);

Servo xservo;	  // create servo object to control a servo
int xservoPos = 0; // variable to store the servo position
int xservoPin = 8; // define the pin of servo signal line

Servo yservo;	  // create servo object to control a servo
int yservoPos = 0; // variable to store the servo position
int yservoPin = 9; // define the pin of servo signal line

//map(value, fromLow, fromHigh, toLow, toHigh)


void setup()
{
	Serial.begin(9600);
	setupMPU();
	motorA.off();
	// motorB.off();
	stepMotor.mount();
	xservo.attach(xservoPin); // attaches the servo on servoPin to the servo object
	yservo.attach(yservoPin); // attaches the servo on servoPin to the servo object
}

void loop()
{
	/*for (xservoPos = 50; xservoPos <= 90; xservoPos += 1)
	{ // goes from 0 degrees to 180 degrees
		// in steps of 1 degree
		xservo.write(xservoPos); // tell servo to go to position in variable 'pos'
		yservo.write(xservoPos); // tell servo to go to position in variable 'pos'

		delay(100); // waits 15ms for the servo to reach the position
	}

	for (xservoPos = 100; xservoPos >= 90; --xservoPos)
	{ // goes from 0 degrees to 180 degrees
		// in steps of 1 degree
		xservo.write(xservoPos); // tell servo to go to position in variable 'pos'
		yservo.write(xservoPos); // tell servo to go to position in variable 'pos'

		delay(100); // waits 15ms for the servo to reach the position
	}

	xservo.write(0); // tell servo to go to position in variable 'pos'
	yservo.write(0); // tell servo to go to position in variable 'pos'
	delay(10000);
*/
	// motorA.on();

	// directionControl(motorA);
	// speedControl(motorA);
	loopMPU(&motorA, &stepMotor, &xservo);

	// loopMotor();
}

/*
// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

void setup() {
	// Set all the motor control pins to outputs
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}



// This function lets you control spinning direction of motors
void directionControl() {
	// Set motors to maximum speed
	// For PWM maximum possible values are 0 to 255
	analogWrite(enA, 255);
	analogWrite(enB, 255);

	// Turn on motor A & B
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
	delay(2000);
	
	// Now change motor directions
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
	delay(2000);
	
	// Turn off motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}

// This function lets you control speed of the motors
void speedControl() {
	// Turn on motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
	
	// Accelerate from zero to maximum speed
	for (int i = 0; i < 256; i++) {
		analogWrite(enA, i);
		analogWrite(enB, i);
		delay(20);
	}
	
	// Decelerate from maximum speed to zero
	for (int i = 255; i >= 0; --i) {
		analogWrite(enA, i);
		analogWrite(enB, i);
		delay(20);
	}
	
	// Now turn off motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}
void loop() {
	directionControl();
	delay(1000);
	speedControl();
	delay(1000);
}*/
