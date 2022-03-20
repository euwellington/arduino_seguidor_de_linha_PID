void readLFSsensors()
{
  LFSensor[0] = analogRead(S0);
  LFSensor[1] = analogRead(S1);
  LFSensor[2] = analogRead(S2);
  LFSensor[3] = analogRead(S3);
  LFSensor[4] = analogRead(S4);
  
  if(( LFSensor[0] < config_sensor )&&( LFSensor[1] < config_sensor )&&( LFSensor[2] < config_sensor )&&( LFSensor[3] < config_sensor )&&( LFSensor[4] > config_sensor ))  {mode = FOLLOWING_LINE; error = 2;}
  else if(( LFSensor[0] < config_sensor )&&( LFSensor[1] < config_sensor )&&( LFSensor[2] < config_sensor )&&(LFSensor[3] > config_sensor )&&( LFSensor[4] < config_sensor ))  {mode = FOLLOWING_LINE; error = 1;}
  else if(( LFSensor[0] < config_sensor )&&( LFSensor[1] < config_sensor )&&( LFSensor[2] > config_sensor )&&( LFSensor[3] < config_sensor )&&( LFSensor[4] < config_sensor ))  {mode = FOLLOWING_LINE; error = 0;}
  else if(( LFSensor[0] < config_sensor )&&( LFSensor[1] > config_sensor )&&( LFSensor[2] < config_sensor )&&( LFSensor[3] < config_sensor )&&( LFSensor[4] < config_sensor ))  {mode = FOLLOWING_LINE; error = -1;}
  else if(( LFSensor[0] > config_sensor )&&( LFSensor[1] < config_sensor )&&( LFSensor[2] < config_sensor )&&( LFSensor[3] < config_sensor )&&( LFSensor[4] < config_sensor ))  {mode = FOLLOWING_LINE; error = -2;}
  else if(( LFSensor[0] < config_sensor )&&( LFSensor[1] < config_sensor )&&( LFSensor[2] < config_sensor )&&(LFSensor[3] < config_sensor )&&(LFSensor[4] < config_sensor ))  {mode = STOPPED; error = 0;}
  else if(( LFSensor[0] > config_sensor )&&( LFSensor[1] > config_sensor )&&( LFSensor[2] > config_sensor )&&( LFSensor[3] > config_sensor )&&( LFSensor[4] > config_sensor ))  {mode = NO_LINE; error = 0;}
}
 
