#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 


Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1); //right wheel
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(4); //left wheel


Servo servo;
// create servo object to control a servo

// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
const int blade =  7; 

// setup() function -- runs once at startup --------------------------------


void setup() {

  Serial.begin(9600); 
  servo.attach(10);   //assign pin 10 to 'servo'
  

  AFMS.begin();  //Motorshield initialized

  myMotor1->setSpeed(200);
  myMotor1->run(FORWARD);
  myMotor2->setSpeed(200);
  myMotor2->run(BACKWARD);  //actually runs forward relative to the robot

  myMotor1->run(RELEASE);
  myMotor2->run(RELEASE);
  
}



// loop() function -- runs repeatedly as long as board is on ---------------

void loop() {

  uint8_t i;  //intiializing i for 'for' loop use
  delay (5000);   //wait 5 seconds before starting

  forward();
  myMotor1->setSpeed(200);  
  myMotor2->setSpeed(200);
  delay(900);   //move forward for .9 seconds in order cue the start of the audio track
  stopped();  //stop for a second in accordance with the audio track
  delay(1000);
    
  wiggle(); // lasts 900 ms (shakes 'awake')
  
  forward();
  myMotor1->setSpeed(150);  
  myMotor2->setSpeed(150);    //moves forward towards centerstage
  delay(4800);  //5700 ms

  stopped();    //stops upon seeing Red
  delay(4000);  //9700 ms
  
  backward();
  myMotor1->setSpeed(150);  
  myMotor2->setSpeed(150);    //backs away from Red
  delay(9700); //19100 ms

  stopped();    //stops in indignation
  delay(7400);  //27500 ms
  
  backward();
  myMotor1->setSpeed(250);    //dashes backward away from Red's lunge
  myMotor2->setSpeed(250);
  delay(1000); //28500 ms

  stopped();      //stands ground
  delay(14000);  //41500 ms
  
  backward();
  myMotor1->setSpeed(250);  //dashes away from Red's blade
  myMotor2->setSpeed(250);
  delay(1000); //42500 ms

  stopped();    //stops
  delay(10000); //52500 ms
  
  forward();
  myMotor1->setSpeed(150);    //chases after Red  
  myMotor2->setSpeed(150);
  delay(5000);  //57500 ms
  
  for (pos = 65; pos > 0; pos --) { 
    servo.write(pos);         //pushes arm forward
    delay(50);  
  }
  
  stopped();    //stops in shock upon Red breaking
  delay(9000);  //66500 ms
  
  forward();      //moves forward to help Red
  myMotor1->setSpeed(250);  
  myMotor2->setSpeed(250);
  delay(4900);  //70400 ms

  stopped();    //stops upon Red's dialogue
  delay(1000);  //71400 ms

  forward();
  myMotor1->setSpeed(200);   //pacing forward and backward
  myMotor2->setSpeed(200);
  delay(12100);   //84500 ms
  
  backward();
  myMotor1->setSpeed(200);  //pacing forward and backward
  myMotor2->setSpeed(200);
  delay(13100);   //976500 ms

  stopped();
  delay(7000);  //102500 ms
  
  forward();
  myMotor1->setSpeed(200);  //pacing forward and backward
  myMotor2->setSpeed(200);
  delay(3000);   //105500 ms
  
  backward();
  myMotor1->setSpeed(200);  //pacing forward and backward
  myMotor2->setSpeed(200);
  delay(3000);   //108500 ms 

  stopped();        //stops during Red's death throes
  delay(16000); //124500 ms

  left();     //turns to look at Red
  delay(1000); //125500 ms

  stopped();
  delay(2000); //127500 ms

  right();      //turns to look at audience
  delay(1000); //128500 ms

  stopped();
  delay(2000); //130500 ms  
  
  left();   //turns back to Red
  delay(3000); //133500 ms

  backward();   //moves upstage
  myMotor1->setSpeed(200);  
  myMotor2->setSpeed(200);
  delay(3000);   //136500 ms 

  wiggle(); //137400 ms

  for(i = 0; i <10; i++){
    inplaceright();
    delay(1000);
                      //"dancing" in time to song
    inplaceleft();
    delay(1000);    
  }   //157400 ms

  stopped();      //stopping when Red moves again
  delay(2200);  //160400 ms

  forward();
  myMotor1->setSpeed(250);    // moving to centerstage
  myMotor2->setSpeed(250);
  delay(1000); //161400 ms

  backward();
  myMotor1->setSpeed(250);  
  myMotor2->setSpeed(250);    //moves to make way for Red
  delay(700); //162100 ms

  stopped();
  delay(900); //163000 ms

  forward();
  myMotor1->setSpeed(150);  
  myMotor2->setSpeed(150);      //approaching audience for "bow"
  delay(17000); //180000 ms 

  
  
  while(1){
  stopped();
  delay(1500);    //preventing further movement
  }
}

void forward(){   //setting motors to move forward
  myMotor1->run(BACKWARD);
  myMotor2->run(FORWARD);
}

void backward(){    //setting motors to move backward
  myMotor1->run(FORWARD);
  myMotor2->run(BACKWARD);
}

void inplaceleft(){   //setting motors to turn in opposite directions at the same speed towards the left
  myMotor1->run(FORWARD);
  myMotor2->run(FORWARD);
  myMotor1->setSpeed(250);  
  myMotor2->setSpeed(250);
}

void inplaceright(){    //setting motors to turn in opposite directions at the same speed towards the right
  myMotor1->run(BACKWARD);
  myMotor2->run(BACKWARD);
  myMotor1->setSpeed(250);  
  myMotor2->setSpeed(250);
}

void left(){  //setting motors to move in the same direction at different speed to turn left
  myMotor1->run(BACKWARD);
  myMotor2->run(FORWARD);
  myMotor1->setSpeed(250);  
  myMotor2->setSpeed(170);
}

void right(){   //setting motors to move in the same direction at different speed to turn right
  myMotor1->run(BACKWARD);
  myMotor2->run(FORWARD);
  myMotor1->setSpeed(170);  
  myMotor2->setSpeed(250);
}

void wiggle(){  //900 ms long wiggle back and forth
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

void stopped(){   //stopping motors
  forward();
  myMotor1->setSpeed(0);  
  myMotor2->setSpeed(0);
}
