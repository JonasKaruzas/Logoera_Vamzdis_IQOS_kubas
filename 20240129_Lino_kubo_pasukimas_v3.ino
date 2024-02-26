#include <AccelStepper.h>

// defines pins numbers
const int stepPin = 4; 
const int dirPin  = 3;
const int enPin   = 2;
//const int analogInPin = A4;
const int buttonPin = 5;     // the number of the pushbutton pin
int buttonState = 0;  

AccelStepper stepper(1, stepPin, dirPin); // Initialize AccelStepper with 1 motor

int sensorValue = 0;
int maxSpeedValue = 0;  

void setup() {
  // Sets the two pins as Outputs
    pinMode(buttonPin, INPUT);
  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);
  
  stepper.setMaxSpeed(2000); // Set the maximum speed
  stepper.setAcceleration(2000); // Set the acceleration
}

void loop() {
//  sensorValue = analogRead(analogInPin);
//  maxSpeedValue = map(sensorValue, 0, 1023, 400, 2000);
  buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
      

  stepper.setSpeed(2000); // Set the speed
  
  digitalWrite(dirPin, HIGH); // Set direction

  stepper.runToNewPosition(stepper.currentPosition() + 800); // Rotate 800 steps
  delay(500); // Three-second delay
}
      }
