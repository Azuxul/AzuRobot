#pragma once

#include <Arduino.h>
#include "Pins.h"

struct MotorPower {
  int _motorLeftFornt;
  int _motorRightFront;
  int _motorLeftBack;
  int _motorRightBack;

  MotorPower(int motorLeftFornt, int motorRightFront, int motorLeftBack, int motorRightBack) : _motorLeftFornt(motorLeftFornt), _motorRightFront(motorRightFront), _motorLeftBack(motorLeftBack), _motorRightBack(motorRightBack) {};
};

class MotorManager
{
public:

  MotorManager();
  
  void init();
  void stop();
  void changeWithPower(MotorPower power);
private:

};
