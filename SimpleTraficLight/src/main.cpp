#include <Arduino.h>
#include "SimpleTrafficLight.h"

SimpleTrafficLight ledRed(D0, true, 5000, 1000);
SimpleTrafficLight ledYellow(D1,false, 5000, 1000);
SimpleTrafficLight ledGreen(D2, false, 5000, 1000);

SimpleTrafficLight ledRed2(D5, true, 5000, 1000);
SimpleTrafficLight ledYellow2(D6, false, 5000, 1000);
SimpleTrafficLight ledGreen2(D7, false, 5000, 1000);



void setup() {
  // put your setup code here, to run once:
  long start = millis();
  ledRed.setup(start);
  ledYellow.setup(start);
  ledGreen.setup(start);
  ledRed2.setup(start);
  ledYellow2.setup(start);
  ledGreen2.setup(start);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  long stateTime[8]={5000,5000,5000,5000,5000,5000,5000,5000};
  static int currentState= 0;
  
  switch (currentState)
  {
  case 0:
    ledRed.update(stateTime[0]);
    ledRed2.update(stateTime[0]);
    currentState = 1;
    break;

  case 1:
    ledRed.update(stateTime[1]);
    ledYellow.update(stateTime[1]);
    ledRed2.update(stateTime[1]);
    currentState = 2;
    break;

  case 2:
    ledGreen.update(stateTime[2]);
    ledRed2.update(stateTime[2]);
    currentState = 3;
    break;

  case 3:
    ledYellow.update(stateTime[3]);
    ledRed2.update(stateTime[3]);
    currentState = 4;
    break; 

  case 4:
    ledRed.update(stateTime[4]);
    ledRed2.update(stateTime[4]);
    currentState = 5;
    break;

  case 5:
    ledRed.update(stateTime[5]);
    ledYellow.update(stateTime[5]);
    ledRed2.update(stateTime[5]);
    currentState = 6;
    break;

  case 6:
    ledRed.update(stateTime[6]);
    ledGreen2.update(stateTime[6]);
    currentState = 7;
    break;

  case 7:
    ledRed.update(stateTime[7]);
    ledYellow2.update(stateTime[7]);
    currentState = 0;
    break;
}
}
