/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 28 May 2015
  by Michael C. Miller
  modified 8 Nov 2013
  by Scott Fitzgerald

  http://arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo servo;  // create servo object to control a servo
// twelve servo objects can be created on most boards


void setup() {
  servo.attach(2);  //pin D5 attaches the servo on GIO2 to the servo object
  servo.write(45);
  delay(500);
}

void loop() {

//    servo.write(180);              // tell servo to go to position in variable 'pos'
//    delay(500);
//    servo.write(0);
//    delay(500);
}
