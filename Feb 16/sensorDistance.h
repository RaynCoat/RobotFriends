#ifndef sensorDistance_h
#define sensorDistance_h

#include "Arduino.h"

class sensorDistance {
  public: 
    sensor(int trigPin, int echoPin);
    float distanceCalc(int trigPin, int echoPin);

  private: 
    int _trigPin;
    int _echoPin;
};

#endif
