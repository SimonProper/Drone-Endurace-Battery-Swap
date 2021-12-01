#include <StepperWrapper.h>
#include <Stepper.h>
#include <Arduino.h>

//*Root Class
MotorController::MotorController(int steps , int pin_1, int pin_2, int pin_3,
 int pin_4):motor_steps{steps}{
    Stepper* stepper_connection = new Stepper(steps, pin_1, pin_2, pin_3, pin_4);

};

void MotorController::setSpeed(const int speed){
  this->stepper_connection->setSpeed(speed);
  Serial.println("settingspeed");
}

void MotorController::RunMotor(const double distance){
  stepper_connection->step(this->CalculateSteps(distance));
  Serial.println("runmotor");
}

//*For thredded rods
MotorControllerThreddedRod::MotorControllerThreddedRod(int steps,
  double thredd_rise, int pin_1, int pin_2, int pin_3, int pin_4)
  :MotorController(steps, pin_1, pin_2, pin_3, pin_4), rise{thredd_rise}, 
  distance_steps{rise/steps}{
    Serial.println("constructor");
  };

int MotorControllerThreddedRod::CalculateSteps(const double distance){
  const int steps_to_run = distance/distance_steps;
  return steps_to_run;  
    Serial.println("calculating");
};

// void MotorControllerThreddedRod::RunMotor(const double distance){
    
//     stepper_connection->step(steps_to_run);
// }

//*Toothed belts
MotorControllerToothedBelt::MotorControllerToothedBelt(int steps,
  double diameter, int pin_1, int pin_2, int pin_3,
  int pin_4):MotorController(steps, pin_1, pin_2, pin_3, pin_4),
  diameter{diameter}, distance_steps{diameter/2*3.14/180*(motor_steps/360)}
  {};

int MotorControllerToothedBelt::CalculateSteps(const double distance){
  const int calculated_steps = int(distance);
  return calculated_steps;  
};

// void MotorControllerToothedBelt::RunMotor(const double distance){
//     // const int steps_to_run = this->CalculateRun(distance);
//     const int steps_to_run = int(diameter/2*3.14/180*(motor_steps/360));
//     stepper_connection->step(steps_to_run);
// }