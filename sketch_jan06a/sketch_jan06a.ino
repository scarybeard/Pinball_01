
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Tutorial code/////////////////////////////////////////////
// constants won't change. They're used here to

const int score_A = A1;    // the number of the pushbutton pin       
const int lostball = A0;      // the number of the LED pin
  
// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

////////////////////////////end of tutorial code^//////////////////


  boolean lastReadButton1;
  boolean lastReadButton2;
  boolean lastReadButton3;


  long int score = 0;
  byte ballnumber = 0;
  int A = 100;
  int B = 500;
  int C = 1000;


// SETUP===========================================
void setup() {

//input pins for scoring triggers
  pinMode(score_A, INPUT);
  pinMode(lostball, INPUT);

// set up the LCD:
  lcd.begin(16, 2);
  lcd.clear();

}

//LOOP==============================================
void loop() {


//////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////TUTORIAL CODE////////////////////////////////////
// read the state of the switch into a local variable:
  int reading = digitalRead(score_A);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  // set the LED:
  digitalWrite(ledPin, ledState);

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
}
/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////END TUTORIAL CODE////////////////////////////////////


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
  
////////////////////////////////////////////////////////////////////
//LOST BALL/////////////////////////////////////////////////////////
   boolean readButton2 = digitalRead(lostball);
  
  if (readButton2 == LOW and lastReadButton2 == HIGH)
  { 
      ballnumber = ballnumber - 1;
  }
  lastReadButton2 = readButton2;

//////////////////////////////////////////////////////////////////////
//SCORE_A ///////////// 100 PTS //////////////////////////////////////
   boolean readButton1 = digitalRead(score_A);
  
  if (readButton1 == LOW and lastReadButton1 == HIGH)
  { 
      score = score + A;
  }
  lastReadButton1 = readButton1;




}
