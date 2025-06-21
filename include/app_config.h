#pragma once
#include <Arduino.h>
#include <IPAddress.h>

namespace AppConfig {
    extern const String ssid;
    extern const String password;
    extern const IPAddress local_ip;
    extern const IPAddress gateway;
    extern const IPAddress subnet;
    extern const IPAddress dns;
    extern const uint8_t relay_pin;
    extern const uint16_t port;
}
