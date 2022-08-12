/**
 * @brief Blink the LEDs sequentially from left to right. The LED will
 * be on for 500 ms then turn off as the next one turns on.
*/

const int LEDS[3] = {8, 9, 10};		// The LED pins being used in sequential order (left to right)
const int BUTTON = 2;				// The button pin

// the setup function runs once when you press reset or power the board
void setup() {
	// Initialize pins
	pinMode(LEDS[0], OUTPUT);
	pinMode(LEDS[1], OUTPUT);
	pinMode(LEDS[2], OUTPUT);
	pinMode(BUTTON, INPUT);
}

// The loop function runs over and over again forever
void loop() {
	// Loop through the LED array, turning one on at a time
	for (int i = 0; i < 3; i++) {
		digitalWrite(LEDS[i], HIGH);	// Turn on the LED
		delay(500);						// Wait for a 500 ms
		digitalWrite(LEDS[i], LOW);		// Turn off the LED
		while(digitalRead(BUTTON));		// Wait here while the button is being pressed
	}
}