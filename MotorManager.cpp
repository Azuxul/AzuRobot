#include "MotorManager.h"
#include <Arduino.h>
#include "Pins.h"

MotorManager::MotorManager() {

}

void MotorManager::init() {
  pinMode(MOTOR_LEFT_FRONT_DOWN, OUTPUT);
  pinMode(MOTOR_LEFT_FRONT_UP, OUTPUT);
  pinMode(MOTOR_RIGHT_FRONT_DOWN, OUTPUT);
  pinMode(MOTOR_RIGHT_FRONT_UP, OUTPUT);
  pinMode(MOTOR_RIGHT_BACK_DOWN, OUTPUT);
  pinMode(MOTOR_RIGHT_BACK_UP, OUTPUT);
  pinMode(MOTOR_LEFT_BACK_DOWN, OUTPUT);
  pinMode(MOTOR_LEFT_BACK_UP, OUTPUT);
  stop();
}

void MotorManager::stop() {
  digitalWrite(MOTOR_LEFT_FRONT_DOWN, LOW);
  digitalWrite(MOTOR_LEFT_FRONT_UP, LOW);
  digitalWrite(MOTOR_RIGHT_FRONT_DOWN, LOW);
  digitalWrite(MOTOR_RIGHT_FRONT_UP, LOW);
  digitalWrite(MOTOR_RIGHT_BACK_DOWN, LOW);
  digitalWrite(MOTOR_RIGHT_BACK_UP, LOW);
  digitalWrite(MOTOR_LEFT_BACK_DOWN, LOW);
  digitalWrite(MOTOR_LEFT_BACK_UP, LOW);
}

void MotorManager::changeWithPower(MotorPower power) {
  
  if(power._motorLeftFornt < 0) {
    digitalWrite(MOTOR_LEFT_FRONT_DOWN, HIGH);
    digitalWrite(MOTOR_LEFT_FRONT_UP, LOW);
  } else if(power._motorLeftFornt > 0) {
    digitalWrite(MOTOR_LEFT_FRONT_DOWN, LOW);
    digitalWrite(MOTOR_LEFT_FRONT_UP, HIGH);
  } else {
    digitalWrite(MOTOR_LEFT_FRONT_DOWN, LOW);
    digitalWrite(MOTOR_LEFT_FRONT_UP, LOW);
  }

  if(power._motorRightFront < 0) {
    digitalWrite(MOTOR_RIGHT_FRONT_DOWN, HIGH);
    digitalWrite(MOTOR_RIGHT_FRONT_UP, LOW);
  } else if(power._motorRightFront > 0) {
    digitalWrite(MOTOR_RIGHT_FRONT_DOWN, LOW);
    digitalWrite(MOTOR_RIGHT_FRONT_UP, HIGH);
  } else {
    digitalWrite(MOTOR_RIGHT_FRONT_DOWN, LOW);
    digitalWrite(MOTOR_RIGHT_FRONT_UP, LOW);
  }

  if(power._motorLeftBack < 0) {
    digitalWrite(MOTOR_RIGHT_BACK_DOWN, HIGH);
    digitalWrite(MOTOR_RIGHT_BACK_UP, LOW);
  } else if(power._motorLeftBack > 0) {
    digitalWrite(MOTOR_RIGHT_BACK_DOWN, LOW);
    digitalWrite(MOTOR_RIGHT_BACK_UP, HIGH);
  } else {
    digitalWrite(MOTOR_RIGHT_BACK_DOWN, LOW);
    digitalWrite(MOTOR_RIGHT_BACK_UP, LOW);
  }

  if(power._motorRightBack < 0) {
    digitalWrite(MOTOR_LEFT_BACK_DOWN, HIGH);
    digitalWrite(MOTOR_LEFT_BACK_UP, LOW);
  } else if(power._motorRightBack > 0) {
    digitalWrite(MOTOR_LEFT_BACK_DOWN, LOW);
    digitalWrite(MOTOR_LEFT_BACK_UP, HIGH);
  } else {
    digitalWrite(MOTOR_LEFT_BACK_DOWN, LOW);
    digitalWrite(MOTOR_LEFT_BACK_UP, LOW);
  }
}

