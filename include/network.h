#pragma once

#include <WiFiClientSecure.h>
#include <WiFiUdp.h>
#include <time.h>

#include "config.h"

extern volatile int isTimeSyncNeeded;

void initWiFi();
String getLocalIP();
String getMacAddress();
void serialPrintWiFiInfo();

void configTime();
void syncTime();
String getStringCurrentTime();
void serialPrintCurrentTime();
void IRAM_ATTR onTimeSyncTimer();