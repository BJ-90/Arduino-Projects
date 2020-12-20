#include <Servo.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char my_keypad[ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
//Arduino pins for Keypad
byte row_pins[ROWS] = {8,7,A5,A4}; //connect to the row pinouts of the keypad
byte col_pins[COLS] = {A3,A2,A1,A0}; //connect to the column pinouts of the keypad
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(my_keypad), row_pins, col_pins, ROWS, COLS);

//For Servo
Servo my_servo;
//Arduino pin for Servo
int servo_pwmpin = 6;
// Variable for Servo
int angle = 20;

// For LCD
int RS = 12, E = 11;
int DB4 = 5, DB5 = 4, DB6 = 3, DB7 = 2;
LiquidCrystal mylcd(RS, E, DB4, DB5, DB6, DB7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Initialize Servo
  my_servo.attach(servo_pwmpin);
  // Initiallize LCD
  mylcd.begin(16, 2);

}

void loop() {
  // put your main code here, to run repeatedly:
  char customKey = customKeypad.getKey();
  if (customKey){
    Serial.println(customKey);
  }
  if (angle < 20)
  {
    angle = 20;
    my_servo.write(angle);
  }
  switch(customKey){
    case '1':
    angle = 20;
    my_servo.write(angle);
    mylcd.setCursor(0, 0);
    mylcd.print("You Pressed: ");
    mylcd.print(customKey);
    mylcd.setCursor(0, 1);
    mylcd.print("SrvoRotate180CW");
    break;
    case '2':
    angle = 180;
    my_servo.write(angle);
    mylcd.setCursor(0, 0);
    mylcd.print("You Pressed: ");
    mylcd.print(customKey);
    mylcd.setCursor(0, 1);
    mylcd.print("SrvoRotate180CCW");
    break;
    
  
  }

}
