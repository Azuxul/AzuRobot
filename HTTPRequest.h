#pragma once

#include <Arduino.h>
#include <LWiFi.h>
#include <LWiFiClient.h>

class HTTPRequest
{
public:

  HTTPRequest(char *host, String serverPath, uint16_t port, String result) : _host(host), _serverPath(serverPath), _port(port), _result(result) {};

  void updateRequest();
  void restart();
  void writeDataToBuffer(int *dataBuffer);
  bool isRequestEnd() {return requestEnd;};
  
private:

  LWiFiClient wifiClient;
  bool requestSend;
  bool requestEnd;
  int data[10] = {};
  const String _result;
  const uint16_t _port;
  const char *_host;
  const String _serverPath;
};
