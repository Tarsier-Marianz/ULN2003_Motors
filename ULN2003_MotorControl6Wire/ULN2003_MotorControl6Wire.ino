#include <Stepper.h>

const int SPEED                   = 60;  // set the speed at 60 rpm
const int stepsPerRevolution      = 24;  // change this to fit the number of steps per revolution 180degree
//const int stepsPerRevolution    = 48;  // change this to fit the number of steps per revolution 360degree
// for your motor , In my case I used AIRPAX motor which is 7.5degree step angle

Stepper _stepper(stepsPerRevolution, 8, 9, 10, 11); // initialize the stepper library on pins 8 through 11

void setup() {
  _stepper.setSpeed(SPEED);             // initialize stepper speed
  Serial.begin(9600);                   // initialize the serial to enable data printing
}

void loop() {
  Serial.println("clockwise");
  _stepper.step(stepsPerRevolution);    // step one revolution  in one direction
  delay(500);

  Serial.println("counterclockwise");
  _stepper.step(-stepsPerRevolution);   // step one revolution in the other direction
  delay(500);

  Serial.println(stepsPerRevolution);
}

