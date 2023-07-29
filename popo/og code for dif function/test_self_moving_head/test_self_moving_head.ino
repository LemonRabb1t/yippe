#include <Servo.h>             //Servo library

Servo servo_1;        //initialize a servo object for the connected servo
int servo_pin = 2;

int angle = 0;
//unsigned long previoustime = 0; // last time head moved
//const long interval = 10000; // interval which head moves
char pos = 'IDK';
int delayTime = 2;
int motorshiftv = 1;
int dir = 0;
int endangle = 115;

void setup()
{
  servo_1.attach(servo_pin);      // attach the signal pin of servo to pin9 of arduino
}

//int moveright {
//}
//
//int moveleft {
//}
//
//int ogposition{
//}

void loop() {

  // write beginning position to middle
  if (pos != 'CC' or pos != 'CCW' or pos != 'M') {
    servo_1.write (0);
    pos = 'M';
    angle = 0;
  }

  // if head position is cc or ccw, turn it to middle
  if (pos = 'CC' or pos = 'CCW') {
    //  if angle <=
    // turns CCW
    for (int a = angle; a < endangle; a += motorshiftv) {  // command to move from 0 degrees to 180 degrees
      servo_1.write(a);                 //command to rotate the servo to the specified angle
      delay(delayTime);
    }

    // if head position if M, turn it to cc or ccw
  } else if (pos = 'M') {
    //choose direction to turn
    dir = random(3)

          // CC (1)
    if (dir == 1) {

      pos = 'CC'
    }

    // CCW (2)
    if (dir == 2) {

      pos = 'CCW'
    }

    for (angle = endangle; angle >= 1; angle -= motorshiftv) // command to move from 180 degrees to 0 degrees
    {
      servo_1.write(angle);              //command to rotate the servo to the specified angle
      delay(delayTime);
    }
  }
  delay(500);






}
//  // gets current time
//  unsigned long currenttime = millis();
//
//  if (currenttime - previoustime >= interval) {
//    // resets last time head moved
//    previoustime = currenttime;
//
//    if ( pos = 'M') {
//      for (angle = 0; angle < 180; angle += 1) {  // command to move from 0 degrees to 180 degrees
//        servo_1.write(angle);                 //command to rotate the servo to the specified angle
//        delay(60);
//      }
//      pos = 'CC';
//    }
//
//    if (pos = 'CC' or pos == 'CCW') {
//      for (angle = 180; angle >= 1; angle -= 5) // command to move from 180 degrees to 0 degrees
//      {
//        servo_1.write(angle);              //command to rotate the servo to the specified angle
//        delay(5);
//      }
//      pos = 'CCW';
//    }
//
//  }



//  for (angle = 180; angle >= 1; angle -= 5) // command to move from 180 degrees to 0 degrees
//  {
//    servo_1.write(angle);              //command to rotate the servo to the specified angle
//    delay(5);
//  }
