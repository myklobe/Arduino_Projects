# WORK IN PROGRESS
# PCA9685 Servo Control System (Web Interface)

A web-based control system for Raspberry Pi that allows users to control multiple servo motors via a visual slider interface. This project uses the **PCA9685** PWM driver to handle the pulse signals, allowing the Raspberry Pi to manage many servos simultaneously with high precision.

## 🚀 Features
- **Real-time Control:** Move servos instantly via a web browser.
- **Dynamic PWM Mapping:** Converts degrees (0–180°) into precise duty cycles.
- **Flask Backend:** Lightweight Python web server to handle requests.
- **Responsive UI:** Simple, mobile-friendly slider interface.

## 🛠 Hardware Requirements
- **Raspberry Pi** (3, 4, 5, or Zero 2W)
- **PCA9685** PWM Driver Board
- **Servo Motors** (e.g., SG90, MG996R)
- **External Power Supply** (5V - 6V, at least 2A recommended)
- **Jumper Wires**

### Connection Map
| PCA9685 Pin | Raspberry Pi Pin | Description |
| :--- | :--- | :--- |
| **VCC** | 3.3V (Pin 1) | Logic Power |
| **GND** | Ground (Pin 6) | Common Ground |
| **SDA** | SDA (Pin 3) | I2C Data |
| **SCL** | SCL (Pin 5) | I2C Clock |
| **V+** | External Power (+) | **DO NOT** power servos from Pi! |

## 🔌 Wiring Diagram
    +-----------------------+             +-----------------------+
    |    EXTERNAL POWER     |             |    RASPBERRY PI       |
    |   (5V - 6V Supply)    |             |       (Host)          |
    +-----------+-----------+             +-----------+-----------+
                |                                       |
       [Positive (+)] -----------------------> [V+ Terminal]
       [Negative (-)] -----------------------> [GND Terminal] (Shared)
                                                      |
                                                      | (I2C Bus)
                                                      v
    +------------------------------------------------------------------+
    |                          PCA9685 DRIVER                          |
    |                                                                  |
    |  [VCC] <--- (3.3V) -----------+           +----------------------+
    |  [GND] <--- (GND)  -----------+           |
    |  [SDA] <--- (SDA)  -----------+-----------+---- [Servo 1]
    |  [SCL] <--- (SCL)  -----------+-----------+---- [Servo 2]
    |                               |           |
    |  [V+ Terminal] <--------------+           |
    |  [GND Terminal] <-------------------------+
    +------------------------------------------------------------------+


    *   Make it clear that **VCC** is for logic (Pi) and **V+** is for motors (External). This is a common point of failure.
    *   Add a clear Pin Table for quick reference.

    *   *Diagram:*
        ```text
        [ EXTERNAL POWER ]          [ RASPBERRY PI ]          [ PCA9685 ]          [ SERVOS ]
           (5V-6V Supply)             (Host)                 (PWM Driver)         (Actuators)
                |                        |                          |                    |
                +------[ + ]------------+----[ V+ Terminal ]       |                    |
                +------[ - ]------------+----[ GND Terminal ]-------+----[ CH 0 ]------->(Servo 1)
                                         |                          |                    |
                                         +----[ 3.3V ]---------->[ VCC ]                |
                                         +----[ GND ]---------->[ GND ]                    |
                                         +----[ SDA ]---------->[ SDA ]                    |
                                         +----[ SCL ]---------->[ SCL ]                    |
                                                                      |                    |
                                                                      +----[ CH 1 ]------->(Servo 2)


## Usage
1. **Setup the Hardware:**
   - Connect the Raspberry Pi to the PCA9685 servo driver.
   - Connect the servo motors to the PCA9685 driver according to the wiring diagram.

2. **Run the Python Scripts:**
   - Run `pca9685_servo_control_system.py` to control the servos using the script.
   - Run `app.py` to start the Flask web server.

3. **Access the Web Interface:**
   - Open a web browser and go to `http://<Raspberry Pi's IP address>:5000`.
   - Use the form to move the servos by specifying the servo ID and degrees.

4. **Interact with the Servos:**
	- The web interface allows you to move the servos interactively. The servos will respond to the commands sent
through the web interface.