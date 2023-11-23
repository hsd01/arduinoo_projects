// variable declaration
int trigPin = 9;
int echoPin = 10;
int out = 5;
int flag=true;
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(out, OUTPUT);
  digitalWrite(out, LOW);
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  // Clears the trigPin
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
  if((distance<10) && (flag == true))
  {
    Serial.println("Tea on");
    digitalWrite(out, HIGH);
    delay(3000);
    Serial.println("Tea off");
    digitalWrite(out, LOW);
    flag = false;
  }
 else if((distance>15) && (flag == false))
 {
  Serial.println("Tea reset");
  digitalWrite(out, LOW);
  flag = true;
 }
 digitalWrite(out, LOW);
}