const int red_led = 8;
const int yellow_led = 7;
const int green_led = 6;

bool randomMode = false;
bool stopLightRunning = false;

void setup() {
  Serial.begin(9600);
  pinMode(red_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(green_led, OUTPUT);

  randomSeed(analogRead(0));
}

void loop() {
  // --- SERIAL COMMAND LOGIC ---
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    data.trim();

    // RED LED Control
    if (data == "RED_LED_ON") digitalWrite(red_led, HIGH);
    else if (data == "RED_LED_OFF") digitalWrite(red_led, LOW);

    // YELLOW LED Control
    else if (data == "YELLOW_LED_ON") digitalWrite(yellow_led, HIGH);
    else if (data == "YELLOW_LED_OFF") digitalWrite(yellow_led, LOW);

    // GREEN LED Control
    else if (data == "GREEN_LED_ON") digitalWrite(green_led, HIGH);
    else if (data == "GREEN_LED_OFF") digitalWrite(green_led, LOW);

    else if (data == "ALL_ON") {
      digitalWrite(red_led, HIGH);
      digitalWrite(yellow_led, HIGH);
      digitalWrite(green_led, HIGH);
    }

    else if (data == "ALL_OFF") {
      digitalWrite(red_led, LOW);
      digitalWrite(yellow_led, LOW);
      digitalWrite(green_led, LOW);
    }

    // Disco Mode
    else if (data == "DISCO_MODE_ON") {
      randomMode = true;
      stopLightRunning = false; // Turn off stop light if disco starts
      Serial.println("Random Mode Activated");
    }
    else if (data == "DISCO_MODE_OFF") {
      randomMode = false;
      digitalWrite(red_led, LOW);
      digitalWrite(yellow_led, LOW);
      digitalWrite(green_led, LOW);
      Serial.println("Random Mode Stopped");
    }

    // Stop Light Control
    else if (data == "STOP_LIGHT_ON") {
      stopLightRunning = true;
      randomMode = false; // Turn off disco if stop light starts
      Serial.println("Stop Light Activated");
    }
    else if (data == "STOP_LIGHT_OFF") {
      stopLightRunning = false;
      digitalWrite(green_led, LOW);
      digitalWrite(red_led, LOW);
      digitalWrite(yellow_led, LOW);
      Serial.println("Stop Light Deactivated");
    }
  }

  // --- EXECUTION LOGIC ---

  if (randomMode) {
    digitalWrite(red_led, random(0, 2));
    digitalWrite(yellow_led, random(0, 2));
    digitalWrite(green_led, random(0, 2));
    delay(100);
  }

  // New Loop for Stop Light
  if (stopLightRunning) {
    digitalWrite(green_led, HIGH);
    delay(3000);
    digitalWrite(green_led, LOW);
    delay(50);

    digitalWrite(yellow_led, HIGH);
    delay(1500);
    digitalWrite(yellow_led, LOW);
    delay(50);

    digitalWrite(red_led, HIGH);
    delay(3000);
    digitalWrite(red_led, LOW);
    delay(50);
  }
}