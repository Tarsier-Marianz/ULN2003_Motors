//declare variables for the motor pins
int motorPin1   = 8;      // Blue   - 28BYJ48 pin 1
int motorPin2   = 9;      // Pink   - 28BYJ48 pin 2
int motorPin3   = 10;     // Yellow - 28BYJ48 pin 3
int motorPin4   = 11;     // Orange - 28BYJ48 pin 4
// Red    - 28BYJ48 pin 5 (VCC)

int speed       = 20;     //variable to set stepper speed
int count       = 0;      // count of steps made
int revolution  = 100;    // counts to trigger change in direction

//int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};
int lookup[8] = {B01010, B01001, B00101, B00110};

void setup() {
  //declare the motor pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (count < revolution ) {
    Serial.println("clockwise");
    clockwise();
  } else if (count == revolution * 2) {
    count = 0;
  } else {
    Serial.println("counter clockwise");
    counterclockwise();
  }
  count++;
}

//set pins to ULN2003 high in sequence from 1 to 4
//delay "speed" between each pin setting (to determine speed)
void counterclockwise()
{
  for (int i = 0; i < 4; i++)
  {
    setOutput(i);
    delayMicroseconds(speed);
  }
}

void clockwise()
{
  for (int i = 4; i > 0; i--)
  {
    setOutput(i);
    delayMicroseconds(speed);
  }
}

void setOutput(int index)
{
  digitalWrite(motorPin1, bitRead(lookup[index], 0));
  digitalWrite(motorPin2, bitRead(lookup[index], 1));
  digitalWrite(motorPin3, bitRead(lookup[index], 2));
  digitalWrite(motorPin4, bitRead(lookup[index], 3));
}
