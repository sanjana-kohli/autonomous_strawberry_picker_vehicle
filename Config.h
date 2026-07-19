#include "Config.h"
#include "Sensors.h"
#include <Arduino.h>
#include <Servo.h>

extern Servo esc;
extern Servo steer;

bool estop = false;
bool previousEstop = false;

unsigned long stuck_Timer = 0;

int previousSpeed = SPEED_STOP;
int throttleInput; 
int currentSpeed = SPEED_STOP;
int speedInput;
int steerInput;

SensorGroup frontSensors = {
  FRONT_LEFT_TRIG, FRONT_LEFT_ECHO,
  FRONT_MID_TRIG,  FRONT_MID_ECHO,
  FRONT_RIGHT_TRIG, FRONT_RIGHT_ECHO
};

SensorGroup rearSensors = {
  REAR_LEFT_TRIG, REAR_LEFT_ECHO,
  REAR_MID_TRIG,  REAR_MID_ECHO,
  REAR_RIGHT_TRIG, REAR_RIGHT_ECHO
};

SensorGroup* activeSensors = &frontSensors;
DriveDirection driveDir = DRIVE_FORWARD;

// ----- Setup ----- //

void TEAM_42(){
  Serial.begin(115200);
  activeSensors = &frontSensors;

  esc.attach(ESC_SERVO);  
  steer.attach(STEER_SERVO);

  esc.write(SPEED_STOP);
  steer.write(90);

  pinMode(STRAWBERRY, INPUT);


  SensorGroup all[] = { frontSensors, rearSensors };
  for (SensorGroup s : all) {
    pinMode(s.leftTrig, OUTPUT); pinMode(s.leftEcho, INPUT);
    pinMode(s.midTrig, OUTPUT); pinMode(s.midEcho, INPUT);
    pinMode(s.rightTrig, OUTPUT); pinMode(s.rightEcho, INPUT);
  }

  delay(1000);
}