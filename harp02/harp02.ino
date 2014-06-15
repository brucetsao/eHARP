#include <LiquidCrystal.h>

#define lightonpin 4
int debugmode = 0; 
int Wt588pin=6;

#define tonepin 3

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

int IRLedTreshhold1 = 500 ;
int IRLedTreshhold2 = 500 ;
int IRLedTreshhold3 = 500 ;
 
   
void setup()
{
    Serial.begin(9600);
    Serial.println("Program Start Here");
    pinMode(lightonpin,OUTPUT);
    pinMode(Led1,OUTPUT);
    pinMode(Led2,OUTPUT);
    pinMode(Led3,OUTPUT);
    
   pinMode(Wt588pin, OUTPUT);
   
/*
    pinMode(IRLed1,INPUT) ;
    pinMode(IRLed2,INPUT) ;
    pinMode(IRLed3,INPUT) ;
 */
    digitalWrite(Led1,LOW);
    digitalWrite(Led2,LOW);
    digitalWrite(Led3,LOW);
    digitalWrite(lightonpin,HIGH);
    
    Serial2.begin(9600);    // start serial to RFID reader
    Serial.begin(9600);  // start serial to PC 
    Serial.println("IR Led Read");
    lcd.begin(20, 4);
// 設定 LCD 的行列數目 (4 x 20)
   lcd.setCursor(0,0);
  // 列印 "Hello World" 訊息到 LCD 上 
    lcd.print("IR Led Read"); 
           PlayVoice(0,Wt588pin);
}

void loop()
{ 
 
   
}



boolean ChkString1()
{
    int tmp ;
      tmp = analogRead(IRLed1) ;    
        Serial.print("The Sensor 1 :(");
        Serial.print(tmp);
        Serial.print(")\n");
      if (tmp <= IRLedTreshhold1)
          {
              return true ;
          }
          else
          {
              return false ;
          }
  
}

boolean ChkString2()
{
    int tmp ;
      tmp = analogRead(IRLed2) ;    
       Serial.print("The Sensor 2 :(");
        Serial.print(tmp);
        Serial.print(")\n");
      if (tmp <= IRLedTreshhold2)
          {
              return true ;
          }
          else
          {
              return false ;
          }
  
}

boolean ChkString3()
{
    int tmp ;
      tmp = analogRead(IRLed3) ;   
      Serial.print("The Sensor 2 :(");
        Serial.print(tmp);
        Serial.print(")\n"); 
      if (tmp <= IRLedTreshhold3)
          {
              return true ;
          }
          else
          {
              return false ;
          }
  
}

long randommusic()
{
  randomSeed(analogRead(IRLed1)); // 使用類比輸入當作亂數種子
    return random(0,5)  ; 
  
}

void PlayVoice(unsigned char addr,unsigned int addrpin)
{
digitalWrite(addrpin,0);
delay(5);
for(int i=0;i<8;i++)
{
digitalWrite(addrpin,1);
if(addrpin & 1)
{
delayMicroseconds(600);
digitalWrite(addrpin,0);
delayMicroseconds(300);
}
else
{
delayMicroseconds(300);
digitalWrite(addrpin,0);
delayMicroseconds(600);
}
addr>>=1;  //此行用>>=还是=>>还不确定
}
digitalWrite(addrpin,1);
}

