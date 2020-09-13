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
SegmentDisplay segmentDisplay(2, 3, 4, 5, 6, 7, 8, 9);
Servo servo_test;

void setup() {
  // put your setup code here, to run once:
   pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(led, OUTPUT);
  servo_test.attach(srv);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  // put your main code here, to run repeatedly:
for(angle=0;angle<180;angle++)
{servo_test.write(angle);
delay(5);
unsigned int distance = sonar.ping_cm();
   Serial.print(distance);
   Serial.println("cm");
   
   if(distance<10)
   {
    segmentDisplay.displayHex(distance , false);
    digitalWrite(led , HIGH);
    delay(20);
    digitalWrite(led , LOW);
    
    }

}

delay(1000);

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
