const int trigPin = A1;
const int echoPin = A0; 
int leftspeed=70;
int rightspeed=90;
int distance;

void setup() {
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 pinMode(3,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);

}

void loop() {
  dist();
  forward();
 
 if(distance<=20&&distance>0)
 {
   while(distance<30)
   {
     reverse();
     dist();
     delay(50);
   }
   stop();
   delay(200);
   turn();
   delay(200);
   stop();
   delay(200);
 }
 else
 {
  forward();
 }
}

void reverse()
{
  analogWrite(9,LOW);
  analogWrite(10,leftspeed);
  analogWrite(3,LOW);
  analogWrite(5,rightspeed);
}
void forward()
{
  analogWrite(9,leftspeed);
  analogWrite(10,LOW);
  analogWrite(3,rightspeed);
  analogWrite(5,LOW);
}
void stop()
{
  analogWrite(9,LOW);
  analogWrite(10,LOW);
  analogWrite(3,LOW);
  analogWrite(5,LOW);
}
void turn()
{
   analogWrite(9,LOW);
  analogWrite(10,leftspeed);
  analogWrite(3,rightspeed);
  analogWrite(5,LOW);
}
void dist()
{
   // for clearing the pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  //to send a 10 microsecond wave
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //to measure how lond echo pin stays high
  long duration = pulseIn(echoPin, HIGH);

 // Calculating Distance
  distance = duration * 0.034 / 2;

}


