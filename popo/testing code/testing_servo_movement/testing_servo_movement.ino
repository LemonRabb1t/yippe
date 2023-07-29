//  L  I  B  R  A  R  I  E  S
#include <Servo.h>             //Servo library

// V  A  R  I  A  B  L  E  S

// servo vars
Servo servo_1;       
int servo_pin = 3;

void setup() {
  // put your setup code here, to run once:
  servo_1.attach(servo_pin);      
  servo_1.write (90);
}

void loop() {
  // put your main code here, to run repeatedly:

}
