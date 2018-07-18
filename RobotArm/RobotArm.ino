#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <math.h>

// pin number for the button that starts the ultrasonic scan
int button = 3;
// creates a pwm object with default I2C and address (0x40)
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// "heat map" for distance from ultrasonic sensor
int[][] distMap = new int[12][12];
// ultrasonic sensor variables
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

// point object in xyz system to store boundary points
struct Point {
  int x
  int y;
  int z;
}
// Boundaries of object in xyz system
// Up to 10 boundary points. More complex objects will be approximated with 10 points
Point[] coordinates = new Point [10];

// if arm is not used within a certain amount of time, then perform a random movement
long randNumber;
long timer;

// "Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!"
// -quote Adafruit servo example
#define SERVO1MIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVO1MAX  600 // this is the 'maximum' pulse length count (out of 4096)
#define SERVO2MIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVO2MAX  600 // this is the 'maximum' pulse length count (out of 4096)


void setup() {
  // begin serial monitor
  Serial.begin(9600);
  Serial.println("Initializing robotic arm");

  // initialize the servo shield
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  delay(10);

  // button pin needs to be input
  pinMode(button, INPUT);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));

  // random number between 1 and 4 hours
  randNumber = random(1, 4);
  timer = millis() + randNumber*3.6*pow(10, 6);
}

int getDistance() {
  // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
  
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
  
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance= duration*0.034/2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
}

// uses the ultrasonic sensor to populate a 12x12 array based on how far objects are away
void scanArea() {
  int servo1Block = (SERVO1MAX - SERVO1MIN)/12;
  int servo2Block = (SERVO2MAX - SERVO2MIN)/12;
  int servo1State = SERVO1MIN;
  int servo2State = servo2Min;

  pwm.setPWM(servonum, 0, pulselen);
  
  for (x = 0; x < 12; x++) {
    servo1State;
    getDistance();
  }
  
}

void findObject() {
  // algorithm used to determine the location of the object to be picked up
  
}

void calculateMovements() {
  // calculates the necessary servo angles to move the arm so that the tip of the claw is at the x position of the object closest
  // to the claw
}

void moveArmToInitialPosition() {
  // move the arm to the actual position calculated in the calculateMovements method
}

void scanDepth() {
  // use the IR LED and sensor to scan the depth of the object
  
}

void grabObject() {
  // (finally) grab the object and hold it in place
}

void loop() {

  if (digitalRead(button)) {
    scanArea();
    findObject();
    calculateMovements();
    moveArmToInitialPosition();
    scanDepth();
    grabObject();

    // random number between 1 and 4 hours
    randNumber = random(1, 4);
    timer = millis() + randNumber*3.6*pow(10, 6);
  }

  if (millis > timer) {
    // perform random movement

    // random number between 1 and 4 hours
    randNumber = random(1, 4);
    timer = millis() + randNumber*3.6*pow(10, 6);
  }

  delay(10);
}
