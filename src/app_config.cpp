#include "app_config.h"
#include <ArduinoJson.h>
#include <LittleFS.h>

namespace AppConfig {
    const IPAddress local_ip(192, 168, 3, 31);
    const IPAddress gateway(192, 168, 3, 1);
    const IPAddress subnet(255, 255, 255, 0);
    const IPAddress dns(8, 8, 8, 8);
    const String ssid = "HUAWEI-010R2C";
    const String password = "PASSWORD";
    const uint8_t relay_pin = 0;
    const uint16_t port = 80;
}
