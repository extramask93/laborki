



#define X_MIN_PIN           3
#ifndef X_MAX_PIN
  #define X_MAX_PIN         2
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



int x, y, z;
int total=0;
String buffer;

  

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
  
  Serial.begin(115200);

  Serial.setTimeout(50);
  //loop();
}
void runMotorX() {
    if(digitalRead(X_MAX_PIN) != 1)   
      digitalWrite(X_STEP_PIN,LOW);
   delayMicroseconds(20);
  digitalWrite(X_STEP_PIN,HIGH);
}
void runMotorY() {
      if(digitalRead(Y_MAX_PIN) != 1)   
      digitalWrite(Y_STEP_PIN,LOW);
   delayMicroseconds(20);
  digitalWrite(Y_STEP_PIN,HIGH);
}
void runMotorZ() {
      if(digitalRead(Z_MAX_PIN) != 1)   
      digitalWrite(Z_STEP_PIN,LOW);
   delayMicroseconds(20);
  digitalWrite(Z_STEP_PIN,HIGH);
}
void runMotor() {
  /*if(digitalRead(X_MAX_PIN))
    digitalWrite(X_DIR_PIN,HIGH);
  /*else if(digitalRead(X_MIN_PIN))
      digitalWrite(X_DIR_PIN,LOW);*/

  if(digitalRead(X_MAX_PIN) != 1)   
  digitalWrite(X_STEP_PIN,LOW);
  if(digitalRead(Y_MAX_PIN) != 1)  
  digitalWrite(Y_STEP_PIN,LOW);
  if(digitalRead(Z_MAX_PIN) != 1)  
  digitalWrite(Z_STEP_PIN,LOW);
  delayMicroseconds(80);
  digitalWrite(X_STEP_PIN,HIGH);
  digitalWrite(Y_STEP_PIN,HIGH);
  digitalWrite(Z_STEP_PIN,HIGH);
}
void loop() {
  // put your main code here, to run repeatedly:
  /*xmax_state=digitalRead(X_MAX_PIN);
  xmin_state=digitalRead(X_MIN_PIN);
  ymax_state=digitalRead(Y_MAX_PIN);
  ymin_state=digitalRead(Y_MIN_PIN);
  zmax_state=digitalRead(Z_MAX_PIN);
  zmin_state=digitalRead(Z_MIN_PIN);
  Serial.println(zmax_state);*/
  while(Serial.available()) {
    buffer = Serial.readString();
      sscanf(buffer.c_str(), "x %d y %d z %d\n", &x, &y, &z);
      Serial.println(x);
      Serial.println(y);
      Serial.println(z);
  }
  total = abs(x) + abs(y) + abs(z);
  while(total) {
  if(x>0)
  { --x;
  digitalWrite(X_DIR_PIN,LOW);
  runMotorX();
  }
  else if(x<0)
  { ++x;
            digitalWrite(X_DIR_PIN,HIGH);
            runMotorX();
  }
if(y>0)
  { --y;
  digitalWrite(Y_DIR_PIN,LOW);
  runMotorY();
  }
  else if(y<0)
  { ++y;
            digitalWrite(Y_DIR_PIN,HIGH);
            runMotorY();
  }
    if(z>0)
  { --z;
  digitalWrite(Z_DIR_PIN,LOW);
  runMotorZ();
  }
  else if(z<0)
  { ++z;
            digitalWrite(Z_DIR_PIN,HIGH);
            runMotorZ();
  }
  total--;
  }
}




