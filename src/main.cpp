#include <WebServer.h>
#include <WiFi.h>

#include "wifiConnected.h"
#include "webui.h"
WebServer server(80);

const char *content_type = "text/html; charset=utf-8";

void setup()
{
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);

    Serial.println("Connecting to Wi-Fi...");
    connectToWiFi();

    server.on("/", []()
              {
                  server.send(200, content_type, htmlContent); // Отправляем HTML
              });

    server.on("/btnClick", []()
              {
        if (server.hasArg("hesh") && server.hasArg("hesh")) {
            String argValueHesh = server.arg("hesh");
            String argValueId = server.arg("id");
            server.send(200, content_type,   "id: " + argValueId + "Hesh" + argValueHesh + "");  // Ответ клиенту
        } else {
            server.send(400, content_type, "Error");  // Ошибка, если аргумент не передан
        } });
 
    server.begin();
}

void loop() { server.handleClient(); }
