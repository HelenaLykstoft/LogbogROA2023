#include "SimpleTrafficLight.h"
#include "Arduino.h"

SimpleTrafficLight::SimpleTrafficLight(int pin, bool ledON,long onTime, long offTime)
    : _pin(pin), _ledON(ledON), _onTime(), _offTime(offTime), _nextChange(0), _state(false)
    {

    }

void SimpleTrafficLight::setup(long startTime){
    pinMode(_pin, OUTPUT);
    _nextChange = startTime + _offTime;
    _state = false;
    digitalWrite(_pin, !_ledON);
}

void SimpleTrafficLight::update(long now){
    if (now < _nextChange) return;
    _state = !_state;
    digitalWrite(_pin, _state == _ledON);
    _nextChange += ( _state ? _onTime : _offTime);
}