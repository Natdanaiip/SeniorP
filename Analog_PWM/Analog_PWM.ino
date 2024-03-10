void setup() {
  pinMode(12, OUTPUT);
  Serial.begin(115200);
  // put your setup code here, to run once:
}

void loop() {
  Serial.println("0");
  analogWrite(12, 0);
  delay(3000);
  Serial.println("255");
  analogWrite(12, 255);
  delay(3000);
  Serial.println("512");
  analogWrite(12, 512);
  delay(3000);
  Serial.println("767");
  analogWrite(12, 767);
  delay(3000);
  Serial.println("1023");
  analogWrite(12, 1023);
  // put your main code here, to run repeatedly:

}
