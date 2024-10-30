//define the pins used by the lora transceiver module and sensors
#define SS 5 
#define DIO0 GPIO_NUM_2 // Dont define just with numbers, use GPIO_NUM_X
#define SENSOR_INPUT GPIO_NUM_4 // Dont define just with numbers, use GPIO_NUM_X
#define SENSORSWITCH 32 // Switching the Sensor on and off.

//general parameters
#define LISTENING_INT_LOW 5000 // in milliseconds
#define LISTENING_INT_HIGH 6000 // in milliseconds
#define TEMP_CHECK_INTERVAL 0.5 // in minutes
#define WAITBEFORERESEND 10 // in seconds
#define RESETINTERVAL 15 // in minutes

//gsm
#define GPRS_APN "dialogbb" // Access Point Name

//mqtt
#define MQTT_SERVER "test.mosquitto.org"
#define MQTT_PORT 1883
#define MQTT_DEVICE_ID "firesense_hazards"
#define DATA_RECEPTION_TOPIC "firesense_hazards/message"
#define DATA_SENDING_TOPIC "firesense_hazards/message"
