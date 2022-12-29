#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const int full=4;
const int threebyfour=5;
const int half=6;
const int onebyfour=7;
const int buzzer = 3;
const int dos = 0;
int LeftMotorForward = 2;
int LeftMotorReverse = 1;
int green = 14;
int red = 15;
int yellow = 16;
int f, q, h, l, d;
int flag = 0;
void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.clear();
  pinMode(full,INPUT);
  pinMode(threebyfour,INPUT);
  pinMode(half,INPUT);
  pinMode(onebyfour,INPUT);
  pinMode(dos, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);  
  pinMode(LeftMotorReverse, OUTPUT);  
  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
}

void loop()
{
  f=digitalRead(full);
  q=digitalRead(threebyfour);
  h=digitalRead(half);
  l=digitalRead(onebyfour);
  d=digitalRead(dos);
  
  lcd.clear();

  if(f == 0 && q == 0 && h == 0 && l == 0){
    if(d == 1){
      lcd.setCursor(0, 0);
      lcd.print("TANK IS EMPTY");
      lcd.setCursor(0, 1);
      lcd.print("PUMP ON");
      digitalWrite(LeftMotorForward, HIGH);
      digitalWrite(LeftMotorReverse, LOW);  
      digitalWrite(yellow,HIGH);
      digitalWrite(green,HIGH);
      digitalWrite(red,LOW);
      tone(buzzer,1000);
      delay(10);
    }

    else{
      lcd.setCursor(0, 0);
      lcd.print("UNSAFE WATER");
      digitalWrite(LeftMotorForward, LOW);
      digitalWrite(LeftMotorReverse, LOW);
      digitalWrite(green,LOW);
      digitalWrite(yellow,LOW);
      digitalWrite(red,HIGH);
      tone(buzzer,1000);
      delay(10);
    }
  }

  else if(f == 0 && q == 0 && h == 0 && l == 1){
    flag = 1;
    if( d == 1){
      lcd.setCursor(0, 0);
      lcd.print("TANK IS 15% FULL");
      lcd.setCursor(0, 1);
      lcd.print("PUMP ON");
      digitalWrite(LeftMotorForward, HIGH);
      digitalWrite(LeftMotorReverse, LOW); 
      tone(buzzer,1000);
      digitalWrite(yellow,HIGH); 
      digitalWrite(green,HIGH);
      digitalWrite(red,LOW);
      delay(10);
    }

    else{
      lcd.setCursor(0, 0);
      lcd.print("UNSAFE WATER");
      digitalWrite(LeftMotorForward, LOW);
      digitalWrite(LeftMotorReverse, LOW);
      digitalWrite(yellow,LOW);
      digitalWrite(green,LOW);
      digitalWrite(red,HIGH);
      tone(buzzer,1000);
      delay(10);
    }
    
  }

  else if(f == 0 && q == 0 && h == 1 && l == 1){
    if(d == 1){
      lcd.setCursor(0, 0);
      lcd.print("TANK IS 50% FULL");
      lcd.setCursor(0, 1);
      if(flag == 1){
        lcd.print("PUMP RUNNING");
        digitalWrite(LeftMotorForward, HIGH);
        digitalWrite(LeftMotorReverse, LOW);  
        digitalWrite(yellow,HIGH);
      }
      if(flag == 0){
        lcd.print("PUMP OFF");
        digitalWrite(yellow,LOW);
      }
      digitalWrite(green,HIGH);
      digitalWrite(red,LOW);
      noTone(buzzer);
      delay(10);
    }
    else{
      lcd.setCursor(0, 0);
      lcd.print("UNSAFE WATER");
      digitalWrite(LeftMotorForward, LOW);
      digitalWrite(LeftMotorReverse, LOW);
      digitalWrite(yellow,LOW);
      digitalWrite(green,LOW);
      digitalWrite(red,HIGH);
      tone(buzzer,1000);
      delay(10);
    }
  }

  else if(f == 0 && q == 1 && h == 1 && l == 1){
    if(d == 1){
      lcd.setCursor(0, 0);
      lcd.print("TANK IS 75% FULL");
      lcd.setCursor(0, 1);

      if(flag == 1){
        lcd.print("PUMP RUNNING");
        digitalWrite(LeftMotorForward, HIGH);
        digitalWrite(LeftMotorReverse, LOW);  
        digitalWrite(yellow,HIGH);
      }

      if(flag == 0){
        lcd.print("PUMP OFF");
        digitalWrite(yellow,LOW);
      }
      digitalWrite(green,HIGH);
      digitalWrite(red,LOW);
      noTone(buzzer);
      delay(10);
    }
    else{
      lcd.setCursor(0, 0);
      lcd.print("UNSAFE WATER");
      digitalWrite(LeftMotorForward, LOW);
      digitalWrite(LeftMotorReverse, LOW);
      digitalWrite(yellow,LOW);
      digitalWrite(green,LOW);
      digitalWrite(red,HIGH);
      tone(buzzer,1000);
      delay(10);
    }
  }
  
  else if(f == 1 && q == 1 && h == 1 && l == 1){ 
    flag = 0;
    if(d == 1){
      lcd.setCursor(0, 0);
      lcd.print("TANK IS FULL");
      lcd.setCursor(0, 1);
      lcd.print("PUMP OFF");
      digitalWrite(LeftMotorForward, LOW);
      digitalWrite(LeftMotorReverse, LOW);  
      digitalWrite(yellow,LOW);
      digitalWrite(green,HIGH);
      digitalWrite(red,LOW);
      noTone(buzzer);
      delay(10);
    }
    else{
      lcd.setCursor(0, 0);
      lcd.print("UNSAFE WATER");
      digitalWrite(LeftMotorForward, LOW);
      digitalWrite(LeftMotorReverse, LOW);
      digitalWrite(yellow,LOW);
      digitalWrite(green,LOW);
      digitalWrite(red,HIGH);
      tone(buzzer,1000);
      delay(10);
    }
  }
  
}
