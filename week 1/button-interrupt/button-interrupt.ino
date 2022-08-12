/**
 * @brief Blink the LEDs sequentially from left to right. The LED will
 * be on for 500 ms then turn off as the next one turns on. When the
 * button is pressed, interrupt the sequence and turn off all the LEDs.
 * Once the button is released, continue the LED sequence where it left off.
*/

const int LEDS[3] = {8, 9, 10};						// The LED pins being used in sequential order
const int LEDS_SIZE = sizeof(LEDS)/sizeof(LEDS[0]);	// The size of the LED array
const int BUTTON = 2;								// Only pins usable for interrupts are 2 & 3

// The flag for determining if the sequence should be paused or not
// Starting out HIGH so the LED sequence starts immediately
volatile bool ledValue = HIGH;

// The setup function runs once when you press reset or power the board
void setup() {
	// initialize digital pin LED_BUILTIN as an output.
	pinMode(LEDS[0], OUTPUT);
	pinMode(LEDS[1], OUTPUT);
	pinMode(LEDS[2], OUTPUT);

	// Initialize the button as an input. PULLUP means that noise will interfere less with input data
	pinMode(BUTTON, INPUT_PULLUP);
	// Create an interrupt service routine for the button (Called when then button is pressed AND released)
	attachInterrupt(digitalPinToInterrupt(BUTTON), button_isr, CHANGE);
}

// The loop function runs over and over again forever
void loop() {
	// Iterate through the LED sequence array
	for (int i = 0; i < LEDS_SIZE; i++) {
		digitalWrite(LEDS[i], ledValue);	// Turn the LED on
		delay(500);							// Wait 500 ms
		digitalWrite(LEDS[i], LOW);			// Turn the LED off
		while (!ledValue);					// Wait until the ISR is activated again
	}
}

// Interrupt service routine (ISR) for turning off LEDs
void button_isr() {
	// Invert the flag
	ledValue = !ledValue;

	// Turn all LEDs off if the sequence was just running
	if (!ledValue) {
		for (int i = 0; i < LEDS_SIZE; i++)
			digitalWrite(LEDS[i], LOW);
	}
}