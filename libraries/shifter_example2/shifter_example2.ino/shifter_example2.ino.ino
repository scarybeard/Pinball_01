#include <Shifter.h>

#define SER_Pin 7 //SER_IN
#define RCLK_Pin 6 //L_CLOCK
#define SRCLK_Pin 8 //CLOCK

#define NUM_REGISTERS 2 //how many registers are in the chain

//initaize shifter using the Shifter library
Shifter shifter(SER_Pin, RCLK_Pin, SRCLK_Pin, NUM_REGISTERS); 



  const int redLight = 12;
  const int button0 = A0;
  const int button1 = A1;
    
  boolean lastReadButton0;
  boolean lastReadButton1;
  
  int buttonState = 0;
  int score_1 = 0;




void setup(){

pinMode(redLight, OUTPUT);
pinMode(button0, INPUT);
pinMode(button1, INPUT);
}






void loop(){


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
     shifter.setPin(1, HIGH); 
     shifter.write();
  }


  lastReadButton0 = readButton0;
  
///SCORE a 100 PTS//////////////////////////////////////////////
   boolean readButton1 = digitalRead(button1);
  if (readButton1 == LOW and lastReadButton1 == HIGH)
  {
     shifter.setPin(1, LOW); 
     shifter.write();
  }

  lastReadButton1 = readButton1;
  
}
