#include <LoRa.h>
#include <functions.h>
#include <globals.h>
#include <constants.h>

// Function to listen for incoming LoRa packets.
String listenForPackets(unsigned long lowerbound, unsigned long upperbound)
{
    unsigned long startTime = millis(); // Record the start time
    while (millis() - startTime < random(lowerbound, upperbound))
    { // Run for loopDuration milliseconds
        int packetSize = LoRa.parsePacket();
        if (packetSize > 0)
        {
            // Received a packet
            Serial.print("Received packet: ");
            String LoRaData;
            while (LoRa.available())
            {
                LoRaData = LoRa.readString(); // Read the packet data as a string
                Serial.println(LoRaData);
            }
            if (validateID(LoRaData))
            {
                return LoRaData;
            }
        }
    }
    Serial.println("No any valid packet received");
    return "NULL";
}

void sendSystemMessage(String message)
{
    while (true)
    {
        LoRa.beginPacket();

        LoRa.print(message); // Send the device ID as the packet content
        Serial.println("Sending packet: " + message);

        if (LoRa.endPacket() == 1)
        {
            Serial.println("Packet sent successfully");
            String reply = listenForPackets(LISTENING_INT_LOW, LISTENING_INT_HIGH);
            if (reply == "NULL")
            {
                Serial.println("All neighbours notified to reset.");
                break;
            }
        }
        else
        {
            Serial.println("Packet failed to send");
            delay(WAITBEFORERESEND * random(1000, 1500)); // Wait before resending
        }
    }
}
