#include <NewPing.h>
int pwm_a = 3;
int pwm_b = 11;
int dir_a = 2;
int dir_b = 4;
int pw_straight_a = 180;
int pw_straight_b = 180;
int TimeDefault = 5000;  // Default time to perform a single drive maneuver (e.g. Forward or Reverse)
int Time90 = 800;      // Set time to rotate robot 90 degrees
/* IR sensor pin definitions and variables. */
int IRsensorPin = A0;  // Define the input pin for the IR sensor


#define TRIGGER 12      // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO 13         // Arduino pin tied to echo pin on the ultrasonic sensor.
#define DISTHRESH_R 20  // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define DISTHRESH_L 5
#define DISTHRESH_F 8
#define MAX_DIST 30


NewPing sonar(TRIGGER, ECHO, MAX_DIST);  // NewPing setup of pins and maximum distance.
void setup() {
  pinMode(pwm_a, OUTPUT);
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);
  Serial.begin(74880);  // Open serial monitor at 115200 baud to see ping results. -;'
}


void loop() {
  delay(50);  // Wait 50ms between pings (20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm());  // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
 
  if (sonar.ping_cm() > DISTHRESH_R || sonar.ping_cm() == 0)  // greater than 15cm turn right back to wall //
  {
    TurnRight(TimeDefault, pw_straight_a, pw_straight_b);
   
    delay(2000);
    Forward(TimeDefault, pw_straight_a, pw_straight_b);
  }
    else if ((sonar.ping_cm() < DISTHRESH_L) && (sonar.ping_cm() != 0)) // less then 8cm turn away from wall
  {
    TurnLeft(TimeDefault, pw_straight_a, pw_straight_b);
   
    delay(2000);
    Forward(TimeDefault, pw_straight_a, pw_straight_b);
  }
    else if ((sonar.ping_cm()))
}


void TurnRight(int Duration, int pulsewidth_a, int pulsewidth_b) {
/*Function to rotate to the right for amount of time Duration, which is argument passed to
  the function. Assumes that right side wheels are plugged into Channel B of the
  Ardumotor board, and left side wheels are plugged into channel A.
  Drives wheels using pareameters pulsewidth_q and pulsewidth_b.*/


  Serial.print("Rotate right for ");
  Serial.print(Duration / 1000.);
  Serial.println(" seconds");
  digitalWrite(dir_a, HIGH);   // Drive left side wheels forward
  digitalWrite(dir_b, LOW);  // Drive right side wheels backward
  analogWrite(pwm_a, pulsewidth_a);
  analogWrite(pwm_b, pulsewidth_b);
  delay(100);
  //hello you gentlesir lentlemen and gadies, i am aliveeeeee
}


void TurnLeft(int Duration, int pulsewidth_a, int pulsewidth_b) {


  Serial.print("Rotate left for ");
  Serial.print(Duration / 1000.);
  Serial.println(" seconds");
  digitalWrite(dir_a, LOW);  // Drive left side wheels backward
  digitalWrite(dir_b, HIGH);   // Drive right side wheels forward
  analogWrite(pwm_a, pulsewidth_a);
  analogWrite(pwm_b, pulsewidth_b);
  delay(100);
}
void Forward(int Duration, int pulsewidth_a, int pulsewidth_b) {
/* Function to drive forward for amount of time Duration, which is argument passed to
  the function. Drives wheels using parameters pulsewidth_a and pulsewidth_b.*/


  Serial.print("Forward for ");
  Serial.print(Duration / 1000.);
  Serial.println(" seconds");
  digitalWrite(dir_a, HIGH);
  digitalWrite(dir_b, HIGH);
  analogWrite(pwm_a, pulsewidth_a);
  analogWrite(pwm_b, pulsewidth_b);
  delay(300);
}
void Reverse(int Duration, int pulsewidth_a, int pulsewidth_b)
{
/* Function to drive backward for amount of time Duration, which is argument passed to
  the function. Drives wheels using parameters pulsewidth_a and pulsewidth_b.*/
  Serial.print("Reverse for ");
  Serial.print(Duration/1000);
  Serial.println(" seconds");
  digitalWrite(dir_a, LOW);
  digitalWrite(dir_b, LOW);
  analogWrite(pwm_a, pulsewidth_a);
  analogWrite(pwm_b, pulsewidth_b);
  delay(Duration);
}
