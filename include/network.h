#pragma once

#include <WiFiClientSecure.h>
#include <WiFiUdp.h>
#include <time.h>

#include "config.h"


void initWiFi();
String getLocalIP();
String getMacAddress();
void serialPrintWiFiInfo();

void configTime();
String getStringCurrentTime();
void serialPrintCurrentTime();
