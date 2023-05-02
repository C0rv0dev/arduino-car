#include "Motor.h"
Motor AppMotor;
#include "FunctionService.cpp"
AppFunctionSet AppFunction;
#include "MPU6050_data.h"
MPU6050_data AppMPU;

void setup() {
  // AppMotor.init_motor();
  // delay(2000);

  Serial.begin(9600);
  AppMPU.MPU_init();
  delay(2000);
  AppMPU.calibration();
}

void loop() {
  // for (AppFunction.Motion_Control = 0; AppFunction.Motion_Control < 2;
  //      AppFunction.Motion_Control = AppFunction.Motion_Control + 1) {
  //   AppFunctionSet_Controls(AppFunction.Motion_Control, 255);
  //   delay(1000);
  // }

  static float Yaw;
  AppMPU.getEulerAngles(&Yaw);
  Serial.print("Yaw:");
  Serial.println(Yaw);
}
