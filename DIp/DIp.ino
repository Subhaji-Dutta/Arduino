#include <Servo.h>

Servo myservo;

#define Flame 1
#define LDR 2
#define Rain 3
#define Mqt 4
#define Relay1 5
#define Relay2 6
#define Relay3 8

void setup() {
  pinMode(Flame,INPUT);
  pinMode(LDR,INPUT);
  pinMode(Mqt,INPUT);
  pinMode(Rain,INPUT);
  myservo.attach(2); // servo pin ai pin a lgbe 
  pinMode(Relay1,OUTPUT);
  pinMode(Relay2,OUTPUT);
  pinMode(Relay3,OUTPUT);


}

void loop() {
  if(digitalRead(Flame)==1){ //flame sensor
    digitalWrite(Relay1,LOW);
    digitalWrite(Relay3,LOW);
  }else{
    digitalWrite(Relay1,HIGH);
    digitalWrite(Relay3,HIGH);
  }
    if(digitalRead(Rain)==1){// position change korle ai ta change korbi
     myservo.write(90);
  }else{
     myservo.write(0);
  }
    if(digitalRead(Mqt)==1){ //mqt sensor
    digitalWrite(Relay2,LOW);
    digitalWrite(Relay3,LOW);
  }else{
    digitalWrite(Relay2,HIGH);
    digitalWrite(Relay3,HIGH);
  }
  if(digitalRead(LDR)==1){ //LDR sensor
    digitalWrite(Relay2,LOW);
    digitalWrite(Relay3,LOW);
  }else{
    digitalWrite(Relay2,HIGH);
    digitalWrite(Relay3,HIGH);
  }
}
