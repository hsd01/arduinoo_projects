#include <Servo.h>
Servo ser;
int sensor = 5;
bool flag = true;
void setup() {
  pinMode(sensor,INPUT);
  ser.attach(3);
  Serial.begin(9600);
}

void loop() {
  int mois = digitalRead(sensor);
  Serial.println(mois);
  Serial.print(" -");
  if(mois == 0 && flag == true) {
    bridge_up();
    delay(3000);
    flag = false;
  }
  if(mois == 1 && flag == false){                      
    bridge_down();
    delay(3000);
    flag = true;
  }
}
void bridge_up(){
  for (int pos = 0; pos <= 180; pos += 1) { 
    ser.write(pos);
    delay(15); 
   }
}
void bridge_down(){
  for (int pos = 180; pos >= 0; pos -= 1) { 
    ser.write(pos);
    delay(15); 
   }
}