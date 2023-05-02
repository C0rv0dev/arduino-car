#include "Motor.h"
Motor AppMotor;
#include "FunctionService.cpp"
AppFunctionSet AppFunction;

void setup() {
  AppMotor.init_motor();  
  delay(2000);
}

void loop() {
  for (AppFunction.Motion_Control = 0; AppFunction.Motion_Control < 2; AppFunction.Motion_Control = AppFunction.Motion_Control + 1) {
    AppFunctionSet_Controls(AppFunction.Motion_Control, 255);
    delay(1000);
  }
}
