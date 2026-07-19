#ifndef CONSTANTS_H
#define CONSTANTS_H

const int Strawberry_Picking_Time = 1000;

const int STEER_CENTER = 90;
const int STEER_MIN = 45;
const int STEER_MAX = 135;

// Distance thresholds
const long DIST_LONG = 200;
const long DIST_MID  = 60;
const long DIST_NEAR = 30;
const long DIST_STOP = 15;

const long SPEED_UP = 2;
const long SLOW_DOWN = 8;



enum FlipState {
  IDLE,
  WAITING_TO_FLIP,
  FLIPPING
};

// Speed values
enum Speed{
  SPEED_STOP   = 90,
  SPEED_REV    = 80,
  SPEED_CRAWL  = 100,
  SPEED_SLOW   = 105,
  SPEED_FAST   = 110
};

struct SensorGroup {
  int leftTrig, leftEcho;
  int midTrig, midEcho;
  int rightTrig, rightEcho;
};

enum DriveDirection {
  DRIVE_FORWARD,
  DRIVE_REVERSE
};

#endif