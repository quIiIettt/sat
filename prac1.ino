int x = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
 
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
 
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  x = 0.085 * readUltrasonicDistance(8, 7);
  if (x < 0 && x <= 150) {
    analogWrite(11, 110);
    analogWrite(10, 110);
    analogWrite(9, 255);
  }
  if (x >= 150 && x <= 300) {
    analogWrite(11, 143);
    analogWrite(10, 130);
    analogWrite(9, 10);
  }
  if (x >= 300 && x <= 450) {
    analogWrite(11, 10);
    analogWrite(10, 143);
    analogWrite(9, 40);
  }
  if (x >= 450 && x <= 600) {
    analogWrite(11, 10);
    analogWrite(10, 140);
    analogWrite(9, 143);
  }
  if (x >= 600 && x <= 750) {
    analogWrite(11, 10);
    analogWrite(10, 10);
    analogWrite(9, 145);
  }
  if (x >= 750 && x <= 900) {
    analogWrite(11, 255);
    analogWrite(10, 100);
    analogWrite(9, 0);
  }
  if (x >= 900 && x <= 1050) {
    analogWrite(11, 100);
    analogWrite(10, 10);
    analogWrite(9, 145);
  }
  if (x >= 1050 && x <= 1200) {
    analogWrite(11, 255);
    analogWrite(10, 3);
    analogWrite(9, 116);
  }
  if (x > 1200) {
    analogWrite(11, 255);
    analogWrite(10, 0);
    analogWrite(9, 0);
  }
  delay(10); 
}
