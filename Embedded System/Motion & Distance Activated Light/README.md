# Motion & Distance Activated Light (Sensor Fusion)

## Objective
To combine multiple sensors (PIR and Ultrasonic) to make a logical decision based on environmental conditions.

## Components
* Arduino Uno R3
* PIR Motion Sensor
* HC-SR04 Ultrasonic Distance Sensor
* Red LED & 220Ω Resistor
* Breadboard & Jumper Wires

## Description
This project acts as a dual-verification proximity alarm. The system turns on an LED alert **only** when motion is detected by the PIR sensor **AND** an object is detected within a 50cm range by the ultrasonic sensor. If only one or neither condition is met, the LED remains off.

## 🎥 Simulation Preview

<img width="1916" height="895" alt="Motion and Distance Activated Light" src="https://github.com/user-attachments/assets/1c00abba-8629-4d64-9220-23b2b1210610" />


## 🚀 Live Simulation
You can view the circuit wiring and test the live simulation directly in your browser using Tinkercad!
[👉 Click here to view and run the Tinkercad Simulation](https://www.tinkercad.com/things/hlYFNgLIR1Y-motion-and-distance-activated-light)

## Learning Outcome
* Multi-sensor integration in embedded systems
* Implementing conditional logic (AND/OR gates) in C++
* Prototyping and simulating hardware circuits virtually
