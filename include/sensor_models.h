#include <Arduino.h>

struct stats
{
  int16_t x = 0;
  int prevX = 0;
  int sumX = 0;
  int sampleCountX = 0;
  int avgX = 0;
  int deltaX = 0;
  int prevDeltaX = 0;
  
    int16_t y = 0;
  int prevY = 0;
  int sumY = 0;
  int sampleCountY = 0;
  int avgY = 0;
  int deltaY = 0;
int prevDeltaY = 0;
  
  int16_t z = 0;
  int prevZ = 0;
  int sumZ = 0;
  int sampleCountZ = 0;
  int avgZ = 0;
  int deltaZ = 0;
  int prevDeltaZ = 0;
};
