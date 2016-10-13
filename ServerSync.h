#pragma once

#include <Arduino.h>
#include <LWiFi.h>
#include <LWiFiClient.h>
#include "MotorManager.h"
#include "HTTPRequest.h"

#define WIFI_AP "123456789"
#define WIFI_PASSWORD "123456789"
#define WIFI_AUTH LWIFI_WPA 
#define API_URL "api.azuxul.fr"

class ServerSync
{
public:

  ServerSync();

  void updateGlobalStatus();
  void init();
  void updateBattery(int level, bool charging);
  MotorPower getMotorsPower();
  String getUid() {return uid;};
  
private:

  LWiFiClient wifiClient;
  HTTPRequest* mainRequest;
  HTTPRequest* secondaryRequest;
  int data[10] = {};
  String uid;
};
