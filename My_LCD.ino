#include <LiquidCrystal.h>
int RS = 12, E = 11;
int DB4 = 5, DB5 = 4, DB6 = 3, DB7 = 2;
LiquidCrystal mylcd(RS, E, DB4, DB5, DB6, DB7);

void setup() {
mylcd.begin(16, 2);
}

void loop() {
mylcd.setCursor(0, 1);
mylcd.print("Hello world!");
}
