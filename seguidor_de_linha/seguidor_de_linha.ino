#include "variaveis.h"
 
void setup(){
  Serial.begin(9600);

//  SENSORES
  pinMode(S0,INPUT);
  pinMode(S1,INPUT);
  pinMode(S2,INPUT);
  pinMode(S3,INPUT);
  pinMode(S4,INPUT);
  
//  MOTORES
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(LED_TESTE, OUTPUT);
}

byte flag = 1;
 
void loop(){

/*Serial.print("Sensor +2: ");
Serial.print(digitalRead(14));//+2
Serial.print("     Sensor +1: ");
Serial.print(digitalRead(18));//+1
Serial.print("     Sensor 0: ");
Serial.print(digitalRead(15)); //0
Serial.print("     Sensor -1: ");
Serial.print(digitalRead(16));//-1
Serial.print("     Sensor -2: ");
Serial.println(digitalRead(17));//-2
delay(500);*/


/*if(flag){
 motorEsq.setSpeed(255); //Define a velocidade maxima
  motorEsq.run(BACKWARD); //Gira o motor sentido horario
  
  motorDir.setSpeed(255); //Define a velocidade maxima
  motorDir.run(BACKWARD); //Gira o motor sentido horario
}
if(digitalRead(15) == 1){
  flag = 0;
  motorEsq.setSpeed(255); //Define a velocidade maxima
  motorEsq.run(BACKWARD); //Gira o motor sentido horario
  
  motorDir.setSpeed(255); //Define a velocidade maxima
  motorDir.run(BACKWARD); //Gira o motor sentido horario
}else if(digitalRead(16) == 1){
  //flag = 0;
  motorEsq.setSpeed(255); //Define a velocidade maxima
  motorEsq.run(BACKWARD); //Gira o motor sentido horario
  
  motorDir.setSpeed(255); //Define a velocidade maxima
  motorDir.run(FORWARD); //Gira o motor sentido horario
}else if(digitalRead(14) == 1){
  //flag = 0;
  motorEsq.setSpeed(255); //Define a velocidade maxima
  motorEsq.run(FORWARD); //Gira o motor sentido horario
  
  motorDir.setSpeed(255); //Define a velocidade maxima
  motorDir.run(BACKWARD); //Gira o motor sentido horario
}*/
//esquerda(255, 2);
  readLFSsensors();   
  switch (mode)
  {
    case STOPPED: 
      frente();
      //ledBlink();
      previousError = error;
      break;
      
    case NO_LINE:  
      frente();
      previousError = 0;
      break;

    case FOLLOWING_LINE:     
      calculatePID();
//      testLineFollowSensors();
      motorPIDcontrol();    
      break;     
  }
}
