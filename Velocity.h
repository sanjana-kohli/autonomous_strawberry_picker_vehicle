#include "Velocity.h"
#include <Arduino.h>
#include "Config.h"
#include "Constants.h"

extern Servo esc;
extern Servo steer;

int speedAdjustment(int current, int target) {

  if (current < target) 
    return min(current + SPEED_UP, target);

  else if (current > target) 
    return max(current - SLOW_DOWN, target);

  else
  return current;
}

int calculateSpeed(long nearestObstacle, DriveDirection driveDir) {
  int safeSpeed;

  if (driveDir ==  DRIVE_REVERSE){
    return SPEED_REV;
  }

  if (nearestObstacle <= DIST_STOP) {
    safeSpeed = SPEED_STOP;
  }
  else if (nearestObstacle <= DIST_NEAR) {
    safeSpeed = SPEED_CRAWL;
  }
  else if (nearestObstacle <= DIST_MID) {
    safeSpeed = SPEED_SLOW;
  }
  else {
    safeSpeed = SPEED_FAST;
  }

  return safeSpeed;
}

void EmergencyStop(long nearestObstacle){
  //Serial.print(estop);
  if (nearestObstacle <= DIST_STOP) {
    estop = true;
  }
  if (nearestObstacle > DIST_STOP) {
    estop = false;
  }
}

bool isEmergencyStop() {
  return estop;
}