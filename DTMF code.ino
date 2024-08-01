#include <Keypad.h>

const byte ROW_NUM    = 4; // Four rows
const byte COLUMN_NUM = 4; // Four columns

// Define the keymap for the keypad
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte pin_rows[ROW_NUM] = {9, 8, 7, 6};

// Connect keypad COLUMN0, COLUMN1, COLUMN2 and COLUMN3 to these Arduino pins.
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2};

// Create the Keypad object
Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    Serial.print("Pressed Key: ");
    Serial.println(key);
    
    // Generate the DTMF tone based on the pressed key
    switch (key) {
      case '1':
        generateDTMFTone(697, 1209);
        break;
      case '2':
        generateDTMFTone(697, 1336);
        break;
      // Add cases for other keys here...
    }
  }
}

void generateDTMFTone(int frequency1, int frequency2) {
  // Generate DTMF tone using the tone() function
  tone(10, frequency1);
  tone(11, frequency2);
  
  // Play the tone for a short duration (adjust this value to change the tone duration)
  delay(500);
  
  // Stop the tones
  noTone(10);
  noTone(11);
}
