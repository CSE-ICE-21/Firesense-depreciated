#include <functions.h>
#include <LoRa.h>

void setup() {
  setupSerial();
  initLora();
  // LoRa.onTxDone(onTxDone);
  // LoRa.onReceive(onReceive);
  LoRa.onCadDone(onCadDone);
  LoRa.onReceive(onReceive);
   // put the radio into CAD mode
   LoRa.channelActivityDetection();
  
}

void loop() {
  
}


