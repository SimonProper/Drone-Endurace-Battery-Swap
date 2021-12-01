#include <Arduino.h>
#include <DcMotorController.h>


DcMotorController::DcMotorController(const int motorPin1, const int motorPin2, 
    const int endStopPin1, const int endStopPin2): motorPin1{motorPin1},
    motorPin2{motorPin2}, endStopPin1{endStopPin1}, endStopPin2{endStopPin2}{
        digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, LOW);
    }

void DcMotorController::runMotor(const int direction){
    uint8_t pin1; 
    uint8_t pin2; 
    if(direction == 1){
        pin1 = HIGH;
        pin2 = LOW;
        // digitalWrite(motorPin1, HIGH);
        // digitalWrite(motorPin2, LOW);
        while( digitalRead(endStopPin1) == 1){
            digitalWrite(endStopPin1, pin1);
            digitalWrite(endStopPin2, pin2);
        };
    }
    else if( direction == 0){
        pin1 = LOW;
        pin2 = HIGH;
        // digitalWrite(motorPin1, LOW);
        // digitalWrite(motorPin2, HIGH);
        while(digitalRead(endStopPin2) == 1){
            digitalWrite(endStopPin1, pin1);
            digitalWrite(endStopPin2, pin2);
        };
    }
    else{
        Serial.println("Unknown direction");
    };
}