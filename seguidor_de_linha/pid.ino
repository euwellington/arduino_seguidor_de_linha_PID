void calculatePID()
{
  P = error;
  I = I + error;
  D = error-previousError;
  PIDvalue = (Kp*P) + (Ki*I) + (Kd*D);
  previousError = error;
}

void checkPIDvalues()
{
  
  Serial.print("PID: ");
  Serial.print(Kp);
  Serial.print(" - ");
  Serial.print(Ki);
  Serial.print(" - ");
  Serial.println(Kd);  
  
}

void testLineFollowSensors()
{
     int LFS0 = analogRead(S0);
     int LFS1 = analogRead(S1);
     int LFS2 = analogRead(S2);
     int LFS3 = analogRead(S3);
     int LFS4 = analogRead(S4);
     
//     Serial.print ("LFS: L  0 1 2 3 4  R ==> "); 
//     Serial.println (LFS0); 
//     Serial.print (" ");
//     Serial.print (LFS1); 
//     Serial.print (" ");
//     Serial.print (LFS2); 
//     Serial.print (" ");
//     Serial.print (LFS3); 
//     Serial.print (" ");
//     Serial.print (LFS4); 
//     Serial.print ("  ==> ");
//    
//     Serial.print (" P: ");
//     Serial.print (P);
//     Serial.print (" I: ");
//     Serial.print (I);
//     Serial.print (" D: ");
//     Serial.print (D);
//     Serial.print (" PID: ");
//     Serial.println (PIDvalue);
}
