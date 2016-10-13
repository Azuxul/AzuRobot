#include <LiquidCrystal_I2C.h>
#include <LBattery.h>
#include "ServerSync.h"
#include "MotorManager.h"

UltrasonicSensor ultrasonicSensor = UltrasonicSensor();
ServerSync sync = ServerSync();
MotorManager motorManager = MotorManager();
LiquidCrystal_I2C lcd(0x27, 16, 2);
int bLevel;
bool batteryCharging;

void setup() {

  motorManager.init();

  lcd.begin();
  lcd.home();
  
  Serial.begin(115200);
  sync.init();

  lcd.print("UID: " + sync.getUid());

  bLevel = LBattery.level();
  batteryCharging = LBattery.isCharging();

  updateBatteryLevel();
}

void loop() {
  
  int newBatteryLevel = LBattery.level();
  bool newBatteryCharging = LBattery.isCharging();

  if(bLevel != newBatteryLevel || batteryCharging != newBatteryCharging) {
    
    bLevel = newBatteryLevel;
    batteryCharging = newBatteryCharging;
    
    updateBatteryLevel();
  }

  sync.updateGlobalStatus();
  motorManager.changeWithPower(sync.getMotorsPower());
}

void updateBatteryLevel() {

  lcd.clear();
  lcd.home();
  lcd.print("UID: " + sync.getUid());
  lcd.setCursor(0, 1);
  lcd.print("Battery: ");
  lcd.print(bLevel);
  lcd.print("%");
  if(batteryCharging) {
    lcd.print("+");
  }
  sync.updateBattery(bLevel, batteryCharging);
}


