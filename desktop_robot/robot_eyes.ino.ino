/*
//
// This section is for use with the ESP8266 Chip and the SSD1306 OLED display
// Refactor this once the Touch Sensor is wired in to ESP Chip
//
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "RoboEyes.h" // Flux Garage Library

// --- Configuration ---
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define TOUCH_PIN D5

// Timing variables
unsigned long lastInteractionTime = 0;
unsigned long lastAnimationTime = 0;
const unsigned long TIMEOUT_MS = 300000;      // 5 minutes in milliseconds
const unsigned long ANIMATION_INTERVAL = 3000; // Change animation every 3 seconds

// State variables
bool isAwake = false;
int currentAnimation = 0;

// Initialize Display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
RoboEyes eyes;

void setup() {
  Serial.begin(115200);

  // Initialize I2C for ESP8266 (D20 = SDA, D21 = SCL)
  Wire.begin(D20, D21);

  // Initialize Display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 0x3C is the standard I2C address
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  pinMode(TOUCH_PIN, INPUT);

  // Initialize RoboEyes
  eyes.begin(display);

  // Set initial state
  eyes.setEyeType(0); // Start with a default eye type
}

void loop() {
  bool touched = digitalRead(TOUCH_PIN);

  // 1. TOUCH LOGIC
  if (touched) {
    isAwake = true;
    lastInteractionTime = millis();
    // "Follow" behavior: Snap to a focused look when touched
    eyes.setEyeType(1);
  }

  // 2. TIMEOUT & AWAKE LOGIC
  if (isAwake) {
    // Check if 5 minutes have passed since last touch
    if (millis() - lastInteractionTime > TIMEOUT_MS) {
      isAwake = false;
      display.clearDisplay(); // Turn off the screen
      display.display();
      Serial.println("System Sleeping...");
    }
    else {
      // 3. ANIMATION LOGIC (Only if awake and not currently being touched)
      if (!touched) {
        if (millis() - lastAnimationTime > ANIMATION_INTERVAL) {
          lastAnimationTime = millis();
          // Generate a random eye type (0 to 5, adjust based on library limits)
          currentAnimation = random(0, 6);
          eyes.setEyeType(currentAnimation);
        }
      }

      // Update the display
      eyes.update();
    }
  }
}*/






// This section is using the Arduino Mega 2650 Board to control the eyes
//Basic random RoboEyes animations for Arduino

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <FluxGarage_RoboEyes.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define I2C_SDA 20 // A4
#define I2C_SCL 21 // A5

RoboEyes<Adafruit_SSD1306> roboEyes(display);

// Declare and initialize variables
unsigned long lastMoodChange = 0;
int currentMood = 0;

void setup() {
  Serial.begin(115200);

  // Initialize the I2C bus
  Wire.begin(); // Use default I2C pins for Arduino Mega 2560

  // Initialize the display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.display();
  delay(2000); // Pause for 2 seconds

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println(F("RoboEyes Test"));
  display.display();
  delay(2000);

  // Initialize RoboEyes
  roboEyes.begin(SCREEN_WIDTH, SCREEN_HEIGHT, 60);
  roboEyes.setAutoblinker(ON, 3, 2);
  roboEyes.setIdleMode(ON, 2, 2);
}

void loop() {
  roboEyes.update();

  if (millis() - lastMoodChange > 4000) {
    lastMoodChange = millis();
    currentMood = (currentMood + 1) % 4;

    if (currentMood == 0) roboEyes.setMood(DEFAULT);
    if (currentMood == 1) roboEyes.setMood(HAPPY);
    if (currentMood == 2) roboEyes.setMood(TIRED);
    if (currentMood == 3) roboEyes.setMood(ANGRY);
  }
}