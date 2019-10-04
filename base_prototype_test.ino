#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 


Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(4);


void setup() {
  Serial.begin(9600);          
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  AFMS.begin();  

  myMotor1->setSpeed(100);
  myMotor1->run(FORWARD);
  myMotor2->setSpeed(100);
  myMotor2->run(FORWARD);

  myMotor1->run(RELEASE);
  myMotor2->run(RELEASE);
}

void loop() {
  
  Serial.print("tick");

  myMotor1->run(FORWARD);
  myMotor2->run(FORWARD);
 
    myMotor1->setSpeed(100);  
    myMotor2->setSpeed(100);  
    delay(5000);
 
  Serial.print("tech");
  myMotor1->run(RELEASE);
  myMotor2->run(RELEASE);
  delay(1000);
}
