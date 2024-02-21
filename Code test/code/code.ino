#include <Ps3Controller.h>
#include <Arduino.h>
#include <ESP32Servo.h> 
#include "robot.h"   


Servo servo1; 
Servo servo2; 
Servo servo0; 


void setup() {
  Ps3.attach(notify);
  Ps3.begin("28:82:26:68:86:88");

  pinMode(m1,OUTPUT); 
  pinMode(m2,OUTPUT); 
  pinMode(m0,OUTPUT); 

  pinMode(d1,OUTPUT); 
  pinMode(d2,OUTPUT); 
  pinMode(d0,OUTPUT); 

  pinMode(p1,OUTPUT); 
  pinMode(p2,OUTPUT);  

  pinMode(en,OUTPUT); 
  pinMode(en0,OUTPUT); 
  // ledcSetup(pm1, f, r);
  // ledcAttachPin(p1, pm1);

  // ledcSetup(pm2, f, r);
  // ledcAttachPin(p2, pm2);

  // ledcSetup(pm0, f, r);
  // ledcAttachPin(p0, pm0);

  servo1.setPeriodHertz(50);        // Standard 50hz servo
  servo1.attach(m1, 500, 2500);   // attaches the servo
  servo1.write(0);

  servo2.setPeriodHertz(50);        // Standard 50hz servo
  servo2.attach(m2, 500, 2500);   // attaches the servo
  servo2.write(100);

  servo0.setPeriodHertz(330);        // Standard 50hz servo
  servo0.attach(m0, 500, 2500);   // attaches the servo
  servo0.write(150);
  Serial.begin(9600);

  digitalWrite(en, 1);
}

void goc0(int d){
  digitalWrite(d0,d);
  digitalWrite(p0,HIGH); 
  delayMicroseconds(500); 
  digitalWrite(p0,LOW); 
  delayMicroseconds(500); 
}

void goc1(int d ){
  digitalWrite(d1,d);
  digitalWrite(p1,HIGH); 
  delayMicroseconds(500); 
  digitalWrite(p1,LOW); 
  delayMicroseconds(500); 
}

void goc2(int d){
  digitalWrite(d2,d);
  digitalWrite(p2,HIGH); 
  delayMicroseconds(500); 
  digitalWrite(p2,LOW); 
  delayMicroseconds(500); 
}

///////////////////////////=============================///////////////////////////////
int g1 =  100; 
int g2 = 0; 
int g0 = 150;

void notify(){
  static unsigned long time1a;
  if(Ps3.data.analog.stick.ly > 120 ){
    for(int c = 0; c <=  5; c++ )
    {
      goc2(0);
    }
  }else if(Ps3.data.analog.stick.ly < -120){
    for(int c = 0; c <=  5; c++ )
    {
      goc2(1);
    }
  }else if(Ps3.data.analog.stick.lx > 120){
    for(int c = 0; c <=  6; c++ )
    {
      goc0(1);
    }
  }else if(Ps3.data.analog.stick.lx < -120){
    for(int c = 0; c <=  6; c++ )
    {
      goc0(0);
    }
  }
  else if(Ps3.data.button.l1){
    for(int c = 0; c <=  10; c++ )
    {
      goc1(1);
    }
  }else if(Ps3.data.button.l2){
    for(int c = 0; c <=  10; c++ )
    {
      goc1(0);
    }
  }
  else if(Ps3.data.button.r2){
    if(millis() - time1a >= 10 && g2 < 70){
      g2++; 
      time1a = millis(); 
    }
  }else if(Ps3.data.button.r1){
    if(millis() - time1a >= 10 && g2 > 0){
      g2--; 
      time1a = millis(); 
    }
  }
  else if(Ps3.data.analog.stick.ry < -120){
    if(millis() - time1a >= 6 && g0 < 140){
      g0++; 
      time1a = millis(); 
    }
  }else if(Ps3.data.analog.stick.ry > 120 ){
    if(millis() - time1a >= 6 && g0 > 0){
      g0--; 
      time1a = millis(); 
    }
  }
  else if(Ps3.data.analog.stick.rx > 80){
    if(millis() - time1a >= 15 && g2 < 180){
      g1++; 
      time1a = millis(); 
    }
  }else if(Ps3.data.analog.stick.rx < -80){
    if(millis() - time1a >= 15 && g2 > 0){
      g1--; 
      time1a = millis(); 
    }
  }

}
void loop() {
  digitalWrite(en0 , 0);
  digitalWrite(en , 1);
  servo2.write(g2);
  servo1.write(g1);
  servo0.write(g0);

  //Serial.println(Ps3.data.analog.stick.rx);

  // for(int c = 0; c <=  1000; c++ )
  // {
  //   goc0(0);
  // }

  // delay(1000);
  // for(int c = 0; c <=  1000; c++ )
  // {
  //   goc0(1);
  // }
  // Serial.println("ok");

}
