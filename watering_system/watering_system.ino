int motor = 8;
void setup() {
  pinMode(motor,OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600); 
}

void loop() {
  int time_del = analogRead(A0);
  Serial.print("start>>");
  Serial.println(analogRead(A0));
  int time_val = map(time_del, 0, 1023, 1, 60);
  int actual_time = time_val*1000;
  Serial.println("time:"+actual_time);
  digitalWrite(motor, HIGH);
  delay(actual_time);
  digitalWrite(motor, LOW);
  delay(actual_time);
}
