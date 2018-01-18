#define X_MIN_PIN           3
#ifndef X_MAX_PIN
#define X_MAX_PIN           2
#endif
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_CS_PIN           53
#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_CS_PIN           49
#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_CS_PIN           40


int x=0; int y=0; int z=0;
int ax=0;  int ay=0;  int az=0;
int total=0;
String buffer;
char bf2[30];
char buf[30];
char a =0;
int i=0;
int flag =0;

int xmax_state,xmin_state,ymax_state,ymin_state,zmax_state, zmin_state;
void setup() {
  // put your setup code here, to run once:
  pinMode(X_MAX_PIN,INPUT);
  digitalWrite(X_MAX_PIN,HIGH);
  pinMode(X_MIN_PIN,INPUT);
  digitalWrite(X_MIN_PIN,HIGH);
  pinMode(Y_MAX_PIN,INPUT);
  digitalWrite(Y_MAX_PIN,HIGH);
  pinMode(Y_MIN_PIN,INPUT);
  digitalWrite(Y_MIN_PIN,HIGH);
  pinMode(Z_MAX_PIN,INPUT);
  digitalWrite(Z_MAX_PIN,HIGH);
  pinMode(Z_MIN_PIN,INPUT);
  digitalWrite(Z_MIN_PIN,HIGH);
  pinMode(X_STEP_PIN,OUTPUT);
  pinMode(X_DIR_PIN,OUTPUT);
  pinMode(X_ENABLE_PIN,OUTPUT);
  pinMode(X_CS_PIN,OUTPUT);
  digitalWrite(X_ENABLE_PIN,LOW);
  digitalWrite(X_DIR_PIN,LOW);

  pinMode(Y_STEP_PIN,OUTPUT);
  pinMode(Y_DIR_PIN,OUTPUT);
  pinMode(Y_ENABLE_PIN,OUTPUT);
  pinMode(Y_CS_PIN,OUTPUT);
  digitalWrite(Y_ENABLE_PIN,LOW);
  digitalWrite(Y_DIR_PIN,LOW);

  pinMode(Z_STEP_PIN,OUTPUT);
  pinMode(Z_DIR_PIN,OUTPUT);
  pinMode(Z_ENABLE_PIN,OUTPUT);
  pinMode(Z_CS_PIN,OUTPUT);
  digitalWrite(Z_ENABLE_PIN,LOW);
  digitalWrite(Z_DIR_PIN,LOW);
  
  Serial.begin(57600);
   initPos();  
   Serial.print('k');
}
void runMotor(int x, int y, int z) {
  if(digitalRead(X_MAX_PIN) != 1 && x>0)   
  digitalWrite(X_STEP_PIN,LOW);
  if(digitalRead(Y_MAX_PIN) != 1 && y>0)  
  digitalWrite(Y_STEP_PIN,LOW);
  if(digitalRead(Z_MAX_PIN) != 1 && z>0)  
  digitalWrite(Z_STEP_PIN,LOW);
  delayMicroseconds(1000);
  digitalWrite(X_STEP_PIN,HIGH);
  digitalWrite(Y_STEP_PIN,HIGH);
  digitalWrite(Z_STEP_PIN,HIGH);
}
void runMotorFast(int x, int y, int z) {
  if(digitalRead(X_MAX_PIN) != 1 && x>0)   
  digitalWrite(X_STEP_PIN,LOW);
  if(digitalRead(Y_MAX_PIN) != 1 && y>0)  
  digitalWrite(Y_STEP_PIN,LOW);
  if(digitalRead(Z_MAX_PIN) != 1 && z>0)  
  digitalWrite(Z_STEP_PIN,LOW);
  delayMicroseconds(20);
  digitalWrite(X_STEP_PIN,HIGH);
  digitalWrite(Y_STEP_PIN,HIGH);
  digitalWrite(Z_STEP_PIN,HIGH);
}
void runMotorDown() {
  digitalWrite(X_DIR_PIN,HIGH);
  digitalWrite(Y_DIR_PIN,HIGH);
  digitalWrite(Z_DIR_PIN,HIGH);
  ///
  digitalWrite(X_STEP_PIN,LOW);
  digitalWrite(Y_STEP_PIN,LOW);
  digitalWrite(Z_STEP_PIN,LOW);
  delayMicroseconds(20);
  digitalWrite(X_STEP_PIN,HIGH);
  digitalWrite(Y_STEP_PIN,HIGH);
  digitalWrite(Z_STEP_PIN,HIGH);
}
void initPos()
{
  while(true) {
    if(digitalRead(X_MAX_PIN) != 1)
      runMotorFast(1,0,0);
    if(digitalRead(Y_MAX_PIN) != 1)
      runMotorFast(0,1,0);
    if(digitalRead(Z_MAX_PIN) != 1)
      runMotorFast(0,0,1);

      if(digitalRead(X_MAX_PIN) == 1 && digitalRead(Y_MAX_PIN) == 1 && digitalRead(Z_MAX_PIN) == 1)
        break;
  }
  delay(1000);
  digitalWrite(X_DIR_PIN,HIGH);
  digitalWrite(Y_DIR_PIN,HIGH);
  digitalWrite(Z_DIR_PIN,HIGH);
  for(int i=0;i<20000;i++)
    runMotorDown();
}
void loop() {
  
  total=0;
  buffer = "";
  x=0;y=0;z=0;
  while(Serial.available()) {
      a=Serial.read();
      if(a!='\n') {
          buf[i++] = a;
      } else {
          i=0;
          sscanf(buf, "x %d y %d z %d", &x, &y, &z);
          flag =1;
          memset(buf,0,sizeof(buf));
          //sprintf(bf2,"%d %d %d",x,y,z);
          //Serial.print(bf2);
      }
  }
  ax = abs(x);
  ay = abs(y);
  az = abs(z);
  total = ax + ay + az;
  x<0?digitalWrite(X_DIR_PIN,HIGH):digitalWrite(X_DIR_PIN,LOW);
  y<0?digitalWrite(Y_DIR_PIN,HIGH):digitalWrite(Y_DIR_PIN,LOW);
  z<0?digitalWrite(Z_DIR_PIN,HIGH):digitalWrite(Z_DIR_PIN,LOW);
  while(total) {
  runMotor(ax--,ay--,az--);
  total = total -1;
  }
  if(flag) {
    flag=0;
    Serial.print('k');
  }
}

