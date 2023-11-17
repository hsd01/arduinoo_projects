const int lm35_pin = A1;	/* LM35 O/P pin */

void setup() {
  Serial.begin(9600);
}

void loop() {
  int temp_val;
  float val;
  temp_adc_val = analogRead(lm35_pin);	/* Read Temperature */
  val = (temp_val * 4.88);	/* Convert adc value to equivalent voltage */
  val = (val/10);	/* LM35 gives output of 10mv/°C */
  Serial.print("Temperature = ");
  Serial.print(temp_val);
  Serial.print(" Degree Celsius\n");
  delay(1000);
}