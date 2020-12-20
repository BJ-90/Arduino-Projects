#include <Servo.h>
#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char my_keypad[ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte row_pins[ROWS] = {10,9,8,7}; //connect to the row pinouts of the keypad
byte col_pins[COLS] = {6,5,4,3}; //connect to the column pinouts of the keypad
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(my_keypad), row_pins, col_pins, ROWS, COLS);

Servo my_servo;
int servo_pwmpin = 12;
int angle = 20;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  my_servo.attach(servo_pwmpin);

}

void loop() {
  // put your main code here, to run repeatedly:
  char customKey = customKeypad.getKey();
  if (customKey){
    Serial.println(customKey);
  }
  if (angle <= 20)
  {
    angle = 20;
    my_servo.write(angle);
  }
  switch(customKey){
    case '1':
    my_servo.write(angle);
    break;
    case '2':
    my_servo.write(angle+100);
    break;
    default:
    my_servo.write(20);
    break;
  
  }

}
