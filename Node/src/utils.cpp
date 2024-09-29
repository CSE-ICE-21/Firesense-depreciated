#include <Arduino.h>
#include <functions.h>
#include <constants.h>
#include <LoRa.h>

void setupSerial() { // Function to setup serial communication
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Sender");
}

void initLora(){
      //setup LoRa transceiver module
  LoRa.setPins(SS, RST, DIO0);
  
  //replace the LoRa.begin(---E-) argument with your location's frequency 
  //433E6 for Asia
  while (!LoRa.begin(433E6)) {
    Serial.println(".");
    delay(500);
  }
  LoRa.enableCrc();
  Serial.println("LoRa Initialization Completed!");
}
