/**
 * @brief A single file to make sure all the parts of the bots are functioning properly.
 * @warning Up to twelve servo objects can be created on most boards
*/
#include <Servo.h>

const double SPEED_OF_SOUND = 0.034;

const int ECHO = A4;
const int TRIG = A5;

// Motor controller
const int ENA = 5;
const int ENB = 6;
const int IN1 = 7;
const int IN2 = 8;
const int IN3 = 9;
const int IN4 = 11;

const int SERVO_PIN = 3;
Servo servo;

// Line tracker
const int LT_R = !digitalRead(10);
const int LT_M = !digitalRead(4);
const int LT_L = !digitalRead(2);


void forward(){ 
	digitalWrite(ENA, HIGH);
	digitalWrite(ENB, HIGH);

	digitalWrite(IN1, HIGH);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, HIGH);

	Serial.println("Moving motors forward");
}

void stop(){
	digitalWrite(ENA, LOW);
	digitalWrite(ENB, LOW);

	Serial.println("Stopping motors");
}

double getDistance() {
	digitalWrite(TRIG, LOW);
	delayMicroseconds(1);

	digitalWrite(TRIG, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG, LOW);

	long duration = pulseIn(ECHO, HIGH);
	return duration * SPEED_OF_SOUND / 2;
}

/**
 * Tests the motors by driving forward for 3 seconds
*/
void motorTest() {
	Serial.println("Test: Motors");
	forward();
	delay(3000);
	stop();
}

/**
 * Tests the ultrasonic distance sensor by getting one distance
*/
void ultrasonicSensorTest() {
	Serial.println("Test: Distance Sensors");
	Serial.print("Distance: ");
	Serial.print(getDistance());
	Serial.println(" cm");
}

/**
 * Tests the bluetooth module
 * @warning Does not test if bluetooth messages work. Would probably be too complicated
*/
void bluetoothTest() {
	Serial.println("Test: Bluetooth");
	if(Serial.available()) {
		Serial.println("Bluetooth working");
	} else {
		Serial.println("Bluetooth not working");
	}
}

/**
 * Tests the line tracker, may not work
*/
void lineTrackerTest() {
	Serial.println("Test: Line Tracker");
	if (LT_M){
		Serial.println("Move forward");
	} else if (LT_R) {
		Serial.println("Turn right");
	} else if (LT_L) {
		Serial.println("Turn left");
	}
}

/**
 * Tests the servo by going to start position, end position, then halfway for 3 seconds.
*/
void servoTest() {
	Serial.println("Test: Servo");
	servo.write(0);
	delay(1000);
	servo.write(180);
	delay(1000);
	servo.write(90);
	delay(3000);
}

void setup() { 
	Serial.begin(9600);

	// Motor controller
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);
	pinMode(ENA, OUTPUT);
	pinMode(ENB, OUTPUT);

	// Distance sensor
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);

	// Servo
	servo.attach(SERVO_PIN);

	// Start with the motors stopped
	stop();
	motorTest();
	ultrasonicSensorTest();
	servoTest();
	lineTrackerTest();
	bluetoothTest();
}

void loop() {
	// Empty loop so the tests do not run continuously
	// Press reset button on arduino to rerun tests
}
