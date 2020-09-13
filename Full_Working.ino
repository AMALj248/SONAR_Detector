//Code By AJ
#include <SegmentDisplay.h>
#include<Servo.h>
#include <NewPing.h>
#define TRIGGER_PIN 10
#define ECHO_PIN 13
#define MAX_DISTANCE 400
int srv =11;
int led = 12;
int angle =0;

 // NewPing setup of pins and maximum distance
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
// Setup the & segment Display with the correct pin order 
SegmentDisplay segmentDisplay(2, 3, 4, 5, 6, 7, 8, 9);
//Setup for the Servo 
Servo servo_test;

void setup() {
  // Configuring Pins for output for 7 segment
   pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

 //Configuring Pin for LED
  pinMode(led, OUTPUT);

  //Configuring Pin for Servo
  servo_test.attach(srv);

  //Configuring HC-SR04  Serial 
  Serial.begin(9600);

}

void loop() {

// To turn the Servo in Postive Direction
for(angle=0;angle<180;angle++)
{
 // T move the servo 
servo_test.write(angle);
delay(5);

// To Calculate Distance 
unsigned int distance = sonar.ping_cm();

// To Print Distance to Serial Monitor 
   Serial.print(distance);
   Serial.println("cm");

// Danger Proximity Check   
   if(distance<10)
   {
    //Display the Distance to 7 segment Display 
    segmentDisplay.displayHex(distance , false);
    //To turn LED ON 
    digitalWrite(led , HIGH);
    delay(20);
    //To turn LED OFF 
    digitalWrite(led , LOW);
    
    }

}

delay(1000);

// To turn the Servo in Negative Direction
for(angle=180;angle>1;angle--)
{servo_test.write(angle);
delay(5);
   unsigned int distance = sonar.ping_cm();
   Serial.print(distance);
   Serial.println("cm");
   if(distance<10)
   {segmentDisplay.displayHex(distance , false);
   digitalWrite(led , HIGH);
   delay(20);
   digitalWrite(led , LOW);
    }
}


}
