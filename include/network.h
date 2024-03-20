#pragma once

#include <WiFiClientSecure.h>
#include "config.h"

void initWiFi();
String getLocalIP();
String getMacAddress();
void serialPrintInfo();
