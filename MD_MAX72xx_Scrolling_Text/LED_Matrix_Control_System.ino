// Include the 3 required libraries
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define MAX_DEVICES 4     // # of your 8x8 LED Matrix modules (I have 4)
#define CLK_PIN 13        // From the CLK pin on your LED Matrix to the Arduino, I used Pin 13
#define DATA_PIN 11       // From the DIN / DATA pin on your LED Matrix to the Arduino, I used Pin 11
#define CS_PIN 10         // From the CS pin on your LED Matrix to the Arduino, I used Pin 10

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW   // Set your hardware type, for the LED Matrix listed above, FC16
                                            // Check the back of your Matrix, it should say
                                            //See MD_MAX72xx documentation for more types if using a different Matrix

//Setup MD_Parola
MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES); // See MD_Parola documentation for all parameters

uint8_t scrollSpeed = 25;                   // default frame delay value
textEffect_t scrollEffect = PA_SCROLL_LEFT; // I used scroll from right to left. See MD_Parola documentation for all scroll effects
textPosition_t scrollAlign = PA_LEFT;
uint16_t scrollPause = 2000;                // in milliseconds

// Global message buffers for Scrolling functions
#define BUF_SIZE  75
char curMessage[BUF_SIZE] = { " " };
char newMessage[BUF_SIZE] = { "Scrolling Text is Fun!" }; // Edit message to display
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
      strcpy(curMessage, newMessage); // displays the message, pauses, then repeats
      P.displayReset();                   // Reset
      newMessageAvailable = true;
    }
  }
}