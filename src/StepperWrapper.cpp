#include <StepperWrapper.h>
#include <Stepper.h>

//*Root Class
MotorController::MotorController(int steps , int pin_1, int pin_2, int pin_3,
 int pin_4):motor_steps{steps}{
    Stepper* stepper_connection = new Stepper(steps, pin_1, pin_2, pin_3, pin_4);
    // double  degree = 360/steps;

};


//*For thredded rods
MotorControllerThreddedRod::MotorControllerThreddedRod(int steps,
  double thredd_rise, int pin_1, int pin_2, int pin_3, int pin_4)
  :MotorController(steps, pin_1, pin_2, pin_3, pin_4) 
{

}

double MotorControllerThreddedRod::CalculateRun(const double distance){
  int calculated_steps = 0;
  return calculated_steps;  
};

void MotorControllerThreddedRod::RunMotor(const double distance){
    const int steps_to_run = this->CalculateRun(distance);
    stepper_connection->step(steps_to_run);
}

//*Toothed belts

MotorControllerToothedBelt::MotorControllerToothedBelt(int steps,
  double diameter, double distance, int pin_1, int pin_2, int pin_3,
  int pin_4):MotorController(steps, pin_1, pin_2, pin_3, pin_4) 
{

}

double MotorControllerToothedBelt::CalculateRun(const double distance){
  int calculated_steps = 0;
  return calculated_steps;  
};

void MotorControllerToothedBelt::RunMotor(const double distance){
    const int steps_to_run = this->CalculateRun(distance);
    stepper_connection->step(steps_to_run);
}