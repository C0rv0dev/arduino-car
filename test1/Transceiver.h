#ifndef _TransceiverServiceLib_H_
#define _TransceiverServiceLib_H_

#include <Arduino.h>

// Transceiver
class Transceiver {
public:
  // initialize
  void init_radio(void);
  bool radio_available();
  void read_data(int[]);

private:
#define PIN_CE 4
#define PIN_CSN 9
};
#endif
