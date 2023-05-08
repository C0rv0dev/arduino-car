#include <SPI.h>
#include "Motor.h"
Motor AppMotor;
#include "Transceiver.h"
Transceiver AppRadio;
#include "FunctionService.cpp"
AppFunctionSet AppFunction;

void setup() {
  Serial.begin(9600);
  Serial.println("Setting everything up...");
  AppRadio.init_radio();
  AppMotor.init_motor();
}

void loop() {
  if (AppRadio.radio_available()) {
    int data[2];
    AppRadio.read_data(data);
    handleControl(data[0], data[1]);
  } else {
    Serial.println("No Signal...");
    delay(100);
  }
}

void handleControl(int dirY, int dirX) {
  Serial.print("VRx: ");
  Serial.println(dirX);
  Serial.print("VRy: ");
  Serial.println(dirY);

  if (dirX == 517) {
    switch (dirY) {
    case 0:
      AppFunctionSet_Controls(Backward, 250);
      break;
    case 200:
      AppFunctionSet_Controls(Backward, 150);
      break;
    case 400:
      AppFunctionSet_Controls(Backward, 100);
      break;
    case 510:
      AppFunctionSet_Controls(Stop, 0);
      break;
    case 600:
      AppFunctionSet_Controls(Forward, 100);
      break;
    case 800:
      AppFunctionSet_Controls(Forward, 150);
      break;
    case 1000:
      AppFunctionSet_Controls(Forward, 250);
      break;
    }
  }

  if (dirY == 510) {
    switch (dirX) {
    case 0:
      AppFunctionSet_Controls(Left, 250);
      break;
    case 300:
      AppFunctionSet_Controls(Left, 150);
      break;
    case 510:
      AppFunctionSet_Controls(Left, 100);
      break;
    case 517:
      AppFunctionSet_Controls(Stop, 0);
      break;
    case 600:
      AppFunctionSet_Controls(Right, 100);
      break;
    case 800:
      AppFunctionSet_Controls(Right, 150);
      break;
    case 1000:
      AppFunctionSet_Controls(Right, 250);
      break;
    }
  }
}
