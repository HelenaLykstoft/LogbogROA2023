#ifndef SERVOMACHINE_H
#define SERVOMACHINE_H

#include <Servo.h>
#include <Arduino.h>


class ServoMachine{
    public:
    // Constructor
        ServoMachine(int pin, int minAngle, int maxAngle);
        void setup();
        void update(long currentTime);
        void setAngle(int angle);
        int getAngle();

    private:
        enum ServoState{
            SERVO_ON,
            SERVO_45,
            SERVO_90,
            SERVO_135,
            SERVO_180,
            SERVO_OFF
        };
        int _pin;
        int _minAngle;
        int _maxAngle;
        int _lastInputTime;
        Servo _servo;
        ServoState _servoState;
        // For millis to try to work
        long _nextChangeTime;

};


#endif // <ServoMachine.h>