#include <AccelStepper.h>
#define HALFSTEP 8
#define FULLSTEP 4

// You need the AccelStepper library for this sketch to run.  You can get it from here: http://aka.ms/AccelStepper

// The AccelStepper constructor expects the "pins" specified to be the ends of each coil respectively.
// First the ends of the Blue/Yellow coil, then the ends of the Pink/Orange coil (Blue,Yellow,Pink,Orange)

// However, 28BYJ connector, ULN2003 board, and our current configuration is that pins are arranged in the proper FIRING order, 
// Blue, Pink, Yellow, Orange.

// No biggie, that just means that we need to pay attention to what pins on our Arduino,
// map to which ends of the coils, and pass the pin numbers in in the proper sequence.  

// To help with that, I will specify my pin variables based on their color.

#define yellow 8
#define orange 9
#define brown 10
#define black 11

//Keeps track of the current direction
//Relative to the face of the motor. 
//Clockwise (true) or Counterclockwise(false)
//We'll default to clockwise
bool clockwise = true;

// How many steps to go before reversing
// int targetPosition = 2048;  //2049 steps per rotation when wave or full stepping
//int targetPosition = 4096;  //4096 steps per rotation when half stepping
int targetPosition = 96;  //4096 steps per rotation when half stepping

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
// Notice, I'm passing them as Blue, Yellow, Pink, Orange (coil ends order) not
// Blue, Pink, Yellow, Orange (firing order). 
AccelStepper stepper1(HALFSTEP, yellow, orange, brown, black);

void setup() {

  Serial.begin(9600);
  //Set the initial speed (read the AccelStepper docs on what "speed" means
  stepper1.setSpeed(10.0);         
  //Tell it how fast to accelerate
  stepper1.setAcceleration(100.0); 
  //Set a maximum speed it should exceed 
  stepper1.setMaxSpeed(4000.0);      
  //Tell it to move to the target position
  stepper1.moveTo(targetPosition);   

}

void loop() {

  //Check to see if the stepper has reached the target:
  if(stepper1.distanceToGo() == 0){
    if(clockwise == true){
      clockwise = false;  //Go counterclockwise now
      stepper1.moveTo(0); //Go back to the "home" (original) position
      Serial.println("//Go counterclockwise now");      
    } else {
      clockwise = true;   //Go clockwise now
      stepper1.moveTo(targetPosition);  //Go to the target position
      Serial.println("//Go clockwise now");
    }
    delay(1000);
  }
  Serial.print("currentPosition: \t");Serial.println(stepper1.currentPosition());
  //If the stepper still needs to move (distanceToGo() != 0)
  //continue to advance (step) the motor
  stepper1.run();
  //delay(1000);
}

