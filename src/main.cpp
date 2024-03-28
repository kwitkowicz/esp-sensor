#include <Arduino.h>
#include <WiFiClientSecure.h>
#include "network.h"
#include "sensors.h"
#include "mqtt.h"

void setup()
{
  Serial.begin(9600);
  initWiFi();
  configTime();
  setupSensors();
  setupMQTT();
}

void loop()
{
  sensorsRead();
  if (isTimeSyncNeeded == 1)
  {
    void syncTime();
    isTimeSyncNeeded = 0;
  }
  publishToMQTT(getPayload());//ugly temporary workaround
}
