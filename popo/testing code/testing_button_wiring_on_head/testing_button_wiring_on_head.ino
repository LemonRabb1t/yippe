int buttonpin = 2;
int ledPin = 13;
int buttonState = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode (buttonpin, INPUT);
  pinMode (ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonpin);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(1000);

  } else {
    digitalWrite(ledPin, LOW);
    delay(100);
  }

  delay(10);


}
