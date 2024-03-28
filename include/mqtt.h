#pragma once

#include<PubSubClient.h>
#include<WiFiClientSecure.h>

#include "config.h"

void setupMQTT();
void callbackMQTT(char *topic, byte *payload, unsigned int length);
void connectToMQTT();
void publishToMQTT(char* p_topic, char* p_payload);
void publishToMQTT(char* payload);