#include <Servo.h>             //Servo library

// servo vars
Servo servo_1;        //initialize a servo object for the connected servo
int servo_pin = 3;

// button press ////////////////////////////////////

// head shake vars ////////////////
int shakeheaddelay = 50;
int leftheadangle = 60;
int rightheadangle = 120;

// after head shake
int delayafterheadshake = 500;

// other
int delayafterbuttonblink = 1000;

// blinking delay vars  ////////
int tDelay = 125;
int inbetweenDelay = 2;
int endblinkDelay = 1000;
int pAValue = 210;
int E = 45;

// dc motor (eye) vars 
int enable2 = 11;
int eyepin1 = 7;
int eyepin2 = 8;

// actual program //////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);

  // enable eye pins
  pinMode(enable2, OUTPUT);
  pinMode(eyepin1, OUTPUT);
  pinMode(eyepin2, OUTPUT);
  
  // enable servo pins
  servo_1.attach(servo_pin);      // attach the signal pin of servo to pin9 of arduino
  servo_1.write (90);

}

void loop() {

  // reset blink position to open

  //  // shake head (turn left and right really quickly)
  for (int x = 0; x < 4; x++) {
    servo_1.write(leftheadangle);
    delay(shakeheaddelay);
    servo_1.write(rightheadangle);
    delay(shakeheaddelay);
  }
  
  // go to middle position
  servo_1.write(90);
  delay(delayafterheadshake);

  Blink();
  delay (delayafterbuttonblink);

}

// blinking function
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
