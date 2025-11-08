
#ifndef CHIPSTATUS_H
#define CHIPSTATUS_H

#include <ArduinoJson.h>
#include <WiFi.h>

String chipStatusJson()
{
    StaticJsonDocument<200> doc;
    doc["chipModel"] = ESP.getChipModel();

    uint64_t chipId = ESP.getEfuseMac();
    String chipIdString = String((chipId >> 8), HEX);
    chipIdString.toUpperCase();
    doc["chipId"] = chipIdString;

    doc["sdkVersion"] = ESP.getSdkVersion();
    doc["chipCores"] = ESP.getChipCores();
    doc["flashSize"] = ESP.getFlashChipSize();
    if (WiFi.status() == WL_CONNECTED)
    {
        doc["localIP"] = WiFi.localIP();
    }
    String jsonOutput;
    serializeJson(doc, jsonOutput);

    return jsonOutput;
}
#endif