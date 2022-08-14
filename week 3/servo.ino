/**
 * @brief Centers the servo for 5 seconds, then rotates from left to right continuously
 * @warning Up to twelve servo objects can be created on most boards
*/

#include <Servo.h>

const int SPEED = 15;		// Higher number means slower movement
const int SERVO_PIN = 3;	// Pin that controls the servo

Servo servo;				// Servo object for controlling it
volatile int angle = 0;		// The angle which will be continuously changing

void setup() {
	servo.attach(SERVO_PIN);
	servo.write(angle);

	// For calibrating. In this 5 second interval, place the distance sensor facing straight ahead
	centerServo();
}

void loop() {
	// Scan from 0 to 180 degrees
	for (angle = 0; angle < 180; angle++) {
		servo.write(angle);
		delay(SPEED);
	}

	// Scan back from 180 to 0 degrees
	for (angle = 180; angle > 0; angle--) {
		servo.write(angle);
		delay(SPEED);
	}
}

// Used for calibrating the servo and the ultrasonic distance sensor
void centerServo() {
	servo.write(90);
	delay(5000);
}