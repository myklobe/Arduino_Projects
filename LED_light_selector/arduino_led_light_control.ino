 import sys

  def main():
      # --- Refactored Section ---
      print("Please select a color for the alert:")
      print("1. Green")
      print("2. Yellow")
      print("3. Red")
      print("4. All On")
      print("5. All Off")
      

      choice = input("Enter the number of your choice (1-3): ")

      # Map the selection to the corresponding color
      color_map = {
          "1": "green",
          "2": "yellow",
          "3": "red",
          "4": "All On",
          "5": "All Off"
        }

      if choice in color_map:
          selected_color = color_map[choice]
          print(f"You selected: {selected_color}")
          # Proceed with logic using selected_color
      else:
          print("Invalid selection. Please run the program again and choose 1, 2, 3, 4, or 5.")
          sys.exit(1)

// Define the pins
const int redLEDPin8 = 8;
const int yellowLEDPin7 = 7;
const int greenLEDPin6 = 6;

// This is your "Selection" control
// 1 = Red, 2 = Yellow, 3 = Green
int selectedColor = 1;

void setup() {
  pinMode(redLEDPin8, OUTPUT);
  pinMode(yellowLEDPin7, OUTPUT);
  pinMode(greenLEDPin6, OUTPUT);
}

void loop() {
  // Turn all lights OFF first
  digitalWrite(redLEDPin8, LOW);
  digitalWrite(yellowLEDPin7, LOW);
  digitalWrite(greenLEDPin6, LOW);

// Logic to map the selection to the color
  if (selectedColor == 1) {
    digitalWrite(redLEDPin8, HIGH);
  }
  else if (selectedColor == 2) {
    digitalWrite(yellowLEDPin7, HIGH);
  }
  else if (selectedColor == 3) {
    digitalWrite(greenLEDPin6, HIGH);
  }
  else if (selectedColor == 4) {
    digitalWrite(greenLEDPin6, HIGH),
    digitalWrite(greenLEDPin7, HIGH),
    digitalWrite(greenLEDPin8, HIGH)
    ;
  }
  
  delay(100); // Small delay for stability
}

# --------------------------

  if __name__ == "__main__":
      main()