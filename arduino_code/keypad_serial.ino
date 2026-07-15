#include <Keypad.h>

// 4x4 Keypad tənzimləmələri
const byte ROWS = 4; 
const byte COLS = 4; 

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Keypad-in Arduino pinlərinə qoşulması
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  // Serial rabitəni 9600 baud sürəti ilə başladır
  Serial.begin(9600);
}

void loop() {
  // Düyməyə basılmanı gözləyir
  char key = keypad.getKey();
  
  // Əgər düyməyə basılıbsa, Serial port vasitəsilə Raspberry Pi-yə göndərir
  if (key) {
    Serial.println(key);
  }
}
