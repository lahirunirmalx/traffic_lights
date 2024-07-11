## ESP32 Traffic Light State Machine

This project implements a basic traffic light system on an ESP32 microcontroller using the state machine pattern. The traffic light cycles through red, yellow, and green states with configurable durations for each phase.

**Features**

* Leverages the state machine pattern for clear and maintainable code.
* Customizable timing for red, yellow, and green light durations.
* Connects to three LEDs (red, yellow, green) for visual representation.

**Hardware Requirements**

* ESP32 development board (e.g., ESP32 DevKitC)
* Three LEDs (red, yellow, green)
* Resistors (values dependent on LED specifications)
* Breadboard and jumper wires

**Software Requirements**

* Arduino IDE ([https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)) 

**Wiring**

Connect the LEDs to the ESP32 pins with appropriate resistors based on your LED specifications. Refer to the ESP32 pinout diagram for specific pin numbers. Here's a general example:

```
Red LED: ESP32 pin (e.g., GPIO25) - resistor - GND
Yellow LED: ESP32 pin (e.g., GPIO26) - resistor - GND
Green LED: ESP32 pin (e.g., GPIO27) - resistor - GND
```

**Installation**

1. Download this repository.
2. Open the `ESP32_Traffic_Light.ino` file in the Arduino IDE.
3. Replace `PIN_RED`, `PIN_YELLOW`, and `PIN_GREEN` with the actual ESP32 pin numbers connected to your LEDs.
4. Adjust the `RED_DURATION`, `YELLOW_DURATION`, and `GREEN_DURATION` constants to your desired timing for each light phase in milliseconds.
5. Connect the ESP32 board to your computer.
6. Select the appropriate ESP32 board and serial port in the Arduino IDE.
7. Upload the code to the ESP32 board.

**Usage**

The traffic light system will automatically run after uploading the code. Each LED will turn on and off according to the defined states and durations.

**State Machine Explanation**

The provided example code might use an `enum` to represent the different traffic light states (RED, YELLOW, GREEN). A loop continuously checks the current state, triggers actions based on that state (turning on/off LEDs), and then transitions to the next state after the specified duration.

**Additional Notes**

* For more advanced control and extensibility, you could explore libraries like ESP IDF that offer finer-grained control over hardware interactions and timing.
* Consider adding comments to the code to improve readability and understanding.

**Contributing**

Feel free to submit pull requests to improve this project or add functionality. Please refer to the contribution guidelines (if any) before submitting changes.

**License**

This project is licensed under the MIT License (see LICENSE file for details).
