const int LEDS[3] = {4, 8, 10};		// The LED pins being used in sequential order
const int BUTTON = 2;				// Only pins usable for interrupts are 2 & 3
const int LEDS_SIZE = sizeof(LEDS)/sizeof(LEDS[0]);

volatile bool ledValue = HIGH;		// Start the ISR flag out HIGH so the LEDs start on

// The setup function runs once when you press reset or power the board
void setup() {
	// initialize digital pin LED_BUILTIN as an output.
	pinMode(LEDS[0], OUTPUT);
	pinMode(LEDS[1], OUTPUT);
	pinMode(LEDS[2], OUTPUT);
	pinMode(BUTTON, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(BUTTON), button_isr, CHANGE);
}

// The loop function runs over and over again forever
void loop() {
	for (int i = 0; i < LEDS_SIZE; i++) {
		digitalWrite(LEDS[i], ledValue);	// Turn the LED on
		delay(1000);						// wait for 500 ms
		digitalWrite(LEDS[i], LOW);			// Turn the LED off
		while (!ledValue);					// Wait until the ISR is activated again
	}
}

// ISR for turning off LEDs
void button_isr() {
	ledValue = !ledValue;					// Invert the flag
	if (!ledValue) {
		for (int i = 0; i < LEDS_SIZE; i++)
			digitalWrite(LEDS[i], LOW);		// Turn all LEDs off if ledValue is now LOW
	}
}