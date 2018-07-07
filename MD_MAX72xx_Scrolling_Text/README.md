"# Arduino_Projects" 

For use with Arduino Create Studio - https://create.arduino.cc/editor/

I have customized an example from the MD_Parola library to make this simple 8x32 LED Might Matrix scroller
Add lines on my Arduino sketch have comments that explain what I've done.

My LED Matrix: https://www.amazon.com/gp/product/B06W9F1J2Z/ - 
Cylewet MAX7219 Dot Matrix Module 4 in 1 Display for Arduino Microcontroller with 5Pin Line CYT1045 - 
FC16 is this hardware type in the MD_MAX72xx library

My Arduino Mega - https://www.amazon.com/gp/product/B016JWNYBE

These are the 3 libraries I used to make my LED Matrix work
include <MD_Parola.h>    // https://github.com/MajicDesigns/MD_Parola - Download here
include <MD_MAX72xx.h>   // https://github.com/MajicDesigns/MD_MAX72xx - Download here
include <SPI.h>          // https://github.com/PaulStoffregen/SPI - Download here

The rest of the code is a basic setup with parameters - refer to the MD_Parola and MC_MAX72xx documentation for all paramters and switches

The example I've created has a text block that scrolles over 4 LED Matrixes (4x38) from right to left, marquee style.