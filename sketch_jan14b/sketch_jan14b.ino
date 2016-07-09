#include <Shifter.h>

#define SER_Pin 7 //SER_IN
#define RCLK_Pin 6 //L_CLOCK
#define SRCLK_Pin 8 //CLOCK

#define NUM_REGISTERS 2 //how many registers are in the chain
Shifter shifter(SER_Pin, RCLK_Pin, SRCLK_Pin, NUM_REGISTERS); 

#define SER_Pin A0 //SER_IN
#define RCLK_Pin A1 //L_CLOCK
#define SRCLK_Pin A2 //CLOCK

#define NUM_REGISTERS 1
Shifter shifter(SER_Pin, RCLK_Pin, SRCLK_Pin, NUM_REGISTERS); 

  boolean lastReadButton0;
  boolean lastReadButton1;
  boolean lastReadButton2;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
