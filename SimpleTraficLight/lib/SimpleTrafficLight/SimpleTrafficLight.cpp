#include "SimpleTrafficLight.h"
#include "Arduino.h"

SimpleTrafficLight::SimpleTrafficLight(int ledRed, int ledYellow, int ledGreen, int ledRed2, int ledYellow2, int ledGreen2, bool ledON,long onTime, long offTime)
    : _ledRed(ledRed),_ledYellow(ledYellow),_ledGreen(ledGreen),_ledRed2(ledRed2),_ledYellow2(ledYellow2),_ledGreen2(ledGreen2), _ledON(ledON), _onTime(), _offTime(offTime), _nextChange(0), _state(false)
    {

    }

void SimpleTrafficLight::setup(long startTime){
    pinMode(_ledRed, OUTPUT);
    pinMode(_ledYellow, OUTPUT);
    pinMode(_ledGreen, OUTPUT);
    pinMode(_ledRed2, OUTPUT);
    pinMode(_ledYellow2, OUTPUT);
    pinMode(_ledGreen2, OUTPUT);
    
    _CurrentState = S0;
}

void SimpleTrafficLight::update(long now){
  
  long stateTime[8]={2000,2000,3000,2000,2000,2000,3000,2000};

  
  switch (_CurrentState)
  {
  case S0:
    if (now > stateTime[1]){
      digitalWrite(_ledRed, HIGH);
      digitalWrite(_ledRed2, HIGH);
      _CurrentState = S1;
    }
    break;

  case S1:
    if (now > stateTime[2] + stateTime[1]){
      digitalWrite(_ledRed, HIGH);
      digitalWrite(_ledRed2, HIGH);
      digitalWrite(_ledYellow, HIGH);
      _CurrentState = S2;
    }
    break;

  case S2:
    if (now > stateTime[3] + stateTime[2] + stateTime[1]){
      digitalWrite(_ledRed, LOW);
      digitalWrite(_ledRed2, HIGH);
      digitalWrite(_ledYellow, LOW);
      digitalWrite(_ledGreen, HIGH);
      _CurrentState = S3;
    }
    break;

  case S3:
    if (now > stateTime[4] + stateTime[3] + stateTime[2] + stateTime[1]){
      digitalWrite(_ledRed, LOW);
      digitalWrite(_ledRed2, HIGH);
      digitalWrite(_ledYellow, HIGH);
      digitalWrite(_ledGreen, LOW);
      _CurrentState = S4;
    }
    break; 

  case S4:
    if (now > stateTime[5] + stateTime[4] + stateTime[3] + stateTime[2] + stateTime[1]){
      digitalWrite(_ledRed, HIGH);
      digitalWrite(_ledRed2, HIGH);
      digitalWrite(_ledYellow, LOW);
      _CurrentState = S5;
    }
    break;

  case S5:
    if (now > stateTime[6] + stateTime[5] + stateTime[4] + stateTime[3] + stateTime[2] + stateTime[1]){
      digitalWrite(_ledRed, HIGH);
      digitalWrite(_ledRed2, HIGH);
      digitalWrite(_ledYellow2, HIGH);
      _CurrentState = S6;
    }
    break;

  case S6:
    if (now > stateTime[7] + stateTime[6] + stateTime[5] + stateTime[4] + stateTime[3] + stateTime[2] + stateTime[1]){
      digitalWrite(_ledRed, HIGH);
      digitalWrite(_ledRed2, LOW);
      digitalWrite(_ledYellow2, LOW);
      digitalWrite(_ledGreen2, HIGH);
      _CurrentState = S7;
    }
    break;

  case S7:
    if (now > stateTime[8] + stateTime[7] + stateTime[6] + stateTime[5] + stateTime[4] + stateTime[3] + stateTime[2] + stateTime[1]){
      digitalWrite(_ledRed, HIGH);
      digitalWrite(_ledRed2, LOW);
      digitalWrite(_ledYellow2, HIGH);
      digitalWrite(_ledGreen2, LOW);
    }
    _CurrentState = S0;
    break;
}
}