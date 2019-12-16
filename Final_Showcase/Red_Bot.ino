#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 


Adafruit_DCMotor *myMotor1 = AFMS.getMotor(3);  //right
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(4);  //left


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
  myMotor2->run(FORWARD);

  myMotor1->run(RELEASE);
  myMotor2->run(RELEASE);
  
  pinMode(blade, OUTPUT);
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
  myMotor1->setSpeed(120);    //moves forward towards centerstage
  myMotor2->setSpeed(120);
  delay(4600);  //5500 ms

  stopped();    //stops upon seeing Blue
  delay(4000);  // 9500 ms
  
  forward();
  myMotor1->setSpeed(150);      //leers at Blue, steadily cornering him
  myMotor2->setSpeed(150);
  delay(11000); //20500 ms
  
  for (pos = 0; pos < 65; pos ++) { 
    servo.write(pos); 
    delay(50);            //threateningly lowering arm without blade rotation
  }

  for (pos = 65; pos > 0; pos --) { 
    servo.write(pos);     //threateningly raising arm without blade rotation
    delay(50);  
  }
  
  stopped();    //stopping to deliver dialogue
  delay(7000);  //27500 ms
  
  forward();
  myMotor1->setSpeed(250);    //lunges forward at Blue
  myMotor2->setSpeed(250);
  delay(1000); //28500 ms
  
  forward();
  myMotor1->setSpeed(150);    //continues leering at Blue
  myMotor2->setSpeed(150);
  delay(13000); //41500 ms
  
  for (pos = 0; pos < 65; pos ++) { 
    servo.write(pos); 
    delay(10);
    if (pos > 40){                  //lowers arm while blade spins
      digitalWrite(blade, HIGH);
      delay(50);               
    }
  }
  
  forward();
  myMotor1->setSpeed(250);  
  myMotor2->setSpeed(250);    //lunges at Blue with lowered blade spinning
  delay(1000); //42500 ms
  
  digitalWrite(blade, LOW);     //stops blade
  
  for (pos = 65; pos > 0; pos --) { 
    servo.write(pos); 
    delay(10);
    if (pos > 40){            //raises arm back up with blade spinning temporarily
      digitalWrite(blade, HIGH);
      delay(50);               
    }
  }
  
  digitalWrite(blade, LOW);   //stops blade
  
  right();
  delay(1500);

  left();
  delay(1500);

  backright();            //threatening circling of Blue
  delay(2500);

  backleft();
  delay(1500);

  right();
  delay(1000);   //52500 ms

  stopped();
  delay(5000);  //57500 ms

  inplaceright();
  delay(4000);  //61500 ms

  inplaceleft();              //continued threatening circling of Blue
  delay(1000);  //62500 ms

  stopped();
  delay(4000);  //66500 ms
  
  inplaceleft();
  delay(2000);  //68500 ms

  inplaceright();
  delay(1000);  //69500 ms

  stopped();
  delay(2000);  //71500 ms      //gets broken in half by Blue

  for(i = 0; i<28; i++){
    wiggle();           //death throes
  }   //97600 ms

  left();
  delay(1000);  //98600 ms

  stopped();
  delay(3900);  //102500 ms

  wiggle(); //103400 ms
  
  stopped();
  delay(7000);  //110400 ms

  wiggle(); //111300 ms

  stopped();
  delay(7000);  //118300 ms

  wiggle(); //119200 ms

  forward();
  myMotor1->setSpeed(250);  
  myMotor2->setSpeed(250);
  delay(1000); //120200 ms  

  stopped();                  //is "dead" during this time
  delay(35500); //157700 ms

  wiggle();
  wiggle();         //comes back to life and wiggles to song
  wiggle(); //160100 ms

  forward();
  myMotor1->setSpeed(250);  
  myMotor2->setSpeed(250);
  delay(1000); //161100 ms

  backward();
  myMotor1->setSpeed(250);  
  myMotor2->setSpeed(250);    // moving back and forth to music
  delay(1000); //162100 ms

  stopped();          //in time to music for effect
  delay(900); //163000 ms

  forward();
  myMotor1->setSpeed(150);  
  myMotor2->setSpeed(150);    //approaching audience for "bow"
  delay(1700); //180000 ms
  
  while(1){
  stopped();
  delay(1500);      //preventing further movement
  }

}

void forward(){     //setting motors to move forward
  myMotor1->run(FORWARD);
  myMotor2->run(FORWARD);
}

void backward(){      //setting motors to move backward
  myMotor1->run(BACKWARD);
  myMotor2->run(BACKWARD);
}

void inplaceright(){      //setting motors to turn in opposite directions at the same speed towards the right
  myMotor1->run(BACKWARD);
  myMotor2->run(FORWARD);
  myMotor1->setSpeed(250);  
  myMotor2->setSpeed(250);
}

void inplaceleft(){       //setting motors to turn in opposite directions at the same speed towards the left
  myMotor1->run(FORWARD);
  myMotor2->run(BACKWARD);
  myMotor1->setSpeed(250);  
  myMotor2->setSpeed(250);
}

void right(){       //setting motors to move in the same direction at different speed to turn right
  myMotor1->run(FORWARD);
  myMotor2->run(FORWARD);
  myMotor1->setSpeed(170);  
  myMotor2->setSpeed(250);
}

void backright(){     //setting motors to move in the same direction at different speed to reverse the right() movement
  myMotor1->run(BACKWARD);
  myMotor2->run(BACKWARD);
  myMotor1->setSpeed(250);  
  myMotor2->setSpeed(170);  
}

void left(){        //setting motors to move in the same direction at different speed to turn left
  myMotor1->run(FORWARD);
  myMotor2->run(FORWARD);
  myMotor1->setSpeed(250);  
  myMotor2->setSpeed(170);
}
  
void backleft(){      //setting motors to move in the same direction at different speed to reverse the left() movement
  myMotor1->run(BACKWARD);
  myMotor2->run(BACKWARD);
  myMotor1->setSpeed(170);  
  myMotor2->setSpeed(250);  
}

void wiggle(){  //900 ms long wiggle back and forth
  inplaceright();
  delay(200);
  inplaceleft();
  delay(300);
  
  inplaceright();
  delay(200);
  inplaceleft();
  delay(200);
}

void stopped(){     //stopping motors
  forward();
  myMotor1->setSpeed(0);  
  myMotor2->setSpeed(0);
}
