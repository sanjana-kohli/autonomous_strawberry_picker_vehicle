#include "Direction.h"
#include "Config.h"
#include "Constants.h"

#include <Arduino.h>

FlipState flipState = IDLE;
unsigned long flipStartTime = 0;

void updateFlip(bool triggerFlip) {
  unsigned long now = millis();

  // ---- TRIGGER ----
  if (triggerFlip && flipState == IDLE) {
    esc.write(SPEED_STOP);      // stop ESC first
    steer.write(STEER_CENTER);  // straighten wheels
    flipState = WAITING_TO_FLIP;
    flipStartTime = now;
  }

  // ---- STATE MACHINE ----
  switch (flipState) {

    case WAITING_TO_FLIP:
      // give ESC time to go neutral
      if (now - flipStartTime >= 300) {

        if (driveDir == DRIVE_FORWARD) {
          driveDir = DRIVE_REVERSE;
          activeSensors = &rearSensors;
          Serial.println("SWITCHED TO REVERSE MODE");
        } else {
          driveDir = DRIVE_FORWARD;
          activeSensors = &frontSensors;
          Serial.println("SWITCHED TO FORWARD MODE");
        }

        flipState = FLIPPING;
        flipStartTime = now;
      }
      break;

    case FLIPPING:
      // allow ESC to settle in new direction
      if (now - flipStartTime >= 150) {
        flipState = IDLE;
      }
      break;

    case IDLE:
    default:
      break;
  }
}