#include "network.h"

void initWiFi()
{
    WiFi.persistent(false);
    WiFi.mode(WIFI_STA);
    Serial.print("Connecting to ");
    Serial.println(WIFI_SSID);

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    delay(1000);
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(500);
    }

    WiFi.setAutoReconnect(true);
    WiFi.persistent(true);

#ifdef DEBUG
    serialPrintWiFiInfo();
#endif
}

String getLocalIP()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        return "Not connected to the WiFi";
    }
    else
    {
        return WiFi.localIP().toString();
    }
}

String getMacAddress()
{
    return WiFi.macAddress();
}
void serialPrintWiFiInfo()
{
    Serial.println('\n');
    Serial.println("Connection established!");
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP());
    Serial.print("Broadcast IP:\t");
    Serial.println(WiFi.broadcastIP());
    Serial.print("Gateway IP:\t");
    Serial.println(WiFi.gatewayIP());
    Serial.print("RSSI: ");
    Serial.println(WiFi.RSSI());
}

void configTime()
{
    configTime(gmtOffset_sec, daylightOffset_sec, NTP_SERVER);
}

void serialPrintCurrentTime()
{
    Serial.print("Current time:\t");
    Serial.println(getStringCurrentTime());
}

String getStringCurrentTime()
{
    char timeString[21];
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo))
    {
        Serial.println("Failed to obtain time");
        return "getting time failed";
    }
    strftime(timeString, sizeof(timeString), "%d-%m-%Y %H:%M:%S", &timeinfo);
    return timeString;
}