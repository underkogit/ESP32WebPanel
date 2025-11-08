#include <WebServer.h>
#include <WiFi.h>
#include <Preferences.h>
#include "wifiConnected.h"
#include <ArduinoJson.h>
#include "webui.h"
#include "chipStatus.h"

WebServer server(80);
Preferences prefs;
const char *content_type = "text/html; charset=utf-8";
const char *content_type_json = "application/json";
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
    if (server.hasArg("id")) {
        String argValueId = server.arg("id");

        // Проверка существования ключа "button" в Preferences
        if (!prefs.isKey(argValueId.c_str())) {
            prefs.putBool(argValueId.c_str(), false); // Устанавливаем значение по умолчанию
        } 

        // Переключение статуса кнопки
        bool currentStatus = !prefs.getBool(argValueId.c_str()); // Получаем текущее значение
        prefs.putBool(argValueId.c_str(), currentStatus); // Меняем значение на противоположное

        // Создание JSON-ответа
        StaticJsonDocument<200> doc;
        String jsonOutput;

        doc["id"] = argValueId;
        doc["status"] = currentStatus ? "ON" : "OFF"; // Получаем текущее значение

        serializeJson(doc, jsonOutput);

        server.send(200, content_type_json, jsonOutput);   
    } else {
        server.send(400, content_type, "Error: Missing arguments");
    } });

    server.on("/chip", []()
              { server.send(200, content_type_json, chipStatusJson()); });
    server.begin();
}

void loop() { server.handleClient(); }
