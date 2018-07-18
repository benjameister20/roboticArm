#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// pin number for the button that starts the ultrasonic scan
int button = 3;
// creates a pwm object with default I2C and address (0x40)
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// "heat map" for distance from ultrasonic sensor
int[][] distMap = new int[12][12];

// "Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!"
//      -quote Adafruit servo example
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)


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

}

// uses the ultrasonic sensor to populate a 12x12 array based on how far objects are away
void scanArea() {
  
}

void loop() {

  if (digitalRead(button)) {
    scanArea();
  }


  delay(10);
}
