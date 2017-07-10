/************************
Exercise the motor using
the L293D chip
************************/

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

enum state_t { stateStopped, stateRunning };
state_t state;
unsigned long startTime;
int i;
 
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

void loop() {
  //---back and forth example
    Serial.println("One way, then reverse");
    digitalWrite(ENABLE,HIGH); // enable on
    digitalWrite(ENABLE2, HIGH);
    for (i=0;i<5;i++) {
    digitalWrite(DIRA,LOW); //forward
    digitalWrite(DIRC, LOW);
    digitalWrite(DIRB,HIGH);
    digitalWrite(DIRD, HIGH);
    delay(400);
    digitalWrite(DIRA,HIGH);  //backwards
    digitalWrite(DIRC, HIGH);
    digitalWrite(DIRB,LOW);
    digitalWrite(DIRD, LOW);
    delay(200);
    digitalWrite(DIRA,LOW); //turn left
    digitalWrite(DIRC, HIGH);
    digitalWrite(DIRB,HIGH);
    digitalWrite(DIRD, LOW);
    delay(400);
    digitalWrite(DIRA,HIGH);  //backwards
    digitalWrite(DIRC, HIGH);
    digitalWrite(DIRB,LOW);
    digitalWrite(DIRD, LOW);
    delay(400);
    }
  digitalWrite(ENABLE,LOW); // disable
  digitalWrite(ENABLE2, LOW);
  delay(1000);
}
