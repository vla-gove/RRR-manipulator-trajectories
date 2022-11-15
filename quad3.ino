#include <VarSpeedServo.h>  


const int servoCount = 8;           
VarSpeedServo motors[servoCount];  


int speed = 100;     
const int angle1 = 30;    
const int angle0 = 0;   
int tempwalk=1;

void setup() {
  Serial.begin(9600);
  motors[0].attach(5, 900, 2100); 
  motors[1].attach(6, 900, 2100);  
  motors[2].attach(7, 900, 2100); 
  motors[3].attach(8, 900, 2100);  
  motors[4].attach(9, 900, 2100); 
  motors[5].attach(10, 900, 2100); 
  motors[6].attach(11, 900, 2100); 
  motors[7].attach(12, 900, 2100); 

}  

void loop() {
  //loop
} 


void walkForward(){ 
  
  if (tempwalk == 1){ 
  Serial.println("forward");
                          
  int  move1[servoCount] =  {-10,  angle1,  20,   angle1,  35,  angle0,      5,    angle1};        
  int  move2[servoCount] =  { 35,  angle0,    5,    angle1,  20,  angle1,   -10,   angle1};        
  int  move3[servoCount] =  { 20,  angle1, -10,   angle1,  5,   angle1,    35,   angle0};         
  int  move4[servoCount] =  { 5,   angle1,  35,   angle0,   -10,  angle1 ,   20,   angle1};       
  for(int k=0; k<=2; k++){
  for (int i = 0; i <= 4; i ++){  
    switch (i){
      
     case 0:    
      for (int x = 0; x < servoCount; x ++){  
        motors[x].write(move1[x], speed, false);
        break;
      }
     case 1:   
      for (int x = 0; x < servoCount; x ++){
        motors[x].write(move2[x], speed, false);
      }
     case 2:
      for (int x = 0; x < servoCount; x ++){
        motors[x].write(move3[x], speed, false);
      }
     case 3:
     for (int x = 0; x < servoCount; x ++){
        motors[x].write(move4[x], speed, false);
     }
    }
   }
  }
  }
   tempwalk --;   
   
} 
void reverse(){       
  if (tempwalk == 1){
  Serial.println("reverse"); 
  int  move1[servoCount] =  {-10,  angle1,  20,   angle1,  35,  angle0,      5,    angle1};        
  int  move2[servoCount] =  { 35,  angle0,    5,    angle1,  20,  angle1,   -10,   angle1};        
  int  move3[servoCount] =  { 20,  angle1, -10,   angle1,  5,   angle1,    35,   angle0};         
  int  move4[servoCount] =  { 5,   angle1,  35,   angle0,   -10,  angle1 ,   20,   angle1};   

  for(int k=0; k<=2; k++){
  for (int i = 0; i <= 4; i ++){  
    switch (i){
      
     case 0:    
      for (int x = 0; x < servoCount; x ++){  
        motors[x].write(move1[x], speed, false);
        break;
      }
     case 1:   
      for (int x = 0; x < servoCount; x ++){
        motors[x].write(move2[x], speed, false);
      }
     case 2:
      for (int x = 0; x < servoCount; x ++){
        motors[x].write(move3[x], speed, false);
      }
     case 3:
     for (int x = 0; x < servoCount; x ++){
        motors[x].write(move4[x], speed, false);
     }
    }
   }
  }
  } 
   
  tempwalk --;
  
}
void neutral(){
    Serial.println("starting position");
    int neutral[servoCount] = {90,90,90,90,90,90,90,90};
     for (int i = 0; i < servoCount; i ++){
        motors[i].write(neutral[i], speed, false);
    }
}
void sit(){
    Serial.println("sit");
    int sit[servoCount] = {90, angle1, 90, angle1, 90, angle1, 90, angle1};
      for (int i = 0; i < servoCount; i ++){
        motors[i].write(sit[i], speed, false);   
    }
}


