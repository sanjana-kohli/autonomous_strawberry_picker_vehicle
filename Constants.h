#ifndef CONFIG_H
#define CONFIG_H

#include "Constants.h"

// ----- Pins ----- //

// Front ultrasonic sensors pins //

#define FRONT_LEFT_TRIG 18    // Trig Yellow
#define FRONT_LEFT_ECHO 19    // Echo Green
#define FRONT_MID_TRIG 14
#define FRONT_MID_ECHO 15
#define FRONT_RIGHT_TRIG 17
#define FRONT_RIGHT_ECHO 20

// Rear ultrasonic sensors pins //

#define REAR_LEFT_TRIG 10
#define REAR_LEFT_ECHO 11
#define REAR_MID_TRIG 8
#define REAR_MID_ECHO 9
#define REAR_RIGHT_TRIG 6
#define REAR_RIGHT_ECHO 7

// Side ultrasonic sensors pins //

//#define SIDE_LEFT_TRIG 4
//#define SIDE_LEFT_ECHO 5
//#define SIDE_RIGHT_TRIG 27
//#define SIDE_RIGHT_ECHO 28

// Servo pins //

#define ESC_SERVO 22
#define STEER_SERVO 21

#define STRAWBERRY 13

extern bool estop;
extern bool previousEstop;

extern unsigned long stuck_Timer;
extern DriveDirection driveDir;

extern SensorGroup frontSensors;
extern SensorGroup rearSensors;
extern SensorGroup* activeSensors;

extern int previousSpeed;
extern int throttleInput; 
extern int currentSpeed;
extern int speedInput;
extern int steerInput;


void TEAM_42();

#endif

/*
PIN 1
PIN 2
PIN 3     Light Resistor            //
PIN 4     Left Side Trig    //
PIN 5     Left Side Echo    //
PIN 6     Rear Right Trig
PIN 7     Rear Right Echo
PIN 8     Rear Mid Trig
PIN 9     Rear Mid Echo
PIN 10    Rear Left Trig
PIN 11    Rear Left Echo
PIN 12    
PIN 13
PIN 14    Front Mid Trig
PIN 15    Front Mid Echo
PIN 16    Right Side Trig     //
PIN 17    Front Right Trig
PIN 18    Front Left Trig
PIN 19    Front Left Echo
PIN 20    Front Right Echo
PIN 21    Steer Servo
PIN 22    ESC Servo
PIN 23
PIN 24
PIN 25
PIN 26    Throttle IN
PIN 27    Steer IN
PIN 28    Right Side Echo   //
PIN 29
PIN 30
PIN 31
PIN 32
PIN 33
PIN 34
PIN 35
PIN 36
PIN 37
PIN 38
PIN 39
PIN 40
*/