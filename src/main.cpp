#include <Arduino.h>
#include <WiFiClientSecure.h>
#include "network.h"

void setup() {
  Serial.begin(9600);
  initWiFi();
}

void loop() {
 Serial.println(getLocalIP());
 delay(3000);
}

