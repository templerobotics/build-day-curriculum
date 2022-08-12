# Week 1: LEDs

This week will focus on buttons and LEDs. Everyone should get into groups of two; one for programming and another for hardware. This is so they can help each other out.

- [Sequential Blinking](./sequential-blinking.ino)
  - Instructions: Create a program that blinks 3 LEDs sequentially at 500 ms intervals. There should always be one LED on during this loop. Temporarily stop the loop when the button is being pressed. There is no need for debouncing, but a pull up resistor (10 kOhm) on the button should help with noise. Start up the loop again when the button is released.
  - Helpful links
    - [Programming an LED](https://create.arduino.cc/projecthub/rowan07/make-a-simple-led-circuit-ce8308)
    - [Programming a button](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button)
- [Button Interrupt](./button-interrupt.ino)
  - Instructions: Create a program that blinks 3 LEDs sequentially at 500 ms intervals. Then, when a button is pressed, the loop is stopped dead in its tracks with an interrupt. Then, when the button is released, have the loop continue right where it left off.
  - **Be Aware**: Only a few pins work as interrupts, not all of them!
  - Helpful links
    - [Using interrupts](https://riptutorial.com/arduino/example/9856/interrupt-on-button-press)
    - [attachInterrupts function](https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/)

## Materials

|Item       |Quantity|
|-----------|--------|
|LEDs|3|
|10 kOhm|1|
|220 Ohm|3|
|Button|1|
