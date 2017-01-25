#include <Servo.h>
#include <Bounce2.h>


#define MS1 8 // finger servo is on pin 8
#define MS2 7 // finger servo is on pin 7
#define SWITCH 11 // switch is on pin 11

Servo ms1; // finger servo
Servo ms2; // box lid servo
int switchStatus=0, action=1;
Bounce debouncer = Bounce(); // this is needed for a decent trigger signal
 
void setup() {
  Serial.begin(9600);
  pinMode(SWITCH, INPUT_PULLUP);
  debouncer.attach(SWITCH);
  debouncer.interval(50);
  ms1.attach(MS1);
  ms2.attach(MS2);

}

void loop() {
  // put your main code here, to run repeatedly:
  debouncer.update();
  switchStatus=debouncer.rose();

  
   if (switchStatus == HIGH){
      //randomSeed(millis());
      action=random(7)+1;

     // action=7;
     Serial.println(millis());
     Serial.println(action);

      if(action==1){
        //box servo
         for(int i= 50; i<=130; i++){
            ms2.write(i);
            delay(20);          
          }

        //finger servo
        for(int i= 80; i>=0; i--){
            ms1.write(i);
            delay(20);          
          }
      
    }

    if(action==2){
        //box servo
         for(int i= 50; i<=130; i++){
            ms2.write(i);
            delay(6);          
          }
        delay(550);
        //finger servo
        ms1.write(10);
        delay(200);
        ms1.write(50);
        delay(250);
        ms1.write(5);
        delay(250);
        ms1.write(50);
        delay(250);
        ms1.write(0);
        delay(250);
      action = 100;  
    }

    if(action==3){
        //box servo
         for(int i= 50; i<=130; i++){
            ms2.write(i);
            delay(6);          
          }
          delay(1550);
          ms2.write(50);
          delay(1550);
          for(int i= 50; i<=130; i++){
            ms2.write(i);
            delay(13);          
          }
          
        delay(550);
        //finger servo
        ms1.write(10);
        delay(550);
        ms1.write(0);
        delay(550);
     
    }

    if(action==4){
        //box servo
         for(int i= 50; i<=130; i++){
            ms2.write(i);
            delay(50);          
          }
          delay(50);
        
        //finger servo
        ms1.write(20);
        delay(550);
        ms1.write(70);
        delay(550);
        ms1.write(0);
        delay(550);
      action = 100; 
    } 
    
    if(action==5){
        //box servo
         for(int i= 50; i<=100; i++){
            ms2.write(i);
            delay(20);          
          }
          delay(2000);
         for(int i= 100; i<=130; i++){
            ms2.write(i);
            delay(10);          
          }      
        //finger servo
        ms1.write(0);
        delay(550);
      action = 100; 
    }
    
    

    if(action==6){
        //box servo
         for(int i= 50; i<=80; i++){
            ms2.write(i);
            delay(30);          
          }
          delay(3000);
         for(int i= 80; i<=100; i++){
            ms2.write(i);
            delay(20);          
          }

          
        //finger servo
        for(int i= 80; i>=20; i--){
            ms1.write(i);
            delay(30);          
          }
 
        delay(1550);
        for(int i= 20; i>=0; i--){
            ms1.write(i);
            delay(10);          
          }
        delay(50);
                
        for(int i= 0; i<=80; i++){
            ms1.write(i);
            delay(5);          
          }
        delay(50);
        
        for(int i= 100; i>=80; i--){
            ms2.write(i);
            delay(20);          
          }
        delay(2550);    
      
    }
    //action++;

        if(action==7){
        //box servo
         for(int i= 50; i<=75; i++){
            ms2.write(i);
            delay(50);          
          }
          delay(2000);
         for(int i= 75; i<=100; i++){
            ms2.write(i);
            delay(20);          
          }

          
        //finger servo
        for(int i= 80; i>=10; i--){
            ms1.write(i);
            delay(30);          
          }
 
        delay(2550);
        for(int i= 10; i>=0; i--){
            ms1.write(i);
            delay(8);          
          }
        delay(100);
                
        for(int i= 0; i<=80; i++){
            ms1.write(i);
            delay(5);          
          }
        delay(50);
        
        for(int i= 100; i>=80; i--){
            ms2.write(i);
            delay(20);          
          }
        delay(2550);    
      
    }
    }
    
   if (switchStatus == LOW){ 
      ms1.write(80);
      delay(200);
      ms2.write(50);
      delay(200);
    }
delay(100);
}





