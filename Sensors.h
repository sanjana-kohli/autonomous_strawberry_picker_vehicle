#include <Arduino.h>
#include "Sensors.h"
#include "Config.h"
#include "Constants.h"

long readUltrasonic(int trig, int echo) {
  long sum = 0;
  const int samples = 5;
  for (int i = 0; i < samples; i++) {
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    long duration = pulseIn(echo, HIGH, 30000);
    if (duration == 0) return DIST_LONG;
    sum += (duration * 0.0343) / 2;
    delay(10);
  }
  return sum / samples;
}