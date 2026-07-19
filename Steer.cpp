#ifndef SENSORS_H
#define SENSORS_H

#include "Config.h"
#include "Constants.h"

extern SensorGroup frontSensors;
extern SensorGroup rearSensors;
extern SensorGroup* activeSensors;

long readUltrasonic(int trig, int echo);


#endif