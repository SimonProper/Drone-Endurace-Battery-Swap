#ifndef DCMOTORCONTROLLER_H
#define DCMOTORCONTROLLER_H
#include <Arduino.h>

class DcMotorController{
    public:
        DcMotorController(const int motorPin1, const int motorPin2, const int endStopPin1, const int endStopPin2);
        void runMotor(const int direction);
    private:
        int endStopPin1;
        int endStopPin2;
        int motorPin1;
        int motorPin2;
};

#endif