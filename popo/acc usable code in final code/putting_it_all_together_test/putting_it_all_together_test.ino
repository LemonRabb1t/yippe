//  L  I  B  R  A  R  I  E  S
#include <Servo.h>             //Servo library

// V  A  R  I  A  B  L  E  S

// servo vars
Servo servo_1;
int servo_pin = 3;

// vars of button
// const
const int buttonPin = 2;     // the number of the pushbutton pin
const long interval = 4000; // time between actions
// vars //////
int buttonState = 0;         // variable for reading the pushbutton status
unsigned long previousTime = 0;        // will store last time LED was updated


// head shake vars
// after head shake /////////////
int delayafterheadshake = 70;
int handremovedelay = 1000;
int delayafterbuttonblink = 400;
// angles
int leftheadangle = 60;
int rightheadangle = 120;
int defaultangle = 90;

// blinking delay vars
int tDelay = 125;
int inbetweenDelay = 2;
int endblinkDelay = 10;
int pAValue = 100;
int E = 45;

// dc motor (eye) vars
int enable2 = 11;
int eyepin1 = 7;
int eyepin2 = 8;

// vars for head turning
int angle = 0;
char pos = 'A';
int delayTime = 3;
int motorshiftv = 1;
int dir = 0;
int endangle = 180;
int middleangle = 90;
int afterheadturndelay = 3000;

// A  C  T  U  A  L       C  O  D  E     U  N  D  E  R

void setup() {
  // put your setup code here, to run once:
  // serial
  Serial.begin(9600);

  // button set up
  pinMode(buttonPin, INPUT);

  // eye pins
  pinMode(enable2, OUTPUT);
  pinMode(eyepin1, OUTPUT);
  pinMode(eyepin2, OUTPUT);

  // servo
  servo_1.attach(servo_pin);
  servo_1.write (defaultangle);

  // head turning
  pos = 'M';
  angle = middleangle;

}

void loop() {
  // put your main code here, to run repeatedly:
  // check for button state
  buttonState = digitalRead(buttonPin);

  // if button is pressed, action
  if (buttonState == HIGH) {
    int TEMP = 5;

    // delay to remove hand
    delay (handremovedelay);
    // shake head
    for (int x = 0; x <= 2; x++) {


      for (int h = defaultangle; h >= leftheadangle; h--) {
        servo_1.write(h);
        delay(TEMP);
      }
      for (int h = leftheadangle; h <= rightheadangle; h++) {
        servo_1.write(h);
        delay(TEMP);
      }
    }

    // go to middle position
    for (int h = rightheadangle; h > defaultangle; h--) {
      servo_1.write(h);
      delay(TEMP);
    }
    delay(delayafterheadshake);

    // blink blink
    for (int x = 0; x < 2; x++) {
      Blink();
      delay (delayafterbuttonblink);
    }

  }

  // if button is not pressed

  // check to see if enough time has passed
  unsigned long currentTime = millis();

  // if enough time has passed, move head
  if (currentTime - previousTime <= interval) {

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
    // reset last time head turned for calc

  }
  // if not enough time passed, small delay to prevent data overload, check again
  delay(10);
}


// functions

// Blink function
void Blink() {
  // CCW close

  analogWrite(enable2, pAValue); // Any value between 0 and 255
  digitalWrite(eyepin1, HIGH);
  digitalWrite(eyepin2, LOW);
  delay(tDelay);
  digitalWrite(eyepin1, LOW);
  delay(inbetweenDelay);

  // CC open
  analogWrite(enable2, pAValue); // Any value between 0 and 255
  digitalWrite(eyepin1, LOW);
  digitalWrite(eyepin2, HIGH);
  delay(tDelay + E );
  digitalWrite(eyepin2, LOW);
  delay(endblinkDelay);
}
