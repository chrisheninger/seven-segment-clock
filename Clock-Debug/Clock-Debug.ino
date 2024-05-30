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
