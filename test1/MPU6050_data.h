#ifndef _MPU6050_data_H_
#define _MPU6050_data_H_
#include <Arduino.h>

class MPU6050_data {
public:
  bool MPU_init(void);
  bool calibration(void);
  bool getEulerAngles(float *Yaw);

public:
  int gz;
  unsigned long now, lastTime = 0;
  float dt;
  float agz = 0;
  long gzo = 0;
};

extern MPU6050_data MPU6050Data;

#endif
