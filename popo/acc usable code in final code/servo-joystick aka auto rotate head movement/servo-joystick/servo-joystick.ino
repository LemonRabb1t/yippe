#include <Servo.h>             //Servo library

Servo servo_1;        //initialize a servo object for the connected servo
int servo_pin = 3;

// vars for head turning
int angle = 0;
char pos = 'A';
int delayTime = 3;
int motorshiftv = 1;
int dir = 0;
int endangle = 180;
int middleangle = 90;
int afterheadturndelay = 3000;

// temp vars


void setup()
{
  servo_1.attach(servo_pin);      // attach the signal pin of servo to pin9 of arduino
  servo_1.write (middleangle);
  delay (500);
  pos = 'M';
  angle = middleangle;

}

void loop() {
  // reset head to Middle position

  // if pos is not in the middle, set it to middle ////////////////////////
  if (pos != 'M') {
    if (pos == 'C') {
      for (int a = endangle; a >= middleangle ; a -= motorshiftv) {
        servo_1.write(a);
        delay(delayTime);
      }
    } else if (pos == 'W') {
      for (int a =  0; a <= middleangle ; a += motorshiftv) {
        servo_1.write(a);
        delay(delayTime);
      }
    }
    pos = 'M';

    // if pos is in the middle      ////////////////////////////

  } else if (pos == 'M') {
    // get a random direction
    dir = random(3);

    // if direction is CCW
    if (dir == 1) {
      // turn head CCW
      for (int a = angle; a >= 0 ; a -= motorshiftv) {
        servo_1.write(a);
        delay(delayTime);
      }

      pos = 'W';

      // if direction is CC
    } else if (dir == 2) {
      // turn head CC
      for (int a =  angle; a <= endangle ; a += motorshiftv) {
        servo_1.write(a);
        delay(delayTime);
      }
      pos = 'C';
    }

  }

  delay (afterheadturndelay);
}
