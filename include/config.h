#pragma once

#include "secrets.h"

#define DEBUG 1

#define NTP_SERVER "pool.ntp.org"
#define GMT_OFFSET_SEC 0
#define DAYLIGHT_OFFSET_SEC 3600

#define DHT_SENSOR



#if defined(DHT_SENSOR)
#define DHTPIN 15
#define DHTTYPE DHT22
#define DHT_READING_INTERVAL 3000
#endif