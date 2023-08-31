#include <Arduino.h>
#include "SimpleTrafficLight.h"


SimpleTrafficLight trafficLight(D0, D1, D2, D5, D6, D7, true, 5000, 1000);

void setup() {
  // put your setup code here, to run once:
  trafficLight.setup(millis());

}

void loop() {
  // put your main code here, to run repeatedly:
  long currentTime = millis();
  trafficLight.update(currentTime);

}
