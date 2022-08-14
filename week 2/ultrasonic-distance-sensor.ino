#include <Servo.h>

/**
 * @brief Use the ultrasonic distance sensor to detect obstacle distance
*/

const int ECHO = A4;
const int TRIG = A5;
const double SPEED_OF_SOUND = 0.034; // The speed of sound in cm/us = 340 m/s * 100 cm/m * 0.000001 s/us

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
	pinMode(TRIG, OUTPUT); 	// Sets the trigPin as an OUTPUT
	pinMode(ECHO, INPUT); 	// Sets the echoPin as an INPUT
	Serial.begin(9600); 	// Serial Communication is starting with 9600 of baudrate speed
}

void loop() {
	double distance = getDistance();
	// Displays the distance on the Serial Monitor
	Serial.print("Distance: ");
	Serial.print(distance);
	Serial.println(" cm");
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