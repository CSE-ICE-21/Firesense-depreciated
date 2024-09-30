//define the pins used by the lora transceiver module

#define SS 5
#define RST 15
#define DIO0 GPIO_NUM_2 // Dont define just with numbers, use GPIO_NUM_X
#define SENSOR_INPUT GPIO_NUM_13 // Dont define just with numbers, use GPIO_NUM_X

#define LISTENING_INTERVAL 5000
#define SLEEP_AFTER_ACK 10 // Sleep for 10 minutes after receiving an ACK for a message.