#include <Arduino.h>
#include <Button.h>

int count = 0;
int buttonPin = D3;
bool _prevButtonState = false;

Button myButton(buttonPin, LOW);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myButton.setup(millis());
  
}

void loop() {
  if (_prevButtonState != myButton.getButtonState()){
    _prevButtonState = myButton.getButtonState();
    if (_prevButtonState){
      count++;
      Serial.println(count);
    }
  }
}
