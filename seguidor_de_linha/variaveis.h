#define STOPPED 0
#define FOLLOWING_LINE 1
#define NO_LINE 2

#define S0 A0
#define S1 A2
#define S2 A4
#define S3 A4
#define S4 A5

int mode = 0;

int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
int ENA = 10;
int ENB = 11;

int LED_TESTE = 13;

const int power = 500;
const int iniMotorPower = 255;
const int adj = 1;
const int config_sensor = 27;

int LFSensor[5]={0, 0, 0, 0, 0};

// PID controller
float Kp=40;
float Ki=0;
float Kd=33;

float error=0, P=0, I=0, D=0, PIDvalue=0;
float previousError=0, previousI=0;
