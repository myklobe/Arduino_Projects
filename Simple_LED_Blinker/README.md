"# Arduino_Projects" 

For use with Arduino Create Studio - https://create.arduino.cc/editor/

I have created a simple LED blinking sketch to work with an Arduino Mega

My LED Matrix: https://www.amazon.com/gp/product/B06W9F1J2Z/ - 
Cylewet MAX7219 Dot Matrix Module 4 in 1 Display for Arduino Microcontroller with 5Pin Line CYT1045

My Arduino Mega - https://www.amazon.com/gp/product/B016JWNYBE

My Setup:
I connected a jumper wire from the ground pin on Arduino to ground bank on my breadboard
From ground bank on breadboard, I jumped a 330 ohm (up to 1k) resistor to row 6 on my breadboard
I plugged in the short lead on the LED to row 6 on the breadboard
I plugged in the long lead on the LED in to row 5 on breadboard
I connected a red wire from row 5 on the Breadboard to Pin 8 on Arduino

My code uses these values. You can modify them for whichever pins you wish on your Arduino.