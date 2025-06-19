#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "ROUTER_SSID";
const char* password = "ROUTER_PASSWORD";
const int relayPin = 0;  // GPIO0

// Настройки статического IP
IPAddress local_IP(192, 168, 3, 30);
IPAddress gateway(192, 168, 3, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(8, 8, 8, 8);  // DNS Google (опционально)

ESP8266WebServer server(80);

void handleRoot() {
  String html = "<html><body>"
               "<h1>ESP-01 Relay Control</h1>"
               "<p>IP: 192.168.1.30</p>"
               "<p><a href='/on'><button>ON</button></a></p>"
               "<p><a href='/off'><button>OFF</button></a></p>"
               "</body></html>";
  server.send(200, "text/html", html);
}

void setup() {
  // Инициализация реле
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);

  // Настройка статического IP
  if (!WiFi.config(local_IP, gateway, subnet, dns)) {
    Serial.println("STA Failed to configure");
  }

  // Подключение к WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

  // Настройка сервера
  server.on("/", handleRoot);
  server.on("/on", []() {
    digitalWrite(relayPin, LOW);
    server.send(200, "text/plain", "Relay ON");
    Serial.print("Relay ON");
  });
  server.on("/off", []() {
    digitalWrite(relayPin, HIGH);
    server.send(200, "text/plain", "Relay OFF");
    Serial.print("Relay OFF");
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
