    // color swirl! connect an RGB LED to the PWM pins as indicated
    // in the #defines
    // public domain, enjoy!
     
    #define REDPIN 5
    #define GREENPIN 6
    #define BLUEPIN 3

    #define REDPIN2 9
    #define GREENPIN2 10
    #define BLUEPIN2 11
     
    #define FADESPEED 1     // make this higher to slow down
     
    void setup() {
      pinMode(REDPIN, OUTPUT);
      pinMode(GREENPIN, OUTPUT);
      pinMode(BLUEPIN, OUTPUT);
    }
     
     
    void loop() {
      int r, g, b, r2, g2, b2;
     
      // fade from blue to violet
      for (r = 0; r < 256; r++) { 
        analogWrite(REDPIN, r);
        delay(FADESPEED);
      } 
      // fade from violet to red
      for (b = 255; b > 0; b--) { 
        analogWrite(BLUEPIN, b);
        delay(FADESPEED);
      } 
      // fade from red to yellow
      for (g = 0; g < 256; g++) { 
        analogWrite(GREENPIN, g);
        delay(FADESPEED);
      } 
      // fade from yellow to green
      for (r = 255; r > 0; r--) { 
        analogWrite(REDPIN, r);
        delay(FADESPEED);
      } 
      // fade from green to teal
      for (b = 0; b < 256; b++) { 
        analogWrite(BLUEPIN, b);
        delay(FADESPEED);
      } 
      // fade from teal to blue
      for (g = 255; g > 0; g--) { 
        analogWrite(GREENPIN, g);
        delay(FADESPEED);

        //second RBG//

        // fade from blue to violet
      for (r2 = 0; r2 < 256; r2++) { 
        analogWrite(REDPIN2, r2);
        delay(FADESPEED);
      } 
      // fade from violet to red
      for (b2 = 255; b2 > 0; b2--) { 
        analogWrite(BLUEPIN2, b2);
        delay(FADESPEED);
      } 
      // fade from red to yellow
      for (g2 = 0; g2 < 256; g2++) { 
        analogWrite(GREENPIN2, g2);
        delay(FADESPEED);
      } 
      // fade from yellow to green
      for (r2 = 255; r2 > 0; r2--) { 
        analogWrite(REDPIN2, r2);
        delay(FADESPEED);
      } 
      // fade from green to teal
      for (b2 = 0; b2 < 256; b2++) { 
        analogWrite(BLUEPIN, b2);
        delay(FADESPEED);
      } 
      // fade from teal to blue
      for (g2 = 255; g2 > 0; g2--) { 
        analogWrite(GREENPIN2, g2);
        delay(FADESPEED);
      } 
      }
    }
