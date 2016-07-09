#include <Shifter.h>

#define SER_Pin 4 //SER_IN
#define RCLK_Pin 3 //L_CLOCK
#define SRCLK_Pin 2 //CLOCK

#define NUM_REGISTERS 1 //how many registers are in the chain

//initaize shifter using the Shifter library
Shifter shifter(SER_Pin, RCLK_Pin, SRCLK_Pin, NUM_REGISTERS); 



  const int redLight = 12;
  const int button0 = A0;
  
  boolean lastReadButton0;
  
  int buttonState = 0;
  int score_1 = 0;




void setup(){

pinMode(redLight, OUTPUT);
pinMode(button0, INPUT);

}






void loop(){
  
  shifter.setPin(1, HIGH); 
  shifter.setPin(2, HIGH); 
  shifter.setPin(3, HIGH);
  shifter.setPin(4, HIGH); 
  shifter.setPin(5, HIGH);
  shifter.setPin(6, HIGH); 
  shifter.setPin(7, HIGH);
  
  shifter.write();

///SCORE a 100 PTS//////////////////////////////////////////////
   boolean readButton0 = digitalRead(button0);
 
  if (readButton0 == LOW and lastReadButton0 == HIGH)
  {
      digitalWrite (redLight, HIGH);
      shifter.setPin(1, LOW);
      shifter.write();
  }
  else
  {
    digitalWrite (redLight, LOW);
    shifter.setPin(1, HIGH);
    shifter.write();
  }
  lastReadButton0 = readButton0;
  
}
