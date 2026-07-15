#include <Keypad.h>

const byte ROWS = 4;  // Four rows
const byte COLS = 4;  // Four columns

// Define the symbols on the keypad (you can customize these if needed)
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Connect row pins to Arduino digital pins 2-5
byte rowPins[ROWS] = {2, 3, 4, 5};

// Connect column pins to Arduino digital pins 6-9
byte colPins[COLS] = {6, 7, 8, 9};

// Initialize keypad object with defined layout
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud
  Serial.println("Starting keypad test. Press any key.");
}

void loop() {
  char key = keypad.getKey();

  if (key) { // If a key is pressed
    //Serial.print("Key pressed: ");
    Serial.println(key);  // Send key to serial monitor
  }
}
