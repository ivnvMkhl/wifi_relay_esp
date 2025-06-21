#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "app_config.h"


ESP8266WebServer server(AppConfig::port);

void setup() {
  // Инициализация реле
  pinMode(AppConfig::relay_pin, OUTPUT);
  digitalWrite(AppConfig::relay_pin, HIGH);

  // Настройка статического IP
  if (!WiFi.config(AppConfig::local_ip, AppConfig::gateway, AppConfig::subnet, AppConfig::dns)) {
    Serial.println("STA Failed to configure");
  }

  // Подключение к WiFi
  WiFi.begin(AppConfig::ssid, AppConfig::password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

  // Настройка сервера
  server.on("/", []() {
    String html = "<html><body>"
                "<h1>ESP-01 Relay Control</h1>"
                "<p>IP: " + AppConfig::local_ip.toString() + "</p>"
                "<p><a href='/on'><button>ON</button></a></p>"
                "<p><a href='/off'><button>OFF</button></a></p>"
                "</body></html>";
    server.send(200, "text/html", html);
  });
  server.on("/on", []() {
    digitalWrite(AppConfig::relay_pin, LOW);
    server.send(200, "text/plain", "Relay ON");
    Serial.print("Relay ON");
  });
  server.on("/off", []() {
    digitalWrite(AppConfig::relay_pin, HIGH);
    server.send(200, "text/plain", "Relay OFF");
    Serial.print("Relay OFF");
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
