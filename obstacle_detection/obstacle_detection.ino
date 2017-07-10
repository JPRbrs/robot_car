#include <NewPing.h>

//Ultrasound sensor
#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 300

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Motors
#define ENABLE 5 // pin 1 chip
#define DIRA 3 // pin 7 chip
#define DIRB 4 // pin 2 chip
#define ENABLE2 10 // pin 10 chip
#define DIRC 8 // pin 15 chip
#define DIRD 9 // pin 9 chip
 // pins 4, 5, 12, 13 GND
 // pins 8 y 16 to 5V
 // pin 3 left motor
 // pin 6 left motor
 // pin 11 right motor
 // pin 14 right motor

//initialize motors
enum state_t { stateStopped, stateRunning };
state_t state;
unsigned long startTime;

void setup() {
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(ENABLE2, OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRC, OUTPUT);
  pinMode(DIRB,OUTPUT);
  pinMode(DIRD, OUTPUT);
  Serial.begin(9600);

  state = stateStopped;
  startTime = millis();
}

void run()
{
  unsigned long currentTime = millis();
  unsigned long elapsedTime = currentTime - startTime;
  switch (state) {
  case stateStopped:
    if (elapsedTime >= 1000) {
      digitalWrite(ENABLE, HIGH);
      digitalWrite(ENABLE2, HIGH);
      digitalWrite(DIRA,HIGH);
      digitalWrite(DIRC, HIGH);
      digitalWrite(DIRB, LOW);
      digitalWrite(DIRD, LOW);
      state = stateRunning;
      startTime = currentTime;
    }
    break;
  case stateRunning:
    if (sonar.ping_cm() < 10){
      digitalWrite(DIRA,HIGH);
      digitalWrite(DIRC, LOW);
      digitalWrite(DIRB, LOW);
      digitalWrite(DIRD, HIGH);
      startTime = 750;
      break;      
    }
    if (elapsedTime >= 2000) {
      digitalWrite(ENABLE, LOW);
      digitalWrite(ENABLE2, LOW);
      digitalWrite(DIRA, LOW);
      digitalWrite(DIRC, LOW);
      digitalWrite(DIRB, LOW);
      digitalWrite(DIRD, LOW);
      state = stateStopped;
      startTime = currentTime;
      }
      break;
  }
} 
void loop()
{
  run();
}
