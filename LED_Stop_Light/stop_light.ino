// Basic blinking LED lights using pins 6, 7, and 8
// Connect a wire from the ground pin on Arduino to ground bank on breadboard
// From ground bank on breadboard, jump a 330 ohm resistor to row 6 on breadboard
// Plug in short lead on LED to row 6 on breadboard
// Plug in long lead on LED on row 5 on breadboard
// Connect Red wire from row 5 on the Arduino to Pin 8 on Arduino
// Repeat on pins 7 and 6 for yellow and green LEDs
// You can reuse the ground jumper

int redLEDPin8 = 8;                   // Red LED connected to pin 8
int yellowLEDPin7 = 7;                // Yellow LED connected to pin 7 
int greenLEDPin6 = 6;                 // Green LED connected to pin 6

void setup()
{
  pinMode(redLEDPin8, OUTPUT);        // sets the digital pin as output
  pinMode(yellowLEDPin7, OUTPUT);     // sets the digital pin as output
  pinMode(greenLEDPin6, OUTPUT);      // sets the digital pin as output
}

void loop()
{
  digitalWrite(redLEDPin8, HIGH);     // sets the Red LED on
  delay(5000);                        // waits for 5 seconds
  digitalWrite(redLEDPin8, LOW);      // sets the Red LED off
  delay(50);                          // waits for 1/20 second
  
  digitalWrite(yellowLEDPin7, HIGH);  // sets the Yellow LED on
  delay(2000);                        // waits for 2 seconds
  digitalWrite(yellowLEDPin7, LOW);   // sets the Yellow LED off
  delay(50);                          // waits for 1/20 second
  
  digitalWrite(greenLEDPin6, HIGH);   // sets the Green LED on
  delay(5000);                        // waits for 5 seconds
  digitalWrite(greenLEDPin6, LOW);    // sets the Green LED off
  delay(50);                          // waits for 1/20 second
  
}