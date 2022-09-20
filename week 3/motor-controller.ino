/**
 * @brief Control the robot motors with the L298N motor controller. Move
 * forward, backwards, left, then right. each movement is 1 second long
*/

const int SPEED = 200;		// The speed of the motors
const int DELAY = 1000;		// The length of movements

// Pins for controlling the speed
const int ENABLE_A = 6;
const int ENABLE_B = 5;

// Pins for the left two motors
const int LEFT_1 = 7;
const int LEFT_2 = 8;

// Pins for the right two motors
const int RIGHT_1 = 9;
const int RIGHT_2 = 11;

void setup() {
	// Setup all the pins as output
	pinMode(ENABLE_A, OUTPUT);
	pinMode(ENABLE_B, OUTPUT);
	pinMode(LEFT_1, OUTPUT);
	pinMode(LEFT_2, OUTPUT);
	pinMode(RIGHT_1, OUTPUT);
	pinMode(RIGHT_2, OUTPUT);

	// Set the speed of the motors
	analogWrite(ENABLE_A, SPEED);
	analogWrite(ENABLE_B, SPEED);
}

void loop() {
	// Move the robot
	forwards();
	delay(DELAY);
	backwards();
	delay(DELAY);
	left();
	delay(DELAY);
	right();
	delay(DELAY);
}

/** @brief Move the robot forwards */
void forwards() {
	digitalWrite(RIGHT_1, HIGH);
	digitalWrite(RIGHT_2, LOW);
	digitalWrite(LEFT_1, HIGH);
	digitalWrite(LEFT_2, LOW);
}

/** @brief Move the robot backwards */
void backwards() {
	digitalWrite(RIGHT_1, LOW);
	digitalWrite(RIGHT_2, HIGH);
	digitalWrite(LEFT_1, LOW);
	digitalWrite(LEFT_2, HIGH);
}

/** @brief Turn the robot to the left */
void left() {
	digitalWrite(RIGHT_1, HIGH);
	digitalWrite(RIGHT_2, LOW);
	digitalWrite(LEFT_1, LOW);
	digitalWrite(LEFT_2, HIGH);
}

/** @brief Turn the robot to the right */
void right() {
	digitalWrite(RIGHT_1, LOW);
	digitalWrite(RIGHT_2, HIGH);
	digitalWrite(LEFT_1, HIGH);
	digitalWrite(LEFT_2, LOW);
}
