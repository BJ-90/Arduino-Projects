void setup()
{
  Serial.begin(9600);
  String a = "21";
  String b = "210";
  int sum;             
 
  int num1 = a.toInt();
  int num2 = b.toInt();
  sum = num1+num2;
  //int b = 10+110;
  Serial.print("Sum of two strings are \t");
  Serial.println(sum);
}
void loop()
{}
