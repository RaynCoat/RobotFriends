#include <NewPing.h>

class Sonar {
// These won't change
int TrigPin;
int EchoPin;
int MaxDistance; // Maximum range allowed in mm
// These will change
int CurrentDistance;
public:
Sonar(int trigpin, int echopin, int maxdistance)
: TrigPin(trigpin), EchoPin(echopin), MaxDistance(maxdistance) {
pinMode(TrigPin, OUTPUT);
pinMode(EchoPin, INPUT);
digitalWrite(TrigPin, LOW);
}
int Measure() {
digitalWrite(TrigPin, HIGH);
delayMicroseconds(10);
digitalWrite(TrigPin, LOW);
int Time = pulseIn(EchoPin, HIGH, 5000);
CurrentDistance = Time * 0.1715;
if (CurrentDistance == 0) {
CurrentDistance = MaxDistance;
}
return CurrentDistance;
}
};
// Initialize sensors with the same pins
Sonar sonarLeft(2, 3, 30); // Initialize left sonar sensor
Sonar sonarRight(4, 5, 30); // Initialize right sonar sensor
int pwm_a = 3;
int pwm_b = 11;
int dir_a = 2;
int dir_b = 4;
int pw_straight_a = 180;
int pw_straight_b = 180;
int TimeDefault = 5000; // Default time to perform a single drive maneuver (e.g. Forward or Reverse)
void setup() {
  pinMode(pwm_a, OUTPUT);
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);
  Serial.begin(9600); // Open serial monitor at 9600 baud
}
void loop() {
  int distanceLeft = sonarLeft.Measure(); // Measure distance from left sonar sensor
  int distanceRight = sonarRight.Measure(); // Measure distance from right sonar sensor
  // Print distances to serial monitor for debugging
  Serial.print("Left Distance: ");
  Serial.print(distanceLeft);
  Serial.print(" Right Distance: ");
  Serial.println(distanceRight);
  // Choose the direction with the shortest distance
  if (distanceLeft < distanceRight) {
    TurnLeft(TimeDefault, pw_straight_a, pw_straight_b);
    delay(2000);
    Forward(TimeDefault, pw_straight_a, pw_straight_b);
} else {
      TurnRight(TimeDefault, pw_straight_a, pw_straight_b);
      delay(2000);
      Forward(TimeDefault, pw_straight_a, pw_straight_b);
}
}
void TurnRight(int Duration, int pulsewidth_a, int pulsewidth_b) {
  // Function to rotate to the right for a specified duration
  Serial.print("Rotate right for ");
  Serial.print(Duration / 1000.);
  Serial.println(" seconds");
  digitalWrite(dir_a, HIGH); // Drive left side wheels forward
  digitalWrite(dir_b, LOW); // Drive right side wheels backward
  analogWrite(pwm_a, pulsewidth_a);
  analogWrite(pwm_b, pulsewidth_b);
  delay(100);
}
void TurnLeft(int Duration, int pulsewidth_a, int pulsewidth_b) {
// Function to rotate to the left for a specified duration
Serial.print("Rotate left for ");
Serial.print(Duration / 1000.);
Serial.println(" seconds");
digitalWrite(dir_a, LOW); // Drive left side wheels backward
digitalWrite(dir_b, HIGH); // Drive right side wheels forward
analogWrite(pwm_a, pulsewidth_a);
analogWrite(pwm_b, pulsewidth_b);
delay(100);
}
void Forward(int Duration, int pulsewidth_a, int pulsewidth_b) {
// Function to drive forward for a specified duration
Serial.print("Forward for ");
Serial.print(Duration / 1000.);
Serial.println(" seconds");
digitalWrite(dir_a, HIGH);
digitalWrite(dir_b, HIGH);
analogWrite(pwm_a, pulsewidth_a);
analogWrite(pwm_b, pulsewidth_b);

delay(500);
}
/* Test code 3/1/24 - object recognition and driving forward
*/