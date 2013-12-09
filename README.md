Lab7
====

Library for interfacing with the sensors on the robot in ECE 382.

## Functions

- `void InitializeADC10()`
  - Sets up the ADC10 subsystem

- `unsigned int LeftSensorReading()`
  - Takes a voltage reading of the left sensor and returns an unsigned int

- `unsigned int RightSensorReading()`
  - Takes a voltage reading of the right sensor and returns an unsigned int


## Notes
The LEDs are initialized in main.c since I will not need the LEDs in Lab 8.

## Documentation Statement
C2C Ryan Turner helped me debug my code and came to the conclusion that I was using = instead of |=. Capt Branchflower also pointed out that I was not calling InitializeADC10() in my main.c.
