#include <Arduino.h>
#include "config.h"

#if defined(DHT_SENSOR)
#include <DHT.h>
#endif

#include "sensors.h"

struct sensorsReadingsType sensorsReadings;
char payload[50] = {0}; //TODO

void sensorsRead()
{
#if defined(DHT_SENSOR)
    static unsigned long dhtLastReadingTime = 0L;
    unsigned long dhtCurrentReadingTime = millis();
    if(dhtCurrentReadingTime - dhtLastReadingTime > DHT_READING_INTERVAL)
    {
        sensorsReadings.dhtTemperature = getDHTTemperature();
        sensorsReadings.dhtHumidity = getDHTHumidity();
        sensorsReadings.dhtHeatIndex = getDHTHeatIndex(sensorsReadings.dhtTemperature, sensorsReadings.dhtHumidity);
        dhtLastReadingTime = dhtCurrentReadingTime;
    }
#endif
}

void setupSensors()
{
#if defined(DHT_SENSOR)
    setupDHT();
#endif
}


#if defined(DHT_SENSOR)
DHT dht(DHTPIN, DHTTYPE);
static float lastDHTTemperature;
static float lastDHTHumidity;
#endif


#if defined(DHT_SENSOR)
void setupDHT()
{
    dht.begin();
    delay(2000);
}

float getDHTTemperature()
{
    float temperature = dht.readTemperature();

    if (isnan(temperature)) 
    {
        Serial.print("NNNN");
        return lastDHTTemperature;
    }
    lastDHTTemperature = temperature;
    return temperature;
}

float getDHTHumidity()
{
    float humidity = dht.readHumidity();
    if (isnan(humidity))
    {
        return lastDHTHumidity;
    }
    lastDHTHumidity = humidity;
    return humidity;
}

float getDHTHeatIndex(float temperature, float humidity)
{
    float heatIndex = dht.computeHeatIndex(temperature, humidity, false);
    return heatIndex;
}
#endif

char * getPayload()
{
#if defined(DHT_SENSOR)
    sprintf(payload, "Temp: %.2f,  Hum: %.2f, HI: %.2f",sensorsReadings.dhtTemperature, sensorsReadings.dhtHumidity, sensorsReadings.dhtHeatIndex);
#endif
    return payload;
}