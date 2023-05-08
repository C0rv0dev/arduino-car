#include "Transceiver.h"
#include <RF24.h>
RF24 radio(PIN_CE, PIN_CSN);

const byte address[6] = "00001";

void Transceiver::init_radio(void) {
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

bool Transceiver::radio_available() {
  return radio.available();
}

void Transceiver::read_data(int data[]) {
  return radio.read(&data, sizeof(data));
}
