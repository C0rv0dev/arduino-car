#include "Motor.h"
#include <IRremote.h>
Motor AppMotor;
#include "FunctionService.cpp"
AppFunctionSet AppFunction;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(9, ENABLE_LED_FEEDBACK);
  AppMotor.init_motor();
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    handleControl(IrReceiver.decodedIRData.decodedRawData);
    IrReceiver.resume();
  }
}

void handleControl(unsigned long btn) {
  switch (btn) {
  case 3158572800:
    AppFunctionSet_Controls(Forward, 150);
    break;
  case 3141861120:
    AppFunctionSet_Controls(Backward, 150);
    break;
  case 3108437760:
    AppFunctionSet_Controls(Left, 100);
    break;
  case 3927310080:
    AppFunctionSet_Controls(Right, 100);
    break;
  case 3208707840:
    AppFunctionSet_Controls(Stop, 0);
    break;
  default:
    AppFunctionSet_Controls(Stop, 0);
    break;
  }
}
