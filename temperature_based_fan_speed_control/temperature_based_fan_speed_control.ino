const int lm35_pin = A1;	/* LM35 O/P pin */
int en = A3;
int in1=3;
int in2=4;
float tempc; //variable to store temperature in degree Celsius
float tempf; //variable to store temperature in Fahreinheit
float vout; //temporary variable to hold sensor reading
void setup() {
  pinMode(en,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(lm35_pin,INPUT); // Configuring sensor pin as input
  Serial.begin(9600);
}

void loop() {
  vout=analogRead(lm35_pin); //Reading the value from sensor
  vout=(vout*500)/1023;
  tempc=vout; // Storing value in Degree Celsius
  tempf=(vout*1.8)+32; // Converting to Fahrenheit
  Serial.print("in DegreeC=");
  Serial.print("\t");
  Serial.print(tempc);
  Serial.print(" ");
  Serial.print("in Fahrenheit=");
  Serial.print("\t");
  Serial.print(tempf);
  Serial.println();
  delay(500);
  if(tempc <=20){
    Serial.println("Speed 1");
    analogWrite(en, 50);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }
  if((tempc > 20) && (tempc <=30)){
    Serial.println("Speed 2");
    analogWrite(en, 100);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }
  if((tempc > 30) && (tempc <=50)){
    Serial.println("Speed 3");
    analogWrite(en, 150);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }
  if(tempc > 50){
    Serial.println("Speed 4");
    analogWrite(en, 200);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }
  
}
