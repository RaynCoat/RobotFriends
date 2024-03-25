#include "Arduino.h"
#include "sensorDistance.h"
#define SPEED_OF_SOUND 343 // Speed of sound in m/s

sensorDistance:: sensor(int trigPin, int echoPin) {
  pinMode(trigPin, INPUT);
  pinMode(echoPin, OUTPUT);
  _trigPin = trigPin;
  _echoPin = echoPin;

}

float sensorDistance:: distanceCalc(int trigPin, int echoPin){
  digitalWrite(_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigPin, LOW);

  float t = pulseIn(_echoPin, HIGH);
  float distance = (t * 0.5 * SPEED_OF_SOUND) / 10000;

  return distance;
}