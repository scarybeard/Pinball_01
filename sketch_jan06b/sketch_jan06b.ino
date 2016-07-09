
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int score_A = A1;    // the number of the pushbutton pin       
const int lostball = A0;      // the number of the lostball pin
  
int score_AState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers


  long int score = 0;
  byte ballnumber = 5;
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

  int reading = analogRead(score_A);
  
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {

    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        score = score + A;
      }
    }
  }

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
  


}
