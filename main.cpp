#include <Arduino.h>
int pin = 2;
int time = 100;
long i = 0;
// put function definitions here:
  ISR(TIMER1_OVF_vect)
{
  TCNT1 = 53035; // Timer Preloading
  i++;
}
// put function declarations here:
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  TCCR1A = 0;           // Init Timer1
  TCCR1B = 0;           // Init Timer1
  TCCR1B |= B00000011;  // Prescalar = 64
  TCNT1 = 40535;        // Timer Preloading
  TIMSK1 |= B00000001;  // Enable Timer Overflow Interrupt
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  if(i % 2 == 0){
    digitalWrite(2, !digitalRead(2));
  }
  if(i % 3 == 0){
    digitalWrite(3, !digitalRead(3));
  }
  if(i % 4 == 0){
    digitalWrite(4, !digitalRead(4));
  }
}

