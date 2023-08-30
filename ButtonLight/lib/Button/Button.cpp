#include <Button.h>
#include <Arduino.h>

Button::Button(int pin, bool buttonDown) : _pin(pin), _buttonDown(buttonDown){}

void Button::setup(long startTime){
    pinMode(_pin, INPUT_PULLUP);
    _ButtonState = BUTTON_OFF;
}

void  Button::update(long now){

    switch (_ButtonState){
        case BUTTON_OFF:
            if (digitalRead(_pin) != _buttonDown) return;
                _ButtonState = BUTTON_PUSH;
                _nextChangeTime = now + _noiseCancelTimer;
            break;

        case BUTTON_PUSH:
            if (now < _nextChangeTime) return;
            _ButtonState = BUTTON_ON;
            break;

        case BUTTON_ON:
            if (digitalRead(_pin) == _buttonDown) return;
            _ButtonState = BUTTON_RELEASE;
            _nextChangeTime = now + _noiseCancelTimer;
            break;

        case BUTTON_RELEASE:
            if (now < _nextChangeTime) return;
            _ButtonState = BUTTON_OFF;
            break;
    }
}

bool Button::getButtonState(){
    return _ButtonState == BUTTON_ON || _ButtonState == BUTTON_PUSH;
}