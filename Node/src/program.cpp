#include <globals.h>
#include <functions.h>
#include <constants.h>
#include <LoRa.h>

void _systemReset(uint64_t resetInterval) // Reset the system after a certain time.
{
    Serial.println("Shutting down the Node...Will reset and restart after " + String(resetInterval) + " minutes.");
    system_state = 0;
    esp_sleep_enable_timer_wakeup(resetInterval * 60000000);
    LoRa.end();
    delay(1000);
    esp_deep_sleep_start();
}

void _initialSetup()
{
    esp_sleep_enable_ext0_wakeup(DIO0, HIGH);                      // Enable wakeup on LoRa message reception.
    esp_sleep_enable_timer_wakeup(TEMP_CHECK_INTERVAL * 60000000); // Enable wakeup on timer to check temperature sensor.
    system_state = 1;
    LoRa.receive(); // Put the radio into receive mode
    Serial.println("Entering deep sleep...");
    esp_deep_sleep_start();
}

void _respond()
{
    if (esp_sleep_get_wakeup_cause() == ESP_SLEEP_WAKEUP_EXT0)
    {
        Serial.println("Incoming LoRa message detected!");
        String msg = listenForPackets(LISTENING_INT_LOW, LISTENING_INT_HIGH);
        if (validateID(msg))
        {
            sendPacket(msg);
            _systemReset(RESETINTERVAL);
        }
        else
        {
            _initialSetup();
        }
    }
    else if (esp_sleep_get_wakeup_cause() == ESP_SLEEP_WAKEUP_TIMER)
    {
        Serial.println("Fire sensor check Wakeup.");
        digitalWrite(SENSORSWITCH, HIGH); // Turn on the sensor
        delay(1000);                      // Wait for the sensor to stabilize
        int reading = readDigitalSensor(SENSOR_INPUT);
        digitalWrite(SENSORSWITCH, LOW); // Turn off the sensor
        if (reading == HIGH)
        {
            Serial.println("Fire Hazard Detected.");
            sendPacket("FIRE");
            _systemReset(RESETINTERVAL);
        }
        else
        {
            Serial.println("All good.");
            // Go back to deep sleep.
            _initialSetup();
        }
    }
}
void runFunction(int state_number)
{
    void (*functionArray[])() = {_initialSetup, _respond};
    functionArray[state_number]();
}
