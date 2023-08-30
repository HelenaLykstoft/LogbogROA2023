#include <Arduino.h>
#include <Servo.h>
 
Servo servo;

void setup() {
  // put your setup code here, to run once:
    servo.attach(D1);
    servo.write(0);
    delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
    servo.write(0);
    delay(3000);
    servo.write(90);
    delay(3000);
    servo.write(180);
    delay(3000);
  
}
