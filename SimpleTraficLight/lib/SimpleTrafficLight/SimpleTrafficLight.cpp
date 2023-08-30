#include "SimpleTrafficLight.h"
#include "Arduino.h"

SimpleTrafficLight ledRed(D0, true, 5000, 1000);
SimpleTrafficLight ledYellow(D1,false, 5000, 1000);
SimpleTrafficLight ledGreen(D2, false, 5000, 1000);

SimpleTrafficLight ledRed2(D5, true, 5000, 1000);
SimpleTrafficLight ledYellow2(D6, false, 5000, 1000);
SimpleTrafficLight ledGreen2(D7, false, 5000, 1000);


SimpleTrafficLight::SimpleTrafficLight(int pin, bool ledON,long onTime, long offTime)
    : _pin(pin), _ledON(ledON), _onTime(), _offTime(offTime), _nextChange(0), _state(false)
    {

    }

void SimpleTrafficLight::setup(long startTime){
    pinMode(_pin, OUTPUT);
    _nextChange = startTime + _offTime;
    _state = false;
    digitalWrite(_pin, !_ledON);
    _CurrentState = S0;
}

void SimpleTrafficLight::update(long now){
    if (now < _nextChange) return;
    _state = !_state;
    digitalWrite(_pin, _state == _ledON);
    _nextChange += ( _state ? _onTime : _offTime);
    long stateTime[8]={5000,5000,5000,5000,5000,5000,5000,5000};

  
  switch (_CurrentState)
  {
  case S0:
    ledRed.update(stateTime[0]);
    ledRed2.update(stateTime[0]);
    _CurrentState = S1;
    break;

  case S1:
    ledRed.update(stateTime[1]);
    ledYellow.update(stateTime[1]);
    ledRed2.update(stateTime[1]);
    _CurrentState = S2;
    break;

  case S2:
    ledGreen.update(stateTime[2]);
    ledRed2.update(stateTime[2]);
    _CurrentState = S3;
    break;

  case S3:
    ledYellow.update(stateTime[3]);
    ledRed2.update(stateTime[3]);
    _CurrentState = S4;
    break; 

  case S4:
    ledRed.update(stateTime[4]);
    ledRed2.update(stateTime[4]);
    _CurrentState = S5;
    break;

  case S5:
    ledRed.update(stateTime[5]);
    ledYellow.update(stateTime[5]);
    ledRed2.update(stateTime[5]);
    _CurrentState = S6;
    break;

  case S6:
    ledRed.update(stateTime[6]);
    ledGreen2.update(stateTime[6]);
    _CurrentState = S7;
    break;

  case S7:
    ledRed.update(stateTime[7]);
    ledYellow2.update(stateTime[7]);
    _CurrentState = S0;
    break;
}