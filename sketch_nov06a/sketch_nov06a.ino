
/* Programmers: Luke Marchand & Faith Goodman
 * Date: 1.6.20
 * 
 */

#include <Stepper.h>

#define STEPS 32

Stepper stepperMotor(STEPS, 8, 10, 9, 11);

void setup() {
  //sets the pin to output for the motor
  pinMode(servoPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //turns the motor on for 1 sec
  digitalWrite(servoPin, HIGH);
  delay(1000);

  

  //turns the motor off for 1 sec
  digitalWrite(servoPin, LOW);
  delay(1000);
}
