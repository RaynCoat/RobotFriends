#include <sensorDistance.h>

sensorDistance sonicSensor1(2, 3);
sensorDistance sonicSensor2(4, 5);

void setup() {
  Serial.begin(9600);

}

void loop() { 
  sonicSensor1.distanceCalc(2, 3);
  sonicSensor2.distanceCalc(4,5);
  
  Serial.println("Distance 1: " + sonicSensor1.distanceCalc);
  Serial.println("Distance 2: " + sonicSensor2.distanceCalc);

  delay(500);
}

//Sound Sensor Test Code 2