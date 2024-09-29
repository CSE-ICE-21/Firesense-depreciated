#include <LoRa.h>
#include <functions.h>



void onCadDone(boolean signalDetected) {
  if (signalDetected) {
    Serial.println("Channel is busy,recieving the message and waiting for a random time");
    // LoRa.receive();
  }
  else {
    Serial.println("Channel is free, sending message");
    // LoRa.channelActivityDetection();
  }
}

void onReceive(int packetSize) {
  // received a packet
  Serial.print("Received packet '");
  // read packet
  for (int i = 0; i < packetSize; i++) {
    Serial.print((char)LoRa.read());
  }
  // put the radio into CAD mode
  LoRa.channelActivityDetection();
}