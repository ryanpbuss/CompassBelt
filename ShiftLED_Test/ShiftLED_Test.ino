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
  //digitalWrite(masterReset, HIGH);
  //Serial.begin(9600);
  //Serial.println("reset");
  
}

void shiftWritePin(int Pin = 1, boolean State = true){
  byte Data = 0;
  digitalWrite(latchPin, LOW);
  bitWrite(Data, Pin, State);
  shiftOut(dataPin, clockPin, MSBFIRST, Data);
  
  digitalWrite(latchPin, HIGH);
  // this would leave the latch pin low, and only pop it to high after a write
  // digitalWrite(latchPin, LOW);
}

void binaryCounter(int switchDelay = 250) {
  digitalWrite(masterReset, HIGH);
  for (int j = 0; j < 256; j++) {
    //ground latchPin and hold low for as long as you are transmitting
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, j);
    //return the latch pin high to signal chip that it
    //no longer needs to listen for information
    digitalWrite(latchPin, HIGH);
    delay(switchDelay);
    //digitalWrite(LED_BUILTIN, HIGH);
    //delay(150);
    //digitalWrite(LED_BUILTIN, LOW);
  }
}


void sequentialLight(int switchDelay = 250){
  // clear whatever's there
  digitalWrite(masterReset, LOW);
  digitalWrite(masterReset, HIGH);

  int pinNum = 0;
  for (pinNum = 0; pinNum < 8; pinNum++){
    shiftWritePin(pinNum, true);
    delay(switchDelay);
  }
  for (pinNum = 7; pinNum >= 0; pinNum--){
    shiftWritePin(pinNum, true);
    delay(switchDelay);
  }

  
  /*
  digitalWrite(latchPin, LOW);
  int i;
  for (i = 1; i < 257; i << 1) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, i);
    digitalWrite(latchPin, HIGH);
    delay(switchDelay);
  }
  for (i = 256; i > 0 ; i >> 1) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, i);
    digitalWrite(latchPin, HIGH);
    delay(switchDelay);
  }
  */
}


void loop() {
  //binaryCounter(75);
  //delay(500);
  sequentialLight(250);
  delay(500);

  /*
  digitalWrite(clockPin, LOW);

  //digitalWrite(masterReset, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(latchPin, LOW);
  delay(10);
  shiftOut(dataPin, clockPin, LSBFIRST, 255);
  digitalWrite(latchPin, HIGH);
  //delay(10);
  //digitalWrite(latchPin, LOW);
  
  delay(1500);
  //digitalWrite(masterReset, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  */
  
  
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
