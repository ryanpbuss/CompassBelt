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
// Connection to Master Reset (MR, pin 10)
const int masterReset = 7;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(masterReset, OUTPUT);
  digitalWrite(masterReset, HIGH);
  //Serial.begin(9600);
  //Serial.println("reset");
  
}

void loop() {

  digitalWrite(masterReset, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 1);
  digitalWrite(latchPin, HIGH);
  delay(1500);
  digitalWrite(masterReset, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  
  
  /*
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(latchPin, HIGH);
  shiftOut(dataPin, clockPin, MSBFIRST, 1);
  delay(2500);
  shiftOut(dataPin, clockPin, MSBFIRST, 0);
  
  digitalWrite(LED_BUILTIN, LOW);
  delay(1500);
  */
  
  /*
  digitalWrite(masterReset, HIGH);
  for (int i = 1; i < 257; i << 1){
    //Serial.print(i, BIN);
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(latchPin, HIGH);
    shiftOut(dataPin, clockPin, MSBFIRST, i);
    delay(1000);
    //digitalWrite(latchPin, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    delay(300);
    
  }
  digitalWrite(masterReset, LOW);
  delay(100);
  */
  
}
