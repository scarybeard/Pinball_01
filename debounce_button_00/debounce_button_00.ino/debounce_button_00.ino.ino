
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

bool button_0State  = HIGH;      // the current STABLE STATE of the input pin
bool lastButton_0State = LOW;   // the previous reading from the input pin
long lastDebounce_0Time = 0;    // the last time the output pin was toggled

long debounceDelay = 30;    // the debounce time; increase if the output flickers

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

///LOST BALL///BLACK///////////////////////////////////
  bool reading = digitalRead(A0);

  if (reading != lastButton_0State) {
    lastDebounce_0Time = millis(); // reset the time since last stable state
    lastButton_0State = reading;   
  }
 
  if ((millis() - lastDebounce_0Time) > debounceDelay) {
    // test for a transition from low-high or high-low
    if (button_0State != lastButton_0State) {
      button_0State = lastButton_0State;

      if (button_0State == HIGH) {
         ballnumber = ballnumber - 1;
      }
    }
  }
}
