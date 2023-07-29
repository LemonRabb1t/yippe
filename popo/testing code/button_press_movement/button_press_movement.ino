#include <Servo.h>             //Servo library

Servo servo_1;        //initialize a servo object for the connected servo
int servo_pin = 2;

int enable2 = 9;
int eyepin1 = 10;
int eyepin2 = 11;

int tDelay = 125;
int inbetweenDelay = 2;
int endblinkDelay = 1000;
int pAValue = 210;
int E = 45;

void setup() {
  // put your setup code here, to run once:
  servo_1.attach(servo_pin);      // attach the signal pin of servo to pin9 of arduino
  servo_1.write (90);


}

void loop() {
  // put your main code here, to run repeatedly:

  //  // shake head (turn left and right really quickly)
    for (int x = 0; x < 2; x++) {
      servo_1.write(70);
      delay(100);
      servo_1.write(110);
      delay(100);
    }
    // go to middle position
    servo_1.write(90);
    delay(100);

  // blink twice
  for (int x = 0; x < 4; x++) {
    Blink();
  }
  //
  Blink();
}
void Blink() {
  // CCW close
  analogWrite(enable2, pAValue); // Any value between 0 and 255
  digitalWrite(eyepin1, HIGH);
  digitalWrite(eyepin2, LOW);
  delay(tDelay + E);
  digitalWrite(eyepin1, LOW);
  delay(inbetweenDelay);

  // CC open
  analogWrite(enable2, pAValue); // Any value between 0 and 255
  digitalWrite(eyepin1, LOW);
  digitalWrite(eyepin2, HIGH);
  delay(tDelay );
  digitalWrite(eyepin2, LOW);
  delay(endblinkDelay);
}
