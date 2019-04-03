/* Testing Playground
 Used to test components
 Author: Ryan Buss
 March 2019
*/

// Using SN74HC595A Shift Register 


// wiring
// Connection to latch pin Storage Register Clock Pin (ST_CP, 595 pin 12) 
const int latchPin = 8;
// Connection to Shift Register Clock Pin (SH_CP, pin 11)
const int clockPin = 12;
// Connection to Data in (DS, pin 14)
const int dataPin = 11;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  //Serial.begin(9600);
  //Serial.println("reset");
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(latchPin, HIGH);
  shiftOut(dataPin, clockPin, LSBFIRST, 16);
  delay(1000);
  digitalWrite(latchPin, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  delay(300);
}
