#include <Arduino.h>

//utils
void setupSerial();
void initLora();
String generateRandomID();
bool validateID(String id);
void runFunction(int state_number);
void sensorSetup();

// lora
void listenForPackets(unsigned long lowerbound, unsigned long upperbound);
void sendPacket( String message);