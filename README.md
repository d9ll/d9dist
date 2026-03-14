# d9dist 📏
**A smart and stable Arduino library for precision ultrasonic distance sensing.**

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Arduino-Compatible](https://img.shields.io/badge/Arduino-Compatible-00979D.svg?style=flat&logo=arduino)](https://www.arduino.cc/)

[Read this in Russian (Читать на русском)](README_RU.md)

## 📖 Overview
Measuring distance with ultrasonic sensors like **HC-SR04** or **HY-SRF05** often results in "noisy" data and jumpy values. **d9dist** solves this by implementing built-in signal filtering and a simplified API, making your robotic projects much more reliable.

## ✨ Key Features
- **🛡️ Noise Filtering:** Exponential moving average algorithm to eliminate random spikes.
- **🤖 Smart Logic:** The `near(cm)` method allows for instant proximity checks in one line.
- **⚡ Non-Blocking:** Optimized 30ms timeouts to ensure your code never freezes.
- **💎 Clean Code:** No more manual math or `pulseIn()` handling in your main sketch.

## 🛠 Wiring
- **VCC:** 5V
- **Trig (Trigger):** Digital Pin (e.g., D12)
- **Echo:** Digital Pin (e.g., D11)
- **GND:** Ground
- **OUT:** Not used (keep disconnected)



## 🚀 Quick Start
```cpp
#include <d9dist.h>

d9dist sensor(12, 11); // Trig, Echo

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Check if an object is closer than 15cm
  if (sensor.near(15)) {
    Serial.println("Object is too close!");
  } else {
    Serial.print("Distance: ");
    Serial.print(sensor.getDist());
    Serial.println(" cm");
  }
  
  delay(100);
}
