## ESPAsync_WiFiManager_Lite Library (Light Weight Credentials / WiFiManager for ESP32/ESP8266)

[![arduino-library-badge](https://www.ardu-badge.com/badge/ESPAsync_WiFiManager_Lite.svg?)](https://www.ardu-badge.com/ESPAsync_WiFiManager_Lite)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/ESPAsync_WiFiManager_Lite.svg)](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/ESPAsync_WiFiManager_Lite.svg)](http://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/issues)


<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>

---
---

## Table of Contents

* [Important Change from v1.9.0](#Important-Change-from-v190)
  * [For v1.9.0 and up](#For-v190-and-up)
* [Why do we need this ESPAsync_WiFiManager_Lite library](#why-do-we-need-this-espasync_wifimanager_lite-library)
  * [Features](#features)
  * [Why Async is better](#why-async-is-better)
  * [Currently supported Boards](#currently-supported-boards)
* [Changelog](changelog.md) 
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Note for Platform IO using ESP32 LittleFS](#note-for-platform-io-using-esp32-littlefs)
* [HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)](#howto-use-analogread-with-esp32-running-wifi-andor-bluetooth-btble)
  * [1. ESP32 has 2 ADCs, named ADC1 and ADC2](#1--esp32-has-2-adcs-named-adc1-and-adc2)
  * [2. ESP32 ADCs functions](#2-esp32-adcs-functions)
  * [3. ESP32 WiFi uses ADC2 for WiFi functions](#3-esp32-wifi-uses-adc2-for-wifi-functions)
* [How It Works](#how-it-works)
* [How to use](#how-to-use)
  * [ 1. Basic usage](#1-basic-usage)
  * [ 2. Add custom parameters](#2-add-custom-parameters)
  * [ 3. Not using custom parameters](#3-not-using-custom-parameters)
  * [ 4. To open Config Portal](#4-to-open-config-portal)
  * [ 5. To use different AP WiFi Channel](#5-to-use-different-ap-wifi-channel)
  * [ 6. To use different static AP IP from default](#6-to-use-different-static-ap-ip-from-default)
  * [ 7. To use custom DHCP HostName](#7-to-use-custom-dhcp-hostname)
  * [ 8. To use custom HTML Style](#8-to-use-custom-html-style)
  * [ 9. To use custom Head Elements](#9-to-use-custom-head-elements)
  * [10. To use CORS Header](#10-to-use-cors-header)
  * [11. To use and input only one set of WiFi SSID and PWD](#11-to-use-and-input-only-one-set-of-wifi-ssid-and-pwd)
    * [11.1 If you need to use and input only one set of WiFi SSID/PWD](#111-if-you-need-to-use-and-input-only-one-set-of-wifi-ssidpwd)
    * [11.2 If you need to use both sets of WiFi SSID/PWD](#112-if-you-need-to-use-both-sets-of-wifi-ssidpwd)
  * [12. To enable auto-scan of WiFi networks for selection in Configuration Portal](#12-to-enable-auto-scan-of-wifi-networks-for-selection-in-configuration-portal)
    * [12.1 Enable auto-scan of WiFi networks for selection in Configuration Portal](#121-enable-auto-scan-of-wifi-networks-for-selection-in-configuration-portal)
    * [12.2 Disable manually input SSIDs](#122-disable-manually-input-ssids)
    * [12.3 Select maximum number of SSIDs in the list](#123-select-maximum-number-of-ssids-in-the-list)
  * [13. To avoid blocking in loop when WiFi is lost](#13-To-avoid-blocking-in-loop-when-wifi-is-lost)
    * [13.1 Max times to try WiFi per loop](#131-max-times-to-try-wifi-per-loop)
    * [13.2 Interval between reconnection WiFi if lost](#132-interval-between-reconnection-wifi-if-lost)
  * [14. Not using Board_Name on Config_Portal](#14-Not-using-Board_Name-on-Config_Portal) 
* [Examples](#examples)
  * [ 1. ESPAsync_WiFi](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi)
  * [ 2. ESPAsync_WiFi_MQTT](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi_MQTT)
* [So, how it works?](#so-how-it-works)
* [Important Notes](#important-notes)
* [How to use default Credentials and have them pre-loaded onto Config Portal](#how-to-use-default-credentials-and-have-them-pre-loaded-onto-config-portal)
  * [1. To always load Default Credentials and override Config Portal data](#1-to-always-load-default-credentials-and-override-config-portal-data)
  * [2. To load Default Credentials when there is no valid Credentials](#2-to-load-default-credentials-when-there-is-no-valid-credentials)
  * [3. Example of Default Credentials](#3-example-of-default-credentials)
* [How to add dynamic parameters from sketch](#how-to-add-dynamic-parameters-from-sketch)
* [Important Notes for using Dynamic Parameters' ids](#important-notes-for-using-dynamic-parameters-ids)
* [Example ESPAsync_WiFi](#example-espasync_wifi)
  * [1. File ESPAsync_WiFi.ino](#1-file-espasync_wifiino)
  * [2. File defines.h](#2-file-definesh)
  * [3. File Credentials.h](#3-file-credentialsh)
  * [4. File dynamicParams.h](#4-file-dynamicparamsh)
* [Debug Termimal Output Samples](#debug-terminal-output-samples)
  * [1. ESPAsync_WiFi_MQTT on ESP32_DEV](#1-espasync_wifi_mqtt-on-esp32_dev)
    * [1.1 No Config Data => Open Config Portal](#11-no-config-data--open-config-portal)
    * [1.2 Got valid Credentials from Config Portal then connected to WiFi](#12-got-valid-credentials-from-config-portal-then-connected-to-wifi)
    * [1.3 Lost a WiFi and autoconnect to another WiFi AP](#13-lost-a-wifi-and-autoconnect-to-another-wifi-ap)
  * [2. ESPAsync_WiFi_MQTT on ESP8266_NODEMCU](#2-espasync_wifi_mqtt-on-esp8266_nodemcu)
    * [2.1 No Config Data => Open Config Portal](#21-no-config-data--open-config-portal)
    * [2.2 Got valid Credentials from Config Portal then connected to WiFi](#22-got-valid-credentials-from-config-portal-then-connected-to-wifi)
    * [2.3 Lost a WiFi and autoconnect to another WiFi AP](#23-lost-a-wifi-and-autoconnect-to-another-wifi-ap)
  * [3. ESPAsync_WiFi_MQTT on ESP32S2_DEV](#3-espasync_wifi_mqtt-on-esp32s2_dev)
    * [3.1 No Config Data => Open Config Portal](#31-no-config-data--open-config-portal)
    * [3.2 Got valid Credentials from Config Portal then connected to WiFi](#32-got-valid-credentials-from-config-portal-then-connected-to-wifi)
    * [3.3 Lost a WiFi and autoconnect to another WiFi AP](#33-lost-a-wifi-and-autoconnect-to-another-wifi-ap)
  * [4. ESPAsync_WiFi_MQTT on ESP32S2_DEV to demo MultiResetDetector](#4-espasync_wifi_mqtt-on-esp32s2_dev-to-demo-multiresetdetector)
    * [4.1 MultiResetDetected => Open Config Portal](#41-multiresetdetected--open-config-portal)
    * [4.2 Got valid Credentials from Config Portal then connected to WiFi](#42-got-valid-credentials-from-config-portal-then-connected-to-wifi)
  * [5. ESPAsync_WiFi_MQTT on ESP32_DEV to demo WiFi Scan](#5-espasync_wifi_mqtt-on-esp32_dev-to-demo-wifi-scan)
    * [5.1 MRD/DRD => Open Config Portal](#51-mrddrd--open-config-portal)
    * [5.2 Config Data Saved => Connection to Adafruit MQTT](#52-config-data-saved--connection-to-adafruit-mqtt)
  * [6. ESPAsync_WiFi on ESP32S3_DEV](#6-ESPAsync_WiFi-on-ESP32S3_DEV) **New**
  * [7. ESPAsync_WiFi on ESP32C3_DEV using LittleFS](#7-ESPAsync_WiFi-on-ESP32C3_DEV-using-LittleFS) **New**
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Important Change from v1.9.0

#### For v1.9.0 and up

##### Fix ESP32 chipID

ESP32 `chipID` is now correct and unique. The previous releases' 32-bit wrong `chipID` is mainly the 24-bit `Organizational Unique Identifier` (OUI) plus 8 bits from the correct chipID. That's why `ESP_getChipId()` function can return duplicated values if the boards are from the same batch.

For example

```
Chip_ID_64 : 0x98F4AB085288
chipOUI    : 0x98F4AB
chipId     : 0x85288
getEfuseMac: 0x885208ABF498
```

##### Libraries to be installed manually by downloading zip

Remove unavailable items from depends field of `library.properties`, such as `ESP Async WebServer`,`ESP AsyncTCP` and `AsyncTCP`.

Check 
- [**Arduino Library Registry** #147](https://github.com/me-no-dev/AsyncTCP/issues/147)
- [**Arduino library manager** #139](https://github.com/me-no-dev/ESPAsyncTCP/issues/139)
- [**Available via Arduino Library Manager?** #158](https://github.com/me-no-dev/ESPAsyncTCP/issues/158)
- [**Add ESPAsyncTCP to the Arduino Library Manager** #168](https://github.com/me-no-dev/ESPAsyncTCP/issues/168)

---
---

### Why do we need this [ESPAsync_WiFiManager_Lite library](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite)

#### Features

If you have used one of the full-fledge Async WiFiManagers such as :

1. [`Alan Steremberg's ESPAsyncWiFiManager`](https://github.com/alanswx/ESPAsyncWiFiManager)
2. [`Khoi Hoang ESPAsync_WiFiManager`](https://github.com/khoih-prog/ESPAsync_WiFiManager)

and have to write **complicated callback functions** to save custom parameters in SPIFFS/LittleFS/EEPROM, you'd appreciate the simplicity of this Light-Weight Credentials / WiFiManager.

This is a Light-Weight Credentials / WiFi Connection Manager for ESP32 and ESP8266 boards, designed to use the better and faster **asynchronous** [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer) instead of (ESP8266)WebServer.

The [ESPAsync_WiFiManager_Lite library](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite) permits the **easy addition of custom parameters to be configured in Config Portal**. The parameters then will be saved automatically, **without the complicated callback functions** to handle data saving / retrieving.

You can also specify DHCP HostName, static AP and STA IP. Use much less memory compared to full-fledge WiFiManager. Config Portal will be auto-adjusted to match the number of dynamic custom parameters. Credentials are saved in LittleFS, SPIFFS or EEPROM.

The web configuration portal, served from the `ESP32/ESP8266 WiFi` is operating as an access point (AP) with configurable static IP address or use default IP Address of 192.168.4.1

New recent features:

- **MultiWiFi** feature for configuring/auto(re)connecting **ESP32/ESP8266 WiFi** to the available MultiWiFi APs at runtime.
- **Multi/DoubleDetectDetector** feature to force Config Portal when multi/double reset is detected within predetermined time, default 10s.
- **Powerful-yet-simple-to-use feature to enable adding dynamic custom parameters** from sketch and input using the same Config Portal. Config Portal will be auto-adjusted to match the number of dynamic parameters.
- Optional default **Credentials as well as Dynamic parameters to be optionally autoloaded into Config Portal** to use or change instead of manually input.
- Dynamic custom parameters to be saved **automatically in non-volatile memory, such as LittleFS, SPIFFS or EEPROM.**.
- Configurable **Config Portal Title** to be either BoardName or default undistinguishable names.
- Examples are designed to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device.
- Control Config Portal from software or Virtual Switches
- To permit autoreset after configurable timeout if DRD/MRD or non-persistent forced-CP
- Use new ESP32 LittleFS features
- **Scan WiFi networks** for selection in Configuration Portal


Thanks to this [ESPAsync_WiFiManager_Lite library](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite) is based on and sync'ed with [`ESP_WiFiManager_Lite`](https://github.com/khoih-prog/ESP_WiFiManager_Lite), all the features currently supported by [`ESP_WiFiManager_Lite`](https://github.com/khoih-prog/ESP_WiFiManager_Lite) will be available.


### Why Async is better

- Using asynchronous network means that you can handle **more than one connection at the same time**
- You are called once the request is ready and parsed
- When you send the response, you are **immediately ready** to handle other connections while the server is taking care of sending the response in the background
- **Speed is OMG**
- **Easy to use API, HTTP Basic and Digest MD5 Authentication (default), ChunkedResponse**
- Easily extensible to handle **any type of content**
- Supports Continue 100
- Async WebSocket plugin offering different locations without extra servers or ports
- Async EventSource (Server-Sent Events) plugin to send events to the browser
- URL Rewrite plugin for conditional and permanent url rewrites
- ServeStatic plugin that supports cache, Last-Modified, default index and more
- Simple template processing engine to handle templates

To appreciate the power of the [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer) and underlying Async libraries, please compare the more efficient [Async_ESP32_FSWebServer example](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/Async_ESP32_FSWebServer) example with the complicated twin [ESP32_FSWebServer](https://github.com/khoih-prog/ESP_WiFiManager/tree/master/examples/ESP32_FSWebServer).


#### Currently supported Boards

This [**ESPAsync_WiFiManager_Lite** library](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite) currently supports these following boards:

 1. **ESP8266 and ESP32-based boards using EEPROM, SPIFFS or LittleFS**.
 2. **ESP32-S2 (ESP32-S2 Saola, AI-Thinker ESP-12K, etc.) using EEPROM, SPIFFS or LittleFS**.
 3. **ESP32-C3 (ARDUINO_ESP32C3_DEV) using EEPROM, SPIFFS or LittleFS**.
 4. **ESP32-S3 (ESP32S3_DEV, ESP32_S3_BOX, UM TINYS3, UM PROS3, UM FEATHERS3, etc.) using EEPROM, SPIFFS or LittleFS**.

---
---

## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`ESP8266 Core 3.1.1+`](https://github.com/esp8266/Arduino) for ESP8266-based boards. [![Latest release](https://img.shields.io/github/release/esp8266/Arduino.svg)](https://github.com/esp8266/Arduino/releases/latest/). To use ESP8266 core 2.7.1+ for LittleFS.
 3. [`ESP32 Core 2.0.6+`](https://github.com/espressif/arduino-esp32) for ESP32-based boards. [![Latest release](https://img.shields.io/github/release/espressif/arduino-esp32.svg)](https://github.com/espressif/arduino-esp32/releases/latest/)
 4. [Forked ESPAsyncWebServer](https://github.com/khoih-prog/ESPAsyncWebServer). **To install manually for Arduino IDE**
 5. [`ESPAsyncDNSServer v1.0.0+`](https://github.com/khoih-prog/ESPAsyncDNSServer/releases/tag/v1.0.0) for all ESP32/ESP8266-based boards.
 6. [`ESPAsyncTCP v1.2.2+`](https://github.com/me-no-dev/ESPAsyncTCP) for ESP8266-based boards. **To install manually, not via Arduino IDE Library Manager**
 7. [`AsyncTCP v1.1.1+`](https://github.com/me-no-dev/AsyncTCP) for ESP32-based boards. **To install manually, not via Arduino IDE Library Manager**
 8. [`ESP_DoubleResetDetector v1.3.2+`](https://github.com/khoih-prog/ESP_DoubleResetDetector) if using DRD feature. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/ESP_DoubleResetDetector.svg?)](https://www.ardu-badge.com/ESP_DoubleResetDetector).
 9. [`ESP_MultiResetDetector v1.3.2+`](https://github.com/khoih-prog/ESP_MultiResetDetector) if using MRD feature. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/ESP_MultiResetDetector.svg?)](https://www.ardu-badge.com/ESP_MultiResetDetector).
10. [`LittleFS_esp32 v1.0.6+`](https://github.com/lorol/LITTLEFS) for ESP32-based boards using LittleFS with ESP32 core **v1.0.5-**. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/LittleFS_esp32.svg?)](https://www.ardu-badge.com/LittleFS_esp32). **Notice**: This [`LittleFS_esp32 library`](https://github.com/lorol/LITTLEFS) has been integrated to Arduino [ESP32 core v1.0.6+](https://github.com/espressif/arduino-esp32/tree/master/libraries/LITTLEFS) and **you don't need to install it if using ESP32 core v1.0.6+**

---

## Installation

### Use Arduino Library Manager

The best and easiest way is to use `Arduino Library Manager`. Search for [**ESPAsync_WiFiManager_Lite**](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite), then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/ESPAsync_WiFiManager_Lite.svg?)](https://www.ardu-badge.com/ESPAsync_WiFiManager_Lite) for more detailed instructions.

### Manual Install

1. Navigate to [**ESPAsync_WiFiManager_Lite**](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite) page.
2. Download the latest release `ESPAsync_WiFiManager_Lite-main.zip`.
3. Extract the zip file to `ESPAsync_WiFiManager_Lite-main` directory 
4. Copy the whole 
  - `ESPAsync_WiFiManager_Lite-main` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO:

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**ESPAsync_WiFiManager_Lite** library](https://registry.platformio.org/libraries/khoih-prog/ESPAsync_WiFiManager_Lite) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/ESPAsync_WiFiManager_Lite/installation). Search for **ESPAsync_WiFiManager_Lite** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---


### Note for Platform IO using ESP32 LittleFS

#### Necessary only for esp32 core v1.0.6-

From esp32 core v1.0.6+, [`LittleFS_esp32 v1.0.6`](https://github.com/lorol/LITTLEFS) has been included and this step is not necessary anymore.

In Platform IO, to fix the error when using [`LittleFS_esp32 v1.0`](https://github.com/lorol/LITTLEFS) for ESP32-based boards with ESP32 core v1.0.4- (ESP-IDF v3.2-), uncomment the following line

from

```cpp
//#define CONFIG_LITTLEFS_FOR_IDF_3_2   /* For old IDF - like in release 1.0.4 */
```

to

```cpp
#define CONFIG_LITTLEFS_FOR_IDF_3_2   /* For old IDF - like in release 1.0.4 */
```

It's advisable to use the latest [`LittleFS_esp32 v1.0.5+`](https://github.com/lorol/LITTLEFS) to avoid the issue.

Thanks to [Roshan](https://github.com/solroshan) to report the issue in [Error esp_littlefs.c 'utime_p'](https://github.com/khoih-prog/ESPAsync_WiFiManager/issues/28) 

---
---


### HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)

Please have a look at [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to have more detailed description and solution of the issue.

#### 1.  ESP32 has 2 ADCs, named ADC1 and ADC2

#### 2. ESP32 ADCs functions

- `ADC1` controls ADC function for pins **GPIO32-GPIO39**
- `ADC2` controls ADC function for pins **GPIO0, 2, 4, 12-15, 25-27**

#### 3.. ESP32 WiFi uses ADC2 for WiFi functions

Look in file [**adc_common.c**](https://github.com/espressif/esp-idf/blob/master/components/driver/adc_common.c#L61)

> In `ADC2`, there're two locks used for different cases:
> 1. lock shared with app and Wi-Fi:
>    ESP32:
>         When Wi-Fi using the `ADC2`, we assume it will never stop, so app checks the lock and returns immediately if failed.
>    ESP32S2:
>         The controller's control over the ADC is determined by the arbiter. There is no need to control by lock.
> 
> 2. lock shared between tasks:
>    when several tasks sharing the `ADC2`, we want to guarantee
>    all the requests will be handled.
>    Since conversions are short (about 31us), app returns the lock very soon,
>    we use a spinlock to stand there waiting to do conversions one by one.
> 
> adc2_spinlock should be acquired first, then adc2_wifi_lock or rtc_spinlock.


- In order to use `ADC2` for other functions, we have to **acquire complicated firmware locks and very difficult to do**
- So, it's not advisable to use `ADC2` with WiFi/BlueTooth (BT/BLE).
- Use `ADC1`, and pins **GPIO32-GPIO39**
- If somehow it's a must to use those pins serviced by `ADC2` (**GPIO0, 2, 4, 12, 13, 14, 15, 25, 26 and 27**), use the **fix mentioned at the end** of [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to work with ESP32 WiFi/BlueTooth (BT/BLE)


---
---

## How It Works

- The [**ESPAsync_WiFi**](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi) example shows how it works and should be used as the basis for a sketch that uses this library.
- The concept of [**ESPAsync_WiFi**](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi) is that a new `ESP32/ESP8266 WiFi` will start a WiFi configuration portal when powered up, but has no valid stored Credentials or can't connect to WiFi APs after a pre-determined time.
- There are 6 more custom parameters added in the sketch which you can use in your program later. In the example, they are: 2 sets of Blynk Servers and Tokens, Blynk Port and MQTT Server.
- Using any WiFi enabled device with a browser (computer, phone, tablet) connect to the newly created AP and type in the configurable AP IP address (default 192.168.4.1). The Config Portal AP channel (default 10) is also configurable to avoid conflict with other APs.
- The Config Portal is **auto-adjusted** to fix the 4 static parameters (WiFi SSIDs/PWDs) as well as 6 more dynamic custom parameters.
- After the custom data entered, and **Save** button pressed, the configuration data will be saved in host's non-volatile memory, then the board reboots.
- If there is valid stored Credentials, it'll go directly to connect to one of the **MultiWiFi APs** without starting / using the Config Portal.
- `ESP32/ESP8266 WiFi` will try to connect. If successful, the dynamic DHCP and/or configured static IP address will be displayed in the configuration portal. 
- The `ESP32/ESP8266 WiFi` Config Portal network and Web Server will shutdown to return control to the sketch code.
- In the operation, if the current WiFi connection is lost because of any reason, the system will **auto(Re)connect** to the remaining WiFi AP.
- **If system can't connect to any of the 2 WiFi APs, the Config Portal will start**, after some pre-determined time, to permit user to update the Credentials.

---

### How to use

#### 1. Basic usage

- Include in your sketch

```cpp
// Must be before #include <ESPAsync_WiFiManager_Lite.h>
#include <ESPAsync_WiFiManager_Lite.h>

ESPAsync_WiFiManager_Lite* ESPAsync_WiFiManager;
```

#### 2. Add custom parameters

- To add custom parameters, just add

https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/blob/2902e0bfbd5c61194a98d81da3a47e155c106138/examples/ESPAsync_WiFi/dynamicParams.h#L13-L74


#### 3. Not using custom parameters

- If you don't need to add dynamic parameters, use the following in sketch

```cpp
#define USE_DYNAMIC_PARAMETERS      false
```

#### 4. To open Config Portal

- When you want to open a config portal, just add

```cpp
ESPAsync_WiFiManager = new ESPAsync_WiFiManager_Lite();
ESPAsync_WiFiManager->begin();
```

#### 5. To use different AP WiFi Channel

- To not use default AP WiFi Channel 10 to avoid conflict with other WiFi APs :

```cpp
ESPAsync_WiFiManager->setConfigPortalChannel(newChannel);
```

- To use random AP WiFi Channel to avoid conflict with other WiFi APs : 

```cpp
ESP_WiFiManager->setConfigPortalChannel(0);
```

#### 6. To use different static AP IP from default

- To use different static AP IP (not use default `192.168.4.1`), call

```cpp
ESPAsync_WiFiManager->setConfigPortalIP(IPAddress(xxx,xxx,xxx,xxx));
```

#### 7. To use custom DHCP HostName

- To set custom DHCP HostName :
 
```cpp
// Set customized DHCP HostName
ESPAsync_WiFiManager->begin("SAMD_ABCDEF");
```
 
or just use the default Hostname, for example "ESP_XXXXXX" for SAMD

```cpp
// Or use default Hostname "ESP_XXXXXX"
ESPAsync_WiFiManager->begin();
```

#### 8. To use custom HTML Style

```cpp
const char NewCustomsStyle[] /*PROGMEM*/ = "<style>div,input{padding:5px;font-size:1em;}input{width:95%;}body{text-align: center;}\
button{background-color:blue;color:white;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}</style>";

...

ESPAsync_WiFiManager->setCustomsStyle(NewCustomsStyle);
```

#### 9. To use custom Head Elements


```cpp
ESPAsync_WiFiManager->setCustomsHeadElement("<style>html{filter: invert(10%);}</style>");
```

#### 10. To use CORS Header

```cpp
ESPAsync_WiFiManager->setCORSHeader("Your Access-Control-Allow-Origin");
```


While in AP mode, connect to it using its `SSID` (ESP_XXXXXX) / `Password` ("MyESP_XXXXXX"), then open a browser to the Portal AP IP, default `192.168.4.1`, configure wifi then click **Save**. The Credentials / WiFi connection information will be saved in non-volatile memory. It will then autoconnect.


Once Credentials / WiFi network information is saved in the host non-volatile memory, it will try to autoconnect to WiFi every time it is started, without requiring any function calls in the sketch.

#### 11. To use and input only one set of WiFi SSID and PWD

#### 11.1 If you need to use and input only one set of WiFi SSID/PWD

```cpp
// Permit input only one set of WiFi SSID/PWD. The other can be "NULL or "blank"
// Default is false (if not defined) => must input 2 sets of SSID/PWD
#define REQUIRE_ONE_SET_SSID_PW       true
```

But it's always advisable to use and input both sets for reliability.
 
#### 11.2 If you need to use both sets of WiFi SSID/PWD

```cpp
// Permit input only one set of WiFi SSID/PWD. The other can be "NULL or "blank"
// Default is false (if not defined) => must input 2 sets of SSID/PWD
#define REQUIRE_ONE_SET_SSID_PW       false
```

#### 12. To enable auto-scan of WiFi networks for selection in Configuration Portal

#### 12.1 Enable auto-scan of WiFi networks for selection in Configuration Portal


```cpp
#define SCAN_WIFI_NETWORKS                  true
```

The manual input of SSIDs is default enabled, so that users can input arbitrary SSID, not only from the scanned list. This is for the sample use-cases in which users can input the known SSIDs of another place, then send the boards to that place. The boards can connect to WiFi without users entering Config Portal to re-configure.

#### 12.2 Disable manually input SSIDs

```cpp
// To disable manually input SSID, only from a scanned SSID lists
#define MANUAL_SSID_INPUT_ALLOWED           false
```

This is for normal use-cases in which users can only select an SSID from a scanned list of SSIDs to avoid typo mistakes and/or security.

#### 12.3 Select maximum number of SSIDs in the list

The maximum number of SSIDs in the list is seletable from 2 to 15. If invalid number of SSIDs is selected, the default number of 10 will be used.


```cpp
// From 2-15
#define MAX_SSID_IN_LIST                    8
```

#### 13. To avoid blocking in loop when WiFi is lost

#### 13.1 Max times to try WiFi per loop

To define max times to try WiFi per loop() iteration. To avoid blocking issue in loop()

Default is 1 if not defined, and minimum is forced to be 1.

To use, uncomment in `defines.h`. 

Check [retries block the main loop #18](https://github.com/khoih-prog/WiFiManager_NINA_Lite/issues/18#issue-1094004380)

```cpp
#define MAX_NUM_WIFI_RECON_TRIES_PER_LOOP     2
```

#### 13.2 Interval between reconnection WiFi if lost

Default is no interval between reconnection WiFi times if lost WiFi. Max permitted interval will be 10mins.

Uncomment to use. Be careful, WiFi reconnection will be delayed if using this method.

Only use whenever urgent tasks in loop() can't be delayed. But if so, it's better you have to rewrite your code, e.g. using higher priority tasks.

Check [retries block the main loop #18](https://github.com/khoih-prog/WiFiManager_NINA_Lite/issues/18#issuecomment-1006197561)

```cpp
#define WIFI_RECON_INTERVAL                   30000     // 30s
```

#### 14. Not using Board_Name on Config_Portal

Default is `true`. Just change to `false` to not using `Board_Name` on Config_Portal

https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/blob/2902e0bfbd5c61194a98d81da3a47e155c106138/examples/ESPAsync_WiFi/defines.h#L125-L130

---
---

### Examples

 1. [ESPAsync_WiFi](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi)
 2. [ESPAsync_WiFi_MQTT](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi_MQTT)

---
---

## So, how it works?

In `Configuration Portal Mode`, it starts an AP called `ESP_WXXXXXX`. Connect to it using the `configurable password` you can define in the code. For example, `MyESP_WXXXXXX` (see examples):

After you connected, please, go to http://192.168.4.1 or newly configured AP IP, you'll see this `Main` page:

<p align="center">
    <img src="https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/raw/main/pics/Main.png">
</p>

Enter your credentials, 

### 1. Without SCAN_WIFI_NETWORKS

Enter your credentials, 

<p align="center">
    <img src="https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/raw/main/pics/Input.png">
</p>

or

<p align="center">
    <img src="https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/raw/main/pics/MQTT.png">
</p>

### 2. With SCAN_WIFI_NETWORKS


<p align="center">
    <img src="https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/raw/main/pics/Input_With_Scan.png">
</p>


then click `Save`. 

<p align="center">
    <img src="https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/raw/main/pics/Save.png">
</p>

The WiFi Credentials will be saved and the board connect to the selected WiFi AP.

If you're already connected to a listed WiFi AP and don't want to change anything, just select `Exit` from the `Main` page to reboot the board and connect to the previously-stored AP. The WiFi Credentials are still intact.

---

### Important Notes

1. Now you can use special chars such as **~, !, @, #, $, %, ^, &, _, -, space,etc.** thanks to [brondolin](https://github.com/brondolin) to provide the amazing fix in [**Blynk_WM**](https://github.com/khoih-prog/Blynk_WM) to permit input special chars such as **%** and **#** into data fields. See [Issue 3](https://github.com/khoih-prog/Blynk_WM/issues/3).
2. The SSIDs, Passwords must be input (or to make them different from **blank**). Otherwise, the Config Portal will re-open until those fields have been changed. If you don't need any field, just input anything or use duplicated data from similar field.
3. WiFi password min length now is 8, max length is 63 chars according to WPA2 standard.

---

### How to use default Credentials and have them pre-loaded onto Config Portal

See this example and modify as necessary

#### 1. To always load [Default Credentials](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi_MQTT/Credentials.h) and override Config Portal data

```cpp
// Used mostly for development and debugging. FORCES default values to be loaded each run.
// Config Portal data input will be ignored and overridden by DEFAULT_CONFIG_DATA
bool LOAD_DEFAULT_CONFIG_DATA = true;
```

#### 2. To load [Default Credentials](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi_MQTT/Credentials.h) when there is no valid Credentials.

Config Portal data input will be override DEFAULT_CONFIG_DATA

```cpp
// Used mostly once debugged. Assumes good data already saved in device.
// Config Portal data input will be override DEFAULT_CONFIG_DATA
bool LOAD_DEFAULT_CONFIG_DATA = false;
```

#### 3. Example of [Default Credentials](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi_MQTT/Credentials.h)

```cpp
/// Start Default Config Data //////////////////

/*
#define SSID_MAX_LEN      32
//From v1.0.3, WPA2 passwords can be up to 63 characters long.
#define PASS_MAX_LEN      64

typedef struct
{
  char wifi_ssid[SSID_MAX_LEN];
  char wifi_pw  [PASS_MAX_LEN];
}  WiFi_Credentials;

#define NUM_WIFI_CREDENTIALS      2

// Configurable items besides fixed Header, just add board_name 
#define NUM_CONFIGURABLE_ITEMS    ( ( 2 * NUM_WIFI_CREDENTIALS ) + 1 )
////////////////

typedef struct Configuration
{
  char header         [16];
  WiFi_Credentials  WiFi_Creds  [NUM_WIFI_CREDENTIALS];
  char board_name     [24];
  int  checkSum;
} ESP_WM_LITE_Configuration;
*/

#define TO_LOAD_DEFAULT_CONFIG_DATA      false

#if TO_LOAD_DEFAULT_CONFIG_DATA

// This feature is primarily used in development to force a known set of values as Config Data
// It will NOT force the Config Portal to activate. Use DRD or erase Config Data with ESPAsync_WiFiManager.clearConfigData()

// Used mostly for development and debugging. FORCES default values to be loaded each run.
// Config Portal data input will be ignored and overridden by DEFAULT_CONFIG_DATA
//bool LOAD_DEFAULT_CONFIG_DATA = true;

// Used mostly once debugged. Assumes good data already saved in device.
// Config Portal data input will be override DEFAULT_CONFIG_DATA
bool LOAD_DEFAULT_CONFIG_DATA = false;


ESP_WM_LITE_Configuration defaultConfig =
{
  //char header[16], dummy, not used
#if ESP8266 
  "ESP8266_Async",
#else
  "ESP32_Async",
#endif

  // WiFi_Credentials  WiFi_Creds  [NUM_WIFI_CREDENTIALS];
  // WiFi_Credentials.wifi_ssid and WiFi_Credentials.wifi_pw
  "SSID1",  "password1",
  "SSID2",  "password2",
  //char board_name     [24];

#if ESP8266 
  "ESP8266_Async-Control",
#else
  "ESP32_Async-Control",
#endif

  // terminate the list
  //int  checkSum, dummy, not used
  0
  /////////// End Default Config Data /////////////
};

#else

bool LOAD_DEFAULT_CONFIG_DATA = false;

ESP_WM_LITE_Configuration defaultConfig;

#endif    // TO_LOAD_DEFAULT_CONFIG_DATA

/////////// End Default Config Data /////////////
```

### How to add dynamic parameters from sketch

Example of [Default dynamicParams](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi_MQTT/dynamicParams.h)

- To add custom parameters, just modify the example below

```cpp
#include "defines.h"

// USE_DYNAMIC_PARAMETERS defined in defined.h

/////////////// Start dynamic Credentials ///////////////

//Defined in <ESPAsync_WiFiManager_Lite.h>
/**************************************
  #define MAX_ID_LEN                5
  #define MAX_DISPLAY_NAME_LEN      16

  typedef struct
  {
  char id             [MAX_ID_LEN + 1];
  char displayName    [MAX_DISPLAY_NAME_LEN + 1];
  char *pdata;
  uint8_t maxlen;
  } MenuItem;
**************************************/

#if USE_DYNAMIC_PARAMETERS

#define AIO_SERVER_LEN       20
#define AIO_SERVERPORT_LEN   6
#define AIO_USERNAME_LEN     20
#define AIO_KEY_LEN          40

// 
#define AIO_PUB_TOPIC_LEN    40
#define AIO_SUB_TOPIC_LEN    40

char AIO_SERVER     [AIO_SERVER_LEN + 1]        = "io.adafruit.com";
char AIO_SERVERPORT [AIO_SERVERPORT_LEN + 1]    = "1883";     //1883, or 8883 for SSL
char AIO_USERNAME   [AIO_USERNAME_LEN + 1]      = "private";
char AIO_KEY        [AIO_KEY_LEN + 1]           = "private";

char AIO_PUB_TOPIC  [AIO_PUB_TOPIC_LEN + 1]     = "/feeds/Temperature";
char AIO_SUB_TOPIC  [AIO_SUB_TOPIC_LEN + 1]     = "/feeds/LED_Control";

MenuItem myMenuItems [] =
{
  { "svr", "AIO_SERVER",      AIO_SERVER,     AIO_SERVER_LEN },
  { "prt", "AIO_SERVERPORT",  AIO_SERVERPORT, AIO_SERVERPORT_LEN },
  { "usr", "AIO_USERNAME",    AIO_USERNAME,   AIO_USERNAME_LEN },
  { "key", "AIO_KEY",         AIO_KEY,        AIO_KEY_LEN },
  { "pub", "AIO_PUB_TOPIC",   AIO_PUB_TOPIC,  AIO_PUB_TOPIC_LEN },
  { "sub", "AIO_SUB_TOPIC",   AIO_SUB_TOPIC,  AIO_SUB_TOPIC_LEN },
};

uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;

#else

MenuItem myMenuItems [] = {};

uint16_t NUM_MENU_ITEMS = 0;

#endif    //USE_DYNAMIC_PARAMETERS

```

- If you don't need to add dynamic parameters, use the following in sketch

```cpp
#define USE_DYNAMIC_PARAMETERS     false
```

or

```cpp
/////////////// Start dynamic Credentials ///////////////

MenuItem myMenuItems [] = {};

uint16_t NUM_MENU_ITEMS = 0;
/////// // End dynamic Credentials ///////////

```

---

### Important Notes for using Dynamic Parameters' ids

1. These ids (such as "mqtt" in example) must be **unique**.

Please be noted that the following **reserved names are already used in library**:

```
"id"    for WiFi SSID
"pw"    for WiFi PW
"id1"   for WiFi1 SSID
"pw1"   for WiFi1 PW
"nm"    for Board Name
```
---
---

### Example [ESPAsync_WiFi](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi)

Please take a look at other examples, as well.

#### 1. File [ESPAsync_WiFi.ino](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi/ESPAsync_WiFi.ino)


https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/blob/716c86cb91fe507cdd2bfa5d89f901c287a9b832/examples/ESPAsync_WiFi/ESPAsync_WiFi.ino#L13-L158


---

#### 2. File [defines.h](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi/defines.h)

https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/blob/716c86cb91fe507cdd2bfa5d89f901c287a9b832/examples/ESPAsync_WiFi/defines.h#L13-L152

---

#### 3. File [Credentials.h](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi/Credentials.h)

https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/blob/716c86cb91fe507cdd2bfa5d89f901c287a9b832/examples/ESPAsync_WiFi/Credentials.h#L13-L100

---

#### 4. File [dynamicParams.h](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi/dynamicParams.h)


https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/blob/716c86cb91fe507cdd2bfa5d89f901c287a9b832/examples/ESPAsync_WiFi/dynamicParams.h#L13-L74

---
---


### Debug Terminal output Samples

### 1. [ESPAsync_WiFi_MQTT](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi_MQTT) on ESP32_DEV

This is the terminal output when running [**ESPAsync_WiFi_MQTT**](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi_MQTT) example on **ESP32_DEV**:

#### 1.1. No Config Data => Open Config Portal

```cpp
Starting ESPAsync_WiFi_MQTT using LittleFS on ESP32_DEV
ESPAsync_WiFiManager_Lite v1.10.5
ESP_MultiResetDetector v1.3.2
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[WML] Hostname=ESP32Async-Control
[WML] LoadCfgFile 
[WML] OK
[WML] ======= Start Stored Config Data =======
[WML] Hdr=ESP_WM_LITE,SSID=HueNet1,PW=12345678
[WML] SSID1=HueNet2,PW1=12345678
[WML] BName=ESP32_WMLite_MQTT
[WML] i=0,id=svr,data=io.adafruit.com
[WML] i=1,id=prt,data=1883
[WML] i=2,id=usr,data=private
[WML] i=3,id=key,data=private
[WML] i=4,id=pub,data=/feeds/Temperature
[WML] i=5,id=sub,data=/feeds/LED_Control
[WML] LoadCredFile 
[WML] OK
[WML] Invalid Stored Dynamic Data. Ignored
[WML] InitCfgFile,sz=236
[WML] SaveCfgFile 
[WML] WCSum=0xda0
[WML] OK
[WML] SaveBkUpCfgFile 
[WML] OK
[WML] SaveCredFile 
[WML] OK
[WML] CrWCSum=0xc30
[WML] SaveBkUpCredFile 
[WML] OK
[WML] LoadCPFile 
[WML] OK
[WML] bg:Stay forever in CP:No ConfigDat
[WML] SaveCPFile 
[WML] OK
[WML] SaveBkUpCPFile 
[WML] OK
C
Your stored Credentials :
AIO_SERVER = blank
AIO_SERVERPORT = blank
AIO_USERNAME = blank
AIO_KEY = blank
AIO_PUB_TOPIC = blank
AIO_SUB_TOPIC = blank
NStop multiResetDetecting
Saving config file...
Saving config file OK
CCC
```

#### 1.2. Got valid Credentials from Config Portal then connected to WiFi

```cpp
[WML] h:UpdLittleFS
[WML] SaveCfgFile 
[WML] WCSum=0xda0
[WML] OK
[WML] SaveBkUpCfgFile 
[WML] OK
[WML] SaveCredFile 
[WML] OK
[WML] CrWCSum=0xc30
[WML] SaveBkUpCredFile 
[WML] OK
[WML] h:Rst


Starting ESPAsync_WiFi_MQTT using LittleFS on ESP32_DEV
ESPAsync_WiFiManager_Lite v1.10.5
ESP_MultiResetDetector v1.3.2
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[WML] Hostname=ESP32Async-Control
[WML] LoadCfgFile 
[WML] OK
[WML] ======= Start Stored Config Data =======
[WML] Hdr=ESP_WM_LITE,SSID=HueNet1,PW=12345678
[WML] SSID1=HueNet2,PW1=12345678
[WML] BName=ESP32_WMLite_MQTT
[WML] i=0,id=svr,data=io.adafruit.com
[WML] i=1,id=prt,data=1883
[WML] i=2,id=usr,data=private
[WML] i=3,id=key,data=private
[WML] i=4,id=pub,data=/feeds/Temperature
[WML] i=5,id=sub,data=/feeds/LED_Control
[WML] LoadCredFile 
[WML] OK
[WML] Valid Stored Dynamic Data
[WML] Hdr=ESP_WM_LITE,SSID=HueNet1,PW=12345678
[WML] SSID1=HueNet2,PW1=12345678
[WML] BName=ESP32_WMLite_MQTT
[WML] i=0,id=svr,data=io.adafruit.com
[WML] i=1,id=prt,data=1883
[WML] i=2,id=usr,data=user_name
[WML] i=3,id=key,data=aio_key
[WML] i=4,id=pub,data=/feeds/Temperature
[WML] i=5,id=sub,data=/feeds/LED_Control
[WML] LoadCPFile 
[WML] OK
[WML] Connecting MultiWifi...
[WML] WiFi connected after time: 1
[WML] SSID=HueNet1,RSSI=-25
[WML] Channel=2,IP=192.168.2.82
[WML] bg: WiFi OK.

Creating new WiFi client object OK
Creating new MQTT object OK
AIO_SERVER = io.adafruit.com, AIO_SERVERPORT = 1883
AIO_USERNAME = user_name, AIO_KEY = aio_key
Creating new MQTT_Pub_Topic, Temperature = user_name/feeds/Temperature
Creating new Temperature object OK
Temperature MQTT_Pub_Topic = user_name/feeds/Temperature
Creating new AIO_SUB_TOPIC, LED_Control = user_name/feeds/LED_Control
Creating new LED_Control object OK
LED_Control AIO_SUB_TOPIC = user_name/feeds/LED_Control

Connecting to WiFi MQTT (3 attempts)...
WiFi MQTT connection successful!
TW
Your stored Credentials :
AIO_SERVER = io.adafruit.com
AIO_SERVERPORT = 1883
AIO_USERNAME = user_name
AIO_KEY = aio_key
AIO_PUB_TOPIC = /feeds/Temperature
AIO_SUB_TOPIC = /feeds/LED_Control
Stop multiResetDetecting
Saving config file...
Saving config file OK
TWTWTWTW TWTWTWTWTW TWTWTWTWTW T
```

#### 1.3. Lost a WiFi and autoconnect to another WiFi AP

```cpp
[WML] WiFi connected after time: 1
[WML] SSID=HueNet2,RSSI=-51
[WML] Channel=4,IP=192.168.2.82
[WML] run: WiFi reconnected
F
Connecting to WiFi MQTT (3 attempts)...
WiFi MQTT connection successful!
W TW
```

---

### 2. [ESPAsync_WiFi_MQTT](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi_MQTT) on ESP8266_NODEMCU

This is the terminal output when running [**ESPAsync_WiFi_MQTT**](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi_MQTT) example on **ESP8266_NODEMCU**:

#### 2.1. No Config Data => Open Config Portal

```cpp
Starting ESPAsync_WiFi_MQTT using LittleFS on ESP8266_NODEMCU
ESPAsync_WiFiManager_Lite v1.10.5
ESP_MultiResetDetector v1.3.2
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[WML] Hostname=ESP8266Async-Control
[WML] LoadCfgFile 
[WML] OK
[WML] ======= Start Stored Config Data =======
[WML] Hdr=ESP_WM_LITE,SSID=HueNet1,PW=12345678
[WML] SSID1=HueNet2,PW1=12345678
[WML] BName=ESP8266_WM_MQTT
[WML] i=0,id=svr,data=io.adafruit.com
[WML] i=1,id=prt,data=1883
[WML] i=2,id=usr,data=private
[WML] i=3,id=key,data=private
[WML] i=4,id=pub,data=/feeds/Temperature
[WML] i=5,id=sub,data=/feeds/LED_Control
[WML] LoadCredFile 
[WML] OK
[WML] Invalid Stored Dynamic Data. Ignored
[WML] InitCfgFile,sz=236
[WML] SaveCfgFile 
[WML] WCSum=0xda0
[WML] OK
[WML] SaveBkUpCfgFile 
[WML] OK
[WML] SaveCredFile 
[WML] OK
[WML] CrWCSum=0xc30
[WML] SaveBkUpCredFile 
[WML] OK
[WML] LoadCPFile 
[WML] OK
[WML] bg:Stay forever in CP:No ConfigDat
[WML] SaveCPFile 
[WML] OK
[WML] SaveBkUpCPFile 
[WML] OK
C
Your stored Credentials :
AIO_SERVER = blank
AIO_SERVERPORT = blank
AIO_USERNAME = blank
AIO_KEY = blank
AIO_PUB_TOPIC = blank
AIO_SUB_TOPIC = blank
NStop multiResetDetecting
Saving config file...
Saving config file OK
CCC
```

#### 2.2. Got valid Credentials from Config Portal then connected to WiFi

```cpp
[WML] h:UpdLittleFS
[WML] SaveCfgFile 
[WML] WCSum=0xda0
[WML] OK
[WML] SaveBkUpCfgFile 
[WML] OK
[WML] SaveCredFile 
[WML] OK
[WML] CrWCSum=0xc30
[WML] SaveBkUpCredFile 
[WML] OK
[WML] h:Rst


Starting ESPAsync_WiFi_MQTT using LittleFS on ESP8266_NODEMCU
ESPAsync_WiFiManager_Lite v1.10.5
ESP_MultiResetDetector v1.3.2
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[WML] Hostname=ESP8266Async-Control
[WML] LoadCfgFile 
[WML] OK
[WML] ======= Start Stored Config Data =======
[WML] Hdr=ESP_WM_LITE,SSID=HueNet1,PW=12345678
[WML] SSID1=HueNet2,PW1=12345678
[WML] BName=ESP8266_WM_MQTT
[WML] i=0,id=svr,data=io.adafruit.com
[WML] i=1,id=prt,data=1883
[WML] i=2,id=usr,data=private
[WML] i=3,id=key,data=private
[WML] i=4,id=pub,data=/feeds/Temperature
[WML] i=5,id=sub,data=/feeds/LED_Control
[WML] LoadCredFile 
[WML] OK
[WML] Valid Stored Dynamic Data
[WML] Hdr=ESP_WM_LITE,SSID=HueNet1,PW=12345678
[WML] SSID1=HueNet2,PW1=12345678
[WML] BName=ESP8266_WM_MQTT
[WML] i=0,id=svr,data=io.adafruit.com
[WML] i=1,id=prt,data=1883
[WML] i=2,id=usr,data=user_name
[WML] i=3,id=key,data=aio_key
[WML] i=4,id=pub,data=/feeds/Temperature
[WML] i=5,id=sub,data=/feeds/LED_Control
[WML] LoadCPFile 
[WML] OK
[WML] Connecting MultiWifi...
[WML] WiFi connected after time: 1
[WML] SSID=HueNet1,RSSI=-41
[WML] Channel=2,IP=192.168.2.98
[WML] bg: WiFi OK.

Creating new WiFi client object OK
Creating new MQTT object OK
AIO_SERVER = io.adafruit.com, AIO_SERVERPORT = 1883
AIO_USERNAME = user_name, AIO_KEY = aio_key
Creating new MQTT_Pub_Topic, Temperature = user_name/feeds/Temperature
Creating new Temperature object OK
Temperature MQTT_Pub_Topic = user_name/feeds/Temperature
Creating new AIO_SUB_TOPIC, LED_Control = user_name/feeds/LED_Control
Creating new LED_Control object OK
LED_Control AIO_SUB_TOPIC = user_name/feeds/LED_Control

Connecting to WiFi MQTT (3 attempts)...
WiFi MQTT connection successful!
TW
Your stored Credentials :
AIO_SERVER = io.adafruit.com
AIO_SERVERPORT = 1883
AIO_USERNAME = user_name
AIO_KEY = aio_key
AIO_PUB_TOPIC = /feeds/Temperature
AIO_SUB_TOPIC = /feeds/LED_Control
Stop multiResetDetecting
Saving config file...
Saving config file OK
TWTWTWTW TWTWTWTWTW TWTWTWTWTW T
```

#### 2.3. Lost a WiFi and autoconnect to another WiFi AP

```cpp
[WML] run: WiFi lost. Reconnect WiFi
[WML] Connecting MultiWifi...
[WML] WiFi connected after time: 1
[WML] SSID=HueNet2,RSSI=-54
[WML] Channel=4,IP=192.168.2.98
[WML] run: WiFi reconnected
H
```

---

### 3. [ESPAsync_WiFi_MQTT](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi_MQTT) on ESP32S2_DEV

This is the terminal output when running [**ESPAsync_WiFi_MQTT**](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi_MQTT) example on **ESP32S2_DEV**:

#### 3.1. No Config Data => Open Config Portal

```cpp
Starting ESPAsync_WiFi_MQTT using LittleFS on ESP32S2_DEV
ESPAsync_WiFiManager_Lite v1.10.5
ESP_MultiResetDetector v1.3.2
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[WML] Hostname=ESP32_S2_Async
[WML] Check if isForcedCP
[WML] LoadCPFile 
[WML] OK
[WML] bg: isForcedConfigPortal = false
[WML] bg:Stay forever in CP:No ConfigDat
[WML] clearForcedCP
[WML] SaveCPFile 
[WML] OK
[WML] SaveBkUpCPFile 
[WML] OK
[WML] 
stConf:SSID=ESP_8A1DF7C,PW=MyESP_8A1DF7C
[WML] IP=192.168.4.1,ch=1
[WML] s:configTimeout = 0
C
Your stored Credentials :
AIO_SERVER = io.adafruit.com
AIO_SERVERPORT = 1883
AIO_USERNAME = private
AIO_KEY = private
AIO_PUB_TOPIC = /feeds/Temperature
AIO_SUB_TOPIC = /feeds/LED_Control
NStop multiResetDetecting
Saving config file...
Saving config file OK
CCC C
```

#### 3.2. Got valid Credentials from Config Portal then connected to WiFi

```cpp
[WML] h: Init menuItemUpdated
[WML] h:repl id
[WML] h:items updated =1
[WML] h:key =id, value =HueNet1
[WML] h:repl pw
[WML] h:items updated =2
[WML] h:key =pw, value =12345678
[WML] h:repl id1
[WML] h:items updated =3
[WML] h:key =id1, value =HueNet2
[WML] h:repl pw1
[WML] h:items updated =4
[WML] h:key =pw1, value =12345678
[WML] h:repl nm
[WML] h:items updated =5
[WML] h:key =nm, value =ESP32_S2
[WML] h:svr=io.adafruit.com
[WML] h:items updated =6
[WML] h:key =svr, value =io.adafruit.com
[WML] h:prt=1883
[WML] h:items updated =7
[WML] h:key =prt, value =1883
[WML] h:usr=user_name
[WML] h:items updated =8
[WML] h:key =usr, value =user_name
[WML] h:key=aio_key
[WML] h:items updated =9
[WML] h:key =key, value =aio_key
[WML] h:pub=/feeds/Temperature
[WML] h:items updated =10
[WML] h:key =pub, value =/feeds/Temperature
[WML] h:sub=/feeds/LED_Control
[WML] h:items updated =11
[WML] h:key =sub, value =/feeds/LED_Control
[WML] h:UpdLittleFS
[WML] SaveCfgFile 
[WML] WCSum=0x1170
[WML] OK
[WML] SaveBkUpCfgFile 
[WML] OK
[WML] SaveCredFile 
[WML] CW1:pdata=io.adafruit.com,len=20
[WML] CW1:pdata=1883,len=6
[WML] CW1:pdata=user_name,len=20
[WML] CW1:pdata=aio_key,len=40
[WML] CW1:pdata=/feeds/Temperature,len=40
[WML] CW1:pdata=/feeds/LED_Control,len=40
[WML] OK
[WML] CrWCSum=0x2236
[WML] SaveBkUpCredFile 
[WML] CW2:pdata=io.adafruit.com,len=20
[WML] CW2:pdata=1883,len=6
[WML] CW2:pdata=user_name,len=20
[WML] CW2:pdata=aio_key,len=40
[WML] CW2:pdata=/feeds/Temperature,len=40
[WML] CW2:pdata=/feeds/LED_Control,len=40
[WML] OK
[WML] h:Rst
ESP-ROM:esp32s2-rc4-20191025
Build:Oct 25 2019
rst:0x3 (RTC_SW_SYS_RST),boot:0x8 (SPI_FAST_FLASH_BOOT)
Saved PC:0x40025f35
SPIWP:0xee
mode:DIO, clock div:1
load:0x3ffe6100,len:0x8
load:0x3ffe6108,len:0x608
load:0x4004c000,len:0xa38
load:0x40050000,len:0x2848
entry 0x4004c190


Starting ESPAsync_WiFi_MQTT using LittleFS on ESP32S2_DEV
ESPAsync_WiFiManager_Lite v1.10.5
ESP_MultiResetDetector v1.3.2
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[WML] Hostname=ESP32_S2_Async
[WML] LoadCfgFile 
[WML] OK
[WML] ======= Start Stored Config Data =======
[WML] Hdr=ESP_WM_LITE,SSID=HueNet1,PW=12345678
[WML] SSID1=HueNet2,PW1=12345678
[WML] BName=ESP32_S2_Async
[WML] i=0,id=svr,data=io.adafruit.com
[WML] i=1,id=prt,data=1883
[WML] i=2,id=usr,data=private
[WML] i=3,id=key,data=private
[WML] i=4,id=pub,data=/feeds/Temperature
[WML] i=5,id=sub,data=/feeds/LED_Control
[WML] CCSum=0x1170,RCSum=0x1170
[WML] LoadCredFile 
[WML] CrR:pdata=io.adafruit.com,len=20
[WML] CrR:pdata=1883,len=6
[WML] CrR:pdata=user_name,len=20
[WML] CrR:pdata=aio_key,len=40
[WML] CrR:pdata=/feeds/Temperature,len=40
[WML] CrR:pdata=/feeds/LED_Control,len=40
[WML] OK
[WML] CrCCsum=0x2236,CrRCsum=0x2236
[WML] Valid Stored Dynamic Data
[WML] Hdr=ESP_WM_LITE,SSID=HueNet1,PW=12345678
[WML] SSID1=HueNet2,PW1=12345678
[WML] BName=ESP32_S2_Async
[WML] i=0,id=svr,data=io.adafruit.com
[WML] i=1,id=prt,data=1883
[WML] i=2,id=usr,data=user_name
[WML] i=3,id=key,data=aio_key
[WML] i=4,id=pub,data=/feeds/Temperature
[WML] i=5,id=sub,data=/feeds/LED_Control
[WML] Check if isForcedCP
[WML] LoadCPFile 
[WML] OK
[WML] bg: noConfigPortal = true
[WML] Connecting MultiWifi...
[WML] WiFi connected after time: 1
[WML] SSID=HueNet1,RSSI=-19
[WML] Channel=2,IP=192.168.2.116
[WML] bg: WiFi OK.
Stop multiResetDetecting
Saving config file...
Saving config file OK

Creating new WiFi client object OK
Creating new MQTT object OK
AIO_SERVER = io.adafruit.com, AIO_SERVERPORT = 1883
AIO_USERNAME = user_name, AIO_KEY = aio_key
Creating new MQTT_Pub_Topic, Temperature = user_name/feeds/Temperature
Creating new Temperature object OK
Temperature MQTT_Pub_Topic = user_name/feeds/Temperature
Creating new AIO_SUB_TOPIC, LED_Control = user_name/feeds/LED_Control
Creating new LED_Control object OK
LED_Control AIO_SUB_TOPIC = user_name/feeds/LED_Control

Connecting to WiFi MQTT (3 attempts)...
WiFi MQTT connection successful!
TW
Your stored Credentials :
AIO_SERVER = io.adafruit.com
AIO_SERVERPORT = 1883
AIO_USERNAME = user_name
AIO_KEY = aio_key
AIO_PUB_TOPIC = /feeds/Temperature
AIO_SUB_TOPIC = /feeds/LED_Control
TWTWTWTW TWTWTW
```

#### 3.3. Lost a WiFi and autoconnect to another WiFi AP

```cpp
[WML] run: WiFi lost. Reconnect WiFi
[WML] Connecting MultiWifi...
[WML] WiFi connected after time: 1
[WML] SSID=HueNet2,RSSI=-54
[WML] Channel=4,IP=192.168.2.116
[WML] run: WiFi reconnected
H
```


---

### 4. [ESPAsync_WiFi_MQTT](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi_MQTT) on ESP32S2_DEV to demo MultiResetDetector

This is the terminal output when running [**ESPAsync_WiFi_MQTT**](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi_MQTT) example on **ESP32S2_DEV**


#### 4.1. MultiResetDetected => Open Config Portal

```cpp
Starting ESPAsync_WiFi_MQTT using LittleFS on ESP32S2_DEV
ESPAsync_WiFiManager_Lite v1.10.5
ESP_MultiResetDetector v1.3.2
LittleFS Flag read = 0xFFFC0003
multiResetDetectorFlag = 0xFFFC0003
lowerBytes = 0x0003, upperBytes = 0x0003
multiResetDetected, number of times = 3
Saving config file...
Saving config file OK
[WML] Hdr=ESP_WM_LITE,SSID=HueNet1,PW=12345678
[WML] SSID1=HueNet2,PW1=12345678
[WML] BName=ESP32-S2
[WML] Hdr=ESP_WM_LITE,SSID=HueNet1,PW=12345678
[WML] SSID1=HueNet2,PW1=12345678
[WML] BName=ESP32-S2
[WML] 
stConf:SSID=ESP_8A1DF7C,PW=MyESP_8A1DF7C
[WML] IP=192.168.4.1,ch=1
C
Your stored Credentials :
AIO_SERVER = io.adafruit.com
AIO_SERVERPORT = 1883
AIO_USERNAME = user_name
AIO_KEY = aio_key
AIO_PUB_TOPIC = /feeds/Temperature
AIO_SUB_TOPIC = /feeds/LED_Control
CCCC CCCC[WML] h:Updating LittleFS:/wm_config.dat
[WML] h:Rst
ESP-ROM:esp32s2-rc4-20191025
Build:Oct 25 2019
rst:0xc (RTC_SW_CPU_RST),boot:0x8 (SPI_FAST_FLASH_BOOT)
Saved PC:0x40027318
SPIWP:0xee
mode:DIO, clock div:1
load:0x3ffe6100,len:0x4b0
load:0x4004c000,len:0xa50
load:0x40050000,len:0x28e8
entry 0x4004c190
```

#### 4.2. Got valid Credentials from Config Portal then connected to WiFi

```cpp
Starting ESPAsync_WiFi_MQTT using LittleFS on ESP32S2_DEV
ESPAsync_WiFiManager_Lite v1.10.5
ESP_MultiResetDetector v1.3.2
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[WML] Hdr=ESP_WM_LITE,SSID=HueNet1,PW=12345678
[WML] SSID1=HueNet2,PW1=12345678
[WML] BName=ESP32-S2
[WML] Hdr=ESP_WM_LITE,SSID=HueNet1,PW=12345678
[WML] SSID1=HueNet2,PW1=12345678
[WML] BName=ESP32-S2
[WML] WiFi connected after time: 1
[WML] SSID=HueNet1,RSSI=-36
[WML] Channel=2,IP=192.168.2.157
Stop multiResetDetecting
Saving config file...
Saving config file OK

Creating new WiFi client object OK
Creating new MQTT object OK
AIO_SERVER = io.adafruit.com, AIO_SERVERPORT = 1883
AIO_USERNAME = user_name, AIO_KEY = aio_key
Creating new MQTT_Pub_Topic, Temperature = user_name/feeds/Temperature
Creating new Temperature object OK
Temperature MQTT_Pub_Topic = user_name/feeds/Temperature
Creating new AIO_SUB_TOPIC, LED_Control = user_name/feeds/LED_Control
Creating new LED_Control object OK
LED_Control AIO_SUB_TOPIC = user_name/feeds/LED_Control

Connecting to WiFi MQTT (3 attempts)...
WiFi MQTT connection successful!
TW
Your stored Credentials :
AIO_SERVER = io.adafruit.com
AIO_SERVERPORT = 1883
AIO_USERNAME = user_name
AIO_KEY = aio_key
AIO_PUB_TOPIC = /feeds/Temperature
AIO_SUB_TOPIC = /feeds/LED_Control
TWTWTWT
```

---

### 5. [ESPAsync_WiFi_MQTT](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi_MQTT) on ESP32_DEV to demo WiFi Scan

This is the terminal output when running [**ESPAsync_WiFi_MQTT**](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi_MQTT) example on **ESP32_DEV** with WiFi Scan for selection in Configuration Portal

#### 5.1 MRD/DRD => Open Config Portal

```cpp
Starting ESPAsync_WiFi_MQTT using LittleFS on ESP32_DEV
ESPAsync_WiFiManager_Lite v1.10.5
ESP_MultiResetDetector v1.3.2
LittleFS Flag read = 0xFFFC0003
multiResetDetectorFlag = 0xFFFC0003
lowerBytes = 0x0003, upperBytes = 0x0003
multiResetDetected, number of times = 3
Saving config file...
Saving config file OK
[WML] Hdr=ESP_WM_LITE,SSID=HueNet1,PW=12345678
[WML] SSID1=HueNet2,PW1=12345678
[WML] BName=ESP32_DEV
[WML] Hdr=ESP_WM_LITE,SSID=HueNet1,PW=12345678
[WML] SSID1=HueNet2,PW1=12345678
[WML] BName=ESP32_DEV
[WML] WiFi networks found:
[WML] 1: HueNet, -26dB
[WML] 2: HueNet1, -28dB
[WML] 3: HueNetTek, -31dB
[WML] 4: dragino-1ed63c, -43dB
[WML] 5: HueNet2, -56dB
[WML] 6: bacau, -74dB
[WML] 7: guest_24, -74dB
[WML] 8: Rogers 786, -86dB
[WML] 9: dlink-4F96, -90dB
[WML] 10: Waterhome, -91dB
[WML] 11: BELL246, -93dB
[WML] 12: BELL627, -96dB
[WML] 
stConf:SSID=ESP_9ABF498,PW=MyESP_9ABF498
[WML] IP=192.168.4.1,ch=5
C
Your stored Credentials :
AIO_SERVER = io.adafruit.com
AIO_SERVERPORT = 1883
AIO_USERNAME = user_name
AIO_KEY = aio_key
AIO_PUB_TOPIC = /feeds/Temperature
AIO_SUB_TOPIC = /feeds/LED_Control
CCCC CCCCC CCCCC C
```

### 5.2 Config Data Saved => Connection to Adafruit MQTT

```cpp
Starting ESPAsync_WiFi_MQTT using LittleFS on ESP32_DEV
ESPAsync_WiFiManager_Lite v1.10.5
ESP_MultiResetDetector v1.3.2
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[WML] Hdr=ESP_WM_LITE,SSID=HueNet1,PW=12345678
[WML] SSID1=HueNet2,PW1=12345678
[WML] BName=ESP32_DEV
[WML] Hdr=ESP_WM_LITE,SSID=HueNet1,PW=12345678
[WML] SSID1=HueNet2,PW1=12345678
[WML] BName=Async_ESP32_DEV
[WML] WiFi connected after time: 1
[WML] SSID=HueNet1,RSSI=-30
[WML] Channel=2,IP=192.168.2.45
Stop multiResetDetecting
Saving config file...
Saving config file OK

Creating new WiFi client object OK
Creating new MQTT object OK
AIO_SERVER = io.adafruit.com, AIO_SERVERPORT = 1883
AIO_USERNAME = user_name, AIO_KEY = aio_key
Creating new MQTT_Pub_Topic, Temperature = user_name/feeds/Temperature
Creating new Temperature object OK
Temperature MQTT_Pub_Topic = user_name/feeds/Temperature
Creating new AIO_SUB_TOPIC, LED_Control = user_name/feeds/LED_Control
Creating new LED_Control object OK
LED_Control AIO_SUB_TOPIC = user_name/feeds/LED_Control

Connecting to WiFi MQTT (3 attempts)...
WiFi MQTT connection successful!
TWTWTWTW TWTWTWTWTWTW
```

---

### 6. [ESPAsync_WiFi](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi) on ESP32S3_DEV


This is the terminal output when running [**ESPAsync_WiFi**](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi) example on **ESP32S3_DEV**

```cpp
Starting ESPAsync_WiFi using LittleFS on ESP32S3_DEV
ESPAsync_WiFiManager_Lite v1.10.5
ESP_MultiResetDetector v1.3.2
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[WML] Hdr=ESP_WM_LITE,SSID=HueNet1,PW=12345678
[WML] SSID1=HueNet2,PW1=12345678
[WML] BName=ESP32_S3
[WML] Hdr=ESP_WM_LITE,SSID=HueNet1,PW=12345678
[WML] SSID1=HueNet2,PW1=12345678
[WML] BName=ESP32_S3
[WML] WiFi connected after time: 0
[WML] SSID=HueNet1,RSSI=-25
[WML] Channel=2,IP=192.168.2.83
H
Your stored Credentials :
Blynk Server1 = account.duckdns.org
Token1 = token1
Blynk Server2 = account.ddns.net
Token2 = token2
Port = 8080
MQTT Server = mqtt.duckdns.org
Stop multiResetDetecting
Saving config file...
Saving config file OK
H
```

---

### 7. [ESPAsync_WiFi](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi) on ESP32C3_DEV using LittleFS


This is the terminal output when running [**ESPAsync_WiFi**](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/tree/main/examples/ESPAsync_WiFi) example on **ESP32C3_DEV** using LittleFS


```cpp
Starting ESPAsync_WiFi using LittleFS on ESP32C3_DEV
ESPAsync_WiFiManager_Lite v1.10.5
ESP_MultiResetDetector v1.3.2
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[WML] Hdr=ESP_WM_LITE,SSID=HueNet1,PW=password
[WML] SSID1=HueNet2,PW1=password
[WML] BName=ESP32_C3
[WML] Hdr=ESP_WM_LITE,SSID=HueNet1,PW=password
[WML] SSID1=HueNet2,PW1=password
[WML] BName=ESP32_C3
[WML] WiFi connected after time: 0
[WML] SSID=HueNet1,RSSI=-21
[WML] Channel=2,IP=192.168.2.85
H
Your stored Credentials :
Blynk Server1 = account.duckdns.org
Token1 = token1
Blynk Server2 = account.ddns.net
Token2 = token2
Port = 8080
MQTT Server = mqtt.duckdns.org
Stop multiResetDetecting
Saving config file...
Saving config file OK
HHH
```


---
---

### Debug

Debug is enabled by default on Serial. To disable, add at the beginning of sketch

```cpp
/* Comment this out to disable prints and save space */
#define ESP_WM_LITE_DEBUG_OUTPUT        Serial

#define _ESP_WM_LITE_LOGLEVEL_          3

#define USING_MRD                       true

#if USING_MRD
  #define MULTIRESETDETECTOR_DEBUG      true
#else
  #define DOUBLERESETDETECTOR_DEBUG     true
#endif
```

---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the board's core or this library version.

Sometimes, the library will only work if you update the `ESP32 / ESP8266` core to the latest version because I am using some newly added function.

If you connect to the created configuration Access Point but the ConfigPortal does not show up, just open a browser and type in the IP of the web portal, by default `192.168.4.1`.


---

### Issues

Submit issues to: [ESPAsync_WiFiManager_Lite issues](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/issues)

---
---

### TO DO

1. Support more boards, shields and libraries
2. Bug Searching and Killing

---

### DONE

 1. Permit EEPROM size and location configurable to avoid conflict with others.
 2. More flexible to configure reconnection timeout.
 3. For fresh config data, don't need to wait for connecting timeout before entering config portal.
 4. If the config data not entered completely (SSIDs, Passwords, etc.), entering config portal
 5. Add configurable Config Portal IP, SSID and Password
 6. Change Synch XMLHttpRequest to Async
 7. Add configurable Static IP, GW, Subnet Mask and 2 DNS Servers' IP Addresses.
 8. Add checksums
 9. Add support to **ESP32 including ESP32-S2 (ESP32-S2 Saola, AI-Thinker ESP-12K, etc.) and ESP8266**
10. Add MultiWiFi features with auto(re)connect
11. Easy-to-use **Dynamic Parameters** without the necessity to write complicated ArduinoJSon functions
12. Permit to input special chars such as **%** and **#** into data fields.
13. Default Credentials and dynamic parameters
14. **Multi/DoubleDetectDetector** to force Config Portal when multi/double reset is detected within predetermined time, default 10s.
15. Configurable Config Portal Title
16. Re-structure all examples to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device.
17. Add Table of Contents and Version String
18. Configurable **Customs HTML Headers**, including Customs Style, Customs Head Elements, CORS Header
19. Add support to **ESP32-S2 (ESP32-S2 Saola, AI-Thinker ESP-12K, etc.) using EEPROM, LittleFS and SPIFFS**
20. Add support to **ESP32-C3 using EEPROM and SPIFFS**
21. Enable **scan of WiFi networks** for selection in Configuration Portal
22. Ready for ESP32 core v2.0.0+
23. Fix ESP8266 bug not easy to connect to Config Portal for ESP8266 core v3.0.0+ 
24. Fix the blocking issue in loop() with configurable `WIFI_RECON_INTERVAL`
25. Optimize library code by using `reference-passing` instead of `value-passing`
26. Add support to **ESP32-S3 (ESP32S3_DEV, ESP32_S3_BOX, UM TINYS3, UM PROS3, UM FEATHERS3, etc.) using EEPROM, SPIFFS or LittleFS**
27. Add `LittleFS` support to **ESP32-C3**
28. Use `ESP32-core's LittleFS` library instead of `Lorol's LITTLEFS` library for ESP32 core v2.0.0+
29. Optimize code by passing by `reference` instead of `value`
30. Optional `Board_Name` in Config Portal
31. Add function `isConfigMode()` to signal system is in Config Portal mode
32. Remove dependency on `LittleFS_esp32` library to prevent PIO error when using new ESP32 core v1.0.6+
33. Remove unavailable items from depends field of `library.properties`, such as `ESP Async WebServer`,`ESP AsyncTCP` and `AsyncTCP`
34. Fix ESP32 `chipID`
35. Add ESP32 `getChipID()` and `getChipOUI()` functions
36. Add `Captive Portal` using AsyncDNSServer
37. Add public methods to load and save dynamic data
38. Add Config Portal `scaling` support to mobile devices
39. Using PROGMEM for strings
40. Default LittleFS for ESP8266 in examples
41. Improve `README.md` so that links can be used in other sites, such as `PIO`

---
---
 
### Contributions and Thanks

Please help contribute to this project and add your name here.

1. Thanks to [Michael H. "bizprof"](https://github.com/bizprof). With the impressive new feature :
  - `Enable scan of WiFi networks for selection in Configuration Portal`. Check [PR for v1.3.0 - Enable scan of WiFi networks #10](https://github.com/khoih-prog/WiFiManager_NINA_Lite/pull/10) leading to v1.5.0
2. Thanks to [Holger Müller](https://github.com/hmueller01) for creating the following merged PRs leading to many new versions
  - [Captive portal #22](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/pull/22)
  - [cleanup reset code #23](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/pull/23)
  - [added public methods to load and save dynamic data #24](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/pull/24)
  - [Mobile scale #26](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/pull/26)
  - [fix compiler error if EEPROM is used #29](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/pull/29)
  - [implement PROGMEM strings, alignment with ESP_WiFiManager_Lite #31](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/pull/31)
  - [Example fixes #32](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/pull/32)
3. Thanks to [securelpb](https://github.com/securelpb) for report issue, leading to `v1.10.3` to fix the problem with PIO
  - [Unable to compile basic example for NodeMCU-32s #28](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/issues/28)
  
<table>
  <tr>
    <td align="center"><a href="https://github.com/bizprof"><img src="https://github.com/bizprof.png" width="100px;" alt="bizprof"/><br /><sub><b>⭐️⭐️ Michael H. "bizprof"</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/hmueller01"><img src="https://github.com/hmueller01.png" width="100px;" alt="hmueller01"/><br /><sub><b>⭐️⭐️ Holger Müller</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/securelpb"><img src="https://github.com/securelpb.png" width="100px;" alt="securelpb"/><br /><sub><b>securelpb</b></sub></a><br /></td>
  </tr> 
</table>


---

### Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [MIT](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/blob/main/LICENSE)

---

### Copyright

Copyright (c) 2021- Khoi Hoang


