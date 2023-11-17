int soil_moisture_value = 0;

int percentage=0;

void setup() {
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
soil_moisture_value = analogRead(A0);
Serial.println(percentage);
percentage = map(soil_moisture_value, 490, 1023, 100, 0);
if(percentage < 10)  
{
  Serial.println(" pump on");
  digitalWrite(3,LOW);
}
if(percentage >80)
{
  Serial.println("pump off");
  digitalWrite(3,HIGH);
}
}