#include <Servo.h>
Servo servo1;
Servo servo2;
int x_key = A1;
int y_key = A0;
int x_pos;
int y_pos;
int servo1_pin = 8;
int servo2_pin = 9;
int initial_position = 90;
int initial_position1 = 90;

int pinButton = 2; //the pin where we connect the button
int LED = 8; //the pin we connect the LED

void setup ( ) {
  Serial.begin (9600) ;
  servo1.attach (servo1_pin ) ;
  servo2.attach (servo2_pin ) ;
  servo1.write (initial_position);
  servo2.write (initial_position1);
  pinMode (x_key, INPUT) ;
  pinMode (y_key, INPUT) ;

  pinMode(pinButton, INPUT); //set the button pin as INPUT
  pinMode(LED, OUTPUT); //set the LED pin as OUTPU
  delay (10);
}

void loop ( ) {
  x_pos = analogRead (x_key) ;
  y_pos = analogRead (y_key) ;


  int stateButton = digitalRead(pinButton); //read the state of the button
  if (stateButton == 1) { //if is pressed
    servo1.write (initial_position);
    servo2.write (initial_position1); //write 1 or HIGH to led pin
    delay (10);
  } else {
  }


//THIS HIT DONT WORK




  if ((x_pos <= 400) and (x_pos >= 4)) {
    if (initial_position < 10){}
      else {
        initial_position = initial_position - 1;
        servo1.write ( initial_position ) ;
        delay (10) ;
    }
  }


  if ((x_pos <= 3)and (x_pos >= 0)) {
    if (initial_position < 10){}
      else {
        initial_position = initial_position - 20;
        servo1.write ( initial_position ) ;
        delay (30) ;
    }
  } 

//BELOW WORKS 
  
  
  
  if ((x_pos >= 1020) and (x_pos <= 1023)) {
    if (initial_position > 180){}
      else {
        initial_position = initial_position + 20;
        servo1.write ( initial_position ) ;
        delay (30) ;
    }
  }
  
if ((x_pos >= 522) and (x_pos <= 1019)) {
    if (initial_position > 180){}
      else {
        initial_position = initial_position + 1;
        servo1.write ( initial_position ) ;
        delay (10) ;
    }
  }
}

//  if ((y_pos >= 10) && (y_pos <= 250))
