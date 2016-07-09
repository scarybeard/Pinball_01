

// 3 TARGET SCRORE FUNCTION. WHEN A TARGET IS HIT IT LIGHTS UP AND PROVIDES POINTS.
// WHEN ALL 3 TARGETS ARE LIT THEY FLASH AND PROVIDE A JACKPOT
// WHEN JACKPOT IS PROVIDED ALL LIGHTS TURN OFF. 
  


int LED_D1 = 11;
int LED_D2 = 12;
int LED_D3 = 13;
int SWITCH_D1 = 1;
int SWITCH_D2 = 2;
int SWITCH_D3 = 3;

int state0 = LOW;
int state1 = HIGH;
int reading;


void setup() {
  // put your setup code here, to run once:



pinMode(LED_D1,OUTPUT);
pinMode(LED_D2,OUTPUT);
pinMode(LED_D3,OUTPUT);
pinMode(SWITCH_D1,INPUT);
pinMode(SWITCH_D2,INPUT);
pinMode(SWITCH_D3,INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

//drop target switch 1  

     if (digitalRead(SWITCH_D1) == HIGH)
       {
         digitalWrite(LED_D1,HIGH);
       }
     else 
     {
      digitalWrite (LED_D1,LOW);
     }
    

//drop target switch 2
    
     if (digitalRead(SWITCH_D2) == HIGH)
       {
         digitalWrite(LED_D2,HIGH);
       }
     else 
     {
      digitalWrite (LED_D2,LOW);
     }

//drop target switch 3
    
     if (digitalRead(SWITCH_D3) == HIGH)
       {
         digitalWrite(LED_D3,HIGH);
       }
     else 
     {
      digitalWrite (LED_D3,LOW);
     }

//drop target RESET
    
      if ((LED_D1) == HIGH && (LED_D2) == HIGH && (LED_D3) == HIGH)
      {
        digitalWrite (LED_D1, LOW);
        digitalWrite (LED_D2, LOW);
        digitalWrite (LED_D3, LOW);
      }
    }
  








