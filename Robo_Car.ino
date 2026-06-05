#include<Servo.h>
const int trigPin = A1;
const int echoPin = A0; 
int leftspeed=70;
int rightspeed=90;
int distance;
Servo headServo;
int leftdistance;
int rightdistance;


void setup() {
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 pinMode(3,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(11,OUTPUT);
 headServo.attach(12);
 headServo.write(90);
 delay(500);

}

void loop() {
  dist();
  if(distance<=25&&distance>0)
  {
    stop();
    delay(200);
    if(distance<20)
    {
      reverse();
      delay(1500);
      stop();
      delay(200);
    }
  lookaround();
  if(leftdistance>=rightdistance)
   {
      turnleft();
      delay(400);
   }
   else
   {
    turnright();
    delay(400);
   }
   stop();
   delay(200);
   headServo.write(90);//centre
   delay(300);
  }
  else
  {
    forward();
  }
  delay(50);
}

void reverse()
{
  analogWrite(6,LOW);
  analogWrite(11,leftspeed);
  analogWrite(3,LOW);
  analogWrite(5,rightspeed);
}
void forward()
{
  analogWrite(6,leftspeed);
  analogWrite(11,LOW);
  analogWrite(3,rightspeed);
  analogWrite(5,LOW);
}
void stop()
{
  analogWrite(6,LOW);
  analogWrite(11,LOW);
  analogWrite(3,LOW);
  analogWrite(5,LOW);
}
void turnleft()
{
  analogWrite(6, LOW);
  analogWrite(11, leftspeed);
  analogWrite(3, rightspeed);
  analogWrite(5, LOW);
}
void turnright()
{
  analogWrite(6, leftspeed);
  analogWrite(11, LOW);
  analogWrite(3, LOW);
  analogWrite(5, rightspeed);
}
void dist()
{
   // 1. Clear the pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // 2. Send a 10 microsecond "Ping"
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 3. Measure how long the Echo pin stays HIGH
  long duration = pulseIn(echoPin, HIGH);

  // 4. Calculate Distance
  distance = duration * 0.034 / 2;

}
void lookaround() {
  // Look Right
  headServo.write(15); 
  delay(500);          //time given for motor to move physicallly
  dist();
  rightdistance = distance;
  
  // Look Left
  headServo.write(165); 
  delay(700);          // Extra time
  dist();
  leftdistance = distance;
  
  // Return to center
  headServo.write(90);
  delay(200);
}

