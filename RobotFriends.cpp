#define trigPin 13
#define echoPin 12
#define blueLED 3

void setup() {

    Serial.begin (9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(blueLED, OUTPUT);
}

void loop() {
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH)
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = 1 + (duration/2) / 29.1;

    analogWrite(blueLED, 1200/distance);
    Serial.println(" cm");
    delay(200);
}