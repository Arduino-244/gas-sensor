#define smokeA0 A5
int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int sensorThreshold = 35;
void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}
void loop() {
  int analogSensor = analogRead(smokeA0);
  digitalWrite(redLed, analogSensor >= sensorThreshold && HIGH || LOW);
  digitalWrite(greenLed, analogSensor < sensorThreshold && HIGH || LOW);
  Serial.println(analogSensor);
  if (analogSensor >= sensorThreshold) {
      tone(buzzer, 1000, 200);
  } else {
      noTone(buzzer);
  }
  delay(1000);
}