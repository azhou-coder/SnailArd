//Annie Zhou
//ART360
//Sideways Snail

//#include <HC_SR04.h>
#include <Ultrasonic.h>
#include <Servo.h> 

#define TRIG_PIN 7 //used to be 12
#define ECHO_PIN 6 //used to be 11
Ultrasonic sr04 = Ultrasonic(ECHO_PIN,TRIG_PIN);
long a;

int pos = 0;    // variable to store the servo position
Servo myservo;  // create servo object to control a servo


long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
pinMode(TRIG_PIN, OUTPUT); // Sets the trigPin as an OUTPUT
pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an INPUT
Serial.begin(9600);
//delay(1000);

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
digitalWrite(TRIG_PIN, LOW);
delayMicroseconds(2);
// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
digitalWrite(TRIG_PIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG_PIN, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(ECHO_PIN, HIGH);
// Calculating the distance
distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
// Displays the distance on the Serial Monitor
Serial.print("Distance: "); //writes out 'Distance: ' in serial monitor
Serial.print(distance); //writes the distance input measured after 'Distance: '
Serial.println(" cm"); //writes ' cm' after the distance input


//snail antenna reacts quickly to objects within a distance of 100
//Antenna reacts slowly to far away objects or a distance greater than 100

if (distance < 100){ //object within the range

    for (pos = 130; pos >= 90; pos -= 1) { // goes from 130 degrees to 90 degrees. 
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos' or 0
    delay(15);                       // waits 15ms for the servo to reach the position. Antenna moves quickly
    }
}
  else if (distance > 100){ //object too far or outside range

    for (pos = 130; pos >= 90; pos -= 1){ //goes from 130 degrees to 90 degrees.
    myservo.write(pos); //tells servo to go to position in variable 'pos' or 0
    delay(55);   //waits 55ms for servo to reach position. Antenna moves slowly
    }

  }

   delay(10); //to test
}
