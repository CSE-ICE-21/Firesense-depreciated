#include <Arduino.h>

//utils
void setupSerial();
void initLora();
String generateRandomID();
bool validateID(String id);
void runFunction(int state_number);
void sensorSetup();
String getDeviceID();

// int readAnalogSensor(int pin, int numSamples = 10);
bool readDigitalSensor(int pin);

// Program
void systemReset(uint64_t resetInterval); // Reset the system after a certain time.

// lora
String listenForPackets(unsigned long lowerbound, unsigned long upperbound);
void sendPacket( String message);
