const int blue_led = 9 ;
const int red_led = 4 ;
int i =0;
int level = 0;

void setup()
{
pinMode(blue_led,OUTPUT) ; 
pinMode(red_led,OUTPUT) ;   
}

void loop()
{

while (i<=41){

analogWrite(blue_led,level) ;

delay(50) ;  

level= level+5;
i++;
}

   while (i<=50){

digitalWrite(blue_led,HIGH) ;

delay(750) ; 
 
digitalWrite(blue_led,LOW) ;

delay(250) ;  

i++;
}

while (i<=53){

digitalWrite(blue_led,HIGH) ;

delay(250) ; 
 
digitalWrite(blue_led,LOW) ;

delay(250) ;  

i++;
}
 }
