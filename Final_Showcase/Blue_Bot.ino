#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 


Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1); //right
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(4); //left


Servo servo;
// create servo object to control a servo

// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
const int blade =  7; 

// setup() function -- runs once at startup --------------------------------


void setup() {

  Serial.begin(9600); 
  servo.attach(10);
  

  AFMS.begin();  

  myMotor1->setSpeed(200);
  myMotor1->run(FORWARD);
  myMotor2->setSpeed(200);
  myMotor2->run(BACKWARD);

  myMotor1->run(RELEASE);
  myMotor2->run(RELEASE);
  
}



// loop() function -- runs repeatedly as long as board is on ---------------

void loop() {

  uint8_t i;
  delay (5000);

  forward();
  myMotor1->setSpeed(200);  
  myMotor2->setSpeed(200);
  delay(900); 
  stopped();
  delay(1000);
    
  wiggle(); //900 ms
  
  forward();
  myMotor1->setSpeed(150);  
  myMotor2->setSpeed(150);
  delay(4800);  //5700 ms

  stopped();
  delay(4000);  //9700 ms
  
  backward();
  myMotor1->setSpeed(150);  
  myMotor2->setSpeed(150);
  delay(9700); //19100 ms

  stopped();
  delay(7400);  //27500 ms
  
  backward();
  myMotor1->setSpeed(250);  
  myMotor2->setSpeed(250);
  delay(1000); //28500 ms

  stopped();
  delay(14000);  //41500 ms
  
  backward();
  myMotor1->setSpeed(250);  
  myMotor2->setSpeed(250);
  delay(1000); //42500 ms

  stopped();
  delay(10000); //52500 ms
  
  forward();
  myMotor1->setSpeed(150);  
  myMotor2->setSpeed(150);
  delay(5000);  //57500 ms

  stopped();
  delay(9000);  //66500 ms
  
  forward();
  myMotor1->setSpeed(250);  
  myMotor2->setSpeed(250);
  delay(4900);  //70400 ms

  stopped();
  delay(1000);  //71400 ms

  forward();
  myMotor1->setSpeed(200);  
  myMotor2->setSpeed(200);
  delay(12100);   //84500 ms
  
  backward();
  myMotor1->setSpeed(200);  
  myMotor2->setSpeed(200);
  delay(13100);   //976500 ms

  stopped();
  delay(7000);  //102500 ms
  
  forward();
  myMotor1->setSpeed(200);  
  myMotor2->setSpeed(200);
  delay(3000);   //105500 ms
  
  backward();
  myMotor1->setSpeed(200);  
  myMotor2->setSpeed(200);
  delay(3000);   //108500 ms 

  stopped();
  delay(16000); //124500 ms

  left();
  delay(1000); //125500 ms

  stopped();
  delay(2000); //127500 ms

  right();
  delay(1000); //128500 ms

  stopped();
  delay(2000); //130500 ms  
  
  left();
  delay(3000); //133500 ms

  backward();
  myMotor1->setSpeed(200);  
  myMotor2->setSpeed(200);
  delay(3000);   //136500 ms 

  wiggle(); //137400 ms

  for(i = 0; i <10; i++){
    inplaceright();
    delay(1000);

    inplaceleft();
    delay(1000);    
  }   //157400 ms

  stopped();
  delay(2200);  //160400 ms

  forward();
  myMotor1->setSpeed(250);  
  myMotor2->setSpeed(250);
  delay(1000); //161400 ms

  backward();
  myMotor1->setSpeed(250);  
  myMotor2->setSpeed(250);
  delay(700); //162100 ms

  stopped();
  delay(900); //163000 ms

  forward();
  myMotor1->setSpeed(150);  
  myMotor2->setSpeed(150);
  delay(17000); //180000 ms

  
  
  while(1){
  stopped();
  delay(1500);
  }
}

void forward(){
  myMotor1->run(BACKWARD);
  myMotor2->run(FORWARD);
}

void backward(){
  myMotor1->run(FORWARD);
  myMotor2->run(BACKWARD);
}

void inplaceleft(){
  myMotor1->run(FORWARD);
  myMotor2->run(FORWARD);
  myMotor1->setSpeed(250);  
  myMotor2->setSpeed(250);
}

void inplaceright(){
  myMotor1->run(BACKWARD);
  myMotor2->run(BACKWARD);
  myMotor1->setSpeed(250);  
  myMotor2->setSpeed(250);
}

void left(){
  myMotor1->run(BACKWARD);
  myMotor2->run(FORWARD);
  myMotor1->setSpeed(250);  
  myMotor2->setSpeed(170);
}

void right(){
  myMotor1->run(BACKWARD);
  myMotor2->run(FORWARD);
  myMotor1->setSpeed(170);  
  myMotor2->setSpeed(250);
}

void wiggle(){  //900 ms
  inplaceleft();
  delay(150);
  inplaceright();
  delay(150);
  inplaceleft();
  delay(150);
  inplaceright();
  delay(150);
  inplaceleft();
  delay(150);
  inplaceright();
  delay(150);
}

void stopped(){
  forward();
  myMotor1->setSpeed(0);  
  myMotor2->setSpeed(0);
}
