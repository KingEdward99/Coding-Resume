/*
    Learning how to use arduino
*/

void setup() {
    pinMode (13, OUTPUT); //Setting pin 13 as an output
    pinMode (2, INPUT); // Setting pin 2 as an input
}

void loop() {
    digitalWrite(13,HIGH) // Turn the LED on
    delay(2000) //Wait for 2 seconds
    digitalWrite(13,LOW) // Turn the LED off
    delay(2000)
}