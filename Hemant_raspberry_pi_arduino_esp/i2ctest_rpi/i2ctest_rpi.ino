/* 
 * Arduino code to send and receive I2C data
 * Tested on Adafruit Feather M0+ Express and Raspberry Pi Model 4
 * 
 * SDA <--> SDA
 * SCL <--> SCL
 * GND <--> GND
 * 
 * Sets built-in LED (1 = on, 0 = off) on Feather when requested 
 * and responds with data received
 */
#include <Wire.h>
#define SLAVE_ADDRESS 0x08     // I2C address for Arduino
#define LED 13                   // Built-in LED
int i2cData = 0; 
int i2cd= 0;                // the I2C data received
void setup(){
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED, HIGH);
}
void loop() {
  // Everything happens in the interrupts
  for(int i=0; i<=10;i++){
    i2cd= i;
    Serial.print("i2cd=");
    Serial.println(i2cd);
    delay(1000);
  }
}
// Handle reception of incoming I2C data
void receiveData(int byteCount) {
  while (Wire.available()) {
    i2cData = Wire.read();
    Serial.print("data rec:");
    Serial.println(i2cData);
    if (i2cData == 1) {
      digitalWrite(LED, 1);
      Serial.println("on");
    }
    else {
      Serial.print("data=");
      Serial.println(i2cData);
      digitalWrite(LED, 0);
      Serial.println("off");
    }
  }
}
// Handle request to send I2C data
void sendData() { 
  Serial.println("writedata to rpi");
  Wire.write(i2cd);
}