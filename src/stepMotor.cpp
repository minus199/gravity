#include <Arduino.h>
int latchPin = 9;  // Pin connected to ST_CP of 74HC595（Pin12）
int clockPin = 10; // Pin connected to SH_CP of 74HC595（Pin11）
int dataPin = 8;   // Pin connected to DS of 74HC595（Pin14）


int outPorts[] = {6, 5, 4, 3};

void setupMotor() {

	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
  // set pins to output
  for (int i = 0; i < 4; i++) {
    pinMode(outPorts[i], OUTPUT);
  }
}

void moveOneStep(bool dir) {
  // Define a variable, use four low bit to indicate the state of port
  static byte out = 0x01;
  // Decide the shift direction according to the rotation direction
  if (dir) {  // ring shift left
    out != 0x08 ? out = out << 1 : out = 0x01;
  }
  else {      // ring shift right
    out != 0x01 ? out = out >> 1 : out = 0x08;
  }
  // Output singal to each port
  for (int i = 0; i < 4; i++) {
    digitalWrite(outPorts[i], (out & (0x01 << i)) ? HIGH : LOW);
  }
}

void moveSteps(bool dir, int steps, byte ms) {
  for (int i = 0; i < steps; i++) {
    moveOneStep(dir); // Rotate a step
    delay(ms);        // Control the speed
  }
}

void move(byte x)
{
	digitalWrite(latchPin, LOW);
	shiftOut(dataPin, clockPin, LSBFIRST, x);
	digitalWrite(latchPin, HIGH);
}


void loopMotor()
{
  // Rotate a full turn
  
  delay(1000);
  // Rotate a full turn towards another direction
  moveSteps(false, 32 * 64, 2);
  delay(1000);
}
