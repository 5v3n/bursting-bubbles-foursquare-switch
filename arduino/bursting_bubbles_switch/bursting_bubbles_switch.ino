// bursting bubbles
// Sven Kraeuter 2013
// MIT License
// http://makingthingshappen.de

void setup() {
 pinMode(4,OUTPUT);
 pinMode(13,OUTPUT);
}

void loop(){
  digitalWrite(4,HIGH);
  digitalWrite(13,LOW);
  delay(5000);
  digitalWrite(4,LOW);
  digitalWrite(13,HIGH);
  delay(5000);
}