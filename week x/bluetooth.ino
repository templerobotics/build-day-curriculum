#define f 16736925  // FORWARD
#define b 16754775  // BACK
#define l 16720605  // LEFT
#define r 16761405  // RIGHT
#define s 16712445  // STOP

#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
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
	digitalWrite(IN1,LOW);
	digitalWrite(IN2,HIGH);
	digitalWrite(IN3,HIGH);
	digitalWrite(IN4,LOW);
	if(debug) Serial.println("Go back!");
}

void back(bool debug = false){ 
	analogWrite(ENA, carSpeed);
	analogWrite(ENB, carSpeed);
	digitalWrite(IN1,HIGH);
	digitalWrite(IN2,LOW);
	digitalWrite(IN3,LOW);
	digitalWrite(IN4,HIGH);
	if(debug) Serial.println("Go forward!");
}

void left(bool debug = false){
	analogWrite(ENA,carSpeed);
	analogWrite(ENB,carSpeed);
	digitalWrite(IN1,LOW);
	digitalWrite(IN2,HIGH);
	digitalWrite(IN3,LOW);
	digitalWrite(IN4,HIGH); 
	if(debug) Serial.println("Go left!");
}

void right(bool debug = false){
	analogWrite(ENA,carSpeed);
	analogWrite(ENB,carSpeed);
	digitalWrite(IN1,HIGH);
	digitalWrite(IN2,LOW);
	digitalWrite(IN3,HIGH);
	digitalWrite(IN4,LOW);
	if(debug) Serial.println("Go right!");
}

void stop(bool debug = false){
	digitalWrite(ENA, LOW);
	digitalWrite(ENB, LOW);
	if(debug) Serial.println("Stop!");
}

void getBTData() {
	if(Serial.available()) {
		switch(Serial.read()) {
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
		case FORWARD: forward(true);  break;
		case BACK:    back(true);     break;
		case LEFT:    left(true);     break;
		case RIGHT:   right(true);    break;
		case STOP:    stop(true);     break;
		default: break;
	}
}

void setup() {
	mov_mode = STOP;
	Serial.begin(9600);
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);
	pinMode(ENA, OUTPUT);
	pinMode(ENB, OUTPUT);
}

void loop() {
	getBTData();
	bluetooth_mode();
}
