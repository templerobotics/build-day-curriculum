const int LED_PIN = 3;		// The LED pins being used in sequential order (left to right)

// the setup function runs once when you press reset or power the board
void setup() {
	// Initialize pins
	pinMode(LED_PIN, OUTPUT);
}

// The loop function runs over and over again forever
void loop() {
	// Loop through the LED array, turning one on at a time
    digitalWrite(LED_PIN, HIGH);	// Turn on the LED
    delay(500);						// Wait for a 500 ms
    digitalWrite(LED_PIN, LOW);		// Turn off the LED
    delay(500);
}