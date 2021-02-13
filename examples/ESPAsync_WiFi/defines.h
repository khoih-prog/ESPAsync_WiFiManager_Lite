/****************************************************************************************************************************
  defines.h
  For ESP8266 / ESP32 boards

  ESPAsync_WiFiManager_Lite (https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite) is a library 
  for the ESP32/ESP8266 boards to enable store Credentials in EEPROM/SPIFFS/LittleFS for easy 
  configuration/reconfiguration and autoconnect/autoreconnect of WiFi and other services without Hardcoding.

  Built by Khoi Hoang https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite
  Licensed under MIT license      
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if !( ESP8266 || ESP32)
  #error This code is intended to run only on the ESP8266/ESP32 boards ! Please check your Tools->Board setting.
#endif

/* Comment this out to disable prints and save space */
#define ESP_WM_LITE_DEBUG_OUTPUT      Serial

#define _ESP_WM_LITE_LOGLEVEL_        2

#define USING_MRD                     true

#if USING_MRD
  #define MULTIRESETDETECTOR_DEBUG      true
  
  // Number of seconds after reset during which a
  // subseqent reset will be considered a double reset.
  #define MRD_TIMEOUT                   10
  
  // RTC Memory Address for the DoubleResetDetector to use
  #define MRD_ADDRESS                   0
  #warning Using MULTI_RESETDETECTOR
#else
  #define DOUBLERESETDETECTOR_DEBUG     true
  
  // Number of seconds after reset during which a
  // subseqent reset will be considered a double reset.
  #define DRD_TIMEOUT                   10
  
  // RTC Memory Address for the DoubleResetDetector to use
  #define DRD_ADDRESS                   0
  #warning Using DOUBLE_RESETDETECTOR
#endif

/////////////////////////////////////////////

// LittleFS has higher priority than SPIFFS
  #define USE_LITTLEFS    true
  #define USE_SPIFFS      false

/////////////////////////////////////////////

// Force some params
#define TIMEOUT_RECONNECT_WIFI                    10000L
#define RESET_IF_CONFIG_TIMEOUT                   true
#define CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET    5

// Config Timeout 120s (default 60s)
#define CONFIG_TIMEOUT                            120000L

#define USE_DYNAMIC_PARAMETERS                    true

#include <ESPAsync_WiFiManager_Lite.h>

#if ESP8266 
  #define HOST_NAME   "ESP8266Async-Control"
#else
  #define HOST_NAME   "ESP32Async-Control"
#endif

#ifdef LED_BUILTIN
  #define LED_PIN     LED_BUILTIN
#else
  #define LED_PIN     13
#endif

#endif      //defines_h
