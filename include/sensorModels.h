#ifndef SENSOR_MODELS_H_
#define SENSOR_MODELS_H_

#include <Arduino.h>
#include "MPU6050.h"

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

struct MPUStats{
  private:
    void setX(stats *statsInstance){
      statsInstance->xsum += statsInstance->x;
      statsInstance->xSampleCount += 1;
      statsInstance->xavg = statsInstance->xsum / statsInstance->xSampleCount;
      statsInstance->xdelta = statsInstance->x - statsInstance->xprev;
      statsInstance->xmax = statsInstance->xmax > abs(statsInstance->x) ? statsInstance->xmax : abs(statsInstance->x);
    }

  public:
    stats acc, gravity;
    void fromMPU(MPU6050 *mpu){
        mpu->getMotion6(&acc.x, &acc.y, &acc.z, &gravity.x, &gravity.y, &gravity.z);
        setX(&acc);
        setX(&gravity);
    }

};

#endif
