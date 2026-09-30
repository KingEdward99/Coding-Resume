/*
    Learning how to use arduino
*/

void setup() {
    pinMode (13, OUTPUT); //Setting pin 13 as an output
}

void loop() {
    digitalWrite(13,HIGH) // Turn the LED on
    delay(2000) //Wait for 2 seconds
    digitalWrite(13,LOW) // Turn the LED off
    delay(2000)
}