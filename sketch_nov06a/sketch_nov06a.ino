
/* Programmers: Luke Marchand & Faith Goodman
 * Date: 1.6.20
 * 
 */

int motorPin = 13; 

void setup() {
  //sets the pin to output for the motor
  pinMode(motorPin, OUTPUT);

}

void loop() {
  //turns the motor on for 1 sec
  digitalWrite(motorPin, HIGH);
  delay(1000);

  //turns the motor off for 1 sec
  digitalWrite(motorPin, LOW);
  delay(1000);
}
