/*
    Learning how to use arduino
*/

#include <Keypad.h>

//Mapping out a 3 x 3 keypad
const byte ROWS = 3;
const byte COLS = 3;

char hexakeys [ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
}

Keypad customKeypad = Keypad(makeKeymap(hexaKeys, rowPins, colPins, ROWS, COLS));

void setup() {
    pinMode (13, OUTPUT); //Setting pin 13 as an output
    pinMode (2, INPUT); // Setting pin 2 as an input
}

void loop() {
    digitalWrite(13,HIGH); // Turn the LED on
    delay(2000); //Wait for 2 seconds
    digitalWrite(13,LOW); // Turn the LED off
    delay(2000);

    char customKey = customKeypad.getKey();

    if (customKey) {
        Serial.println(customKey);
    }
//Establishing the password and telling the user whether they got it right
    int password = 9843;
    if (char != password) {
        digitalWrite(13,HIGH);
        delay(5000);
        digitalWrite(13,LOW);
    }
    else {
        digitalWrite(14,HIGH);
        delay(5000);
        digitalWrite(14,LOW);s
    }
}