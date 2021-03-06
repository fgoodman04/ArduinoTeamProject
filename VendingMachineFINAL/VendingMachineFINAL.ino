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
bool welcome = true;

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

  Serial.println(buttonState);

  if (money == 0 && welcome == false){
    lcd.clear();
    lcd.print("Welcome ");
    welcome = true;
  }

  if (receiverValue == LOW && isLaserDetected == true){
    isLaserDetected = false;
    money = money + .25;
    lcd.clear();
    lcd.print("$");
    lcd.print(money);
    welcome = false;
  }
  else if (receiverValue == HIGH && isLaserDetected == false) {
    isLaserDetected = true;
  }

  if (buttonState == HIGH && money >= .75){
    money = money - .75;
    lcd.clear();
    lcd.print("Dispensing...");
    stepperMotor.step(-2048);
    lcd.clear();
    lcd.print("$");
    lcd.print(money);
  }

  //adds delay for stability
  delay(1);
}
