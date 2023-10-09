/*
 * this program is under editing for push notification
 */
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLik2TO8IH"
#define BLYNK_DEVICE_NAME "waterproofultrasonic"
#define BLYNK_AUTH_TOKEN "Your Auth Token"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define USE_NODE_MCU_BOARD

#include "BlynkEdgent.h"

#define echoPin D7
#define trigPin D6

long duration;
int distance; 

void ultrasonic()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2; //formula to calculate the distance for ultrasonic sensor
    Serial.print("Distance: ");
    Serial.println(distance);
    Blynk.virtualWrite(V0, distance);
    delay(500);
}
void setup()
{
  Serial.begin(9600);
  pinMode(34, INPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  BlynkEdgent.begin();
  delay(2000); 
}

void loop() 
{
  BlynkEdgent.run();
  ultrasonic();
}
