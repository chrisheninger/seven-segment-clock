# Seven Segment Clock Code

This project uses [Engineezy's Seven Segment Display](https://engineezy.com/products/the-rack-driven-7-segment-display) with servos and an Arduino Nano in order to function as a clock.

Video: https://raw.githubusercontent.com/chrisheninger/seven-segment-clock/main/clock-demo.mp4

## Clock.ino

Currently not using any real time clock module– so you'll need to input the start time when loading the .ino file onto the Arduino.

```cpp
#include <Servo.h>

// Declare servo objects
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// Array to map numbers to servo positions - my servos didn't work in perfect 20 degree increments
int numbers1[] = {0, 20, 40, 60, 80, 100, 116, 136, 152, 172};
int numbers2[] = {0, 20, 40, 60, 80, 100, 116, 136, 152, 172};
int numbers3[] = {0, 24, 44, 64, 84, 100, 120, 140, 160, 180};
int numbers4[] = {0, 24, 44, 64, 82, 100, 120, 140, 160, 180};

// Current time
int hours = 13;
int minutes = 37;

// Function to update servo positions based on current time
void updateServos(int hours, int minutes) {
  int hourTens = hours / 10;
  int hourOnes = hours % 10;
  int minuteTens = minutes / 10;
  int minuteOnes = minutes % 10;

  servo1.write(numbers4[hourTens]); // H
  servo2.write(numbers3[hourOnes]); // H
  servo3.write(numbers2[minuteTens]); // M
  servo4.write(numbers1[minuteOnes]); // M
}

void setup() {
  servo1.attach(6);  // Arduino Nano pin d6
  servo2.attach(7); // Arduino Nano pin d7
  servo3.attach(8); // Arduino Nano pin d8
  servo4.attach(9); // Arduino Nano pin d9

  // Initialize servos to initial time (hours/minutes variables above)
  updateServos(hours, minutes);
}

void loop() {
  // Wait for one minute (60000 milliseconds)
  delay(60000);

  // Increment the time
  minutes++;
  if (minutes >= 60) {
    minutes = 0;
    hours++;
    if (hours >= 24) {
      hours = 0;
    }
  }

  // Update the servo positions
  updateServos(hours, minutes);
}
```

## Clock-Debug.ino

An easy way to control individual servos for debugging and calibrating the motor angles. My servos didn't end up working with perfect 20 degree increments– I had to adjust it 2-4 degrees in a handful of places.

```cpp
#include <Servo.h>

// Declare servo objects
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// Array to map numbers to servo positions
int numbers1[] = {0, 20, 40, 60, 80, 100, 116, 136, 152, 172};
int numbers2[] = {0, 20, 40, 60, 80, 100, 116, 136, 152, 172};
int numbers3[] = {0, 24, 44, 64, 84, 100, 120, 140, 160, 180};
int numbers4[] = {0, 24, 44, 64, 82, 100, 120, 140, 160, 180};

void setup() {
  servo1.attach(6);  // Arduino Nano pin d6
  servo2.attach(7); // Arduino Nano pin d7
  servo3.attach(8); // Arduino Nano pin d8
  servo4.attach(9); // Arduino Nano pin d9

  // 1337
  servo1.write(numbers4[0]);
  servo2.write(numbers3[0]);
  servo3.write(numbers2[0]);
  servo4.write(numbers1[0]);
}

void loop() {
  // for (int i = 0; i < 10; i++) {
  //   servo1.write(numbers4[i]);
  //   servo2.write(numbers3[i]);
  //   servo3.write(numbers2[i]);
  //   servo4.write(numbers1[i]);
  //   delay(2000);
  // }
}
```
