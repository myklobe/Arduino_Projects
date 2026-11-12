# Arduino LED Control System

A web-based interface to control a set of LEDs (Red, Yellow, Green) connected to an Arduino Mega 2560.

## 🛠 Hardware Requirements
* Arduino Mega 2560
* Breadboard
* 3x LEDs (Red, Yellow, Green)
* 3x Resistors (appropriate for your LEDs)
* Jumper wires

## 🔌 Wiring Diagram (Breadboard View)
```text
ARDUINO MEGA 2560         BREADBOARD (Wiring View)
    +-----------+
    |           |
    | [Pin 6] --|-----------[Resistor]-----((+ long) LED Green (-))-----|
    |           |                                                       |
    | [Pin 7] --|-----------[Resistor]-----((+ long) LED Yellow (-))----|---- [GND RAIL]
    |           |                                                       |         |
    | [Pin 8] --|-----------[Resistor]-----((+ long) LED Red (-))-------|         |
    |           |                                                       |         |
    | [GND] ----|-------------------------------------------------------|---------|
    |           |                                                       |
    +-----------+                                                       |
                                                                    [GROUND]
```

## 🚀 Getting Started

### 1. Preparation
* Download all contents of this repository to your local machine.
* Extract/Open the folder.

### 2. Firmware Setup
1. Launch the **Arduino IDE**.
2. **Select your board**: Go to *Tools > Board* and select **Arduino Mega 2560**.
3. **Load the script**: Copy the code from `led_control_setup.ino` into a new sketch in the IDE.
4. **Compile**: Click the **Checkmark** icon (Verify). You should see a "Done Compiling" message.
5. **Upload**: Click the **$\rightarrow$ arrow** icon (Upload). You should see a "Done Uploading" message.
6. **Close**: Once uploaded, close the Arduino IDE (no need to save changes).

### 3. Web Interface Setup
1. Open `index.html` in a web browser (tested successfully in **Chrome**).
2. Click the **Connect to Arduino** button on the webpage.
3. A "Connect to a serial port" pop-up will appear.
4. Select your Arduino board's COM port and click **Connect**.
5. You should see a `Status: Connected` message on the page.

## ✨ Features
Once connected, you can control the LEDs using the following modes:

*   **Basic Controls**: Individually toggle the Red, Yellow, and Green LEDs.
*   **All LEDs On/Off**: Quickly toggle all lights simultaneously.
*   **Disco Mode**: A randomizer that cycles through the LEDs randomly.
    *   *Note: This repeats automatically until you click the **Stop** button.*
*   **Stop Light Simulator**: A programmed sequence:
    *   **Green**: 3 seconds
    *   **Yellow**: 1.5 seconds
    *   **Red**: 3 seconds
    *   *Note: This repeats automatically until you click the **Stop** button.*