#include <Arduino.h>
#include <Servo.h>
#include <ServoMachine.h>
 
int servoPin = D1; 
ServoMachine servo(servoPin, 500, 2400);
//Servo servo(D1, 500, 2400);

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    //servo.attach(D1, 500, 2400);
    //servo.write(0);
    servo.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
    //servo.write(-90);
    //delay(1000);
    //servo.write(135);
    //delay(2000);
    //servo.write(90);
    //delay(1000);
    //servo.write(0);
    //delay(2000);
    long currentTime = millis();
    servo.update(currentTime);
    
}
