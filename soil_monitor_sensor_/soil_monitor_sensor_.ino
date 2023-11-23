#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int out = 3;
void setup()
{
  pinMode(out,OUTPUT);
  Serial.begin(9600);
  pinMode(A0, INPUT);
  digitalWrite(out, LOW);
  lcd.init();
  lcd.clear();         
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Soil moisture sensor");
  delay(2000);
  //lcd.setCursor(2,1);
  //lcd.print("value = ");
}
void loop()
{
  int mois = analogRead(A0);
  Serial.print(mois);
  Serial.print(" -");
  if(mois >= 1000) {
    Serial.println("Sensor is not in the Soil or DISCONNECTED");
    lcd.clear();         
    //lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("Sensor outof Soil");
  }
  if(mois < 1000 && mois >= 600) { 
    Serial.println("Soil is DRY");
    digitalWrite(out, HIGH);
    lcd.clear(); 
    lcd.setCursor(0,0);
    lcd.print("Soil is dry");
    lcd.setCursor(0,1);
    lcd.print("watering plant");
  }
  if(mois < 600 && mois >= 370) {  
    Serial.println("Soil is HUMID");
    digitalWrite(out, LOW); 
    lcd.clear(); 
    lcd.setCursor(0,0);
    lcd.print("Soil is HUMID");
    lcd.setCursor(0,1);
    lcd.print("no need of water");
  }
  if(mois < 370) {  
    Serial.println("Sensor in WATER");
    lcd.clear(); 
    lcd.setCursor(0,0);
    lcd.print("access water");
    digitalWrite(out, LOW);
  }                                          
  delay(2000);
}