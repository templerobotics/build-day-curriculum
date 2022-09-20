# Week 3: Motors

This week is about how to use the motor controller on the robot with 4 different motors.

- [Motor Controller](./motor-controller.ino)
  - Instructions: Use the L298N motor controller on the robot to drive it forwards, backwards, turn left, then turn right. Do each action for 1 second each and repeat once finished. Keep the speed at 200 on all movement.
    - **Warning**: The robot seems to stop working when going over 200 or so for the motor controller speed

## Motor Controller Directions

|Direction|Pins|
|---------|----|
|Left side forward|9 HIGH & 11 LOW|
|Left side backward|9 LOW & 11 HIGH|
|Right side forward|7 LOW & 8 HIGH|
|Right side backward|7 HIGH & 8 LOW|
