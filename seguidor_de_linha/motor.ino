void motorPIDcontrol()
{  

  int leftMotorSpeed;
  int rightMotorSpeed;

  if(error == 0){
    leftMotorSpeed = iniMotorPower - abs(PIDvalue);
    rightMotorSpeed = iniMotorPower - abs(PIDvalue);
    }
  if(error == 1)
    leftMotorSpeed = iniMotorPower;
    rightMotorSpeed = iniMotorPower - abs(PIDvalue);
  }else if(error == -1){
    leftMotorSpeed = iniMotorPower - abs(PIDvalue);
    rightMotorSpeed = iniMotorPower;
  }else if(error == 2){
    leftMotorSpeed = iniMotorPower; 
    rightMotorSpeed = 50 +  abs(PIDvalue);
  }else if(error == -2){
    leftMotorSpeed = 50 + abs(PIDvalue);
    rightMotorSpeed = iniMotorPower; 
  }
   /*leftMotorSpeed = iniMotorPower - PIDvalue;
    rightMotorSpeed = iniMotorPower - PIDvalue;*/
  
  // The motor speed should not exceed the max PWM value
   constrain(leftMotorSpeed, 1000, 2000);
   constrain(rightMotorSpeed, 1000, 2000);

  if(error == 1 || error == 2){
    esquerda(rightMotorSpeed, leftMotorSpeed);
//  motorEsq.setSpeed(leftMotorSpeed); //Define a velocidade maxima
//  motorEsq.run(BACKWARD); //Gira o motor sentido horario
//  motorDir.setSpeed(rightMotorSpeed); //Define a velocidade maxima
//  motorDir.run(FORWARD); //Gira o motor sentido horario
  
  }else if(error == -1 || error == -2){
    direita(rightMotorSpeed, leftMotorSpeed);
//     motorEsq.setSpeed(leftMotorSpeed); //Define a velocidade maxima
//     motorEsq.run(FORWARD); //Gira o motor sentido horario
//  motorDir.setSpeed(rightMotorSpeed); //Define a velocidade maxima
//  motorDir.run(BACKWARD); //Gira o motor sentido horario
  }else{
    tras(rightMotorSpeed, leftMotorSpeed);
//     motorEsq.setSpeed(leftMotorSpeed); //Define a velocidade maxima
//      motorEsq.run(BACKWARD); //Gira o motor sentido horario
  
//    motorDir.setSpeed(rightMotorSpeed); //Define a velocidade maxima
//    motorDir.run(BACKWARD); //Gira o motor sentido horario  
  }
//
//  Serial.print (PIDvalue);
//  Serial.print (" ==> Left, Right:  ");
//  Serial.print (leftMotorSpeed);
//  Serial.print ("   ");
//  Serial.print (rightMotorSpeed);
//  Serial.print ("  ==> erro: ");
//  Serial.println (error);
}

void frente(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(ENA, 255);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(ENB, 255);
}

void esquerda(int velocidadeA, int velocidadeB) {
    digitalWrite(IN1, LOW);  
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);  
    digitalWrite(IN4, HIGH); 
    analogWrite(ENA, velocidadeA);  
    analogWrite(ENB, velocidadeB);
}

void direita(int velocidadeA, int velocidadeB) {
    digitalWrite(IN1, HIGH);  
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);  
    digitalWrite(IN4, LOW); 
    analogWrite(ENA, velocidadeA);  
    analogWrite(ENB, velocidadeB);
}

void tras(int velocidada_motor_direita, int velocidada_motor_esquerda) {
  digitalWrite(IN1, LOW);  
  digitalWrite(IN2, HIGH);   
  digitalWrite(IN3, HIGH);  
  digitalWrite(IN4, LOW); 
  analogWrite(ENA, velocidada_motor_direita);
  analogWrite(ENB, velocidada_motor_esquerda);
}
