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

* [Changelog](#changelog)
  * [Release v1.10.5](#release-v1105)
  * [Release v1.10.3](#release-v1103)
  * [Release v1.10.2](#release-v1102)
  * [Release v1.10.1](#release-v1101)
  * [Release v1.9.1](#release-v191)
  * [Release v1.9.0](#release-v190)
  * [Release v1.8.2](#release-v182)
  * [Release v1.8.1](#release-v181)
  * [Release v1.8.0](#release-v180)
  * [Major Release v1.7.0](#major-release-v170)
  * [Release v1.6.0](#release-v160)
  * [Release v1.5.1](#release-v151)
  * [Major Release v1.5.0](#major-release-v150)
  * [Release v1.4.0](#release-v140)
  * [Release v1.3.0](#release-v130)
  * [Release v1.2.0](#release-v120)
  * [Release v1.1.0](#release-v110)
  * [Release v1.0.0](#release-v100)

---
---


## Changelog

### Release v1.10.5

1. Using PROGMEM for strings in examples. Check [Example fixes #32](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/pull/32)
2. Using PROGMEM for HTML strings. Check [implement PROGMEM strings, alignment with ESP_WiFiManager_Lite #31](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/pull/31)
3. Default LittleFS for ESP8266 in examples
4. Improve `README.md` so that links can be used in other sites, such as `PIO`
5. Sync with `ESP_WiFiManager_Lite` v1.10.5

### Release v1.10.3

1. Fix compiler error if EEPROM is used. Check [fix compiler error if EEPROM is used #29](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/pull/29)
2. Fix compiler error in PIO. Check [Unable to compile basic example for NodeMCU-32s #28](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/issues/28)

### Release v1.10.2

1. Add Config Portal scaling support to mobile devices. Check [Mobile scale #26](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/pull/26)

### Release v1.10.1

1. Add public methods to load and save dynamic data. Check [added public methods to load and save dynamic data #24](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/pull/24)
2. Bump up to `v1.10.1` to sync with [ESP_WiFiManager_Lite](https://github.com/khoih-prog/ESP_WiFiManager_Lite)

### Release v1.9.1

1. Add `Captive Portal` using AsyncDNSServer. Check [Captive portal #22](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/pull/22)
2. Cleanup reset code. Check [cleanup reset code #23](https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite/pull/23)
3. Periodical code clean-up

### Release v1.9.0

1. Fix ESP32 chipID. Check [Help for storing variables in memory (non-volatile) #87](https://github.com/khoih-prog/ESP_WiFiManager/discussions/87#discussioncomment-3593028)
2. Add ESP32 getChipID() and getChipOUI() functions
3. Remove dependency on `LittleFS_esp32` library to prevent PIO error when using new ESP32 core v1.0.6+
4. Remove unavailable items from depends field of `library.properties`, such as `ESP Async WebServer`,`ESP AsyncTCP` and `AsyncTCP`. Check 
- [**Arduino Library Registry** #147](https://github.com/me-no-dev/AsyncTCP/issues/147)
- [**Arduino library manager** #139](https://github.com/me-no-dev/ESPAsyncTCP/issues/139)
- [**Available via Arduino Library Manager?** #158](https://github.com/me-no-dev/ESPAsyncTCP/issues/158)
- [**Add ESPAsyncTCP to the Arduino Library Manager** #168](https://github.com/me-no-dev/ESPAsyncTCP/issues/168)


### Release v1.8.2

1. Optimize code by using passing by `reference` instead of by `value`
2. Optional `Board_Name` in Menu. Check [option to remove board name from web page #25](https://github.com/khoih-prog/WiFiManager_NINA_Lite/issues/25)
3. Add function `isConfigMode()` to signal system is in Config Portal mode.

### Release v1.8.1

1. Add LittleFS support to `ESP32-C3`.
2. Use `ESP32-core's LittleFS` library instead of `Lorol's LITTLEFS` library for ESP32 core v2.0.0+

### Release v1.8.0

1. Add support to `ESP32-S3` (`ESP32S3_DEV, ESP32_S3_BOX, UM TINYS3, UM PROS3, UM FEATHERS3`, etc.) using [ESP32 core, esp32-s3-support branch, v2.0.2+](https://github.com/espressif/arduino-esp32/tree/esp32-s3-support)

### Major Release v1.7.0

1. Fix ESP8266 bug not easy to connect to Config Portal for ESP8266 core v3.0.0+ 
2. Fix the blocking issue in loop(). Check [retries block the main loop #18](https://github.com/khoih-prog/WiFiManager_NINA_Lite/issues/18)
3. Configurable `WIFI_RECON_INTERVAL`. Check [retries block the main loop #18](https://github.com/khoih-prog/WiFiManager_NINA_Lite/issues/18#issuecomment-1006197561)
4. Optimize library code by using `reference-passing` instead of `value-passing`
5. Clean up

### Release v1.6.0

1. Auto detect ESP32 core and use either built-in LittleFS or [LITTLEFS](https://github.com/lorol/LITTLEFS) library. 
2. Fix bug returning IP `255.255.255.255` in core v2.0.0+ when using `hostname`

### Release v1.5.1

1. Update `platform.ini` and `library.json` to use original `khoih-prog` instead of `khoih.prog` after PIO fix

### Major Release v1.5.0

1. Enable scan of WiFi networks for selection in Configuration Portal. Check [PR for v1.3.0 - Enable scan of WiFi networks #10](https://github.com/khoih-prog/WiFiManager_NINA_Lite/pull/10). Now you can select optional **SCAN_WIFI_NETWORKS**, **MANUAL_SSID_INPUT_ALLOWED** to be able to manually input SSID, not only from a scanned SSID lists and **MAX_SSID_IN_LIST** (from 2-15)
2. Minor enhancement to not display garbage when data is invalid

### Release v1.4.0

1. Add **LittleFS and SPIFFS** support to new **ESP32-S2** boards (**Arduino ESP32C3_DEV**). Check [HOWTO Install esp32 core for ESP32-S2 (Saola, AI-Thinker ESP-12K) and ESP32-C3 boards into Arduino IDE](#howto-install-esp32-core-for-esp32-s2-saola-ai-thinker-esp-12k-and-esp32-c3-boards-into-arduino-ide).
2. Add **EEPROM and SPIFFS** support to new **ESP32-C3** boards (**Arduino ESP32C3_DEV**). Check [HOWTO Install esp32 core for ESP32-S2 (Saola, AI-Thinker ESP-12K) and ESP32-C3 boards into Arduino IDE](#howto-install-esp32-core-for-esp32-s2-saola-ai-thinker-esp-12k-and-esp32-c3-boards-into-arduino-ide).

### Release v1.3.0

1. Fix invalid "blank" Config Data treated as Valid.
2. Permit optionally inputting one set of WiFi SSID/PWD by using `REQUIRE_ONE_SET_SSID_PW == true`
3. Enforce WiFi PWD minimum length of 8 chars
4. Fix bug where EEPROM_SIZE truncated by DRD/MRD to 512, resulting lost and corrupted data.

### Release v1.2.0

1. Configurable **Customs HTML Headers**, including Customs Style, Customs Head Elements, CORS Header.
2. Fix Config Portal Bug. 
3. Update examples

### Release v1.1.0

1. Add support to **ESP32-S2 (ESP32-S2 Saola and AI-Thinker ESP-12K)**
2. Add [**Instructions to install ESP32-S2 core**](#howto-install-esp32-s2-core-for-esp32-s2-saola-ai-thinker-esp-12k-boards-into-arduino-ide)

### Release v1.0.0

1. Initial release to support ESP32 and ESP8266 to use the better **asynchronous** [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer).



