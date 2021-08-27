



#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int rlypin2 = D2;
int rlypin3 = D3;
int rlypin4 = D4;
int sensorPin = A1;
int sensorValue = 0;
int percentValue = 0;
void setup()
{
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  delay(100);

}


void loop() {

  sensorValue = analogRead(sensorPin);
  Serial.print("\n\nAnalog Value: ");
  Serial.print(sensorValue);

  percentValue = map(sensorValue, 1023, 200, 0, 100);
  Serial.print("\nPercentValue: ");
  Serial.print(percentValue);
  Serial.print("%");
  lcd.setCursor(0, 0);
  lcd.print("Moisture");

  lcd.setCursor(0, 1);
  lcd.print("Percent: ");
  lcd.print(percentValue);
  lcd.print("%");
  delay(1000);
  lcd.clear();
}
