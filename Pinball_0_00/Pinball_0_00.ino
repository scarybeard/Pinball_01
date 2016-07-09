#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

  boolean lastReadButton1;
  boolean lastReadButton2;
  boolean lastReadButton3;
  boolean lastReadButton4;


  unsigned int score = 0;
  int ballnumber = 5;
  int a = 100;
  int b = 500;
  int c = 1000;


// SETUP===========================================
void setup() {

//input pins for scoring triggers
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  

// set up the LCD:
  lcd.begin(16, 2);
  lcd.clear();

}

//LOOP==============================================
void loop() {

//LCD TOP ROW: SCORE / GAME OVER

  lcd.setCursor(0, 0);

  if (ballnumber < 1)
  { 
   
    lcd.print("GAME OVER         ");
  }
  else
  {
  lcd.print("SCORE:    BALL:");
  lcd.print(ballnumber);
  }
//LCD BOTTOM ROW: NUMERIC SCORE
 
  lcd.setCursor(0, 1);
  lcd.print(score);

///LOST BALL//////////////////////////////////////
   boolean readButton1 = digitalRead(A0);
 
  if (readButton1 == LOW and lastReadButton1 == HIGH)
  {
      ballnumber = ballnumber - 1;
  }
  lastReadButton1 = readButton1;

 
///SCORE a 100 PTS///////////////////
   boolean readButton2 = digitalRead(A1);
 
  if (readButton2 == LOW and lastReadButton2 == HIGH)
  {
      score = score + a;
  }
  lastReadButton2 = readButton2;

///SCORE B 500 PTS///////////////////
   boolean readButton3 = digitalRead(A2);
 
  if (readButton3 == LOW and lastReadButton3 == HIGH)
  {
      score = score + b;
  }
  lastReadButton3 = readButton3;

///SCORE C 1000 PTS///////////////////
   boolean readButton4 = digitalRead(A3);
 
  if (readButton4 == LOW and lastReadButton4 == HIGH)
  {
      score = score + c;
  }
  lastReadButton4 = readButton4;

}
