
/* Programmers: Luke Marchand & Faith Goodman
   Date: 1.6.20

*/
#include <LiquidCrystal.h>
#include <Stepper.h>

#define STEPS 32

const int rs = 24, en = 22, d4 = 52, d5 = 47, d6 = 43, d7 = 40;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Stepper stepperMotor(STEPS, 8, 10, 9, 11);

int receiver = 13;

int button = 2;

float money = 0;

bool isLaserDetected = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(receiver, INPUT);

  pinMode(button, INPUT);

  stepperMotor.setSpeed(700);

  lcd.begin(16, 2);

  lcd.print("Welcome");

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int receiverValue = digitalRead(receiver);
  int buttonState = digitalRead(button);

  if (money == 0){
    lcd.clear();
    lcd.print("Welcome");
  }

  if (receiverValue == LOW && isLaserDetected == true){
    isLaserDetected = false;
    money = money + .25;
    lcd.clear();
    lcd.print("$" + int(money));
  }
  else if (receiverValue == HIGH && isLaserDetected == false) {
    isLaserDetected = true;
  }

  if (button == HIGH && money >= .75){
    stepperMotor.step(2048);
  }

  //adds delay for stability
  delay(1);
}
