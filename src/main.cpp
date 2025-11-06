#include <WebServer.h>
#include <WiFi.h>

#include "wifiConnected.h"
#include "webui.h"
WebServer server(80);

const char* content_type = "text/html; charset=utf-8";

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);

    Serial.println("Connecting to Wi-Fi...");
    connectToWiFi();

    server.on("/", []() {
        server.send(200, content_type, htmlContent);  // Отправляем HTML
    });

    server.on("/click", []() {
        if (server.hasArg("hash")) {
            String argValue = server.arg("hash");
            server.send(200, content_type, "Argument received: " + argValue);  // Ответ клиенту
        } else {
            server.send(400, content_type, "Missing argument");  // Ошибка, если аргумент не передан
        }
    });

    server.begin();
}

void loop() { server.handleClient(); }
