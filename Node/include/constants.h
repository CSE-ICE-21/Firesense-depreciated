//define the pins used by the lora transceiver module and sensors
#define SS 5
#define RST 22
#define DIO0 GPIO_NUM_2 // Dont define just with numbers, use GPIO_NUM_X
#define SENSOR_INPUT GPIO_NUM_15 // Dont define just with numbers, use GPIO_NUM_X

#define LISTENING_INT_LOW 2000
#define LISTENING_INT_HIGH 5000