int a1 = 1;
int a2 = 2;
int a3 = 3;
int a4 = 4;
int i1 = 5;
int i2 = 6;
int i3 = 7;
bool irc1;
bool irc2;
bool irc3;
int trigPin = 8;
int echoPin = 9;
long duration;
int distance;

void setup(){
  pinMode(a1,OUTPUT);
  pinMode(a2,OUTPUT);
  pinMode(a3,OUTPUT);
  pinMode(a4,OUTPUT);
  pinMode(i1,INPUT);
  pinMode(i2,INPUT);
  pinMode(i3,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(50);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(50);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = duration*0.034/2;
  irc2 = digitalRead(i1);
  irc3 = digitalRead(i2);
  irc1 = digitalRead(i3);
  
  if(distance >= 5 && distance <= 10){
    if(irc2 == 1 & irc3 == 1){
      digitalWrite(a1,HIGH);
      digitalWrite(a2,LOW);
      digitalWrite(a3,HIGH);
      digitalWrite(a4,LOW);
    }
    else if(irc2 == 0 && irc3 == 1){
      digitalWrite(a1,LOW);
      digitalWrite(a2,HIGH);
      digitalWrite(a3,HIGH);
      digitalWrite(a4,LOW);
    }
    else if(irc2 == 1 && irc3 == 0){
      digitalWrite(a1,HIGH);
      digitalWrite(a2,LOW);
      digitalWrite(a3,LOW);
      digitalWrite(a4,HIGH);
    }
    else{
      digitalWrite(a1,LOW);
      digitalWrite(a2,LOW);
      digitalWrite(a3,LOW);
      digitalWrite(a4,LOW);
    }
  }
  else if(distance <= 5 && irc1 == 1){
    digitalWrite(a1,LOW);
    digitalWrite(a2,HIGH);
    digitalWrite(a3,LOW);
    digitalWrite(a4,HIGH);
  }
  else{
    digitalWrite(a1,LOW);
    digitalWrite(a2,LOW);
    digitalWrite(a3,LOW);
    digitalWrite(a4,LOW);
  }
}
