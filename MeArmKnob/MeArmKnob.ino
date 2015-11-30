/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo rightArm; //  11  -- 50 a 180 -- para frente e para tras     -->> valores altos para frente
Servo leftArm;  //  10  -- 30 a 120 -- Sobe e desce a garra        -->> valores altos sobe
Servo base;     //  9   -- 10 a 170 -- Gira a base (centro ~84)
Servo cloak;    //  6   -- 0 a 40   -- Abre a garra


void setup()
{
  rightArm.attach(11);  // attaches the servo on pin 9 to the servo object
  leftArm.attach(10);
  base.attach(9);
  cloak.attach(6);
  moveSlow(rightArm, 93, 10);//rightArm.write(93);
  moveSlow(leftArm, 90, 10); //leftArm.write(90);
  moveSlow(base, 84, 10);//base.write(90);
  cloak.write(25);  
  delay(1000);  
  Serial.begin(9600);
}



void loop()
{
  base.write(60);
  cloak.write(0);
  moveSlow(leftArm, 30, 10);
  moveSlow(rightArm, 130, 10);
  delay(5000);
  cloak.write(30);  
  
  while(1){
    porEmcima();  
    porEmbaixo();
  }
   
  while(1){delay(100);}
  
}

void porEmbaixo(){
  
  moveSlow(base,84,20);    
  moveSlow(leftArm, 30, 20);
  moveSlow(rightArm, 130, 20);
  
  cloak.write(0);      

  moveSlow(rightArm, 90, 10);
  moveSlow(leftArm, 50, 10);
  
  cloak.write(30);
  
  delay(500);
  
  cloak.write(0);  
  moveSlow(leftArm, 30, 20);
  moveSlow(rightArm, 130, 20);  
  cloak.write(30);
}

void porEmcima(){
  //Sobe
  moveSlow(rightArm, 90, 30);
  moveSlow(leftArm, 120, 20);
  
  //gira
  moveSlow(base,120,20);
  
  //Desce e poe
  moveSlow(rightArm, 100, 30);
  moveSlow(leftArm, 100, 20);
  cloak.write(0);  
  moveSlow(leftArm, 120, 20);
  delay(1000);
  moveSlow(leftArm, 100, 20);
  cloak.write(30);
  
  //levanta
  moveSlow(leftArm, 120, 20);  
  moveSlow(rightArm, 90, 30);      
}

void moveSlow(Servo servo, byte newpos, byte wait){
  byte pos = servo.read();
  if(pos < newpos){
    for(;pos<=newpos;pos++){
      servo.write(pos);
      delay(wait);
    }  
  } else {
    for(;pos>=newpos;pos--){
      servo.write(pos);
      delay(wait);
    }
  }  
}



