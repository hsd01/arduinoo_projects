#include <Wire.h>
#define SLAVE_ADDRESS 0x08     // I2C address for Arduino
#define LED 13                   // Built-in LED
int i2cData = 0; 
int i2cd= 0;
int data1 = 0;                // the I2C data received
#define trigPin 9 // it defines the ECHO pin of the sensor to pin 5 of Arduino  
#define echoPin 10
int in1 = 5;
int in2 = 6;
int in3 = 7;
int in4 = 8;
long duration; // variable for the duration of sound wave travel  
int distance; // variable for the distance measurement  
byte data_to_echo = 0;
void setup(){
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED, HIGH);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
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
  /*if(distance < 15){
    stop_();
  }*/
}
// Handle reception of incoming I2C data
void receiveData(int byteCount) {
  while (Wire.available()) {
    i2cData = Wire.read();
    Serial.print("data rec:");
    Serial.println(i2cData);
    if (i2cData == 1) {
      forward();
      Serial.println("forward");
    }
    else if (i2cData == 2){
      reverse();
      Serial.println("reverse");
    }
    else if (i2cData == 3){
      left();
      Serial.println("left");
    }
    else if (i2cData == 4){
      right();
      Serial.println("right");
    }
    else if(i2cData == 5){
      stop_();
      Serial.println("STOP");
    }
  }
}
// Handle request to send I2C data
void sendData() { 
  Serial.println("writedata to rpi");
  Wire.write(distance);
}
void forward(){
  Serial.println("forward");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
  delay(2000);
}
void reverse(){
  Serial.println("reverse");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
  delay(2000);
}
void left(){
  Serial.println("left");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(2000);
}
void right(){
  Serial.println("right");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(2000);
}
void stop_(){
  Serial.println("stop");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}