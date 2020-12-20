#include<Servo.h>
Servo myservo;
int servopwmpin = 3;
void setup() {
  // put your setup code here, to run once:
myservo.attach(servopwmpin);
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.write(20);
  delay(1000);
  myservo.write(100);
  delay(1000);

}
