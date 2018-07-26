/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test - this will drive 8 servos, one after the other on the
  first 8 pins of the PCA9685

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815
  
  These drivers use I2C to communicate, 2 pins are required to  
  interface.

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address and I2C interface
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(&Wire, 0x40);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  250 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  400 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
int servonum = 1;
bool count = true;
int servo;

void setup() {
  Serial.begin(9600);
  Serial.println("Testing all arm movements");

  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  pwm.setPWM(7, 0, 150); // 150 - 550
  pwm.setPWM(2, 0, 400);
  pwm.setPWM(3, 0, 100); // 280 - 600
  pwm.setPWM(4, 0, 350); // 100 - 600 with middle 350

 /*pwm.setPWM(4, 0, 100);
 pwm.setPWM(4, 0, 600);
 pwm.setPWM(4, 0, 100);
 for (int x = 100; x < 350; x++) {
    pwm.setPWM(4, 0, x);
    delay(10);
  }
  
  for (int x = 100; x < 500; x++) {
    pwm.setPWM(3, 0, x);
    delay(50);
  }
  for (int x = 500; x > 100; x--) {
    pwm.setPWM(3, 0, x);
    delay(50);
  }
  
  for (int x = 500; x > 100; x--) {
    pwm.setPWM(2, 0, x);
    delay(50);
  }
  for (int x = 100; x < 350; x++) {
    pwm.setPWM(2, 0, x);
    delay(50);
  }*/

  Serial.println("The servos on the are numbered 1 to 5 with servo 1 being the base and servo 5 being the tip of the arm");

  delay(10);
}

void loop() {
  /*if (count) {
    if (servonum == 1)
      Serial.println("Testing each servo one at a time");
    // Drive each servo one at a time
    Serial.print("Testing servo ");
    Serial.print(servonum);
    Serial.println(" movement");
    for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
      pwm.setPWM(servonum, 0, pulselen);
      delay(100);
    }
  
    delay(500);
    for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
      pwm.setPWM(servonum, 0, pulselen);
      delay(100);
    }
  
    delay(500);
  
    servonum++;
    if (servonum > 5) count=false;
  }
  else {
    Serial.println("Testing all servos together");
    
    for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
      for (int servo = 1; servo < 6; servo++) {
        pwm.setPWM(servo, 0, pulselen);
        delay(10);
      }
    }
    
    for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
      for (int servo = 1; servo < 6; servo++) {
        pwm.setPWM(servo, 0, pulselen);
        delay(10);
      }
    }
    count = 0;
    servonum = 1;
    
  }
  delay(500);*/

  //Serial.println("Which servo would you like to try?");
  //while(Serial.available() == 0);
  //servo = Serial.read();
  //Serial.print("Testing servo ");
  //Serial.println(servonum);

  /*for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(servonum, 0, pulselen);
    delay(50);
  }
 servonum++;
 if (servonum > 7) servonum=1;*/
 delay(10); 
}
