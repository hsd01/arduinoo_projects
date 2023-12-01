int fire=2;
int out=6;
void setup() {
  pinMode(fire,INPUT);
  pinMode(out,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int val = digitalRead(fire);
  Serial.println(val);
  if (val==0){
    digitalWrite(out,HIGH);
    delay(1000);
    digitalWrite(out,LOW);
    delay(200);
    digitalWrite(out,HIGH);
    delay(1000);
    digitalWrite(out,LOW);
    delay(200);
    digitalWrite(out,HIGH);
    delay(1000);
    digitalWrite(out,LOW);
    delay(200);
    digitalWrite(out,HIGH);
    delay(1000);
    digitalWrite(out,LOW);
    delay(200);
  }
  delay(300);

}
