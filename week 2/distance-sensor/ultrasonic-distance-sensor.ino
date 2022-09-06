/**
 * @brief Use the ultrasonic distance sensor to detect obstacle distance
*/

#include <Servo.h>

const int ECHO = A4;
const int TRIG = A5;
const int SERVO_PIN = 3;	// Pin that controls the servo
const double SPEED_OF_SOUND = 0.034; // The speed of sound in cm/us = 340 m/s * 100 cm/m * 0.000001 s/us

// defines variables
long duration; 				// variable for the duration of sound wave travel
int distance; 				// variable for the distance measurement
Servo servo;				// Servo object for controlling it

void setup() {
	Serial.begin(9600); 	// Serial Communication is starting with 9600 of baudrate speed

	servo.attach(SERVO_PIN);
	pinMode(TRIG, OUTPUT); 	// Sets the trigPin as an OUTPUT
	pinMode(ECHO, INPUT); 	// Sets the echoPin as an INPUT
}

void loop() {
	double distance = getDistance();
	// Displays the distance on the Serial Monitor
	Serial.print("Distance: ");
	Serial.print(distance);
	Serial.println(" cm");

	// For calibrating
	centerServo();
}

double getDistance() {
	// Clears the trigPin condition
	digitalWrite(TRIG, LOW);
	delayMicroseconds(1);
	// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
	digitalWrite(TRIG, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG, LOW);
	// Reads the echoPin, returns the sound wave travel time in microseconds
	duration = pulseIn(ECHO, HIGH);
	// Calculating the distance
	return duration * SPEED_OF_SOUND / 2; // Speed of sound wave divided by 2 (there and back)
}

// Used for calibrating the servo and the ultrasonic distance sensor
void centerServo() {
	servo.write(90);
}