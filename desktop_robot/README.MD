## 🛠 Implementation Details

The software logic is built around a **State Machine** architecture to ensure the robot remains responsive even while "sleeping" or "thinking."

*   **Non-Blocking Timing:** The code uses `millis()` instead of `delay()`. This allows the ESP8266 to constantly poll the touch sensor for a "Wake Up" signal while simultaneously tracking the 5-minute timeout.
*   **State Management:** A boolean flag `isAwake` tracks the robot's status.
    *   **Awake State:** The robot cycles through random eye animations every 3 seconds.
    *   **Interaction State:** If the touch sensor is triggered, the robot immediately switches to a "Focused" eye type and resets the 5-minute countdown.
    *   **Sleep State:** After 5 minutes of inactivity, the OLED is cleared and the logic halts until the next touch interaction.
*   **I2C Communication:** Configured specifically for the ESP8266 hardware pins (D2/D1) to communicate with the SSD1306 OLED display.

## 🚀 How to Use

Follow these steps to deploy the code to your robot:

1.  **Install Libraries:**
    *   Open the Arduino IDE.
    *   Go to **Sketch** -> **Include Library** -> **Manage Libraries**.
    *   Search for and install:
        *   `FluxGarage RoboEyes`
        *   `Adafruit SSD1306`
        *   `Adafruit GFX Library`
2.  **Configure Board:**
    *   Go to **Tools** -> **Board** and select your ESP8266 model (NodeMCU 1.0 ESP-12E module matches my pin out).
    *   Ensure the **Port** is correctly selected.
3.  **Upload:**
    *   Copy the provided code into a new sketch.
    *   Click the **Upload** button.
4.  **Testing:**
    *   Upon power-up, the eyes will begin random animations.
    *   Tap the touch sensor to see the eyes "focus" and reset the timer.

## 🔌 Wiring Confirmation

Ensure your hardware is connected as follows before powering on the board:

| Component | Pin Name | ESP8266 Pin | Note |
| :--- | :--- | :--- | :--- |
| **OLED Screen** | SDA | **D20** | I2C Data |
| **OLED Screen** | SCL | **D21** | I2C Clock |
| **OLED Screen** | VCC | **5V / 3.3V** | Check screen specs |
| **OLED Screen** | GND | **GND** | Ground |
| **Touch Sensor** | I/O | **D5** | Digital Input |
| **Touch Sensor** | VCC | **5V / 3.3V** | Power |
| **Touch Sensor** | GND | **GND** | Ground |