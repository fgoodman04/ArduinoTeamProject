
/* Programmers: Luke Marchand & Faith Goodman
   Date: 1.6.20

*/

// Includes the stepper motor library for use in our program
#include <Stepper.h>

#define STEPS 32

Stepper stepperMotor(STEPS, 8, 10, 9, 11);

int val = 0;

void setup() {
  //sets the pin to output for the motor
  stepperMotor.setSpeed(700);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0)
  {
    val = Serial.parseInt();
    stepperMotor.step(val);
    Serial.println(val);
  }
}
