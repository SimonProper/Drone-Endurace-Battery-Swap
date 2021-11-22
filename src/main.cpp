
#include <Arduino.h>
#include <Stepper.h>
// #include <StepperWrapper.h>

#define STEPS 200

Stepper stepper1(STEPS, 4,5,6,7);
Stepper stepper2(STEPS, 8,9,10,11);
// MotorController Motor1(1,1,1,1,1);
int a = 0;

void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
  stepper1.setSpeed(60);
  stepper2.setSpeed(120);
}

void loop() {
  // put your main code here, to run repeatedly:
  // stepper1.step(-200);
  stepper2.step(200);
}
  
