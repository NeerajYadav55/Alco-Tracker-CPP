#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

 int MQ3= A0;
 int Relay=6;
int value;

void setup() {
  
  pinMode(MQ3, INPUT);
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay,LOW);
  
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(" Alcohol ");
  lcd.setCursor(0, 1);
  lcd.print(" Detection ");
  delay(3000);
  lcd.clear();

}

void loop()
{
  value= analogRead(MQ3);
  Serial.println(value);
    lcd.setCursor(0, 0);
  lcd.print("Alcohol :");
  lcd.print(value);
  
  if(value>350)
  {
    digitalWrite(Relay,HIGH);
  }else{
    digitalWrite(Relay,LOW);
  }

  delay (500);
}
