// I have customized an example from the MD_Parola library to make this simple 8x32 LED Might Matrix scroller
// My LED Matrix: https://www.amazon.com/gp/product/B06W9F1J2Z/
// Cylewet MAX7219 Dot Matrix Module 4 in 1 Display for Arduino Microcontroller with 5Pin Line CYT1045 (FC16 is this hardware type)

// My Arduino Mega - https://www.amazon.com/gp/product/B016JWNYBE

// Include the 3 required libraries
#include <MD_Parola.h>    // https://github.com/MajicDesigns/MD_Parola - Download here
#include <MD_MAX72xx.h>   // https://github.com/MajicDesigns/MD_MAX72xx - Download here
#include <SPI.h>          // https://github.com/PaulStoffregen/SPI - Download here

#define MAX_DEVICES 4     // # of your 8x8 LED Matrix modules (I have 4)
#define CLK_PIN 13        // From the CLK pin on your LED Matrix to the Arduino, I used Pin 13
#define DATA_PIN 11       // From the DIN / DATA pin on your LED Matrix to the Arduino, I used Pin 11
#define CS_PIN 10         // From the CS pinon your LED Matrix to the Arduino, I used Pin 10

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW   // Set your hardware type, for the LED Matrix listed above, FC16
                                            // Check the back of your Matrix, it should say
                                            //See MD_MAX72xx documentation for more types if using a different Matrix

//Setup MD_Parola
MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES); // See MD_Parola documentation for all parameters

uint8_t scrollSpeed = 25;                         // default frame delay value
textEffect_t scrollEffect = PA_SCROLL_LEFT;       // I wanted the text to scroll from right to left, See MD_Parola documentation for all scroll effects
textPosition_t scrollAlign = PA_LEFT;
uint16_t scrollPause = 2000;                      // in milliseconds

// Global message buffers for Scrolling functions
#define	BUF_SIZE	75
char curMessage[BUF_SIZE] = { "First Message..." };   // First message to display
char newMessage[BUF_SIZE] = { "Second Message..." };  // Second message to display
bool newMessageAvailable = true;

void setup(void)
{
  P.begin();
  P.displayText(curMessage, scrollAlign, scrollSpeed, scrollPause, scrollEffect, scrollEffect);   // scroll effects defined above
}

void loop()   // basic loop to make the text scroll through the entire message, pause, then repeat indefinitely
{
  if (P.displayAnimate())   // See MD_Parola documentation for more information
  {
    if (newMessageAvailable)
    {
      strcpy(curMessage, newMessage);   // displays the first message, pauses, then displays the second message
      newMessageAvailable = false;      // clears
    }
    P.displayReset();                   // Reset / Repeat
  }
}
