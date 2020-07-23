#include <LiquidCrystal.h>
#define TRIG_PIN 8
#define ECHO_PIN 9
#define TRIG_PIN1 10
#define ECHO_PIN1 11
#define detDist 10
#define LED_RED 33 
#define LED_BLUE 32
#define LED_YELL 12
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
void setup()
{
  pinMode(LED_RED,  INPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_YELL, OUTPUT);
  
  pinMode(TRIG_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN1, OUTPUT); 
  pinMode(ECHO_PIN1, INPUT);
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(19200);
}

double previousMillis = 0;

bool isStart = false;
bool isFirst = true;

double i1 = 0;
double i2 = 0;

double sec = 0;

double a = millis();
void loop()
{
  int distance = 0;
   int distance1 = 0;
   digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(0); 
  digitalWrite(TRIG_PIN, LOW); 
  distance = pulseIn(ECHO_PIN, HIGH)/58.2;
  digitalWrite(TRIG_PIN1, HIGH);
  delayMicroseconds(0); 
  digitalWrite(TRIG_PIN1, LOW); 
  distance1 = pulseIn(ECHO_PIN1, HIGH)/58.2; 
  if(isFirst){
printFirst(lcd);
   digitalWrite(LED_BLUE, HIGH);
  }
  if (distance <= detDist) { 
    isStart = true;
    lcd.clear();
  
   printSec(lcd);

previousMillis = millis();
   
  

    }
   if(isStart)
   {
printSec(lcd);
Serial.println("\n");
   Serial.println(sec);
   Serial.println("Sec's");
   Serial.println("........");
   Serial.println(50 / sec);
   Serial.println("m/s");
   Serial.println("\n--------");
   digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_BLUE, LOW);
    }
    if(distance1 <= detDist)
   {
    if(isStart)
    {
      printVel(lcd);
      
    }
    
    isStart=false;
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_YELL, HIGH);
    delay(2000);
    digitalWrite(LED_YELL, LOW);
    printFirst(lcd);
    isFirst = true;
    
   }
  }
  
  void printSec(LiquidCrystal lcd){ 
   sec = (millis() - previousMillis) / (double)1000;
   lcd.setCursor(0,0);
  lcd.print(sec);
   lcd.setCursor(11,0);
   lcd.print("Sec's");
  }
  
  void printFirst(LiquidCrystal lcd){
    lcd.clear();
lcd.print("Just run.");
delay(0);
isFirst = false;
  }
  
  void printVel(LiquidCrystal lcd){
    double vel = 50 / sec;
    lcd.setCursor(0,1); 
    lcd.print(vel);
       lcd.setCursor(12,1);
       lcd.print("m/s");
  }
  

