
#include <SoftwareSerial.h>


char t;

void setup() {
 
pinMode(13,OUTPUT);   //left motors forward
pinMode(12,OUTPUT);   //left motors reverse
pinMode(11,OUTPUT);   //right motors forward
pinMode(10,OUTPUT);   //right motors reverse

SoftwareSerial mySerial(0 , 1); // RX | TX 

Serial.begin(9600); 
 Serial.println("Ready to connect\nDefualt password is 1234 or 000"); 
}

 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
//move forward(all motors rotate in forward direction)
if(t == 'F'){            
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
}
//move reverse (all motors rotate in reverse direction)
else if(t == 'B'){      
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
}
 //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
else if(t == 'L'){     
  digitalWrite(11,HIGH);
}
//turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
else if(t == 'R'){      
  digitalWrite(13,HIGH);
}
 //turn led on or off)
else if(t == 'W'){   
  digitalWrite(9,HIGH);
}
else if(t == 'w'){
  digitalWrite(9,LOW);
}
//STOP (all motors stop)
else if(t == 'S'){      
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}

delay(100);
}
