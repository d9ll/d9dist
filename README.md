# d9dist 📏

**Advanced ultrasonic distance sensing for Arduino with built-in filtering.**

`d9dist` is a lightweight, high-performance library designed for **HC-SR04** and **HY-SRF05** sensors. It eliminates "jumpy" data and simplifies distance logic for robots and smart devices.

## ✨ Key Features
* **🛡️ Smart Filtering:** Uses an exponential moving average to filter out sensor noise.
* **🤖 Non-Blocking:** Optimized 30ms timeouts to keep your main loop running fast.
* **⚡ One-Line Logic:** Use the `near(cm)` function to check proximity instantly.
* **💎 Clean API:** No more complex math in your sketches.

## 🚀 Quick Start
```cpp
#include <d9dist.h>

d9dist sensor(12, 11); // Trig, Echo

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (sensor.near(15)) {
    Serial.println("Object detected!");
  }
  delay(50);
}
