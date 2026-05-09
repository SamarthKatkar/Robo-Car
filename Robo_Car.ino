void setup() {
 pinMode(3,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);

}

void loop() {
  int leftspeed=70;
  int rightspeed=90;
  analogWrite(9,leftspeed);
  analogWrite(10,LOW);
  analogWrite(3,rightspeed);
  analogWrite(5,LOW);
  

 


}
