#define in1 2
#define in2 3
#define in3 4
#define in4 5
int trigPin = 9;
int echoPin = 10;
int out = 8;
int flag=true;
long duration;
int distance;
void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(out, OUTPUT);
  digitalWrite(out, LOW);
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  // Clears the trigPin
  //flag = true;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  if((distance<=11) && (flag == true))
  {
    Serial.println("Tea on");
    delay(100);
    digitalWrite(out,HIGH);
    delay(4000);
    Serial.println("off");
    digitalWrite(out,LOW);
    flag = false;
  }
  if((distance>=20) && (flag == false) )
 {
  Serial.println("Tea reset");
  delay(200);
  digitalWrite(out,LOW);
  flag = true;
 }
 delay(200);   
//digitalWrite(out,LOW);

}