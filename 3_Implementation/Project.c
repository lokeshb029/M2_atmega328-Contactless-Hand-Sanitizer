#include <Servo.h>

const int trigPin = 7; // Trigger Pin of Ultrasonic Sensor

const int echoPin= 6; // Echo Pin of Ultrasonic Sensor

Servo Myservo;

void setup()
{

Serial.begin(9600); // Starting Serial Terminal

Myservo.attach (5); // Signal Pin of Servo

pinMode(trigPin, OUTPUT);

pinMode(echoPin, INPUT); 
Serial.print(" Distance ");

Serial.print(" Measurement ");
delay(1000);

delay(1000);


delay (2000);
}
void loop()
{

long duration, cm;
 pinMode(trigPin, OUTPUT); 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds (2);
 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);

pinMode(echoPin, INPUT); 
duration= pulseIn(echoPin, HIGH); 
cm = microsecondsToCentimeters(duration);

Serial.print("Distance: ");

Serial.print(cm);

Serial.print("cm");

delay(100);

if (cm >= 20) {

Myservo.write(0);
}
else {
Myservo.write(90);
}
Serial.println();
delay(100);
}
long microsecondsToCentimeters(long microseconds)
{
return microseconds /29/2;
}