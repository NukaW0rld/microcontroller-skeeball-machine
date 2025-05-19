// Date: May 2nd 2022
// Name: Andrew Davis, James Le, Smile Tongkaw
// Course number: EE 1301
// Term: Spring 2022
// Lab/assignment number: IoT Final Project
// Short Program Description: Skeeball Machine

#include "Particle.h"
#include "HC_SR04.h"

// Sensors: (trigPin, echoPin, minDist, maxDist)
HC_SR04 sensorLow = HC_SR04(A2, D2, 7.0, 999);
HC_SR04 sensorMid = HC_SR04(A1, D1, 7.0, 999);
HC_SR04 sensorHigh = HC_SR04(A0, D0, 7.0, 999);

// Distance tracking variables
double distSensorLow, distSensorMid, distSensorHigh;
double distLastSensorLow = -1, distLastSensorMid = -1, distLastSensorHigh = -1;

// Hardware pins
const int button = D6;
int buttonLast = LOW;

const int led1 = D3;
const int led2 = D4;
const int led3 = D5;
const int buzzer = D7;

int totalScore = 0;
unsigned long int timeToRecordDist;
unsigned long int timeToBuzz;

// Timers
Timer led3Timer(10000, led3Run);
Timer led2Timer(20000, led2Run);
Timer led1Timer(30000, led1Run);
Timer buzzerTimerOn(30000, buzzerOn, true);
Timer buzzerTimerOff(31000, buzzerOff);
Timer endTimer(30000, endSequence, true);

// Function Definitions
void led3Run() {
    digitalWrite(led3, HIGH);
}

void led2Run() {
    digitalWrite(led2, HIGH);
}

void led1Run() {
    digitalWrite(led1, HIGH);
}

void buzzerOn
