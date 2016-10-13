#include "HTTPRequest.h"
#include <Arduino.h>
#include <LWiFi.h>
#include <LWiFiClient.h>

void HTTPRequest::updateRequest() {

  if(!requestEnd) {
    if(!requestSend) {
      if(0 == wifiClient.connect(_host, _port)) {
        return;
      }

      String line2 = "Host: ";
      line2 += _host;
  
      wifiClient.println("GET " + _serverPath + " HTTP/1.1");
      wifiClient.println(line2);
      wifiClient.println("Connection: close");
      wifiClient.println();
  
      requestSend = true;
    }
  
    if(wifiClient.available()) {
  
      String bufferRequest;
      int dataIndex = -1;

      for(byte i = 0; i < 10; i++) {
        data[i] = 0;
      }
      
      while (wifiClient){
        int v = wifiClient.read();
        if (v != -1) {
          
          bufferRequest += (char) v;
          if(isControl(v)) {
            
            if (dataIndex > 0) {
              data[--dataIndex] = bufferRequest.toInt();
            } else if(bufferRequest.startsWith(_result)) {
              dataIndex = 10;
            }
            bufferRequest = "";
          }
        } else {
          wifiClient.stop();
        }
      }
  
      requestEnd = true;
    }
  }
}

void HTTPRequest::restart() {
  
  requestEnd = false;
  requestSend = false;
}

void HTTPRequest::writeDataToBuffer(int *dataBuffer) {

  for(byte i = 0; i < 10; i++) {
    dataBuffer[i] = data[i];
  }
}

