int enable2 = 9;
int eyepin1 = 10;
int eyepin2 = 11;

int tDelay = 125;
int inbetweenDelay = 20;
int endblinkDelay = 1000;
int pAValue = 210;
int E = 15;
int F = 0;

void setup() {

  pinMode(enable2, OUTPUT);
  pinMode(eyepin1, OUTPUT);
  pinMode(eyepin2, OUTPUT);

}

void loop() {

  // reset blink position to open
  if (F == 0) {
    analogWrite(enable2, pAValue); // Any value between 0 and 255
    digitalWrite(eyepin1, LOW);
    digitalWrite(eyepin2, HIGH);
    delay(tDelay + E);
    digitalWrite(eyepin2, LOW);
    delay(endblinkDelay);
    F = 1;
  }

  Blink();
  delay (3000);

}

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
  delay(tDelay + E);
  digitalWrite(eyepin2, LOW);
  delay(endblinkDelay);
}
