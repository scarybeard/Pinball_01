#include "pitches.h"
#include <LiquidCrystal.h>
#include <Shifter.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define SER_Pin 8 //SER_IN
#define RCLK_Pin 9 //L_CLOCK
#define SRCLK_Pin 10 //CLOCK

#define NUM_REGISTERS 3 //how many registers are in the chain
Shifter shifter(SER_Pin, RCLK_Pin, SRCLK_Pin, NUM_REGISTERS); 

  boolean lastReadButton0;
  boolean lastReadButton1;
  boolean lastReadButton2;
  boolean lastReadButton3;
  boolean lastReadButton4;
  boolean lastReadButton5;


  unsigned int score = 0;
  int ballnumber = 0;
  int a = 100;
  int b = 500;
  int c = 1000;


////NEW GAME////
int newGameMelody[] = 
{
  NOTE_DS3, NOTE_D2, NOTE_D1, NOTE_DS3, NOTE_D2, NOTE_D1, NOTE_G4, NOTE_E4, NOTE_DS4,
};
int noteDurations5[] = 
{
  8, 8, 8, 8, 8, 8, 4, 4, 2, 2, 
};
///////////////////////

////Ball lost melody////
int ballLostMelody[] = 
{
  NOTE_DS3, NOTE_D3, NOTE_B2, NOTE_GS2, NOTE_B1
};
int noteDurations0[] = 
{
  8, 8, 4, 2, 2,
};
///////////////////////

////SCORE A////
int scoreAMelody[] = 
{
 NOTE_E4, NOTE_E5, NOTE_E6,
};
int noteDurations1[] = 
{
 8, 16, 16,
};
///////////////////////

////SCORE B////
int scoreBMelody[] = 
{
 NOTE_E7, NOTE_E6, NOTE_E5, NOTE_E4, NOTE_E5, NOTE_E6,
};
int noteDurations2[] = 
{
 16, 16, 16, 8, 16, 16,
};
///////////////////////

////SCORE C////
int scoreCMelody[] = 
{
 NOTE_E7, NOTE_E6, NOTE_E5,  NOTE_E7, NOTE_E6, NOTE_E5, NOTE_E7, NOTE_E6, NOTE_E5,
};
int noteDurations3[] = 
{
 16, 16, 16, 16, 16, 16, 8, 8, 8,
};
///////////////////////

// SETUP===========================================
void setup() {

//input pins for scoring triggers
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);

// set up the LCD:
  lcd.begin(16, 2);
  lcd.clear();

}

//LOOP==============================================
void loop() {

////LCD DISPLAY: SCORE / GAME OVER////

  if (ballnumber < 1)
  { 
    lcd.setCursor(0, 0);
    lcd.print("GAME OVER         ");
  }
  else
  {
  lcd.setCursor(0, 0);
  lcd.print("SCORE:    BALL:");
  lcd.print(ballnumber);
  }
//LCD: NUMERIC SCORE
 
  lcd.setCursor(0, 1);
  lcd.print(score);


///NEW GAME////////////////////////////////////////////////
   boolean readButton5 = digitalRead(A4);
 
  if (readButton5 == LOW and lastReadButton5 == HIGH)
  {
      score = 0;
      ballnumber = 3;
      lcd.setCursor(0,1);
      lcd.print("               ");

      shifter.setAll(HIGH);
      shifter.write();


////NEW GAME MELODY////=============================
  for (int thisNote = 0; thisNote < 7; thisNote++) {

    int noteDuration5 = 1000 / noteDurations5[thisNote];
    tone(7, newGameMelody[thisNote], noteDuration5);

    int pauseBetweenNotes = noteDuration5 * 1.0;
    delay(pauseBetweenNotes);
 
    noTone(7);

      shifter.setAll(LOW);
      shifter.write();
}////================================================
       
  }
 lastReadButton5 = readButton5;

///LOST BALL//////////////////////////////////////
   boolean readButton0 = digitalRead(A0);
 
  if (readButton0 == LOW and lastReadButton0 == HIGH)
  {
      ballnumber = ballnumber - 1;
      
////BALL LOST MELODY////=============================
  for (int thisNote = 0; thisNote < 7; thisNote++) {

    int noteDuration0 = 1000 / noteDurations0[thisNote];
    tone(7, ballLostMelody[thisNote], noteDuration0);

    int pauseBetweenNotes = noteDuration0 * 1.10;
    delay(pauseBetweenNotes);

    noTone(7);
}////================================================
  
  }
  lastReadButton0 = readButton0;

 
///SCORE a 100 PTS//////////////////////////////////////////////
   boolean readButton2 = digitalRead(A1);
 
  if (readButton2 == LOW and lastReadButton2 == HIGH)
  {
      score = score + a;
     shifter.setPin(8, HIGH); 
     shifter.write();

      ////SCORE A MELODY////=============================
  for (int thisNote = 0; thisNote < 7; thisNote++) {

    int noteDuration1 = 1000 / noteDurations1[thisNote];
    tone(7, scoreAMelody[thisNote], noteDuration1);

    int pauseBetweenNotes = noteDuration1 * 1.0;
    delay(pauseBetweenNotes);

    noTone(7);
}////================================================

  }
  lastReadButton2 = readButton2;

///SCORE B 500 PTS/////////////////////////////////////////////////
   boolean readButton3 = digitalRead(A2);
 
  if (readButton3 == LOW and lastReadButton3 == HIGH)
  {
      score = score + b;

////SCORE B MELODY////=============================
  for (int thisNote = 0; thisNote < 7; thisNote++) {

    int noteDuration2 = 1000 / noteDurations2[thisNote];
    tone(7, scoreBMelody[thisNote], noteDuration2);

    int pauseBetweenNotes = noteDuration2 * 1.0;
    delay(pauseBetweenNotes);

    noTone(7);
}////================================================

  }
  lastReadButton3 = readButton3;

///SCORE C 1000 PTS////////////////////////////////////////////////
   boolean readButton4 = digitalRead(A3);
 
  if (readButton4 == LOW and lastReadButton4 == HIGH)
  {
      score = score + c;


////SCORE C MELODY////=============================
  for (int thisNote = 0; thisNote < 7; thisNote++) {

    int noteDuration3 = 1000 / noteDurations3[thisNote];
    tone(7, scoreCMelody[thisNote], noteDuration3);

    int pauseBetweenNotes = noteDuration3 * 1.0;
    delay(pauseBetweenNotes);
 
    noTone(7);
}////================================================
      
  }
  lastReadButton4 = readButton4;

}
