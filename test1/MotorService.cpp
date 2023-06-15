#include "Motor.h"

void Motor::init_motor(void) {
  pinMode(PIN_Motor_PWMA, OUTPUT);
  pinMode(PIN_Motor_PWMB, OUTPUT);
  pinMode(PIN_Motor_AIN_1, OUTPUT);
  pinMode(PIN_Motor_BIN_1, OUTPUT);
  pinMode(PIN_Motor_STBY, OUTPUT);
}

void Motor::controls(bool direction_A, float speed_A, bool direction_B,
                     float speed_B, bool enable_controls) {
  if (enable_controls == enable_control) {
    digitalWrite(PIN_Motor_STBY, HIGH);
    // A - Direita
    {
      switch (direction_A) 
      {
        case move_forward:
          digitalWrite(PIN_Motor_AIN_1, HIGH);
          analogWrite(PIN_Motor_PWMA, speed_A);
          break;

        case move_backward:
          digitalWrite(PIN_Motor_AIN_1, LOW);
          analogWrite(PIN_Motor_PWMA, speed_A);
          break;

        case stand_by:
          digitalWrite(PIN_Motor_STBY, LOW);
          analogWrite(PIN_Motor_PWMA, 0);
          break;

        default:
          digitalWrite(PIN_Motor_STBY, LOW);
          analogWrite(PIN_Motor_PWMA, 0);
          break;
      }
    }

    { // B - Esquerda
      switch (direction_B)
      {
        case move_forward:
          analogWrite(PIN_Motor_PWMB, speed_B);
          digitalWrite(PIN_Motor_BIN_1, HIGH);
          break;

        case move_backward:
          analogWrite(PIN_Motor_PWMB, speed_B);
          digitalWrite(PIN_Motor_BIN_1, LOW);
          break;

        case stand_by:
          analogWrite(PIN_Motor_PWMB, 0);
          digitalWrite(PIN_Motor_STBY, LOW);
          break;

        default:
          analogWrite(PIN_Motor_PWMB, 0);
          digitalWrite(PIN_Motor_STBY, LOW);
          break;
      }
    }
  } else {
      digitalWrite(PIN_Motor_STBY, LOW);
    return;
  }
}
