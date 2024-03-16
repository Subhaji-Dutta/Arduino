// LIGHTNING ARDUINO CHANNEL CODE:-
char t;
int trigPin = A0;
int echoPin = A1;
long duration, distance;
void setup() {
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);

}

void loop() {
if(Serial.available()>0)
{

t=Serial.read();
Serial.println(t);
delay(100);
    
    
 
  switch(t)
  {
   case 'F': forward();
    break;
    case 'B':backward();
    break;
    case 'L':leftward();
    break;
    case 'R':rightward();
    break;
    case 'S':stop_the();
    break;
    case 'X' :
    
     ultra();
    break;
  }
  
}
}
 void forward(){
  digitalWrite(6,HIGH);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
}


 void backward()
{
digitalWrite(6,LOW );
digitalWrite(7,HIGH);
digitalWrite(8,LOW);
digitalWrite(9,HIGH);

}

 void stop_the()
{
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);

}
void leftward()
{
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
}
void rightward()
{
digitalWrite(6,HIGH);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,HIGH);
}
void ultra()
{
  digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 duration = pulseIn(echoPin, HIGH);
 distance = duration / 58.2;
 Serial.println(distance);
 delay(10);

if (distance > 30)
 {
  forward();
 }

 if (distance < 30)
 {
 stop_the();
 delay(500);
 backward();
 delay(500);
 stop_the();
 delay(100);
 rightward();
 delay(500);
}

}