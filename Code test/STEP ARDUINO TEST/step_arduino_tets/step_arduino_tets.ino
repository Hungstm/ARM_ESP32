#include <SimpleKalmanFilter.h>
SimpleKalmanFilter ADCADC(2, 2, 0.01);

const int stepPin = 5; 
const int dirPin = 2; 
const int enPin = 8;
void setup() {
  Serial.begin(9600);
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(A4, INPUT);
  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,HIGH);
  
}
int a, a2, b =0 , c = 10, ain, ain1, ain2, ain22;
bool d = 1; 
void goc(){
  digitalWrite(dirPin,d);
  digitalWrite(stepPin,HIGH); 
  delayMicroseconds(500); 
  digitalWrite(stepPin,LOW); 
  delayMicroseconds(500); 
}
void loop() {
  for(c = 0; c <=  2000; c++  )
  {
    d = 1; 
    goc();
  }

  delay(1000);
   for(c = 0; c <=  2000; c++ )
  {
    d= 0; 
    goc();
  }
  delay(1000);
  // ain = map(analogRead(A4),0,1023, 0, 2000);
  // ain1 =  ADCADC.updateEstimate(ain);
  // a  = ADCADC.updateEstimate(ain1);

  // ain2 = map(analogRead(A3),0,1023, 0, 2000);
  // ain22 =  ADCADC.updateEstimate(ain2);
  // //a2  = ADCADC.updateEstimate(ain22);
  // if(a != b)
  // {
  //   if(a > b)
  //   {
  //     d = 1; 
  //     for(c = 0; c <=  a-b; c++ )
  //     {
  //       goc();
  //     }
  //     b = a;
  //   } 
  //   else if( a < b)
  //   {
  //     d = 0; 
  //      for(c = 0; c <=  b - a; c++ )
  //     {
  //       goc();
  //     }
  //     b = a;
  //   }
  // }
  // Serial.print(a);   Serial.print("___"); 
  // Serial.println(ain22);
}