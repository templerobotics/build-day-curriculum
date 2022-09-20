# Week 2: Ultrasonic Distance Sensors

This week is about the ultrasonic distance sensor that we will be using on the robot.

- [Ultrasonic Distance Sensor](./ultrasonic-distance-sensor.ino)
  - Instructions: Create a program that sends a ping out from the TRIG pin for 10 microseconds, get the duration from the ECHO pin, multiply that by the speed of sound (in cm/microseconds) divided by two (ping needs to go out and come back), then print the result to the serial monitor.
  - **Be Aware**: The robot uses pins A5 and A4 (analog) for the TRIG and ECHO pins respectively
  - Helpful links
    - [How ultrasonic distance sensors work](https://lastminuteengineers.com/arduino-sr04-ultrasonic-sensor-tutorial/)
- [Servo](./servo.ino)
  - Instructions: Create a program that pans the servo from left to right continuously. At the beginning of the program, the servo should center itself for 5 seconds so the ultrasonic distance sensor can be calibrated at the center of the rotation path.
  - Helpful links
    - [Controlling servos 101](https://docs.arduino.cc/learn/electronics/servo-motors)

## Materials

Only the ultrasonic distance sensor is needed for this week
