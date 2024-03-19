#include "network.h"


void initWiFi()
{
  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
  Serial.println(WiFi.macAddress());
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