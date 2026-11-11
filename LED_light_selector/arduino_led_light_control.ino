// Pin Definitions
const int RED_PIN = 8;
const int YELLOW_PIN = 7;
const int GREEN_PIN = 6;

void setup() {
  // Initialize Serial Communication at 9600 bits per second
  Serial.begin(9600);

  // Set all LED pins as OUTPUT
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  // Start with all lights off
  allOff();

  // Print a welcome message
  Serial.println("--- LED Control System ---");
  Serial.println("Enter a command:");
  Serial.println("Options: red, yellow, green, all on, all off");
}

void loop() {
  // Check if the user has typed anything in the Serial Monitor
  if (Serial.available() > 0) {
    // Read the incoming string until a newline character
    String input = Serial.readStringUntil('\n');

    // Remove any hidden characters (like \r)
    input.trim();

    // Convert input to lowercase to make it case-insensitive
    input.toLowerCase();

    Serial.print("You entered: ");
    Serial.println(input);

    // Logic to handle the input
    if (input == "red") {
      turnOnRed();
    }
    else if (input == "yellow") {
      turnOnYellow();
    }
    else if (input == "green") {
      turnOnGreen();
    }
    else if (input == "all on") {
      turnAllOn();
    }
    else if (input == "all off") {
      allOff();
    }
    else {
      Serial.println("Invalid command. Please try again.");
    }
  }
}

// --- Helper Functions to control the lights ---

void turnOnRed() {
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  Serial.println("Red light is ON");
}

void turnOnYellow() {
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  Serial.println("Yellow light is ON");
}

void turnOnGreen() {
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  Serial.println("Green light is ON");
}

void turnAllOn() {
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  Serial.println("All lights are ON");
}

void allOff() {
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  Serial.println("All lights are OFF");
}
