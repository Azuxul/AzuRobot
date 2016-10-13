#include "ServerSync.h"
#include <Arduino.h>
#include <LWiFi.h>
#include <LWiFiClient.h>
#include "MotorManager.h"
#include "HTTPRequest.h"

ServerSync::ServerSync() {
}

void ServerSync::init() {

  uid = "2a674281b";

  mainRequest = new HTTPRequest(API_URL, "/azurobot/get/?uid=" + uid + "&format=line", 80, "OK " + uid);
  
  LWiFi.begin();

  Serial.println("Connecting to WIFI");
  while (0 == LWiFi.connect(WIFI_AP, LWiFiLoginInfo(WIFI_AUTH, WIFI_PASSWORD))) {
    delay(500);
  }
  Serial.println("Connected");
}

void ServerSync::updateGlobalStatus() {

  if(mainRequest->isRequestEnd()) {
    mainRequest->restart();
  } else {
    mainRequest->updateRequest();
  }

  if(secondaryRequest != NULL && !secondaryRequest->isRequestEnd()) {
    secondaryRequest->updateRequest();
  }
  
}

void ServerSync::updateBattery(int level, bool charging) {
  secondaryRequest = new HTTPRequest(API_URL, "/azurobot/set/?uid=" + uid + "&battery-level=" + level + "&battery-charging=" + (charging?"1":"0"), 80, "");
}

MotorPower ServerSync::getMotorsPower() {

  mainRequest->writeDataToBuffer(data);

  if(data[9] == 1) {
    return MotorPower(data[8], data[7], data[6], data[5]);
    Serial.println(data[8]);
  } else {
    return MotorPower(0, 0, 0, 0);
  }
}

