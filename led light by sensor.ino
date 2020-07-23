#define TRIG_PIN 11
#define ECHO_PIN 12
#define LED_PIN 13

void setup() { 
  pinMode(TRIG_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}
 
void loop() 
{
  int distance = 0;  
 
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(5); 
  digitalWrite(TRIG_PIN, LOW); 
  distance = pulseIn(ECHO_PIN, HIGH)/58.2;
  if (distance <= 30) { 
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}


