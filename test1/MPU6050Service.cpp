#include "MPU6050_data.h"
#include "Wire.h"
#include <stdio.h>
MPU6050_data MPU6050Data;
#include "MPU6050.h"
MPU6050 accelgyro;

bool MPU6050_data::MPU_init(void) {
  Wire.begin();
  int chip_id = 0x00;
  int cout;

  do {
    chip_id = accelgyro.getDeviceID();
    Serial.print("MPU chip id: ");
    Serial.println(chip_id);
    delay(10);
    cout += 1;

    if (cout > 10) {
      return true;
    }
  } while (chip_id == 0x00 || chip_id == 0XFF);

  accelgyro.initialize();

  return false;
}

bool MPU6050_data::calibration(void) {
  unsigned short times = 100;

  for (int i = 0; i < times; i++) {
    gz = accelgyro.getRotationZ();
    gzo = gz;
  }

  gzo /= times;
  return false;
}

bool MPU6050_data::getEulerAngles(float *Yaw) {
  unsigned long now = millis();
  dt = (now - lastTime) / 1000.0;
  lastTime = now;

  gz = accelgyro.getRotationZ();
  float gyroz = -(gz - gzo) / 131.0;
  // if (< 0.65) {
  if (fabs(gyroz < 0.65)) {
    gyroz = 0.00;
  }
  agz += gyroz;
  *Yaw = agz;
  return false;
}
