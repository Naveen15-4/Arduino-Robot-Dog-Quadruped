#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create the PWM servo driver object
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Define the minimum and maximum pulse lengths for your servos
#define SERVOMIN  150  // Minimum pulse length count (adjust this for your servos)
#define SERVOMAX  600  // Maximum pulse length count (adjust this for your servos)

// Function to map angles (0-180 degrees) to pulse width
int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

// Set desired angles for each servo (0 to 180 degrees)
int servo1_angle =45;   // Change this value to set the angle for Servo 1
int servo2_angle = 55;  // Change this value to set the angle for Servo 2
int servo3_angle = 45;  // Change this value to set the angle for Servo 3
int servo4_angle = 30;  // Change this value to set the angle for Servo 4
int servo5_angle = 140; // Change this value to set the angle for Servo 5
int servo6_angle = 35;  // Change this value to set the angle for Servo 6

void setup() {
  Serial.begin(9600);
  Serial.println("Manually Setting Servo Angles");

  // Initialize the PCA9685
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz frequency

  delay(10);  // Short delay to allow driver to stabilize

   //Set each servo to the desired angle
  pwm.setPWM(0, 0, angleToPulse(servo1_angle)); // Servo 1
  pwm.setPWM(1, 0, angleToPulse(servo2_angle)); // Servo 2
  pwm.setPWM(2, 0, angleToPulse(servo3_angle)); // Servo 3
  pwm.setPWM(3, 0, angleToPulse(servo4_angle)); // Servo 4
  pwm.setPWM(4, 0, angleToPulse(servo5_angle)); // Servo 5
  pwm.setPWM(5, 0, angleToPulse(servo6_angle)); // Servo 6
}

void loop() {
  // Nothing here, as angles are set in setup()
  // Modify the angle values above, and re-upload the code to update servo positions
}
