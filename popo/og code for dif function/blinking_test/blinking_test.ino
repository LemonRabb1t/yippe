int enable2 = 11;
int in3 = 7;
int in4 = 8;
int tDelay = 125;
int inbetweenDelay = 5;
int pAValue = 50;

void setup() {

  pinMode(enable2, OUTPUT);

  pinMode(in3, OUTPUT);

  pinMode(in4, OUTPUT);

}

void loop() {

  analogWrite(enable2, pAValue); // Any value between 0 and 255
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(tDelay);
  digitalWrite(in3, LOW);
  delay(inbetweenDelay);


  analogWrite(enable2, pAValue); // Any value between 0 and 255
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(tDelay);
  digitalWrite(in4, LOW);
  delay(1000);

}
