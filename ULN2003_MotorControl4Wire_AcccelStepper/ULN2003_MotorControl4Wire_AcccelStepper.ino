#include <AccelStepper.h>
#define HALFSTEP 8


// Initialize with pin sequence 8-9-10-11 for using the AccelStepper with 28BYJ-48
AccelStepper stepper1(HALFSTEP, 8, 9, 10, 11);

void setup() {
  stepper1.setMaxSpeed(1000.0);
  stepper1.setAcceleration(100.0);
  stepper1.setSpeed(200);
  stepper1.moveTo(20000);
}

void loop() {
  //Change direction when the stepper reaches the target position
  if (stepper1.distanceToGo() == 0) {
    stepper1.moveTo(-stepper1.currentPosition());
  }
  stepper1.run();
}
