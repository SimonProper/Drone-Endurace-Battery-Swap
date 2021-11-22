// #ifndef STEPPERWRAPPER_H
#define STEPPERWRAPPER_H
#include <Stepper.h>

class MotorController {
    public:
        MotorController(int steps, int pin_1, int pin_2, int pin_3, int pin_4);
        //In milimeters
        virtual void RunMotor(const double distance);

    protected:
        virtual double CalculateRun(const double);
        Stepper* stepper_connection;
        int motor_steps;
};

class MotorControllerThreddedRod : public MotorController {
    public:
        MotorControllerThreddedRod(int steps, double thredd_rise, int pin_1, int pin_2, int pin_3, int pin_4);
        void RunMotor(const double distance);
    private:
        double CalculateRun(const double distance);
        double rise;
};

class MotorControllerToothedBelt : public MotorController {
    public:
        MotorControllerToothedBelt(int steps, double diameter, double transmission, int pin_1, int pin_2, int pin_3, int pin_4);
        void RunMotor(const double distance);
    private:
        double CalculateRun(const double distance);
        double diameter;
        double transmission;
};


// #endif