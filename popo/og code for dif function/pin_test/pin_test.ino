int eyedelay = 500

void setup () {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}
void loop() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(12, HIGH);
  delay(1000);
}
