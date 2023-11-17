int sensor=5;
int buzzer = 6;
int sensor_status = 0;
void setup() {
  pinMode(5,OUTPUT);
  Serial.begin(9600);
}

void loop() {
sensor_status = digitalRead(sensor);
Serial.println(sensor_status);
if(sensor_status == 1)  
{
  Serial.println(" bell on");
  digitalWrite(buzzer,HIGH);
}
else
{
  Serial.println("bell off");
  digitalWrite(buzzer,LOW);
}
}