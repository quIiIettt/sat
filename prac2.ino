const int gasSensorPin = A5;
const int tempSensorPin = A0;
const int piezoPin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(piezoPin, OUTPUT);
}

void loop() {
  int gasLevel = analogRead(gasSensorPin);
  int temp = analogRead(tempSensorPin);

  float voltage = (temp * 5.0) / 1024;
  float temperature = (voltage - 0.5) * 100;
  
  Serial.print("Gas level: ");
  Serial.println(gasLevel);

  Serial.print("Temperature: ");
  Serial.println(temperature);

  if (temperature > 100) {
    digitalWrite(piezoPin, HIGH);
  } else {
    digitalWrite(piezoPin, LOW);
  }

  if (gasLevel > 500) {
    digitalWrite(piezoPin, HIGH);
  } else {
    digitalWrite(piezoPin, LOW);
  }

  delay(1000);
}
