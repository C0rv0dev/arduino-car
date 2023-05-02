#ifndef _MotorServiceLib_H_
#define _MotorServiceLib_H_

#include <Arduino.h>

// Motor
class Motor {
public:
  // initialize
  void init_motor(void);
  void controls(bool direction_A, float speed_A, bool direction_B,
                float speed_B, bool enable_controls);

private:
#define PIN_Motor_PWMA 5
#define PIN_Motor_PWMB 6
#define PIN_Motor_BIN_1 8
#define PIN_Motor_AIN_1 7
#define PIN_Motor_STBY 3

public:
#define max_speed 255
#define move_forward true
#define move_backward false
#define stand_by 3

#define enable_duration true
#define disable_duration false
#define enable_control true
#define disable_control false
};
#endif
