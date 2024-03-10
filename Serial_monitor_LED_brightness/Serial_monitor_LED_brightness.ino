const int ledRed = 14;
const int ledYellow = 12;
const int ledGreen = 15;
int duty;
void setup() {
  pinMode(14,OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(15, OUTPUT);
  Serial.begin(115200);
  Serial.println("Please enter numbers since 0-1023");
 
}

void loop() {
  if(Serial.available()>0)
  {
    duty = Serial.parseInt();
    analogWrite(14, duty);
    analogWrite(12, duty);
    analogWrite(15, duty);
    Serial.println(duty);
    delay(300);
  }
  // put your main code here, to run repeatedly:

}
