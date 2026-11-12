# Arduino LED Matrix Control System

## 🛠 Hardware Requirements
* PC / laptop
* Arduino Mega 2560 - (Mine - https://www.amazon.com/gp/product/B016JWNYBE)
* MAX7219 Dot Matrix Module 4 in 1 Display - (Mine - https://www.amazon.com/gp/product/B06W9F1J2Z/)
    *   *Note: FC16 is the hardware type in the MD_MAX72xx library*
* Jumper wires (Female --> Male)

## 🛠 Libraries Neeeded
* MD_Parola.h    // https://github.com/MajicDesigns/MD_Parola - Download here
* MD_MAX72xx.h   // https://github.com/MajicDesigns/MD_MAX72xx - Download here
* SPI.h          // https://github.com/PaulStoffregen/SPI - Download here

## 🔌 Wiring Diagram (Breadboard View)
```text
	   ARDUINO MEGA 2560						LED Matrix
    +-------------------+
    |					|
    | [POWER SIDE GND]--|-------------------------( GND )----->
    |					|
    | [POWER SIDE 5V]---|-------------------------( VCC )----->
    |					| 
    | [Pin 13]----------|-------------------------( CLK )----->
    |					|
    | [Pin 11]----------|-------------------------( DIN )----->
    |					|
    | [Pin 10]----------|-------------------------( CS )------>
    +-------------------+                                                       
```

## 🚀 Getting Started

### 1. Preparation
* Download all contents of this repository to your local machine.
* Extract/Open the folder.
* Edit the `LED_Matrix_Control_System.ino` file.
    *   *Search for the `char newMessage[BUF_SIZE] = { "Scrolling Text is Fun!" };` line.*
	*   *Edit the text to what you want to display on the LED Matrix.*
    *   *Save the file.*

### 2. Firmware Setup
1. Launch the **Arduino IDE**.
2. **Select your board**: Go to *Tools > Board* and select **Arduino Mega 2560**.
3. **Load Libraries**: Click the Sketch Menu, Include Library, Manage Libraries.
    *   *Search for MD_MAX72xx.h and install (if not installed).*
    *   *Search for MD_Parola.h and install (if not installed).*
    *   *Search for SPI and install (if not installed).*
3. **Load the script**: Copy the code from `LED_Matrix_Control_System` into a new sketch in the IDE.
4. **Compile**: Click the **Checkmark** icon (Verify). You should see a "Done Compiling" message.
5. **Upload**: Click the **$\rightarrow$ arrow** icon (Upload). You should see a "Done Uploading" message.
6. **Close**: Once uploaded, close the Arduino IDE (no need to save changes).

## ✨ Features
* The example I've created has a text block that scrolles over 4 LED Matrixes (4x38) from right to left, marquee style.
    *   *Note: The text scrolling will repeat automatically until you remove power from the Arduino Mega.*
