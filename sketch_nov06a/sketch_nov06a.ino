
/* Programmers: Luke Marchand & Faith Goodman
 * Date: 1.6.20
 * 
 */

//int laser = 13;
int receiver = 2;

void setup() {
  //provides output to the laser
  //pinMode(laser, OUTPUT);

  //initializes serial communication at 9600 bits per second
  Serial.begin(9600);

  //Makes the reciever give input
  pinMode(receiver, INPUT);
}

void loop() {
  //pulls the receiver value and puts it in an integer so it can be read on the serial monitor
  int receiverValue = digitalRead(receiver);

  //prints the previous value to the serial monitor
  Serial.println(receiverValue);
  
  //adds delay for stability
  delay(1);
}
