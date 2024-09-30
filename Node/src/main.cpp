#include <Arduino.h>
#include <constants.h>
#include <globals.h>
#include <functions.h>
#include <LoRa.h>

RTC_DATA_ATTR int state_number = 0;

void initialSetup()
{
  pinMode(GPIO_NUM_13, INPUT); // Sensor Input
                               // Configure the two wake-up pins (GPIO 2 and GPIO 13)
  uint64_t wakeup_pins = (1ULL << DIO0) | (1ULL << SENSOR_INPUT);
  // Enable EXT1 wakeup for both pins, wake up when either pin goes HIGH
  esp_sleep_enable_ext1_wakeup(wakeup_pins, ESP_EXT1_WAKEUP_ANY_HIGH);
  Serial.println("Entering deep sleep...");
  state_number = 1;
  esp_deep_sleep_start();
}


void respond()
{
  Serial.println("Wake up reason: " + String(esp_sleep_get_wakeup_cause()));

  if (esp_sleep_get_wakeup_cause() == ESP_SLEEP_WAKEUP_EXT1)
  {
    uint64_t wakeup_pin_mask = esp_sleep_get_ext1_wakeup_status(); // Get wake-up status
    if (wakeup_pin_mask != 0)
    { // Ensure the wake-up cause was EXT1
      if (wakeup_pin_mask & (1ULL << SENSOR_INPUT))
      {
        Serial.println("GPIO 2 caused the wakeup.");
        sendPacket("sdeviceID");
        // Go back to deep sleep.
        state_number = 0;
        esp_deep_sleep_start();
      }
      if (wakeup_pin_mask & (1ULL << DIO0))
      {
        Serial.println("GPIO 13 caused the wakeup.");
        listenForPackets(LISTENING_INTERVAL);
      }
    }
  }
}
void runFunction(int state_number)
{
  void (*functionArray[])() = {initialSetup, respond};
  functionArray[state_number]();
}

void setup()
{
  setupSerial();
  initLora();
  runFunction(state_number);
}

void loop()
{
  // The ESP32 will enter deep sleep and not reach this point, will always stop after running setup().
}
