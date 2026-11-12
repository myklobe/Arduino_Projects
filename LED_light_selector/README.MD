This project uses an Arduino Mega 2560 and a standard breadboard.

1.  Download all contents of this repo to your local machine (I am running Windows 11)
    A. Open the folder
2.  Launch Arduino IDE
    A. Select your board (Mine is Arduino Mega 2560)
    B. Copy led_control_setup.ino script into Arduino IDE
    C. Click the Checkmark (You will get a Done Compiling message)
    D. Click the --> arrow to Upload to the board (You will get a Done Uploading message)
    E. Once uploaded, close the Arduino IDE (don't save)
3.  Launch index.html in a browser (I tested in Chrome)
    A. In the browser, click the Connect to Arduino button
    B. A Connect to a serial port pop up will display
    C. Select your Arduino board and then click the Connect button
    D. You will see a Status: Connected message on the page
4.  You now have multiple controls of your LED lights
    A. Basic LEDs: Red LED, Yellow LED, and Green LED
    B. Special Modes: All LEDs On and Off, Disco Mode (LED Light randomizer On and Off), and Stop Light Simulator (Red for 3 seconds, Yellow for 1.5 seconds, and then Green for 3 seconds). This will repeat until you click the Stop Button.



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

