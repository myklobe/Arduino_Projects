// This is code for the Arduino IDE
// Copy and paste into Arduino IDE
// Click the check mark
// Push to board
// Close Arduino IDE before launching Website

// Connect Pin 5 GND on Arduino Mega to breadboard
const int red_led = 8; // Pin 8 on Arduino board is wired to Red LED
const int yellow_led = 7; // Pin 7 on Arduino board is wired to Yellow LED
const int green_led = 6; // Pin 6 on Arduino board is wired to Green LED

bool randomMode = false; // Random mode initial state
bool stopLightRunning = false; // Stop Light initial state

void setup() {
  Serial.begin(9600); // Serial setup COM3 9600
  pinMode(red_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(green_led, OUTPUT);

  randomSeed(analogRead(0)); // Seeding randomizer
}

void loop() {
  // --- SERIAL COMMAND LOGIC ---
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    data.trim();

    // RED LED Only Control
    if (data == "RED_LED_ON") digitalWrite(red_led, HIGH);
    else if (data == "RED_LED_OFF") digitalWrite(red_led, LOW);

    // YELLOW LED Only Control
    else if (data == "YELLOW_LED_ON") digitalWrite(yellow_led, HIGH);
    else if (data == "YELLOW_LED_OFF") digitalWrite(yellow_led, LOW);

    // GREEN LED Only Control
    else if (data == "GREEN_LED_ON") digitalWrite(green_led, HIGH);
    else if (data == "GREEN_LED_OFF") digitalWrite(green_led, LOW);

    // All On Control
    else if (data == "ALL_ON") {
      digitalWrite(red_led, HIGH);
      digitalWrite(yellow_led, HIGH);
      digitalWrite(green_led, HIGH);
    }

    // All Off Control
    else if (data == "ALL_OFF") {
      digitalWrite(red_led, LOW);
      digitalWrite(yellow_led, LOW);
      digitalWrite(green_led, LOW);
    }

    // Disco Mode ON
    else if (data == "DISCO_MODE_ON") {
      randomMode = true;
      stopLightRunning = false; // Turn off stop light if disco starts
      Serial.println("Random Mode Activated");
    }

    // Disco Mode OFF
    else if (data == "DISCO_MODE_OFF") {
      randomMode = false;
      digitalWrite(red_led, LOW);
      digitalWrite(yellow_led, LOW);
      digitalWrite(green_led, LOW);
      Serial.println("Random Mode Stopped");
    }

    // Stop Light ON
    else if (data == "STOP_LIGHT_ON") {
      stopLightRunning = true;
      randomMode = false; // Turn off disco if stop light starts
      Serial.println("Stop Light Activated");
    }

    // Stop Light OFF
    else if (data == "STOP_LIGHT_OFF") {
      stopLightRunning = false;
      digitalWrite(green_led, LOW);
      digitalWrite(red_led, LOW);
      digitalWrite(yellow_led, LOW);
      Serial.println("Stop Light Deactivated");
    }
  }

  // --- EXECUTION LOGIC ---

  if (randomMode) { //For Disco Mode
    digitalWrite(red_led, random(0, 2));
    digitalWrite(yellow_led, random(0, 2));
    digitalWrite(green_led, random(0, 2));
    delay(100);
  }

  // Loop for Stop Light
  if (stopLightRunning) {
    digitalWrite(green_led, HIGH); // Green LED ON
    delay(3000); // 3 seconds on
    digitalWrite(green_led, LOW); // Green LED OFF
    delay(50); // .5 second delay

    digitalWrite(yellow_led, HIGH); // Yellow LED ON
    delay(1500); // 1.5 seconds on
    digitalWrite(yellow_led, LOW); //Yellow LED OFF
    delay(50); // .5 second delay

    digitalWrite(red_led, HIGH); // Red LED ON
    delay(3000); // 3 seconds on
    digitalWrite(red_led, LOW); // Red LED OFF
    delay(50); // .5 second delay
  }
}