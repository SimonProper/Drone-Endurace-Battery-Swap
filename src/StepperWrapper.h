#ifndef STEPPERWRAPPER_H
#define STEPPERWRAPPER_H
#include <Stepper.h>

class MotorController {
    public:
        MotorController(int steps, int pin_1, int pin_2, int pin_3, int pin_4);
        //In milimeters
        void RunMotor(const double distance);
        void setSpeed(const int);
    protected:
        virtual int CalculateSteps(const double) = 0;
        Stepper* stepper_connection;
        int motor_steps;
};

class MotorControllerThreddedRod : public MotorController {
    public:
        MotorControllerThreddedRod(int steps, double thredd_rise, int pin_1, int pin_2, int pin_3, int pin_4);
    private:
        int CalculateSteps(const double distance);
        double rise;
        const double distance_steps;
};

class MotorControllerToothedBelt : public MotorController {
    public:
        MotorControllerToothedBelt(int steps, double diameter, int pin_1, int pin_2, int pin_3, int pin_4);
    private:
        int CalculateSteps(const double distance);
        double diameter;
        const double distance_steps;
};


#endif