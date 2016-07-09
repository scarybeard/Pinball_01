
#include "pitches.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

  boolean lastReadButton0;
  boolean lastReadButton1;
  int ballnumber = 5;
  int a = 100;
  unsigned int score = 0;

////Ball lost melody////
int ballLostMelody[] = 
{
  NOTE_DS3, NOTE_D3, NOTE_B2, NOTE_GS2, NOTE_B1
};
int noteDurations0[] = 
{
  8, 8, 4, 2, 2,
};

////SCORE A MELODY////
int scoreAMelody[] = 
{
  NOTE_DS3, NOTE_D3, NOTE_B2, NOTE_GS2
};
int noteDurationsA[] = 
{
  8, 8, 4, 2, 1,
};

///////////////////////////////SETUP////////////////////////////////////
void setup() {

//input pins for scoring triggers
  pinMode(A0, INPUT);
  
// set up the LCD:
  lcd.begin(16, 2);
  lcd.clear();

}
////////////////////////////////LOOP////////////////////////////////////
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



////LOST BALL////
   boolean readButton0 = digitalRead(A0);
 
  if (readButton0 == LOW and lastReadButton0 == HIGH)
  {
      ballnumber = ballnumber - 1;
////BALL LOST MELODY////
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    int noteDuration0 = 1000 / noteDurations0[thisNote];
    tone(8, ballLostMelody[thisNote], noteDuration0);

    int pauseBetweenNotes = noteDuration0 * 1.10;
    delay(pauseBetweenNotes);

    noTone(8);
      }
    }
  lastReadButton0 = readButton0;

  
 
///SCORE a 100 PTS///////////////////
   boolean readButton1 = digitalRead(A1);
 
  if (readButton1 == HIGH and lastReadButton1 == LOW)
  {
      score = score + a;
        lastReadButton1 = readButton1;
  }

}
