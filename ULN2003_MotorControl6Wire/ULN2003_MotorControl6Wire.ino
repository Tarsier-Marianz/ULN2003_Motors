#include <Stepper.h>

const int stepsPerRevolution = 24;  // change this to fit the number of steps per revolution 180degree
//const int stepsPerRevolution = 48;  // change this to fit the number of steps per revolution 360degree
// for your motor , In my case I used AIRPAX motor which is 7.5degree step angle

//const int SPEED = 60;  // set the speed at 60 rpm:
const int SPEED = 60;
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  myStepper.setSpeed(SPEED);
  // initialize the serial port:
  //Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  //Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);

  //Serial.println(stepsPerRevolution);
}

