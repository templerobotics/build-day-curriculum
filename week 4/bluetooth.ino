#define ENA 5
#define ENB 6
#define LEFT_1 7
#define LEFT_2 8
#define RIGHT_1 9
#define RIGHT_2 11
#define carSpeed 250

enum MOTION_MODE {
	STOP,
	FORWARD,
	BACK,
	LEFT,
	RIGHT
} mov_mode;

void forward(bool debug = false){
	analogWrite(ENA, carSpeed);
	analogWrite(ENB, carSpeed);
	digitalWrite(RIGHT_1, LOW);
	digitalWrite(RIGHT_2, HIGH);
	digitalWrite(LEFT_1, HIGH);
	digitalWrite(LEFT_2, LOW);
	if(debug) Serial.println("Go back!");
}

void back(bool debug = false){ 
	analogWrite(ENA, carSpeed);
	analogWrite(ENB, carSpeed);
	digitalWrite(RIGHT_1, HIGH);
	digitalWrite(RIGHT_2, LOW);
	digitalWrite(LEFT_1, LOW);
	digitalWrite(LEFT_2, HIGH);
	if(debug) Serial.println("Go forward!");
}

void left(bool debug = false){
	analogWrite(ENA,carSpeed);
	analogWrite(ENB,carSpeed);
	digitalWrite(RIGHT_1, LOW);
	digitalWrite(RIGHT_2, HIGH);
	digitalWrite(LEFT_1, LOW);
	digitalWrite(LEFT_2, HIGH);
	if(debug) Serial.println("Go left!");
}

void right(bool debug = false){
	analogWrite(ENA,carSpeed);
	analogWrite(ENB,carSpeed);
	digitalWrite(RIGHT_1, HIGH);
	digitalWrite(RIGHT_2, LOW);
	digitalWrite(LEFT_1, HIGH);
	digitalWrite(LEFT_2, LOW);
	if(debug) Serial.println("Go right!");
}

void stop(bool debug = false){
	digitalWrite(ENA, LOW);
	digitalWrite(ENB, LOW);
	if(debug) Serial.println("Stop!");
}

void getBTData() {
	if(Serial.available()) {
		int bt_data = Serial.read();
		Serial.println(bt_data);
		switch(bt_data) {
			case 'f': mov_mode = FORWARD;  break;
			case 'b': mov_mode = BACK;     break;
			case 'l': mov_mode = LEFT;     break;
			case 'r': mov_mode = RIGHT;    break;
			case 's': mov_mode = STOP;     break;
			default:  break;
		} 
	}
}

void bluetooth_mode() {
	switch(mov_mode){
		case FORWARD: forward();  break;
		case BACK:    back();     break;
		case LEFT:    left();     break;
		case RIGHT:   right();    break;
		case STOP:    stop();     break;
		default: break;
	}
}

void setup() {
	mov_mode = STOP;
	Serial.begin(9600);
	pinMode(LEFT_1, OUTPUT);
	pinMode(LEFT_2, OUTPUT);
	pinMode(RIGHT_1, OUTPUT);
	pinMode(RIGHT_2, OUTPUT);
	pinMode(ENA, OUTPUT);
	pinMode(ENB, OUTPUT);
	Serial.println("Program Starting");
}

void loop() {
	getBTData();
	bluetooth_mode();
}
