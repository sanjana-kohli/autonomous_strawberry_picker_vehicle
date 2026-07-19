#ifndef DIRECTION_H
#define DIRECTION_H

#include "Config.h"
#include "Constants.h"

#include <Servo.h>

extern Servo esc;
extern Servo steer;

extern FlipState flipState;
extern unsigned long flipStartTime;

void updateFlip(bool triggerFlip);


#endif