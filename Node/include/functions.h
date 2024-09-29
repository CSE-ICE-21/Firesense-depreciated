#include <Arduino.h>
//utils
void setupSerial();
void initLora();
void loraCallBacksRegister();

// lora
void onCadDone(boolean signalDetected);
void onReceive(int packetSize);