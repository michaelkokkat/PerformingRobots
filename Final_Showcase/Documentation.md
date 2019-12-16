# The Distant Future: The Year 2000

## Project Concept
### Description
[BattleBots](https://battlebots.com/) is an American robot combat television series that features armed and armoured robots fighting each other for audience entertainment. In a satirical critique of robot combat and BattleBots in particular, this performance gives the robots a voice; two voices, to be precise. The performance is a comedic take of the possible context of a robot fight, dramatizing and parodying the clichés of robot combat. Blue, a robot minding his own business, happens upon the aggressive and territorial Red, who is larger and better equipped; yet, in a twist of fate, Blue grievously injures Red, who dies a glorious death... Or does he? In *another* twist of fate, Red joins Blue in his rendition of '[Camptown Races](https://www.youtube.com/watch?v=cdZliSDhgXY)'.


## Robot Specifications
Both robots have similar dimensions, with Red being longer than Blue, and being made in two separate parts (pre-broken). Both robots are primarily constructed out of wood, with cardboard lids for easier access to the electronics inside. The arms attached to the servos are made from foam core board, and the "blade" attached to Red is made from recycled copper PCB.

![System Diagram Red](https://raw.githubusercontent.com/michaelkokkat/PerformingRobots/master/Final_Showcase/Pictures/Red.png)
Basic System Diagram of Red's Hardware

![System Diagram Blue](https://raw.githubusercontent.com/michaelkokkat/PerformingRobots/master/Final_Showcase/Pictures/Blue.png)
Basic System Diagram of Blue's Hardware

Red and Blue are spray-painted their respective colors.
The robots are controlled by Arduino microcontrollers and are entirely autonomous.

![Electronics Red](https://raw.githubusercontent.com/michaelkokkat/PerformingRobots/master/Final_Showcase/Pictures/Red_Inside.png)
Electronic components of Red

![Electronics Blue](https://raw.githubusercontent.com/michaelkokkat/PerformingRobots/master/Final_Showcase/Pictures/Blue_Inside.png)
Electronic components of Blue

## List of Important Parts
  * 2x 11V Lithium battery pack
  * 2x Arduino Uno
  * 2x Adafruit MotorShields
  * 16x AA batteries
  * 4x 4-cell battery case
  * 4x Large DC Motor
  * 2x High Torque Servo Motor
  * 1x Toggle Switch
  * Lots of velcro, duct tape, zipties, and hot glue

## Challenges Faced
  * Lack of sturdiness in original prototype:
          The original prototype was constructed entirely out of cardboard, and as such couldn't support the weight of the electronics between the two heavy DC motors. This was solved by remaking the robots out of wood in the Scene Shop.
  * Servo arm not working for Blue:
          This turned out to be a fault with the servo itself, as the code worked on other tester servos after multiple trials (and re-wiring the motor shield connections to prevent possible short circuits).
  * Screw terminal short circuiting in Red:
          The MotorShield's M1 & M2 screw terminal short circuiting during a performance rehearsal hours before the performance, due to exposed wiring and a lack of anchoring for the inner components. This was resolved by securely inserting and screwing in the wires into the M2 terminal, as well as anchoring down all live components in both robots.
  * Rubber wheel:
          The rubber track of the large DC motor wheel was not securely fixed in place; this led to it coming off before the performance and preventing the two robots from lining up as programmed and rehearsed. This issue was overcome by literally kicking the robot (in order to break it, as that was a crucial part of the performance).

