#include "ServoMachine.h"
#include <Arduino.h>
#include <Servo.h>

ServoMachine::ServoMachine(int pin, int minAngle, int maxAngle) : _pin(pin), _minAngle(minAngle), _maxAngle(maxAngle), _servoState(SERVO_OFF), _lastInputTime(0) {}

void ServoMachine::setup() {
    pinMode(_pin, OUTPUT);
    _servo.attach(_pin, 500, 2400);
}

void ServoMachine::update(long now) {
    unsigned long timeElapsed = now - _lastInputTime;

    switch (_servoState) {

        case SERVO_ON:
            _lastInputTime = now;
            _servo.write(0);
            _servoState = SERVO_45;
            break;

        case SERVO_45:
            if (timeElapsed >= 1000) {
                _servo.write(45);
                _servoState = SERVO_90;
                _lastInputTime = now;
            }
            break;

        case SERVO_90:
            if (timeElapsed >= 1000) {
                _servo.write(90);
                _lastInputTime = now;
                _servoState = SERVO_135;
                
            }
            break;

        case SERVO_135:
            if (timeElapsed >= 1000) {
                _servo.write(135);
                Serial.println("Servo 135");
                _lastInputTime = now;
                _servoState = SERVO_180;
            
            }
            break;

        case SERVO_180:
            if (timeElapsed >= 1000) {
                _servo.write(180);
                Serial.println("Servo 180");
                _lastInputTime = now;
                _servoState = SERVO_OFF;
            }
            break;

        case SERVO_OFF:
            if (timeElapsed >= 1000){
            _servo.write(0);
            _lastInputTime = now;
            _servoState = SERVO_ON;
            }

            break;
            default:
            break;

    }
}
