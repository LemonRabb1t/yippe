
// const
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  3;      // the number of the LED pin
const int delayTime = 10; // delay time for light flashing
const long interval = 4000; // time between actions

// vars
int buttonState = 0;         // variable for reading the pushbutton status
char ledStat = 'OFF';
unsigned long previousTime = 0;        // will store last time LED was updated

// temp vars
int redLED = 4;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {

  // constantly running code

  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // if button is pressed turn yellow light on
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // do the thing
    for (int x = 0; x < 7; x++) {
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      delay(100);
    }
  }

  // is it time to turn head
  // millis() check for time elapsed
  unsigned long currentTime = millis();

  // if so, turn head
  if (currentTime - previousTime >= interval) {
    // reset last time
    previousTime = currentTime;
    // flash red light
    digitalWrite(redLED, HIGH);
    delay(delayTime * 100);
    digitalWrite(redLED, LOW);

  }

  // delay to prevent data overload
  delay(delayTime);
}
