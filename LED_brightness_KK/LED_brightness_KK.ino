const int analogPin = A0;
const int ledRed = 14;
const int ledYellow = 12;
const int ledGreen = 15;
int sensorValue = 0;
int adcValue = 0;
void setup() {
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(15, OUTPUT);
  Serial.begin(115200);
  
  // put your setup code here, to run once:

}

void loop() {
  sensorValue = analogRead(analogPin);
  adcValue = sensorValue;
  analogWrite(14, adcValue);
  analogWrite(12, adcValue);
  analogWrite(15, adcValue);
  Serial,println(adcValue);
  delay(10);
  // put your main code here, to run repeatedly:

}
