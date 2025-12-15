# Line Following Robot 🤖

[![Arduino](https://img.shields.io/badge/Platform-Arduino-blue)](https://www.arduino.cc/)  
[![License](https://img.shields.io/badge/License-MIT-green)](LICENSE)  

A **line-following robot** built with Arduino, infrared sensors, and DC motors. The robot can detect a black line, follow it smoothly, turn based on the sensor input, and stop if the line is lost. Ideal for learning **robotics, motor control, and sensor integration**.  

---

## Table of Contents
- [Features](#features)  
- [Components](#components)  
- [Wiring & Connections](#wiring--connections)  
- [How It Works](#how-it-works)  
- [Usage](#usage)  
- [Code Structure](#code-structure)  
- [Troubleshooting](#troubleshooting)  
- [Future Improvements](#future-improvements)  
- [License](#license)  

---

## Features
- Detects a line using **three IR sensors** (left, center, right)  
- **Smooth motor control** based on sensor input  
- Stops automatically when no line is detected  
- Turns left or right depending on which sensor detects the line  
- **Debugging info** printed to Serial Monitor for calibration  

---

## Components
- Arduino Uno (or compatible board)  
- 2 DC motors with motor driver (e.g., L298N)  
- 3 IR sensors for line detection  
- Chassis, wheels, and power supply  
- Jumper wires  

---

## Wiring & Connections

| Component     | Arduino Pin |
|---------------|-------------|
| Left Sensor   | A0          |
| Center Sensor | A1          |
| Right Sensor  | A2          |
| Left Motor    | 9 (PWM)     |
| Right Motor   | 11 (PWM)    |

> Ensure motor driver EN pins are connected and powered for PWM control.  

![Wiring Diagram](https://via.placeholder.com/600x300?text=Wiring+Diagram)  

---

## How It Works
1. **Sensor Reading**: Analog values from IR sensors are converted to binary (1 = black, 0 = white).  
2. **Motor Control Logic**:
   - Center sensor detects line → move forward  
   - Right sensor detects line → turn right (left motor faster)  
   - Left sensor detects line → turn left (right motor faster)  
   - No sensor detects line → stop  
3. **Serial Debugging**: Prints sensor values and motor speeds to help with tuning.  

---

## Usage
1. Connect all components according to the wiring table.  
2. Upload the Arduino sketch (`main.ino`) to your board.  
3. Open the **Serial Monitor** to verify sensor readings.  
4. Adjust the sensor threshold in `readSensors()` if needed:  
