#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int Glow_stone;

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x03F, 16, 2);

void setup()
{
  pinMode(13,OUTPUT);
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  
}

void loop()
{
  lcd.clear();
  Glow_stone = analogRead(A0);
 lcd.print("svet="); // Do nothing here...
  lcd.print(1023-Glow_stone);
  lcd.setCursor(0,1);
  if(Glow_stone>900){
    lcd.print("tobi p*@#%"); 
  }
 delay(100);
 
 if(Glow_stone>500){
  digitalWrite(13,HIGH);
  
 }else {
  digitalWrite(13,LOW);
 }
 
}
