const int ledRed = 14;
const int ledYellow = 12;
const int ledGreen = 15;
int duty;
void setup() {
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(15, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  for(duty=0; duty<1023; duty+=10)
  {
    analogWrite(14, duty);
    analogWrite(12, duty);
    analogWrite(15, duty);
    Serial.println(duty);
    delay(50);
   }
   for(duty=1023; duty>0; duty-=10)
   {
    analogWrite(14, duty);
    analogWrite(12, duty);
    analogWrite(15, duty);
    Serial.println(duty);
    delay(50);
   }
  
}
