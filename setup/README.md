# Working with the Environment

## Setting up the Environment

Here are instructions for setting up an environment for arduino coding on Mac and Windows.

- Download and install the [Arduino IDE](https://www.arduino.cc/en/software) for your operating system
- Download and install [vscode](https://code.visualstudio.com/download) for your operating system
- Install the following extensions for vscode by clicking the extensions icon on the left sidebar
  - [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
  - [Arduino](https://marketplace.visualstudio.com/items?itemName=vsciot-vscode.vscode-arduino)

## Building Arduino Projects in VScode

This is the directions for using arduino projects in the vscode IDE
Follow [this](https://www.youtube.com/watch?v=VfLTZcKCGfk) tutorial for building an arduino project with vscode

- Open the folder where you wish to create the arduino project
- Create a new file named the same as the project folder with a `.ino` extension
- When the file is opened, there should be two buttons in the top right of vscode
  - The left is for uploading to the board's microchip
  - The right is for verifying the program
- At the bottom of vscode click `select board type` and choose `arduino uno`
- At the bottom of vscode click `select programmer` and choose `AVRISP mkll`
- At the bottom of vscode click `serial port` and choose where the arduino board is connected
- Now you should be ready to upload a program to the board!
- You can test by trying to run `test-script.ino` in this folder
