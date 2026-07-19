# Autonomous Strawberry Picking Vehicle

Team 42 – CSEE Coursework

This project implements an autonomous RC vehicle capable of detecting and harvesting strawberries. The vehicle uses ultrasonic sensors for obstacle avoidance and camera based detection, and machine learning (YOLO) for object recognition.



## Table of Contents

1. [Overview](#overview)
2. [Requirements](#requirements)
3. [Installation](#installation)
4. [Known Issues](#known-issues)
5. [File Structure](#file-structure)
6. [Acknowledgements](#acknowledgements)



## Overview

This project provides:

* Autonomous navigation in a strawberry field
* Obstacle detection using ultrasonic sensors
* Speed control system
* Strawberry detection using YOLOv8
* Integration of sensors and actuators for real-world harvesting



## Requirements

* **Programming Language:**
Python 3.10+ (for Raspberry Pi and YOLO Training)

C++ / Arduino (for RC car movement and sensor control)

* **Libraries/Dependencies:**

Arduino / C++ (Movement Control)

Standard Arduino libraries (Servo.h, Wire.h)

Ultrasonic sensor library (NewPing.h)

Ultralytics

OpenCV



* **Hardware:**
Hardware

RC vehicle chassis

HCSR04 Ultrasonic sensors (front,rear and side)

Raspberry Pi Camera Module 2 x2

Raspberry Pi 5

Raspberry Pi Pico MCU

Servo Motor PWM Driver

Vehicle Power Supply

9-24V->5V5A Buck converter to power the Pi 5

Robotic arm (3D printed + MG996R + 2x MG90)

LED Lights

Buzzer

## Installation

**Setup of the Pi 5**

Install Pi5 OS Bookworm 64 bit

Connect cameras, servo driver and GPIO from Pico

Create Virtual environment for the project

Install python3 and dependencies

Run calibration\_capture.py and calibration\_compute.py

**Setup fo the Pi PICO**
Connect RC car, motors, and ultrasonic sensors

Upload Final.ino to the Arduino using the Arduino IDE

**Connect Raspberry Pi 5 GPIO Pin to the Pico GPIO Pin 17**

## Known issues

Sensor response is slightly delayed when multiple obstacles are close together

Vision Arm Control only software tested, unvalidated

Outdoor lighting can affect camera detection in direct sunlight



## Acknowledgements

YOLO Ultralytics

OpenCV

Raspberry Pi \& Arduino communities

Supervisors and teaching staff for guidance



Team 42 members for contributions to hardware software and documentation

