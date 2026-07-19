#include "Config.h"
#include "Constants.h"
#include "Sensors.h"
#include "Velocity.h"
#include "Steer.h"
#include "Direction.h"

#include <Servo.h>
#include <Arduino.h>

Servo esc;
Servo steer;

void debugOutput(DriveDirection driveDir, long Left, long Mid, long Right, int speedInput, int steerInput);

// Version 3.0 //

// PID steering added // Added in 2.0 //
// Dual Directions // 
// Updated Primative names // Added in 3.0 //
// Debug output // 

// Heat sensor notes = 70 degrees //

void setup() {
  TEAM_42();
}



/*void loop() {
  Serial.println("forward");
  esc.write(120);  // full forward
  delay(4000);

  Serial.println("stop");
  esc.write(90);   // neutral
  delay(4000);

  Serial.println("back");
  esc.write(80);   // full reverse
  delay(4000);
}*/

void loop() {

  // ---- STRAWBERRY STOP ----
  if (digitalRead(STRAWBERRY) == HIGH){
    esc.write(SPEED_STOP);
    steer.write(STEER_CENTER);
    delay(Strawberry_Picking_Time);
  }

  // ---- READ SENSORS ----
  long Left = readUltrasonic(activeSensors->leftTrig, activeSensors->leftEcho);
  long Mid = readUltrasonic(activeSensors->midTrig, activeSensors->midEcho);
  long Right = readUltrasonic(activeSensors->rightTrig, activeSensors->rightEcho);

  long nearestObstacle = min(Left, min(Mid, Right));

  // ---- STUCK DETECTION (time-based) ----
  if (nearestObstacle <= DIST_STOP) {
      if (stuck_Timer == 0) stuck_Timer = millis();  // start timer
  } else {
      stuck_Timer = 0;  // reset timer
  }

  bool shouldFlip = (stuck_Timer && millis() - stuck_Timer > 1500); // 1.5 seconds stuck

  // ---- FLIP SYSTEM (RUN FIRST!) ----
  updateFlip(shouldFlip);

  if (shouldFlip) {
    stuck_Timer = 0;
  }

  if (flipState != IDLE) {
    return;
  }

  // ---- EMERGENCY STOP ----
  EmergencyStop(nearestObstacle);
  bool currentEstop = isEmergencyStop();

  if (currentEstop) {
      esc.write(SPEED_STOP);
      steer.write(STEER_CENTER);

      Serial.println("EMERGENCY STOP");

      previousSpeed = SPEED_STOP;
      previousEstop = true;

      debugOutput(driveDir, Left, Mid, Right, speedInput, steerInput);
      return;
  }

  if (previousEstop && !currentEstop) {
      Serial.println("ESTOP CLEARED");
      previousEstop = false;
  }

  currentSpeed = calculateSpeed(nearestObstacle, driveDir);
  speedInput = speedAdjustment(previousSpeed, currentSpeed);
  steerInput = Steer(Left, Right, driveDir);

  previousSpeed = speedInput;

  esc.write(speedInput);
  steer.write(steerInput);

  debugOutput(driveDir, Left, Mid, Right, speedInput, steerInput);
}

void debugOutput(DriveDirection driveDir, long Left, long Mid, long Right, int speedInput, int steerInput) {
  Serial.print(driveDir == DRIVE_FORWARD ? "FWD " : "REV ");
  Serial.print("Left:"); Serial.print(Left); 
  Serial.print(" Mid:"); Serial.print(Mid);
  Serial.print(" Right:"); Serial.print(Right);
  Serial.print(" ESC:"); Serial.print(speedInput);
  Serial.print(" STR:"); Serial.println(steerInput);
}