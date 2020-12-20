#include<Servo.h>
Servo myservo;
int servopwmpin = 9;
int sensor1 = A1;
int sensor2 = A2;
int led = 3;
int buzzer = 4;
int pos = 20;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  myservo.attach(servopwmpin);

}

void loop() {
  // put your main code here, to run repeatedly:
  int state1 = analogRead(sensor1);
  int state2 = analogRead(sensor2);
  if (state1 >= 400 && state1>= (state2 + 0.3*state2))
  {
    pos += 2;
    myservo.write(pos);
    delay(15);
    //digitalWrite(led, 1);
    //digitalWrite(buzzer, 0);
  }
  if (state2 >= 400 && state2>= (state1 + 0.3*state1))
  {
    pos -= 2;
    myservo.write(pos);
    delay(15);
    //digitalWrite(led, 0);
    //digitalWrite(buzzer, 1);
  }
  if (pos >= 178)
  {
    pos = 178;
    delay(15);
  }
  if (pos<= 20)
  {
    pos = 20;
    delay(15);
  }
  //if (state1 <=390 && state2 <= 390)
  //{
    //pos == pos;
    //digitalWrite(led, 0);
    //digitalWrite(buzzer, 0);
  //}
  Serial.print("SENSOR1: ");
  Serial.println(pos);
  //Serial.print("\t");
  //Serial.print("SENSOR2: ");
  //Serial.println(state2);
}
