#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int distanceThreshold = 15;

Servo doorServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  doorServo.attach(3);
  doorServo.write(0);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance < distanceThreshold) {
    doorServo.write(90);
    delay(3000);
  } else {
    doorServo.write(0);
  }

  delay(500);
}
