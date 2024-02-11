//#include <AccelStepper.h>

// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin 3
#define stepPin 2
#define motorInterfaceType 1

//AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

const int buttonPin = 5;     // the number of the pushbutton pin
int buttonState = 0;  
int pos = 0;
const int enablePin = 4;  
const int analogInPin = A4  ;  // Analog input pin that the potentiometer is attached to
int sensorValue = 0;        // value read from the pot
int maxSpeedValue = 0;        // value output to the PWM (analog out)
int accelerationValue = 0;        // value output to the PWM (analog out)

int ROTATE_STEPS = 1600; //200 full steps * 32 microstepping = 6400 / 4 (for 90 degree turn)

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(enablePin , OUTPUT); // for stepper controller
}

void loop() {
  sensorValue = analogRead(analogInPin);
  maxSpeedValue = map(sensorValue, 0, 1023, 50, 8000);
//  accelerationValue = map(sensorValue, 0, 1023, 10, 800);
  
//  stepper.setMaxSpeed(maxSpeedValue);
//  stepper.setAcceleration(accelerationValue);

 // stepper.setCurrentPosition(0); // Setting AccelStepper position value to 0
    
  digitalWrite(enablePin, HIGH);  // Disable controller
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {

    digitalWrite(enablePin, LOW);

      for (int i = 0; i < ROTATE_STEPS; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(maxSpeedValue);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(maxSpeedValue);
  }
 //   pos = stepper.currentPosition() + ROTATE_STEPS;
  
//    stepper.moveTo(pos);
//    stepper.runToPosition();
  
    delay(300);
  } 
}
