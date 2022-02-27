#include <LiquidCrystal.h>;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  const float BETA = 3950;
  float temp = analogRead(A0);
  float celsius = 1 / (log(1 / (1023. / temp - 1)) / BETA + 1.0 / 298.15) - 273.15;
  float farenheit = celsius*9/5+32;
  lcd.setCursor(0,0);
  lcd.print("TEMP = ");
  lcd.print(celsius);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("TEMP = ");
  lcd.print(farenheit);
  lcd.print((char)223);
  lcd.print("F");
  delay(1500);
  lcd.clear();
}
