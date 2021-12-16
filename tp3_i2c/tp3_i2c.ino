
#include <LCD_I2C.h>

LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according
#define PASVOLT (float)(5.0F/1024.0F)
void changeType();

void setup()
{
    lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
                 // this stop the library(LCD_I2C) from calling Wire.begin()
    lcd.backlight();


    pinMode (2, INPUT);
  
    attachInterrupt(INT0, changeType, CHANGE);
}

volatile bool isVoltOrOhm=false;
void loop()
{
  // put your main code here, to run repeatedly:
  
  if (isVoltOrOhm) showVoltage();
  else showRes();

delay (1000);

}

void changeType() {
  isVoltOrOhm =!isVoltOrOhm;
}
void showVoltage(){
  // put your main code here, to run repeatedly:
  unsigned int palier=analogRead (A0);
  
  Serial.print ("Voici la valeur de tension :\t");
Serial.print (palier);
lcd.setCursor(8,1);
Serial.print ("     ");
float pasSortie=1;//33.5F/5.0F;
  Serial.println (palier *pasSortie*PASVOLT);

  lcd.setCursor(8,1);
  lcd.print(palier *pasSortie*PASVOLT);
  lcd.print ("V");

}

#define R1 1000.0F
void showRes() {
  unsigned int palier = analogRead(A1);
  float tensionEnA1 = palier * PASVOLT;
  float r2=R1*(5.0F/tensionEnA1) -R1;
  lcd.setCursor (8,1);
  lcd.print ("        ");
  lcd.setCursor(8,1);
  lcd.print(r2);
  lcd.print ("R");
}
