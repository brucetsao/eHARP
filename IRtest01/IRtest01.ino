#include <LiquidCrystal.h>

int debugmode = 0; 


/* LiquidCrystal display with:

LiquidCrystal(rs, enable, d4, d5, d6, d7) 
LiquidCrystal(rs, rw, enable, d4, d5, d6, d7) 
LiquidCrystal(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7) 
LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7) 
R/W Pin Read = LOW / Write = HIGH   // if No pin connect RW , please leave R/W Pin for Low State

Parameters
*/

LiquidCrystal lcd(8,9,10,38,40,42,44);   //ok
String keyno1;
#define Led1 31
#define Led2 33
#define Led3 35

#define IRLed1 A1
#define IRLed2 A2
#define IRLed3 A3
/*
#define IRLed1 47
#define IRLed2 49
#define IRLed3 51
*/
int line1 = 0 ;
int line2 = 0 ;
int line3 = 0 ;


void setup()
{

    pinMode(Led1,OUTPUT);
    pinMode(Led2,OUTPUT);
    pinMode(Led3,OUTPUT);
/*
    pinMode(IRLed1,INPUT) ;
    pinMode(IRLed2,INPUT) ;
    pinMode(IRLed3,INPUT) ;
 */
    digitalWrite(Led1,LOW);
    digitalWrite(Led2,LOW);
    digitalWrite(Led3,LOW);

    
    Serial2.begin(9600);    // start serial to RFID reader
    Serial.begin(9600);  // start serial to PC 
    Serial.println("IR Led Read");
    lcd.begin(20, 4);
// 設定 LCD 的行列數目 (4 x 20)
   lcd.setCursor(0,0);
  // 列印 "Hello World" 訊息到 LCD 上 
    lcd.print("IR Led Read"); 

}

void loop()
{ 
    delay( 200);         //延時0.5秒
//    line1 = digitalRead(IRLed1) ;
//    line2 = digitalRead(IRLed2) ;
//    line3 = digitalRead(IRLed3) ;
    line1 = analogRead(IRLed1) ;
    line2 = analogRead(IRLed2) ;
    line3 = analogRead(IRLed3) ;
    Serial.print("The light Sensor value is :(");
    Serial.print(line1) ;
    Serial.print("/");
    Serial.print(line2) ;
    Serial.print("/");
    Serial.print(line3) ;
    Serial.print(")\n");
    
    
    
}

