int sensor=2;
int buzzer = 5;
int sensor_status = 0;
void setup() {
  pinMode(sensor, INPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
}

void loop() {
sensor_status = digitalRead(sensor);
Serial.println(sensor_status);
if(sensor_status == 0)  
{
  Serial.println(" bell on");
  digitalWrite(buzzer,HIGH);
  delay(500);
}
else
{
  Serial.println("bell off");
  digitalWrite(buzzer,LOW);
}
}