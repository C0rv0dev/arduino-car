#include "Motor.h"

extern Motor Motor;

enum Controls {
  Forward,
  Backward,
  Left,
  Right,
  LeftForward,
  LeftBackward,
  RightForward,
  RightBackward,
  Stop
};

struct AppFunctionSet {
  Controls Motion_Control;
};

extern AppFunctionSet AppFunction;

static void AppFunctionSet_Controls(Controls direction, int func_speed) {
  static int directionRecord = 0;
  int Kp, UpperLimit;
  int speed = func_speed;

  switch (direction) {
  case Forward:
    Motor.controls(move_forward, speed, move_forward, speed, enable_control);
    break;
  case Backward:
    Motor.controls(move_backward, speed, move_backward, speed, enable_control);
    break;
  case Left:
    Motor.controls(move_forward, speed, move_backward, speed, enable_control);
    break;
  case Right:
    Motor.controls(move_backward, speed, move_forward, speed, enable_control);
    break;
  case LeftForward:
    Motor.controls(move_forward, speed, move_forward, speed / 2,
                    enable_control);
    break;
  case LeftBackward:
    Motor.controls(move_backward, speed, move_backward, speed, enable_control);
    break;
  case RightForward:
    Motor.controls(move_forward, speed, move_forward, speed, enable_control);
    break;
  case RightBackward:
    Motor.controls(move_backward, speed, move_backward, speed, enable_control);
    break;
  case Stop:
    Motor.controls(stand_by, 0, stand_by, 0, enable_control);
    break;
  default:
    break;
  }
}
