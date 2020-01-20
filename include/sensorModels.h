#include <Arduino.h>

struct stats
{
  int16_t x = 0;
  int16_t xprev = 0;
  int16_t xsum = 0;
  int16_t xmax = 0;
  int16_t xavg = 0;
  int xdelta = 0;
  int xprevDelta = 0;
  int16_t xSampleCount = 0;

  int16_t y = 0;
  int16_t prevY = 0;
  int16_t sumY = 0;
  int16_t maxY = 0;
  int16_t avgY = 0;
  int deltaY = 0;
  int prevDeltaY = 0;
  int16_t ySampleCount = 0;

  int16_t z = 0;
  int16_t prevZ = 0;
  int16_t sumZ = 0;
  int16_t maxZ = 0;
  int16_t avgZ = 0;
  int deltaZ = 0;
  int prevDeltaZ = 0;
  int16_t zSampleCount = 0;
};
