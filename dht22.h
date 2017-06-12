/* 
DHT library for the ESP8266, a port from the Adafruit library for the Arduino
MIT license
written by IoT Pipe
*/

#ifndef DHT22_H
#define DHT22_H

#include "ets_sys.h"
#include "osapi.h"
#include "os_type.h"
#include "user_config.h"
#include "mem.h"
#include "user_interface.h"

#include "gpio.h"
// Uncomment to enable printing out nice debug messages.
//#define DHT_DEBUG

// Setup debug printing macros.
#ifdef DHT_DEBUG
	#define LOG_DEBUG(message)		do {os_printf("[DHT-DEBUG] %s", message); os_printf("\r\n");} while (0)
	#define LOG_DEBUG_ARGS(message, args...)		do {os_printf("[DHT-DEBUG] "); os_printf(message, args); os_printf("\r\n");} while (0)
#else
	#define LOG_DEBUG(message) do {} while(0)
	#define LOG_DEBUG_ARGS(message, args...) do {} while(0)
#endif

// Define types of sensors.
#define DHT11 11
#define DHT22 22
#define DHT21 21
#define AM2301 21


static uint8_t data[5];
static uint8_t _pin, _type, _bit;
static uint32_t _lastreadtime, _maxcycles;
static bool _lastresult;
static uint32_t expectPulse(bool level);
static int ICACHE_FLASH_ATTR get_index(int pin);
static bool read();



void DHT_init(uint8_t pin, uint8_t type, uint8_t count);
void DHT_begin(void);
float readTemperature(bool S);
float readHumidity();
float ICACHE_FLASH_ATTR convertCtoF(float);
float ICACHE_FLASH_ATTR convertFtoC(float);

#endif
