#pragma once

#include "config.h"

struct sensorsReadingsType
{
#if defined(DHT_SENSOR)
    float dhtTemperature;
    float dhtHumidity;
    float dhtHeatIndex;
#endif
};

extern struct sensorsReadingsType sensorsReadings;

void sensorsRead();
void setupSensors();

#if defined (DHT_SENSOR)
#define DHTTYPE DHT22
#define DHT_SENSOR_EVT
#endif

#if defined(DHT_SENSOR)
    void setupDHT(void);
    float getDHTTemperature(void);
    float getDHTHumidity(void);
    float getDHTHeatIndex(float temperature, float humidity);
#endif

char * getPayload();