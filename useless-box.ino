// 

#include <Servo.h>
#include <Bounce2.h>

#define PIN_UNCONNECTED 0  // for seeding random number generator
#define PIN_SWITCH 11  // switch is on pin 11
#define PIN_FINGER 8  // finger servo is on pin 8
#define PIN_LID 7  // lid servo is on pin 7
#define MIN_ANGLE_FINGER 0
#define MAX_ANGLE_FINGER 80
#define MIN_ANGLE_LID 50
#define MAX_ANGLE_LID 130

#define MAX_FUNCTION 7
typedef void(*offFunction)(void);
offFunction offFunctions[MAX_FUNCTION] = {off_1, off_2, off_3, off_4, off_5, off_6, off_7};
//offFunctions[0] = &off_1;  // throws compiler error "does not name a type"...

Servo servoFinger;  // finger servo
Servo servoLid;  // box lid servo
int switchStatus = 0;
int action = 1;
long int actionCounter = 0;
Bounce debouncer = Bounce(); // this is needed for a decent trigger signal

// ---- done once when Arduino boots -------------------------------------------
void setup() {
  Serial.begin(9600);
  pinMode(PIN_SWITCH, INPUT_PULLUP);
  debouncer.attach(PIN_SWITCH);
  debouncer.interval(50);
  servoFinger.attach(PIN_FINGER);
  servoFinger.write(MAX_ANGLE_FINGER);
  servoLid.attach(PIN_LID);
  servoLid.write(MIN_ANGLE_LID);
  randomSeed(analogRead(PIN_UNCONNECTED));
}

// ---- repeat until Arduino is turned off -------------------------------------
void loop() {
  debouncer.update();
  switchStatus = debouncer.rose();
  Serial.print("At ");
  Serial.print(millis());
  Serial.print(" msecs,");
  if (switchStatus == LOW) {
    Serial.println(" no action required");
  } else if (switchStatus == HIGH){
    action = (random(7)+1);
    actionCounter++;
    // action=7;
    Serial.print(" action is ");
    Serial.print(action);
    Serial.print(" (");
    Serial.print(actionCounter);
    Serial.println(". action overall)");
    offFunctions[action - 1]();
    servoFinger.write(MAX_ANGLE_FINGER);
    delay(200);
    servoLid.write(MIN_ANGLE_LID);
    delay(200);
  }
  delay(100);    
}


// ---- functions to switch off again ------------------------------------------
void off_1() {
  for(int i = 50; i <= 130; i++){
    servoLid.write(i);
    delay(20);          
  }
  for(int i = 80; i >= 0; i--){
    servoFinger.write(i);
    delay(20);          
  }
  delay(100);
}

void off_2() {
  for(int i= 50; i<=130; i++){
    servoLid.write(i);
    delay(6);          
  }
  delay(550);
  servoFinger.write(10);
  delay(200);
  servoFinger.write(50);
  delay(250);
  servoFinger.write(5);
  delay(250);
  servoFinger.write(50);
  delay(250);
  servoFinger.write(0);
  delay(250);
}

void off_3() {
  for(int i= 50; i<=130; i++){
    servoLid.write(i);
    delay(6);          
  }
  delay(1550);
  servoLid.write(50);
  delay(1550);
  for(int i= 50; i<=130; i++){
    servoLid.write(i);
    delay(13);          
  }  
  delay(550);
  servoFinger.write(10);
  delay(550);
  servoFinger.write(0);
  delay(550);
}

void off_4() {
  for(int i= 50; i<=130; i++){
    servoLid.write(i);
    delay(50);          
  }
  delay(50);
  servoFinger.write(20);
  delay(550);
  servoFinger.write(MAX_ANGLE_FINGER);
  delay(550);
  servoFinger.write(0);
  delay(550);
}

void off_5() {
  for(int i= 50; i<=100; i++){
    servoLid.write(i);
    delay(20);          
  }
  delay(2000);
  for(int i= 100; i<=130; i++){
    servoLid.write(i);
    delay(10);          
  }      
  servoFinger.write(0);
  delay(550);
}

void off_6() {
  for(int i= 50; i<=80; i++){
    servoLid.write(i);
    delay(30);          
  }
  delay(3000);
  for(int i= 80; i<=100; i++){
    servoLid.write(i);
    delay(20);          
  }
  for(int i= 80; i>=20; i--){
    servoFinger.write(i);
    delay(30);          
  }
  delay(1550);
  for(int i= 20; i>=0; i--){
    servoFinger.write(i);
    delay(10);          
  }
  delay(50);
  for(int i= 0; i<=80; i++){
    servoFinger.write(i);
    delay(5);          
  }
  delay(50);
  for(int i= 100; i>=80; i--){
    servoLid.write(i);
    delay(20);          
  }
  delay(2550);    
}

void off_7() {
  for(int i= 50; i<=75; i++){
    servoLid.write(i);
    delay(50);          
  }
  delay(2000);
  for(int i= 75; i<=100; i++){
    servoLid.write(i);
    delay(20);          
  }
  for(int i= 80; i>=10; i--){
    servoFinger.write(i);
    delay(30);          
  }
  delay(2550);
  for(int i= 10; i>=0; i--){
    servoFinger.write(i);
    delay(8);          
  }
  delay(100);
  for(int i= 0; i<=80; i++){
    servoFinger.write(i);
    delay(5);          
  }
  delay(50);
  for(int i= 100; i>=80; i--){
    servoLid.write(i);
    delay(20);          
  }
  delay(2550);    
}

