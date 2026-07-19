#include "steer.h"
#include <Arduino.h>

#include "Config.h"
#include "Constants.h"

float Kp = 0.8;
float Ki = 0.0;
float Kd = 0.3;

float integral = 0;
float lastError = 0;
unsigned long lastTime = 0;

int Steer(long left, long right, DriveDirection driveDir) {

  // ---- Sensor safety ----
  left  = max(left, 5L);
  right = max(right, 5L);
  float error = right - left;

  // ---- Force-based avoidance ----
  float leftForce  = 1.0 / (left * left);
  float rightForce = 1.0 / (right * right);
  //float error = rightForce - leftForce;

  // ---- Timing ----
  unsigned long now = millis();
  if (lastTime == 0) lastTime = now;
  float dt = (now - lastTime) / 1000.0;
  if (dt <= 0) dt = 0.01;
  lastTime = now;

  // ---- PID ----
  integral += error * dt;
  integral = constrain(integral, -1.0, 1.0);  // anti-windup

  float derivative = (error - lastError) / dt;
  lastError = error;

  float output = Kp * error + Ki * integral + Kd * derivative;

  if (driveDir == DRIVE_REVERSE)
    output = -output;

  // ---- Scale to servo range ----
  int steerVal = 90 + output;

  return constrain(steerVal, STEER_MIN, STEER_MAX);
}