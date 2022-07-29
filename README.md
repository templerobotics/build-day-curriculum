# build-day-curriculum
A curriculum for build days that can be followed throughout the school year. Each should be short (max an hour) and be reproducible by a newbie.
[Robot kit](https://www.amazon.com/KEYESTUDIO-Bluetooth-Controller-Ultrasonic-Programming/dp/B08276N3D9/ref=asc_df_B08276N3D9/?tag=hyprod-20&linkCode=df0&hvadid=507731305156&hvpos=&hvnetw=g&hvrand=17314281805372487668&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9052386&hvtargid=pla-1045715635134&psc=1)

## Materials List
|Item       |Quantity|Weeks Used|
|-----------|--------|----------|
|Arduino Uno|1       |All       |
|LEDs|3|1|
|10 kOhm|1|1|
|220 Ohm|3|1|
|Button|1|1|
|L298N motor driver|1|3 & 5|
|[12 V DC motor](https://www.amazon.com/EUDAX-Electric-Magnetic-Propeller-Connector/dp/B08GPPJR1T/ref=sr_1_26?keywords=12+v+dc+motor&qid=1659058076&sprefix=12+v+dc+mo%2Caps%2C186&sr=8-26)|2|5|
|12 Volt power supply|1|5|

## Software Setup
- First step is to download the [Arduino IDE](https://www.arduino.cc/en/software)
  - Optional but recommended: I like to use vscode, not the actual Arduino IDE. You can download vscode [here](https://code.visualstudio.com/download)
  - With vscode installed, download these extensions: Arduino, and C/C++
  - Can follow [this](https://www.youtube.com/watch?v=VfLTZcKCGfk) tutorial for building an arduino project with vscode

## Week 1: LEDs
This week will focus on buttons and LEDs. Everyone should get into groups of two; one for programming and another for hardware. This is so they can help each other out.

- [Sequential Blinking](./week%201/sequential-blinking/sequential-blinking.ino)
  - Instructions: Create a program that blinks 3 LEDs sequentially at 500 ms intervals. There should always be one LED on during this loop. Temporarily stop the loop when the button is being pressed. There is no need for debouncing, but a pullup resistor (10 kOhm) on the button should help with noise. Start up the loop again when the button is released.
  - Helpful links
    - [Programming an LED](https://create.arduino.cc/projecthub/rowan07/make-a-simple-led-circuit-ce8308)
    - [Programming a button](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button)
- [Button Interrupt](./week%201/button-interrupt/button-interrupt.ino)
  - Instructions: Create a program that blinks 3 LEDs sequentially at 500 ms intervals. Then, when a button is pressed, the loop is stopped dead in its tracks with an interrupt. Then, when the button is released, have the loop continue right where it left off.
  - **Be Aware**: Only a few pins work as interrupts, not all of them! 
  - Helpful links
    - [Using interrupts](https://riptutorial.com/arduino/example/9856/interrupt-on-button-press)
    - [attachInterrupts function](https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/)

### Materials
|Item       |Quantity|
|-----------|--------|
|LEDs|3|
|10 kOhm|1|
|220 Ohm|3|
|Button|1|

## Week 2: LCD Screen

## Week 3: Servos or Motors

## Week 4: RFID Reader

## Week 5: 3D Printed Car?

- Maybe split into two weeks: one for 3D printing, and one for programming

## Week 6: 
