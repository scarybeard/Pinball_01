#include <Shifter.h>

#define SER_Pin 9 //SER_IN
#define RCLK_Pin 10 //L_CLOCK
#define SRCLK_Pin 7 //CLOCK

#define NUM_REGISTERS 3 //how many registers are in the chain

//initaize shifter using the Shifter library
Shifter shifter(SER_Pin, RCLK_Pin, SRCLK_Pin, NUM_REGISTERS); 


  boolean lastReadButton0;
  boolean lastReadButton1;
  boolean lastReadButton2;
  boolean lastReadButton3;
  boolean lastReadButton4;
  boolean lastReadButton5;


void setup(){

//input pins for scoring triggers
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);


 shifter.setPin(0, LOW);
 shifter.setPin(1, LOW); 
 shifter.setPin(2, LOW);
 shifter.setPin(3, LOW);
 shifter.setPin(4, LOW);
 shifter.setPin(5, LOW);
 shifter.setPin(6, LOW);
 shifter.setPin(7, LOW);
 shifter.setPin(8, LOW);
 shifter.setPin(9, LOW);
 shifter.setPin(10, LOW);
 shifter.setPin(11, LOW);
 shifter.setPin(12, LOW);
 shifter.setPin(13, LOW);
 shifter.setPin(14, LOW);
 shifter.setPin(15, LOW);//LAST GREEN
 shifter.setPin(16, HIGH);////AMBIENT WHITE
 shifter.setPin(17, LOW);////BLUE
 shifter.setPin(18, LOW);////GREEN
 shifter.setPin(19, LOW);////RED
 shifter.setPin(20, LOW);
 shifter.setPin(21, LOW);
 shifter.setPin(22, LOW);
 shifter.setPin(23, LOW);
 shifter.setPin(24, LOW);


 shifter.write();

}

void loop(){

////shifter RGB////
  shifter.setPin(17, HIGH);///Blue
  shifter.setPin(18, HIGH);///GREEN
  shifter.setPin(19, HIGH);///RED
  shifter.write();


///SCORE a 100 PTS//////////////////////////////////////////////
   boolean readButton2 = digitalRead(A1);
 
  if (readButton2 == LOW and lastReadButton2 == HIGH)
{

}
  lastReadButton2 = readButton2;

  
///SCORE a 500 PTS//////////////////////////////////////////////
   boolean readButton3 = digitalRead(A2);
 
  if (readButton3 == LOW and lastReadButton3 == HIGH)
{
  
}
  lastReadButton3 = readButton3;
 
}
