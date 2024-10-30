#define TINY_GSM_MODEM_SIM900
#define SerialMon Serial
#define SerialAT Serial2
#define TINY_GSM_DEBUG SerialMon
#define TINY_GSM_USE_GPRS true
#define TINY_GSM_USE_WIFI false

#include <TinyGsmClient.h>
#include <PubSubClient.h>
#include <constants.h>

#include <StreamDebugger.h>
StreamDebugger debugger(SerialAT, SerialMon);
TinyGsm modem(debugger);

TinyGsmClient client(modem);
PubSubClient mqtt(client);

void mqttCallback(char *topic, byte *payload, unsigned int len)
{
    SerialMon.print("Message arrived [");
    SerialMon.print(topic);
    SerialMon.print("]: ");
    SerialMon.write(payload, len);
    SerialMon.println();

    //   // Only proceed if incoming message's topic matches
    //   if (String(topic) == topic) {
    //     // Do whatever needed
    //   }
}

boolean mqttConnect()
{
    SerialMon.print("Connecting to ");
    SerialMon.print(MQTT_SERVER);

    // Connect to MQTT Broker
    boolean status = mqtt.connect(MQTT_DEVICE_ID);

    if (status == false)
    {
        SerialMon.println(" fail");
        return false;
    }
    SerialMon.println(" success");
    mqtt.publish(DATA_SENDING_TOPIC, "GsmClientTest started");
    mqtt.subscribe(DATA_RECEPTION_TOPIC);
    return mqtt.connected();
}

void setupGSM()
{
    modem.setBaud(115200);
    delay(6000);
    SerialMon.println("Initializing modem...");
    String modemInfo = modem.getModemInfo();
    SerialMon.print("Modem Info: ");
    // SerialMon.println(modemInfo);
    modem.init();
    SerialMon.print("Waiting for network...");
    if (!modem.waitForNetwork())
    {
        SerialMon.println(" fail waiting for network!");
        delay(2000);
        return;
    }
    SerialMon.println(" success");

    if (modem.isNetworkConnected())
    {
        SerialMon.println("Network connected");
    }

     SerialMon.print(F("Connecting to "));
  SerialMon.print(GPRS_APN);
  if (!modem.gprsConnect(GPRS_APN)) {
    SerialMon.println(" failed to connect to GPRS");
    delay(10000);
    return;
  }
  SerialMon.println(" success");

  if (modem.isGprsConnected()) { SerialMon.println("GPRS connected"); }

  // MQTT Broker setup
  mqtt.setServer(MQTT_SERVER, 1883);
  mqtt.setCallback(mqttCallback);
}