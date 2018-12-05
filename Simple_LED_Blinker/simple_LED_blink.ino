// Simple blinking LED light using pin 8
// Connect a wire from the ground pin on Arduino to ground bank on your breadboard
// From ground bank on breadboard, jump a 330 ohm (up to 1k) resistor to row 6 on breadboard
// Plug in the short lead on LED to row 6 on the breadboard
// Plug in long lead on LED in to row 5 on breadboard
// Connect Red wire from row 5 on the Breadboard to Pin 8 on Arduino

int ledPin8 = 8;                // LED connected to pin 8

void setup()
{
  pinMode(ledPin8, OUTPUT);      // sets the digital pin as output
}

void randomSleeper() // to randomize the sleeps
{
	float duration = rand() % 10 + 1;
	cout << Sleep(duration);
}

void loop()
{
  digitalWrite(ledPin8, HIGH);   // sets the LED on
  	randomSleeper();             // untested
//  delay(250);                  // waits for half a second
  digitalWrite(ledPin8, LOW);    // sets the LED off
  	randomSleeper();             // untested
//  delay(250);                  // waits for half a second
}
