#include <Arduino.h>
#include <WiFiClientSecure.h>
#include "network.h"
#include "sensors.h"

void setup()
{
  Serial.begin(9600);
  initWiFi();
  configTime();
  setupSensors();
}

void loop()
{
  //serialPrintCurrentTime();
  sensorsRead();
}
