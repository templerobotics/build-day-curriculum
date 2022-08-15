# build-day-curriculum

A curriculum for build days that can be followed throughout the school year. Each should be short (max an hour) and be reproducible by a newbie.
[Robot kit](https://www.amazon.com/KEYESTUDIO-Bluetooth-Controller-Ultrasonic-Programming/dp/B08276N3D9/ref=asc_df_B08276N3D9/?tag=hyprod-20&linkCode=df0&hvadid=507731305156&hvpos=&hvnetw=g&hvrand=17314281805372487668&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9052386&hvtargid=pla-1045715635134&psc=1)

## Trouble Shooting

- If you are having uploading troubles, my main issue was that the HAT was affecting the upload (possibly because PINS 0 and 1 are being used). The solution is to remove the HAT, upload your code, then put the HAT back on.
- If a library is not found, you need to add it to the C/C++ path by Rebuilding the IntelliSense Configuration
  - Put the include statement (Ex: `#include <Servo.h>`) at the top of the file
  - Press `ctrl+shift+P`
  - Type `Arduino: Rebuild IntelliSense Configuration`
  - The library should now be included in the C/C++ path. This can be checked in [this file](./.vscode/c_cpp_properties.json) under `includePath`
- If the upload is working correctly but doesnt seem to be working, check that the correct sketch file is selected

## Software Setup

For setting up one's environment and software, go to [this folder](./setup/README.md)

## Week 1

Follow the README located [here](./week%201/README.md)

## Week 2

Follow the README located [here](./week%202/README.md)

## Week 3

Follow the README located [here](./week%203/README.md)

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
