#pragma once

#include "secrets.h"

#define DEBUG 1

#define NTP_SERVER "pool.ntp.org"
#define GMT_OFFSET_SEC 0
#define DAYLIGHT_OFFSET_SEC 3600
#define TIME_SYNC_TIMER_NUMBER 3
#define TIME_SYNC_INTERVAL_PRESCALER 80
#define TIME_SYNC_INTERVAL_TICKS 1000000

#define DHT_SENSOR



#if defined(DHT_SENSOR)
#define DHTPIN 15
#define DHTTYPE DHT22
#define DHT_READING_INTERVAL 3000
#endif